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
		//while(REG_VCOUNT < 160);
		UpdateGame( deltaTimeMS );
	}

	/*
    //set GBA rendering context to MODE 3 Bitmap Rendering
	*(unsigned int*)0x04000000 = 0x0403;

	
	int t = 0;
	while(1){
		int x,y;
		for(x = 0; x < 240; ++x){
			for( y = 0; y < 160; ++y){
				((unsigned short*)0x06000000)[x+y*240] = ((((x&y)+t) & 0x1F) << 10)|
				((((x&y)+t*3)&0x1F)<<5) | ((((x&y)+t * 5)&0x1F)<<0);
			}
		}
		++t;
	}
	*/
	return 0;
    
}
////////////////////////////////////////////////////////////////////////////////////////////////////