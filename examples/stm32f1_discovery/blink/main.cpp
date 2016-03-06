#include "../stm32f1_discovery.hpp"

using namespace Board;

int
xpcc_main()
{
	Board::initialize();

	LedBlue::set();

	while (1)
	{
		LedGreen::toggle();
		xpcc::delayMilliseconds(Button::read() ? 100 : 300);

		LedBlue::toggle();
		xpcc::delayMilliseconds(Button::read() ? 100 : 300);
	}

	return 0;
}
