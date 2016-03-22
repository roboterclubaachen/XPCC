
#include <xpcc/math/utils/endianness.hpp>

#include "endianness_test.hpp"

/**
 * Test coverage is only 50% as this is expected to run on
 * a little Endian system (x86)
 */

void
EndiannessTest::testToBigEndian()
{
	if (xpcc::isLittleEndian())
	{
		uint32_t val = 0xdeadbeef;
		TEST_ASSERT_EQUALS(xpcc::toBigEndian(val), 0xefbeadde);

		TEST_ASSERT_EQUALS(xpcc::toBigEndian(static_cast<uint32_t>(0xdeadbeef)), 0xefbeadde);

		// Constants are promoted to 32 bits by the compiler.
		// Without static cast, this does not yield to the expected result
		TEST_ASSERT_EQUALS(xpcc::toBigEndian(static_cast<uint16_t>(0xdead)), 0xadde);

		TEST_ASSERT_EQUALS(xpcc::toBigEndian(static_cast<int32_t>(0xdeadbeef)), static_cast<int32_t>(0xefbeadde));
		TEST_ASSERT_EQUALS(xpcc::toBigEndian(static_cast<int16_t>(    0xbeef)), static_cast<int16_t>(0xefbe));
	}
}

void
EndiannessTest::testToLittleEndian()
{
	if (xpcc::isLittleEndian())
	{
		TEST_ASSERT_EQUALS(xpcc::toLittleEndian(static_cast<uint32_t>(0xdeadbeef)), static_cast<uint32_t>(0xdeadbeef));
		TEST_ASSERT_EQUALS(xpcc::toLittleEndian(static_cast<uint16_t>(0xdead    )), static_cast<uint16_t>(0xdead    ));
		TEST_ASSERT_EQUALS(xpcc::toLittleEndian(static_cast<int32_t> (0xdeadbeef)), static_cast<int32_t> (0xdeadbeef));
		TEST_ASSERT_EQUALS(xpcc::toLittleEndian(static_cast<int16_t> (    0xbeef)), static_cast<int16_t> (0xbeef    ));
	}
}

void
EndiannessTest::testFromBigEndian()
{
	if (xpcc::isLittleEndian())
	{
		TEST_ASSERT_EQUALS(xpcc::fromBigEndian(static_cast<uint32_t>(0xdeadbeef)), static_cast<uint32_t>(0xefbeadde));
		TEST_ASSERT_EQUALS(xpcc::fromBigEndian(static_cast<uint16_t>(0xdead    )), static_cast<uint16_t>(0xadde    ));
		TEST_ASSERT_EQUALS(xpcc::fromBigEndian(static_cast<int32_t> (0xdeadbeef)), static_cast<int32_t> (0xefbeadde));
		TEST_ASSERT_EQUALS(xpcc::fromBigEndian(static_cast<int16_t> (    0xbeef)), static_cast<int16_t> (0xefbe    ));
	}
}

void
EndiannessTest::testFromLittleEndian()
{
	if (xpcc::isLittleEndian())
	{
		TEST_ASSERT_EQUALS(xpcc::fromLittleEndian(static_cast<uint32_t>(0xdeadbeef)), static_cast<uint32_t>(0xdeadbeef));
		TEST_ASSERT_EQUALS(xpcc::fromLittleEndian(static_cast<uint16_t>(0xdead    )), static_cast<uint16_t>(0xdead    ));
		TEST_ASSERT_EQUALS(xpcc::fromLittleEndian(static_cast<int32_t> (0xdeadbeef)), static_cast<int32_t> (0xdeadbeef));
		TEST_ASSERT_EQUALS(xpcc::fromLittleEndian(static_cast<int16_t> (    0xbeef)), static_cast<int16_t> (0xbeef    ));
	}
}

