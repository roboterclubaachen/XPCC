#include <xpcc/architecture/platform.hpp>

using namespace Board;

int
main()
{
	Board::initialize();

	Board::LedNorth::set();

	while (1)
	{
		Board::LedNorth::toggle();
		xpcc::delayMilliseconds(100);
		Board::LedNorthEast::toggle();
		xpcc::delayMilliseconds(100);
		Board::LedEast::toggle();
		xpcc::delayMilliseconds(100);
		Board::LedSouthEast::toggle();
		xpcc::delayMilliseconds(100);
		Board::LedSouth::toggle();
		xpcc::delayMilliseconds(100);
		Board::LedSouthWest::toggle();
		xpcc::delayMilliseconds(100);
		Board::LedWest::toggle();
		xpcc::delayMilliseconds(100);
		Board::LedNorthWest::toggle();
		xpcc::delayMilliseconds(100);
	}

	return 0;
}
