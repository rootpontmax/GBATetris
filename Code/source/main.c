#include "Core/gbaregs.h"
#include "Core/Input.h"
#include "Game/Game.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
static void ProfilerStart()
{
	REG_TM2CNT_L = 0;
	REG_TM3CNT_L = 0;
	REG_TM2CNT_H = 0;
	REG_TM3CNT_H = 0;

    REG_TM3CNT_H = TMCNT_EN | TMCNT_CASCADE;
    REG_TM2CNT_H = TMCNT_EN;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static uint32_t ProfilerStop()
{
	REG_TM2CNT_H = 0;
	return ( REG_TM3CNT_L << 16 ) | REG_TM2CNT_L;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{	
	InitGraphics();
	ProfilerStart();
	for( ; ; )
	{
		PollHardwareButtons();
		if( WasKeyPressed( KEY_START ) || WasKeyPressed( KEY_A ) || WasKeyPressed( KEY_B ))
		{
			const uint32_t deltaTimeNS = ProfilerStop();
			break;
		}
	}

	InitGame();
	ProfilerStart();
	int frameCount = 0;
	uint32_t timeMS = 0;
	for( ; ; )
	{
		const uint32_t deltaTimeNS = ProfilerStop() * 60;
		ProfilerStart();
		const uint32_t deltaTimeMS = deltaTimeNS / 1000000;
		timeMS += deltaTimeMS;

		while( REG_VCOUNT >= 160 );
    	while( REG_VCOUNT < 160 );
		UpdateGame( deltaTimeMS );

		if( timeMS > 1000 )
		{
			ShowFPS(frameCount);
			frameCount = 0;
			timeMS -= 1000;
		}

		++frameCount;
	}

	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////