// void
// BitOperationTest::testSwap()
// {
// 	TEST_ASSERT_EQUALS(xpcc::swap(static_cast<uint8_t>(0xab)), 0xbaU);
// 	TEST_ASSERT_EQUALS(xpcc::swap(static_cast<uint8_t>(0x18)), 0x81U);
// 	TEST_ASSERT_EQUALS(xpcc::swap(static_cast<uint8_t>(0x0f)), 0xf0U);
// 	TEST_ASSERT_EQUALS(xpcc::swap(static_cast<uint8_t>(0x73)), 0x37U);

// 	TEST_ASSERT_EQUALS(xpcc::swap(static_cast<uint16_t>(0xab45)), 0x45abU);
// 	TEST_ASSERT_EQUALS(xpcc::swap(static_cast<uint16_t>(0x18ab)), 0xab18U);
// 	TEST_ASSERT_EQUALS(xpcc::swap(static_cast<uint16_t>(0x0f26)), 0x260fU);
// 	TEST_ASSERT_EQUALS(xpcc::swap(static_cast<uint16_t>(0x73f7)), 0xf773U);

// 	TEST_ASSERT_EQUALS(xpcc::swap(static_cast<uint32_t>(0xab45de90)), 0x90de45abU);
// 	TEST_ASSERT_EQUALS(xpcc::swap(static_cast<uint32_t>(0x18ab28cf)), 0xcf28ab18U);
// 	TEST_ASSERT_EQUALS(xpcc::swap(static_cast<uint32_t>(0x0f26fe87)), 0x87fe260fU);
// 	TEST_ASSERT_EQUALS(xpcc::swap(static_cast<uint32_t>(0x73f72234)), 0x3422f773U);
// }

// void
// BitOperationTest::testReverse8bit()
// {
// 	uint8_t i, k;
// 	for (i = 1, k = 0x80; i != 0; i <<= 1, k >>= 1)
// 	{
// 		TEST_ASSERT_EQUALS(xpcc::bitReverse(i), k);
// 	}

// 	// test some random values
// 	TEST_ASSERT_EQUALS(xpcc::bitReverse(static_cast<uint8_t>(0xa3)), 0xc5U);
// 	TEST_ASSERT_EQUALS(xpcc::bitReverse(static_cast<uint8_t>(0x0f)), 0xf0U);
// 	TEST_ASSERT_EQUALS(xpcc::bitReverse(static_cast<uint8_t>(0xc1)), 0x83U);
// }

// void
// BitOperationTest::testReverse16bit()
// {
// 	uint16_t i, k;
// 	for (i = 1, k = 0x8000; i != 0; i <<= 1, k >>= 1)
// 	{
// 		TEST_ASSERT_EQUALS(xpcc::bitReverse(i), k);
// 	}

// 	// test some random values
// 	TEST_ASSERT_EQUALS(xpcc::bitReverse(static_cast<uint16_t>(0xa302)), 0x40c5U);
// 	TEST_ASSERT_EQUALS(xpcc::bitReverse(static_cast<uint16_t>(0x00f0)), 0x0f00U);
// 	TEST_ASSERT_EQUALS(xpcc::bitReverse(static_cast<uint16_t>(0xc176)), 0x6e83U);
// }

// void
// BitOperationTest::testReverse32bit()
// {
// 	uint32_t i, k;
// 	for (i = 1, k = 0x80000000; i != 0; i <<= 1, k >>= 1)
// 	{
// 		TEST_ASSERT_EQUALS(xpcc::bitReverse(i), k);
// 	}

// 	// test some random values
// 	TEST_ASSERT_EQUALS(xpcc::bitReverse(static_cast<uint32_t>(0xa3010ff0)), 0x0ff080c5U);
// 	TEST_ASSERT_EQUALS(xpcc::bitReverse(static_cast<uint32_t>(0xa3010ff0)), 0x0ff080c5U);
// 	TEST_ASSERT_EQUALS(xpcc::bitReverse(static_cast<uint32_t>(0x0f0c1760)), 0x06e830f0U);
// 	TEST_ASSERT_EQUALS(xpcc::bitReverse(static_cast<uint32_t>(0xc1040aaa)), 0x55502083U);
// }

