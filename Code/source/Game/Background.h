#ifndef GAME_BACKGROUND_INCLUDED
#define GAME_BACKGROUND_INCLUDED

////////////////////////////////////////////////////////////////////////////////////////////////////
const uint16_t g_tetrisTiles[2560] __attribute__((aligned(4)))=
{
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0B0B,0x0B0B,0x0B0B,0x0B0B,0x0B0B,0x0B0B,0x0B0B,0x0B0B,
	0x0B0B,0x0B0B,0x0B0B,0x0B0B,0x0B0B,0x0B0B,0x0B0B,0x0B0B,
	0x0B0B,0x0B0B,0x0B0B,0x0B0B,0x0B0B,0x0B0B,0x0B0B,0x0B0B,
	0x0B0B,0x0B0B,0x0B0B,0x0B0B,0x0B0B,0x0B0B,0x0B0B,0x0B0B,

	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0505,0x0505,0x0505,0x0505,0x0505,0x0505,0x0505,0x0505,
	0x0505,0x0505,0x0505,0x0505,0x0505,0x0505,0x0505,0x0505,
	0x0505,0x0505,0x0505,0x0505,0x0505,0x0505,0x0505,0x0505,
	0x0505,0x0505,0x0505,0x0505,0x0505,0x0505,0x0505,0x0505,

	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x090C,0x0909,0x0909,0x0909,
	0x090C,0x0909,0x0909,0x0909,0x090C,0x0909,0x0909,0x0909,
	0x090C,0x0909,0x0909,0x0909,0x090C,0x0909,0x0909,0x0909,
	0x090C,0x0909,0x0909,0x0909,0x090C,0x0909,0x0909,0x0909,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0909,0x0909,0x0909,0x0C09,
	0x0909,0x0909,0x0909,0x0C09,0x0909,0x0909,0x0909,0x0C09,
	0x0909,0x0909,0x0909,0x0C09,0x0909,0x0909,0x0909,0x0C09,
	0x0909,0x0909,0x0909,0x0C09,0x0909,0x0909,0x0909,0x0C09,

	0x090C,0x0909,0x0909,0x0909,0x090C,0x0909,0x0909,0x0909,
	0x090C,0x0909,0x0909,0x0909,0x090C,0x0909,0x0909,0x0909,
	0x090C,0x0909,0x0909,0x0909,0x090C,0x0909,0x0909,0x0909,
	0x090C,0x0909,0x0909,0x0909,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0909,0x0909,0x0909,0x0C09,0x0909,0x0909,0x0909,0x0C09,
	0x0909,0x0909,0x0909,0x0C09,0x0909,0x0909,0x0909,0x0C09,
	0x0909,0x0909,0x0909,0x0C09,0x0909,0x0909,0x0909,0x0C09,
	0x0909,0x0909,0x0909,0x0C09,0x0C0C,0x0C0C,0x0C0C,0x0C0C,

	0x060C,0x0606,0x0606,0x0C06,0x060C,0x0606,0x0606,0x0C06,
	0x060C,0x0606,0x0606,0x0C06,0x060C,0x0606,0x0606,0x0C06,
	0x060C,0x0606,0x0606,0x0C06,0x060C,0x0606,0x0606,0x0C06,
	0x060C,0x0606,0x0606,0x0C06,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x060C,0x0606,0x0606,0x0C06,
	0x060C,0x0606,0x0606,0x0C06,0x060C,0x0606,0x0606,0x0C06,
	0x060C,0x0606,0x0606,0x0C06,0x060C,0x0606,0x0606,0x0C06,
	0x060C,0x0606,0x0606,0x0C06,0x060C,0x0606,0x0606,0x0C06,

	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0606,0x0606,0x0606,0x0C06,
	0x0606,0x0606,0x0606,0x0C06,0x0606,0x0606,0x0606,0x0C06,
	0x0606,0x0606,0x0606,0x0C06,0x0606,0x0606,0x0606,0x0C06,
	0x0606,0x0606,0x0606,0x0C06,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x060C,0x0606,0x0606,0x0606,
	0x060C,0x0606,0x0606,0x0606,0x060C,0x0606,0x0606,0x0606,
	0x060C,0x0606,0x0606,0x0606,0x060C,0x0606,0x0606,0x0606,
	0x060C,0x0606,0x0606,0x0606,0x0C0C,0x0C0C,0x0C0C,0x0C0C,

	0x060C,0x0606,0x0606,0x0C06,0x060C,0x0606,0x0606,0x0C06,
	0x060C,0x0606,0x0606,0x0C06,0x060C,0x0606,0x0606,0x0C06,
	0x060C,0x0606,0x0606,0x0C06,0x060C,0x0606,0x0606,0x0C06,
	0x060C,0x0606,0x0606,0x0C06,0x060C,0x0606,0x0606,0x0C06,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0606,0x0606,0x0606,0x0606,
	0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,
	0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,0x0606,
	0x0606,0x0606,0x0606,0x0606,0x0C0C,0x0C0C,0x0C0C,0x0C0C,

	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x030C,0x0303,0x0303,0x0C03,
	0x030C,0x0303,0x0303,0x0C03,0x030C,0x0303,0x0303,0x0C03,
	0x030C,0x0303,0x0303,0x0C03,0x030C,0x0303,0x0303,0x0C03,
	0x030C,0x0303,0x0303,0x0C03,0x030C,0x0303,0x0303,0x0C03,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0303,0x0303,0x0303,0x0C03,
	0x0303,0x0303,0x0303,0x0C03,0x0303,0x0303,0x0303,0x0C03,
	0x0303,0x0303,0x0303,0x0C03,0x0303,0x0303,0x0303,0x0C03,
	0x0303,0x0303,0x0303,0x0C03,0x0C0C,0x0C0C,0x0C0C,0x0C0C,

	0x030C,0x0303,0x0303,0x0C03,0x030C,0x0303,0x0303,0x0C03,
	0x030C,0x0303,0x0303,0x0C03,0x030C,0x0303,0x0303,0x0C03,
	0x030C,0x0303,0x0303,0x0C03,0x030C,0x0303,0x0303,0x0C03,
	0x030C,0x0303,0x0303,0x0C03,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x030C,0x0303,0x0303,0x0303,
	0x030C,0x0303,0x0303,0x0303,0x030C,0x0303,0x0303,0x0303,
	0x030C,0x0303,0x0303,0x0303,0x030C,0x0303,0x0303,0x0303,
	0x030C,0x0303,0x0303,0x0303,0x0C0C,0x0C0C,0x0C0C,0x0C0C,

	0x030C,0x0303,0x0303,0x0C03,0x030C,0x0303,0x0303,0x0303,
	0x030C,0x0303,0x0303,0x0303,0x030C,0x0303,0x0303,0x0303,
	0x030C,0x0303,0x0303,0x0303,0x030C,0x0303,0x0303,0x0303,
	0x030C,0x0303,0x0303,0x0303,0x030C,0x0303,0x0303,0x0C03,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0303,0x0303,0x0303,0x0303,
	0x0303,0x0303,0x0303,0x0303,0x0303,0x0303,0x0303,0x0303,
	0x0303,0x0303,0x0303,0x0303,0x0303,0x0303,0x0303,0x0303,
	0x0303,0x0303,0x0303,0x0303,0x030C,0x0303,0x0303,0x0C03,

	0x030C,0x0303,0x0303,0x0C03,0x0303,0x0303,0x0303,0x0C03,
	0x0303,0x0303,0x0303,0x0C03,0x0303,0x0303,0x0303,0x0C03,
	0x0303,0x0303,0x0303,0x0C03,0x0303,0x0303,0x0303,0x0C03,
	0x0303,0x0303,0x0303,0x0C03,0x030C,0x0303,0x0303,0x0C03,
	0x030C,0x0303,0x0303,0x0C03,0x0303,0x0303,0x0303,0x0303,
	0x0303,0x0303,0x0303,0x0303,0x0303,0x0303,0x0303,0x0303,
	0x0303,0x0303,0x0303,0x0303,0x0303,0x0303,0x0303,0x0303,
	0x0303,0x0303,0x0303,0x0303,0x0C0C,0x0C0C,0x0C0C,0x0C0C,

	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x020C,0x0202,0x0202,0x0C02,
	0x020C,0x0202,0x0202,0x0C02,0x020C,0x0202,0x0202,0x0C02,
	0x020C,0x0202,0x0202,0x0C02,0x020C,0x0202,0x0202,0x0C02,
	0x020C,0x0202,0x0202,0x0C02,0x020C,0x0202,0x0202,0x0C02,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0202,0x0202,0x0202,0x0C02,
	0x0202,0x0202,0x0202,0x0C02,0x0202,0x0202,0x0202,0x0C02,
	0x0202,0x0202,0x0202,0x0C02,0x0202,0x0202,0x0202,0x0C02,
	0x0202,0x0202,0x0202,0x0C02,0x0C0C,0x0C0C,0x0C0C,0x0C0C,

	0x020C,0x0202,0x0202,0x0C02,0x020C,0x0202,0x0202,0x0C02,
	0x020C,0x0202,0x0202,0x0C02,0x020C,0x0202,0x0202,0x0C02,
	0x020C,0x0202,0x0202,0x0C02,0x020C,0x0202,0x0202,0x0C02,
	0x020C,0x0202,0x0202,0x0C02,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x020C,0x0202,0x0202,0x0202,
	0x020C,0x0202,0x0202,0x0202,0x020C,0x0202,0x0202,0x0202,
	0x020C,0x0202,0x0202,0x0202,0x020C,0x0202,0x0202,0x0202,
	0x020C,0x0202,0x0202,0x0202,0x0C0C,0x0C0C,0x0C0C,0x0C0C,

	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x020C,0x0202,0x0202,0x0202,
	0x020C,0x0202,0x0202,0x0202,0x020C,0x0202,0x0202,0x0202,
	0x020C,0x0202,0x0202,0x0202,0x020C,0x0202,0x0202,0x0202,
	0x020C,0x0202,0x0202,0x0202,0x020C,0x0202,0x0202,0x0C02,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0202,0x0202,0x0202,0x0C02,
	0x0202,0x0202,0x0202,0x0C02,0x0202,0x0202,0x0202,0x0C02,
	0x0202,0x0202,0x0202,0x0C02,0x0202,0x0202,0x0202,0x0C02,
	0x0202,0x0202,0x0202,0x0C02,0x020C,0x0202,0x0202,0x0C02,

	0x020C,0x0202,0x0202,0x0C02,0x0202,0x0202,0x0202,0x0C02,
	0x0202,0x0202,0x0202,0x0C02,0x0202,0x0202,0x0202,0x0C02,
	0x0202,0x0202,0x0202,0x0C02,0x0202,0x0202,0x0202,0x0C02,
	0x0202,0x0202,0x0202,0x0C02,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x020C,0x0202,0x0202,0x0C02,0x020C,0x0202,0x0202,0x0202,
	0x020C,0x0202,0x0202,0x0202,0x020C,0x0202,0x0202,0x0202,
	0x020C,0x0202,0x0202,0x0202,0x020C,0x0202,0x0202,0x0202,
	0x020C,0x0202,0x0202,0x0202,0x0C0C,0x0C0C,0x0C0C,0x0C0C,

	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0202,0x0202,0x0202,0x0202,
	0x0202,0x0202,0x0202,0x0202,0x0202,0x0202,0x0202,0x0202,
	0x0202,0x0202,0x0202,0x0202,0x0202,0x0202,0x0202,0x0202,
	0x0202,0x0202,0x0202,0x0202,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x020C,0x0202,0x0202,0x0C02,0x020C,0x0202,0x0202,0x0C02,
	0x020C,0x0202,0x0202,0x0C02,0x020C,0x0202,0x0202,0x0C02,
	0x020C,0x0202,0x0202,0x0C02,0x020C,0x0202,0x0202,0x0C02,
	0x020C,0x0202,0x0202,0x0C02,0x020C,0x0202,0x0202,0x0C02,

	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x070C,0x0707,0x0707,0x0C07,
	0x070C,0x0707,0x0707,0x0C07,0x070C,0x0707,0x0707,0x0C07,
	0x070C,0x0707,0x0707,0x0C07,0x070C,0x0707,0x0707,0x0C07,
	0x070C,0x0707,0x0707,0x0C07,0x070C,0x0707,0x0707,0x0C07,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0707,0x0707,0x0707,0x0C07,
	0x0707,0x0707,0x0707,0x0C07,0x0707,0x0707,0x0707,0x0C07,
	0x0707,0x0707,0x0707,0x0C07,0x0707,0x0707,0x0707,0x0C07,
	0x0707,0x0707,0x0707,0x0C07,0x0C0C,0x0C0C,0x0C0C,0x0C0C,

	0x070C,0x0707,0x0707,0x0C07,0x070C,0x0707,0x0707,0x0C07,
	0x070C,0x0707,0x0707,0x0C07,0x070C,0x0707,0x0707,0x0C07,
	0x070C,0x0707,0x0707,0x0C07,0x070C,0x0707,0x0707,0x0C07,
	0x070C,0x0707,0x0707,0x0C07,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x070C,0x0707,0x0707,0x0707,
	0x070C,0x0707,0x0707,0x0707,0x070C,0x0707,0x0707,0x0707,
	0x070C,0x0707,0x0707,0x0707,0x070C,0x0707,0x0707,0x0707,
	0x070C,0x0707,0x0707,0x0707,0x0C0C,0x0C0C,0x0C0C,0x0C0C,

	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x070C,0x0707,0x0707,0x0707,
	0x070C,0x0707,0x0707,0x0707,0x070C,0x0707,0x0707,0x0707,
	0x070C,0x0707,0x0707,0x0707,0x070C,0x0707,0x0707,0x0707,
	0x070C,0x0707,0x0707,0x0707,0x070C,0x0707,0x0707,0x0C07,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0707,0x0707,0x0707,0x0C07,
	0x0707,0x0707,0x0707,0x0C07,0x0707,0x0707,0x0707,0x0C07,
	0x0707,0x0707,0x0707,0x0C07,0x0707,0x0707,0x0707,0x0C07,
	0x0707,0x0707,0x0707,0x0C07,0x070C,0x0707,0x0707,0x0C07,

	0x070C,0x0707,0x0707,0x0C07,0x0707,0x0707,0x0707,0x0C07,
	0x0707,0x0707,0x0707,0x0C07,0x0707,0x0707,0x0707,0x0C07,
	0x0707,0x0707,0x0707,0x0C07,0x0707,0x0707,0x0707,0x0C07,
	0x0707,0x0707,0x0707,0x0C07,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x070C,0x0707,0x0707,0x0C07,0x070C,0x0707,0x0707,0x0707,
	0x070C,0x0707,0x0707,0x0707,0x070C,0x0707,0x0707,0x0707,
	0x070C,0x0707,0x0707,0x0707,0x070C,0x0707,0x0707,0x0707,
	0x070C,0x0707,0x0707,0x0707,0x0C0C,0x0C0C,0x0C0C,0x0C0C,

	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0707,0x0707,0x0707,0x0707,
	0x0707,0x0707,0x0707,0x0707,0x0707,0x0707,0x0707,0x0707,
	0x0707,0x0707,0x0707,0x0707,0x0707,0x0707,0x0707,0x0707,
	0x0707,0x0707,0x0707,0x0707,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x070C,0x0707,0x0707,0x0C07,0x070C,0x0707,0x0707,0x0C07,
	0x070C,0x0707,0x0707,0x0C07,0x070C,0x0707,0x0707,0x0C07,
	0x070C,0x0707,0x0707,0x0C07,0x070C,0x0707,0x0707,0x0C07,
	0x070C,0x0707,0x0707,0x0C07,0x070C,0x0707,0x0707,0x0C07,

	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x010C,0x0101,0x0101,0x0C01,
	0x010C,0x0101,0x0101,0x0C01,0x010C,0x0101,0x0101,0x0C01,
	0x010C,0x0101,0x0101,0x0C01,0x010C,0x0101,0x0101,0x0C01,
	0x010C,0x0101,0x0101,0x0C01,0x010C,0x0101,0x0101,0x0C01,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0101,0x0101,0x0101,0x0C01,
	0x0101,0x0101,0x0101,0x0C01,0x0101,0x0101,0x0101,0x0C01,
	0x0101,0x0101,0x0101,0x0C01,0x0101,0x0101,0x0101,0x0C01,
	0x0101,0x0101,0x0101,0x0C01,0x0C0C,0x0C0C,0x0C0C,0x0C0C,

	0x010C,0x0101,0x0101,0x0C01,0x010C,0x0101,0x0101,0x0C01,
	0x010C,0x0101,0x0101,0x0C01,0x010C,0x0101,0x0101,0x0C01,
	0x010C,0x0101,0x0101,0x0C01,0x010C,0x0101,0x0101,0x0C01,
	0x010C,0x0101,0x0101,0x0C01,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x010C,0x0101,0x0101,0x0101,
	0x010C,0x0101,0x0101,0x0101,0x010C,0x0101,0x0101,0x0101,
	0x010C,0x0101,0x0101,0x0101,0x010C,0x0101,0x0101,0x0101,
	0x010C,0x0101,0x0101,0x0101,0x0C0C,0x0C0C,0x0C0C,0x0C0C,

	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0101,0x0101,0x0101,0x0C01,
	0x0101,0x0101,0x0101,0x0C01,0x0101,0x0101,0x0101,0x0C01,
	0x0101,0x0101,0x0101,0x0C01,0x0101,0x0101,0x0101,0x0C01,
	0x0101,0x0101,0x0101,0x0C01,0x010C,0x0101,0x0101,0x0C01,
	0x010C,0x0101,0x0101,0x0C01,0x0101,0x0101,0x0101,0x0C01,
	0x0101,0x0101,0x0101,0x0C01,0x0101,0x0101,0x0101,0x0C01,
	0x0101,0x0101,0x0101,0x0C01,0x0101,0x0101,0x0101,0x0C01,
	0x0101,0x0101,0x0101,0x0C01,0x0C0C,0x0C0C,0x0C0C,0x0C0C,

	0x010C,0x0101,0x0101,0x0C01,0x010C,0x0101,0x0101,0x0101,
	0x010C,0x0101,0x0101,0x0101,0x010C,0x0101,0x0101,0x0101,
	0x010C,0x0101,0x0101,0x0101,0x010C,0x0101,0x0101,0x0101,
	0x010C,0x0101,0x0101,0x0101,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x010C,0x0101,0x0101,0x0101,
	0x010C,0x0101,0x0101,0x0101,0x010C,0x0101,0x0101,0x0101,
	0x010C,0x0101,0x0101,0x0101,0x010C,0x0101,0x0101,0x0101,
	0x010C,0x0101,0x0101,0x0101,0x010C,0x0101,0x0101,0x0C01,

	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x040C,0x0404,0x0404,0x0C04,
	0x040C,0x0404,0x0404,0x0C04,0x040C,0x0404,0x0404,0x0C04,
	0x040C,0x0404,0x0404,0x0C04,0x040C,0x0404,0x0404,0x0C04,
	0x040C,0x0404,0x0404,0x0C04,0x040C,0x0404,0x0404,0x0C04,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0404,0x0404,0x0404,0x0C04,
	0x0404,0x0404,0x0404,0x0C04,0x0404,0x0404,0x0404,0x0C04,
	0x0404,0x0404,0x0404,0x0C04,0x0404,0x0404,0x0404,0x0C04,
	0x0404,0x0404,0x0404,0x0C04,0x0C0C,0x0C0C,0x0C0C,0x0C0C,

	0x040C,0x0404,0x0404,0x0C04,0x040C,0x0404,0x0404,0x0C04,
	0x040C,0x0404,0x0404,0x0C04,0x040C,0x0404,0x0404,0x0C04,
	0x040C,0x0404,0x0404,0x0C04,0x040C,0x0404,0x0404,0x0C04,
	0x040C,0x0404,0x0404,0x0C04,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x040C,0x0404,0x0404,0x0404,
	0x040C,0x0404,0x0404,0x0404,0x040C,0x0404,0x0404,0x0404,
	0x040C,0x0404,0x0404,0x0404,0x040C,0x0404,0x0404,0x0404,
	0x040C,0x0404,0x0404,0x0404,0x0C0C,0x0C0C,0x0C0C,0x0C0C,

	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0404,0x0404,0x0404,0x0C04,
	0x0404,0x0404,0x0404,0x0C04,0x0404,0x0404,0x0404,0x0C04,
	0x0404,0x0404,0x0404,0x0C04,0x0404,0x0404,0x0404,0x0C04,
	0x0404,0x0404,0x0404,0x0C04,0x040C,0x0404,0x0404,0x0C04,
	0x040C,0x0404,0x0404,0x0C04,0x0404,0x0404,0x0404,0x0C04,
	0x0404,0x0404,0x0404,0x0C04,0x0404,0x0404,0x0404,0x0C04,
	0x0404,0x0404,0x0404,0x0C04,0x0404,0x0404,0x0404,0x0C04,
	0x0404,0x0404,0x0404,0x0C04,0x0C0C,0x0C0C,0x0C0C,0x0C0C,

	0x040C,0x0404,0x0404,0x0C04,0x040C,0x0404,0x0404,0x0404,
	0x040C,0x0404,0x0404,0x0404,0x040C,0x0404,0x0404,0x0404,
	0x040C,0x0404,0x0404,0x0404,0x040C,0x0404,0x0404,0x0404,
	0x040C,0x0404,0x0404,0x0404,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x040C,0x0404,0x0404,0x0404,
	0x040C,0x0404,0x0404,0x0404,0x040C,0x0404,0x0404,0x0404,
	0x040C,0x0404,0x0404,0x0404,0x040C,0x0404,0x0404,0x0404,
	0x040C,0x0404,0x0404,0x0404,0x040C,0x0404,0x0404,0x0C04,

	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0C0C,0x0C0B,0x0C0B,0x0C0C,0x0B0C,0x0B0C,0x0B0C,0x0B0C,
	0x0B0C,0x0B0C,0x0B0C,0x0B0C,0x0B0C,0x0B0C,0x0B0C,0x0C0C,
	0x0B0C,0x0B0C,0x0B0C,0x0B0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0C0C,0x0B0C,0x0B0B,0x0B0B,0x0C0C,0x0C0C,0x0B0C,0x0C0C,
	0x0B0B,0x0C0C,0x0B0C,0x0C0C,0x0C0C,0x0C0C,0x0B0C,0x0C0C,
	0x0C0B,0x0C0C,0x0B0C,0x0C0C,0x0B0C,0x0C0C,0x0B0C,0x0C0C,
	0x0C0B,0x0C0C,0x0B0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,

	0x0B0C,0x0B0B,0x0B0B,0x0C0C,0x0B0C,0x0C0C,0x0C0C,0x0B0C,
	0x0B0C,0x0C0C,0x0C0C,0x0B0C,0x0B0C,0x0B0B,0x0C0B,0x0B0C,
	0x0B0C,0x0C0C,0x0C0C,0x0B0C,0x0B0C,0x0C0C,0x0C0C,0x0B0C,
	0x0B0C,0x0B0B,0x0B0B,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0B0B,0x0C0B,0x0B0C,0x0C0C,0x0C0C,0x0B0C,0x0B0C,0x0C0C,
	0x0C0C,0x0B0C,0x0B0C,0x0C0C,0x0C0C,0x0C0C,0x0B0C,0x0B0B,
	0x0C0C,0x0B0C,0x0B0C,0x0C0C,0x0C0C,0x0B0C,0x0B0C,0x0C0C,
	0x0B0B,0x0C0B,0x0B0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,

	0x0B0C,0x0C0C,0x0C0C,0x0C0C,0x0B0C,0x0C0C,0x0C0C,0x0B0C,
	0x0B0C,0x0C0C,0x0C0C,0x0C0B,0x0B0B,0x0C0C,0x0C0C,0x0C0B,
	0x0B0C,0x0C0C,0x0C0C,0x0C0B,0x0B0C,0x0C0C,0x0C0C,0x0B0C,
	0x0B0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0B0B,0x0C0B,0x0C0C,0x0C0C,0x0C0C,0x0B0C,0x0C0C,0x0C0C,
	0x0B0C,0x0C0C,0x0C0B,0x0C0C,0x0C0B,0x0C0C,0x0C0B,0x0C0C,
	0x0B0C,0x0C0C,0x0C0B,0x0C0C,0x0C0C,0x0B0C,0x0C0C,0x0C0C,
	0x0B0B,0x0C0B,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,

	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0A0C,0x0C0A,0x0C0C,
	0x0C0C,0x0C0A,0x0A0C,0x0C0C,0x0C0C,0x0C0A,0x0A0C,0x0C0C,
	0x0C0C,0x0C0A,0x0A0C,0x0C0C,0x0C0C,0x0C0A,0x0A0C,0x0C0C,
	0x0C0C,0x0A0C,0x0C0A,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0A0C,0x0C0C,0x0C0C,
	0x0C0C,0x0A0C,0x0C0C,0x0C0C,0x0C0C,0x0A0A,0x0C0C,0x0C0C,
	0x0C0C,0x0A0C,0x0C0C,0x0C0C,0x0C0C,0x0A0C,0x0C0C,0x0C0C,
	0x0C0C,0x0A0A,0x0C0A,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,

	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0A0C,0x0C0A,0x0C0C,
	0x0C0C,0x0C0A,0x0A0C,0x0C0C,0x0C0C,0x0C0C,0x0A0C,0x0C0C,
	0x0C0C,0x0A0C,0x0C0A,0x0C0C,0x0C0C,0x0C0A,0x0C0C,0x0C0C,
	0x0C0C,0x0A0A,0x0A0A,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0A0C,0x0C0A,0x0C0C,
	0x0C0C,0x0C0A,0x0A0C,0x0C0C,0x0C0C,0x0C0C,0x0C0A,0x0C0C,
	0x0C0C,0x0C0C,0x0A0C,0x0C0C,0x0C0C,0x0C0A,0x0A0C,0x0C0C,
	0x0C0C,0x0A0C,0x0C0A,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,

	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0A0A,0x0C0C,
	0x0C0C,0x0A0C,0x0A0C,0x0C0C,0x0C0C,0x0C0A,0x0A0C,0x0C0C,
	0x0C0C,0x0C0A,0x0A0C,0x0C0C,0x0C0C,0x0A0A,0x0A0A,0x0C0C,
	0x0C0C,0x0C0C,0x0A0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0A0A,0x0A0A,0x0C0C,
	0x0C0C,0x0C0A,0x0C0C,0x0C0C,0x0C0C,0x0A0A,0x0C0A,0x0C0C,
	0x0C0C,0x0C0C,0x0A0C,0x0C0C,0x0C0C,0x0C0A,0x0A0C,0x0C0C,
	0x0C0C,0x0A0C,0x0C0A,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,

	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0A0C,0x0C0A,0x0C0C,
	0x0C0C,0x0C0A,0x0C0C,0x0C0C,0x0C0C,0x0A0A,0x0C0A,0x0C0C,
	0x0C0C,0x0C0A,0x0A0C,0x0C0C,0x0C0C,0x0C0A,0x0A0C,0x0C0C,
	0x0C0C,0x0A0C,0x0C0A,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0A0A,0x0A0A,0x0C0C,
	0x0C0C,0x0C0A,0x0A0C,0x0C0C,0x0C0C,0x0C0C,0x0C0A,0x0C0C,
	0x0C0C,0x0A0C,0x0C0C,0x0C0C,0x0C0C,0x0A0C,0x0C0C,0x0C0C,
	0x0C0C,0x0A0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,

	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0A0C,0x0C0A,0x0C0C,
	0x0C0C,0x0C0A,0x0A0C,0x0C0C,0x0C0C,0x0A0C,0x0C0A,0x0C0C,
	0x0C0C,0x0C0A,0x0A0C,0x0C0C,0x0C0C,0x0C0A,0x0A0C,0x0C0C,
	0x0C0C,0x0A0C,0x0C0A,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0A0C,0x0C0A,0x0C0C,
	0x0C0C,0x0C0A,0x0A0C,0x0C0C,0x0C0C,0x0C0A,0x0A0C,0x0C0C,
	0x0C0C,0x0A0C,0x0A0A,0x0C0C,0x0C0C,0x0C0C,0x0A0C,0x0C0C,
	0x0C0C,0x0A0C,0x0C0A,0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0C0C,

	0x0B0B,0x0B0B,0x0B0B,0x0B0B,0x0C0B,0x0C0C,0x0C0C,0x0C0C,
	0x0C0B,0x0C0C,0x0C0C,0x0C0C,0x0C0B,0x0C0C,0x0C0C,0x0B0C,
	0x0C0B,0x0C0C,0x0C0C,0x0B0C,0x0C0B,0x0C0C,0x0C0C,0x0C0C,
	0x0C0B,0x0C0C,0x0C0C,0x0C0C,0x0B0B,0x0B0B,0x0B0B,0x0B0B,
	0x0B0B,0x0B0B,0x0B0B,0x0B0B,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0B0B,0x0C0C,0x0C0B,0x0B0C,0x0C0C,0x0B0C,0x0B0C,0x0B0C,
	0x0B0C,0x0B0C,0x0B0B,0x0B0C,0x0B0B,0x0B0C,0x0B0C,0x0B0C,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0B0B,0x0B0B,0x0B0B,0x0B0B,

	0x0B0B,0x0B0B,0x0B0B,0x0B0B,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0B0C,0x0B0C,0x0B0B,0x0C0C,0x0B0B,0x0B0C,0x0C08,0x0C0C,
	0x0B0C,0x0B0C,0x0C0C,0x0C0C,0x0B0C,0x0B0C,0x0B0B,0x0C0C,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0B0B,0x0B0B,0x0B0B,0x0B0B,
	0x0B0B,0x0B0B,0x0B0B,0x0B0B,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0C0C,0x0B0C,0x0C0C,0x0C0B,0x0C0C,0x0C0B,0x0C0B,0x0C0B,
	0x0C0C,0x0C0B,0x0C0B,0x0C0B,0x0C0C,0x0B0C,0x0C0C,0x0B0C,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0B0B,0x0B0B,0x0B0B,0x0B0B,

	0x0B0B,0x0B0B,0x0B0B,0x0B0B,0x0C0C,0x0C0C,0x0C0C,0x0C0C,
	0x0C0B,0x0B0B,0x0C0B,0x0B0B,0x0C0B,0x080B,0x0C0C,0x0C0B,
	0x0C0B,0x0C0B,0x0C0C,0x0B0B,0x0C0C,0x0B0B,0x0C0B,0x0C0B,
	0x0C0C,0x0C0C,0x0C0C,0x0C0C,0x0B0B,0x0B0B,0x0B0B,0x0B0B,
	0x0B0B,0x0B0B,0x0B0B,0x0B0B,0x0C0C,0x0C0C,0x0C0C,0x0B0C,
	0x0C0B,0x0C0C,0x0C0C,0x0B0C,0x0C0B,0x0C0C,0x0C0C,0x0B0C,
	0x0C0C,0x0C0C,0x0C0C,0x0B0C,0x0C0B,0x0C0C,0x0C0C,0x0B0C,
	0x0C0C,0x0C0C,0x0C0C,0x0B0C,0x0B0B,0x0B0B,0x0B0B,0x0B0B,	
};
////////////////////////////////////////////////////////////////////////////////////////////////////
const uint16_t g_tetrisPal[256] __attribute__((aligned(4)))=
{
	0x0000,0x001F,0x7C00,0x7C1F,0x03E0,0x3DEF,0x7FE0,0x021F,
	0x6739,0x03FF,0x0721,0x7FFF,0x0421,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,	
};
////////////////////////////////////////////////////////////////////////////////////////////////////
const int BG_TILES_COUNT = sizeof( g_tetrisTiles ) / sizeof( g_tetrisTiles[0] ) / 32;
////////////////////////////////////////////////////////////////////////////////////////////////////

#endif