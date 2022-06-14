#include "Core/gbaregs.h"
#include "Game/Game.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	InitGame();
	
	// Because it constant for GBA 16 frames per second result in 62.5 msec between frames
	const int deltaTimeMS = 62;
	for( ; ; )
	{
		while( REG_VCOUNT >= 160 );
    	while( REG_VCOUNT < 160 );
		UpdateGame( deltaTimeMS );
	}

	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////