// // ----------------------------------------------------------------------------

// void
// BitOperationTest::testCount8bit()
// {
// 	uint8_t i, k;
// 	for (i = 0, k = 0; i < 9; i++)
// 	{
// 		TEST_ASSERT_EQUALS(xpcc::bitCount(k), i);

// 		k <<= 1;
// 		k |= 1;
// 	}

// 	TEST_ASSERT_EQUALS(xpcc::bitCount(static_cast<uint8_t>(0x00)), 0U);
// 	TEST_ASSERT_EQUALS(xpcc::bitCount(static_cast<uint8_t>(0x3c)), 4U);
// 	TEST_ASSERT_EQUALS(xpcc::bitCount(static_cast<uint8_t>(0x80)), 1U);
// 	TEST_ASSERT_EQUALS(xpcc::bitCount(static_cast<uint8_t>(0x07)), 3U);
// 	TEST_ASSERT_EQUALS(xpcc::bitCount(static_cast<uint8_t>(0xaa)), 4U);
// 	TEST_ASSERT_EQUALS(xpcc::bitCount(static_cast<uint8_t>(0x55)), 4U);
// 	TEST_ASSERT_EQUALS(xpcc::bitCount(static_cast<uint8_t>(0xff)), 8U);
// }

// void
// BitOperationTest::testCount16bit()
// {
// 	uint16_t i, k;
// 	for (i = 0, k = 0; i < 17; i++)
// 	{
// 		TEST_ASSERT_EQUALS(xpcc::bitCount(k), i);

// 		k <<= 1;
// 		k |= 1;
// 	}

// 	TEST_ASSERT_EQUALS(xpcc::bitCount(static_cast<uint16_t>(0x0000)), 0U);
// 	TEST_ASSERT_EQUALS(xpcc::bitCount(static_cast<uint16_t>(0x3c00)), 4U);
// 	TEST_ASSERT_EQUALS(xpcc::bitCount(static_cast<uint16_t>(0x0080)), 1U);
// 	TEST_ASSERT_EQUALS(xpcc::bitCount(static_cast<uint16_t>(0xaaaa)), 8U);
// 	TEST_ASSERT_EQUALS(xpcc::bitCount(static_cast<uint16_t>(0x5555)), 8U);
// 	TEST_ASSERT_EQUALS(xpcc::bitCount(static_cast<uint16_t>(0xf307)), 9U);
// 	TEST_ASSERT_EQUALS(xpcc::bitCount(static_cast<uint16_t>(0xffff)), 16U);
// }

// void
// BitOperationTest::testCount32bit()
// {
// 	uint32_t i, k;
// 	for (i = 0, k = 0; i < 33; i++)
// 	{
// 		TEST_ASSERT_EQUALS(xpcc::bitCount(k), i);

// 		k <<= 1;
// 		k |= 1;
// 	}

// 	TEST_ASSERT_EQUALS(xpcc::bitCount(static_cast<uint32_t>(0x00000000)), 0U);
// 	TEST_ASSERT_EQUALS(xpcc::bitCount(static_cast<uint32_t>(0x00003c00)), 4U);
// 	TEST_ASSERT_EQUALS(xpcc::bitCount(static_cast<uint32_t>(0x0560f307)), 13U);
// 	TEST_ASSERT_EQUALS(xpcc::bitCount(static_cast<uint32_t>(0xaaaaaaaa)), 16U);
// 	TEST_ASSERT_EQUALS(xpcc::bitCount(static_cast<uint32_t>(0x55555555)), 16U);
// 	TEST_ASSERT_EQUALS(xpcc::bitCount(static_cast<uint32_t>(0xffffffff)), 32U);
// }
