#include "string.h"
#include "../Core/gbaregs.h"
#include "Graphics.h"
#include "Background.h"
#include "Sprite.h"

#define VIDEOMODE_0    0x0000
#define BACKGROUND_0   0x0100
#define BACKGROUND_1   0x0200
#define ENABLE_OBJECTS 0x1000
#define MAPPINGMODE_1D 0x0040

#define REG_DISPLAYCONTROL     *((volatile uint16_t*)(0x04000000))
#define REG_BG0_CONTROL        *((volatile uint16_t*)(0x04000008))
#define REG_BG1_CONTROL        *((volatile uint16_t*)(0x0400000A))
#define REG_BG2_CONTROL        *((volatile uint16_t*)(0x0400000C))
#define REG_BG3_CONTROL        *((volatile uint16_t*)(0x0400000E))


////////////////////////////////////////////////////////////////////////////////////////////////////
typedef uint16_t Tile[32];
typedef Tile TileBlock[256];
typedef uint16_t ScreenBlock[1024];
////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct SSpriteAttr
{
	uint16_t attr0;
	uint16_t attr1;
	uint16_t attr2;
	uint16_t padding;
} __attribute__((packed, aligned(4))) SSpriteAttr;
////////////////////////////////////////////////////////////////////////////////////////////////////

#define MEM_BG_PALETTE          ((uint16_t*)(0x05000000)) // Background palette
#define MEM_SP_PALETTE          ((uint16_t*)(0x05000200)) // Sprite palette
#define MEM_VRAM                ((volatile uint32_t*)VRAM_START_ADDR)
#define MEM_TILE                ((TileBlock*)VRAM_START_ADDR)
#define MEM_SCREENBLOCKS        ((ScreenBlock*)0x6000000)
#define MEM_OAM                 ((volatile SSpriteAttr *)0x07000000) // Object Attribute Memory
////////////////////////////////////////////////////////////////////////////////////////////////////
volatile SSpriteAttr           *g_spriteAttribs[8];// = &MEM_OAM[0];
static const uint16_t           BLOCK_ATTR0 = 0x2000;
static const uint16_t           BLOCK_ATTR1 = 0x0000;
////////////////////////////////////////////////////////////////////////////////////////////////////
static void LoadPalette()
{
    memcpy(MEM_BG_PALETTE, g_backgroundPalette, 256);
    memcpy(MEM_SP_PALETTE, g_spritePalette, 256);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static void LoadTiles()
{   
    memcpy(&MEM_TILE[0][0], g_backgroundTiles, BG_TILES_COUNT * 64);
    memcpy(&MEM_TILE[4][1], g_spriteTiles, SP_TILES_COUNT * 64);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static void CreateBackground()
{
    const int BLOCK_SIZE_X = 32;
    const int BLOCK_SIZE_Y = 32;
    const int BLOCK_SIZE = BLOCK_SIZE_X * BLOCK_SIZE_Y;
    uint16_t block[BLOCK_SIZE];
    for( int i = 0; i < BLOCK_SIZE; ++i )
        block[i] = 0;
    
    // Vertical lines
    for( int y = 0; y < 20; ++y )
    {
        const int xA = 9;
        const int xB = 20;
        const int offsetA = y * 32 + xA;
        const int offsetB = y * 32 + xB;
        block[offsetA] = 3;
        block[offsetB] = 3;
    }

    // Free LCD blocks
    for( int y = 0; y < 20; ++y )
        for( int x = 0; x < 10; ++x )
        {
            const int offset = y * 32 + x + 10;
            block[offset] = 1;
        }

    // Free LCD blocks for next tetramino
    for( int y = 0; y < 4; ++y )
        for( int x = 0; x < 4; ++x )
        {
            const int offset = ( y + NEXT_TETRAMINO_BLOCK_Y ) * 32 + x + NEXT_TETRAMINO_BLOCK_X;
            block[offset] = 1;
        }

    memcpy(&MEM_SCREENBLOCKS[1], block, BLOCK_SIZE * sizeof(uint16_t) );
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static void CreateSprites()
{
    for( int i = 0; i < 8; ++i )
    {
        g_spriteAttribs[i] = &MEM_OAM[i];
        g_spriteAttribs[i]->attr0 = BLOCK_ATTR0;
        g_spriteAttribs[i]->attr1 = BLOCK_ATTR1;
        g_spriteAttribs[i]->attr2 = 2;
        ShowBlockForeground(i, -1, -1 );
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void InitGraphics()
{
    LoadPalette();
    LoadTiles();
    CreateBackground();
    CreateSprites();

    REG_BG0_CONTROL = 0x0180;// 0000 0001 1000 0000;
    REG_BG1_CONTROL = 0x4285; // 0100 0010 1000 0101
    //REG_DISPLAYCONTROL =  VIDEOMODE_0 | BACKGROUND_0 | BACKGROUND_1;
    REG_DISPLAYCONTROL =  VIDEOMODE_0 | BACKGROUND_0 | ENABLE_OBJECTS | MAPPINGMODE_1D;// | BACKGROUND_1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void ShowBlockBackground(const int id, int x, int y )
{
    //memcpy(&MEM_SCREENBLOCKS[1], block, BLOCK_SIZE * sizeof(uint16_t) );

}
////////////////////////////////////////////////////////////////////////////////////////////////////
void ShowBlockForeground(const int id, int x, int y )
{
    if( x < 0 || x >= 30 || y < 0 || y >= 20 )
    {
        x = 30;
        y = 30;
    }
    const int POS_MASK = 0x000000FF;
    const int posX = x << 3;
    const int posY = y << 3;
    const uint16_t attr0 = (uint16_t)( posY & POS_MASK );
    const uint16_t attr1 = (uint16_t)( posX & POS_MASK );
    g_spriteAttribs[id]->attr0 = BLOCK_ATTR0 | attr0;
    g_spriteAttribs[id]->attr1 = BLOCK_ATTR1 | attr1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////