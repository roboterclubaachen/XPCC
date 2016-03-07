#include "../stm32f429_discovery.hpp"

using namespace Board;

// ----------------------------------------------------------------------------
int
xpcc_main()
{
	Board::initialize();

	LedRed::set();
	usb::VBus::setOutput(xpcc::Gpio::Low);
	usb::Overcurrent::setOutput(xpcc::Gpio::Low);

	while (1)
	{
		LedRed::toggle();
		LedGreen::toggle();

		xpcc::delayMilliseconds(Button::read() ? 125 : 500);

		usb::VBus::toggle();
		usb::Overcurrent::toggle();

		xpcc::delayMilliseconds(Button::read() ? 125 : 500);
	}

	return 0;
}
