// coding: utf-8
/* Copyright (c) 2016, Roboterclub Aachen e. V.
 * All Rights Reserved.
 *
 * The file is part of the xpcc library and is released under the 3-clause BSD
 * license. See the file `LICENSE` for the full license governing this code.
 */
// ----------------------------------------------------------------------------

#ifndef	XPCC__ZEROMQ_CONNECTOR_HPP
#define	XPCC__ZEROMQ_CONNECTOR_HPP

#include <cstring>		// for std::memcpy

#include <zmqpp/zmqpp.hpp>

#include <xpcc/debug/logger.hpp>
#undef XPCC_LOG_LEVEL
#define	XPCC_LOG_LEVEL xpcc::log::ERROR

#include "../backend_interface.hpp"

namespace xpcc
{
class ZeroMQConnectorBase
{
public:
	enum class Mode
	{
		SubPush, /// In this mode the backend connects to a remote machine.
		PubPull, /// Server mode in which the backend binds to two ports. The ports must be accessible.
	};
};

class ZeroMQConnector : public ZeroMQConnectorBase, public BackendInterface
{
public:
	ZeroMQConnector(std::string endpointIn, std::string endpointOut, Mode mode = Mode::SubPush) :
		socketIn (context, (mode == Mode::SubPush ? zmqpp::socket_type::sub  : zmqpp::socket_type::pull)),
		socketOut(context, (mode == Mode::SubPush ? zmqpp::socket_type::push : zmqpp::socket_type::pub)),
		isAvailable(false)
	{
		switch(mode)
		{
			case
			Mode::SubPush:
				this->socketIn.connect(endpointIn);
				this->socketIn.subscribe("");

				this->socketOut.connect(endpointOut);
			break;

			case
			Mode::PubPull:
				this->socketIn.bind(endpointIn);
				this->socketOut.bind(endpointOut);
			break;
		}
	}

	virtual
	~ZeroMQConnector() {
		this->socketIn.unsubscribe("");
		this->socketOut.unsubscribe("");
		this->socketIn.close();
		this->socketOut.close();
	}

	virtual void
	sendPacket(const Header &header, SmartPointer payload)
	{
		// Publish the reassembled message with zeromq
		zmqpp::message message;

		// Manual serialisation of XPCC Header and Payload into a byte buffer
		// The mapping of type, ack, dest, src and id into a uint32_t from
		// CanConnectorBase is used.

		// 5 bytes for header
		uint16_t buf_size = 5 + payload.getSize();
		uint8_t buf[buf_size];

		buf[0] = static_cast<uint8_t>(header.type);
		buf[1] = header.isAcknowledge;
		buf[2] = header.destination;
		buf[3] = header.source;
		buf[4] = header.packetIdentifier;

		memcpy(buf + 5, payload.getPointer(), payload.getSize());

#		if ZMQPP_VERSION_MAJOR >= 4
		/**
		 * Breaking change in 4.1.1:
		 * Removed message::add(pointer, size_t) as there were situations it conflicts with the new easier 
		 * to use templated add. This has been replaced with a message::add_raw(pointer, size_t) method.
		 * https://github.com/zeromq/zmqpp/blob/develop/CHANGES.md
		 */
		message.add_raw(buf, buf_size);
#		else
		message.add(buf, buf_size);
#		endif

		socketOut.send(message, /* dont_block = */ true);
	}

	virtual bool
	isPacketAvailable() const {
		return isAvailable;
	}

	virtual const Header&
	getPacketHeader() const { return receiveItem->header; };

	virtual const xpcc::SmartPointer
	getPacketPayload() const { return receiveItem->payload; };

	virtual void
	dropPacket()
	{
		isAvailable = false;
		delete receiveItem;

#		if ZMQPP_VERSION_MAJOR < 4
		// swap and discard old message as in zmqpp 3
		// "receiving can only be done to empty messages"
		zmqpp::message local;
		std::swap(local, message);
#		endif
	}


	virtual void
	update()
	{
		if (not this->isAvailable) {
			if (this->socketIn.receive(this->message, /* no_block = */ true)) {
				this->isAvailable = true;

				// Parse the data
				uint16_t size = this->message.size(0);

				if (size >= 5)
				{
					uint8_t *buf = (uint8_t *)this->message.raw_data();
					xpcc::Header header = xpcc::Header(
						/* type = */ xpcc::Header::Type(buf[0]),
						/* ack  = */ buf[1],
						/* dest = */ buf[2],
						/* src  = */ buf[3],
						/* id   = */ buf[4]);

					receiveItem = new ReceiveItem(size, header);

					// The XPCC Header is five bytes long.
					// The XPCC payload begins after the XPCC Header
					// The XPCC payload is five bytes shorter than the zeromq message.
					std::memcpy(receiveItem->payload.getPointer(), buf + 5, size - 5);
				}
				else
				{
					XPCC_LOG_ERROR << XPCC_FILE_INFO;
					XPCC_LOG_ERROR << "Message length is " << size << " which is smaller than expected size of 5+" << xpcc::endl;
				}
			}
		}
	}

protected:
	zmqpp::context context;
	zmqpp::socket socketIn;
	zmqpp::socket socketOut;

	/// Store one zmqpp message in backend
	zmqpp::message message;
	bool isAvailable;

	class ReceiveItem
	{
	public:
		ReceiveItem(uint8_t size, const Header& inHeader) :
			header(inHeader), payload(size) {}

	public:
		xpcc::Header header;
		xpcc::SmartPointer payload;
	};

	ReceiveItem *receiveItem;
};

} // xpcc namespace

#endif // XPCC__ZEROMQ_CONNECTOR_HPP
