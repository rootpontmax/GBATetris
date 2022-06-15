#ifndef GAME_GRAPHICS_INCLUDED
#define GAME_GRAPHICS_INCLUDED

#include "../Core/gbaregs.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
#define NEXT_TETRAMINO_BLOCK_X 24
#define NEXT_TETRAMINO_BLOCK_Y 4
#define START_FIELD_POS_X 10
////////////////////////////////////////////////////////////////////////////////////////////////////
void InitGraphics();
void CreateBackground();
void ShowBlockBackground(const uint16_t id, int x, int y );
void ShowBlockForeground(const int id, int x, int y, int tileID );
void ShowScores(const int scores);
void ShowLayers(const int layers);
void ShowSpeed(const int speed);
void ShowFPS(const int val);
////////////////////////////////////////////////////////////////////////////////////////////////////

#endif