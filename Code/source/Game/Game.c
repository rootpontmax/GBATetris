#include "Game.h"
#include "Graphics.h"
#include "../Core/Input.h"
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
#define TERMINO_COUNT 2 // 7
#define ROTATION_COUNT 4
#define FIELD_SIZE_X 10
#define FIELD_SIZE_Y 20
////////////////////////////////////////////////////////////////////////////////////////////////////
typedef uint8_t TTetromino[16];
////////////////////////////////////////////////////////////////////////////////////////////////////
static const TTetromino g_colorTetromino[TERMINO_COUNT][ROTATION_COUNT] =
{
    // Type O
    {
        { 0,0,0,0, 0,4,5,0, 0,6,7,0, 0,0,0,0 },
        { 0,0,0,0, 0,4,5,0, 0,6,7,0, 0,0,0,0 },
        { 0,0,0,0, 0,4,5,0, 0,6,7,0, 0,0,0,0 },
        { 0,0,0,0, 0,4,5,0, 0,6,7,0, 0,0,0,0 },
    },
    // Type I
    {
        {
             0, 0, 0, 0,
            11,13,13,10,
            0,0,0,0,
            0,0,0,0
        },

        {
            0,0, 9,0,
            0,0,12,0,
            0,0,12,0,
            0,0, 8,0
        },

        {
            0, 0, 0, 0,
            0,0,0,0,
            11,13,13,10,
            0,0,0,0
        },

        {
            0, 9,0, 0,
            0,12,0, 0,
            0,12,0, 0,
            0, 8,0, 0
        },
    }
};
/*
////////////////////////////////////////////////////////////////////////////////////////////////////
static const uint16_t g_tetrominoMask[16] =
{
    0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080,
    0x0100, 0x0200, 0x0400, 0x0800, 0x1000, 0x2000, 0x4000, 0x8000
};
*/
/*
////////////////////////////////////////////////////////////////////////////////////////////////////
static const uint16_t   g_tetromino[TERMINO_COUNT][ROTATION_COUNT] =
{
    { 0x0660, 0x0660, 0x0660, 0x0660 }, // Type O
    { 0x00F0, 0x4444, 0x0F00, 0x2222 }, // Type I
    { 0x0071, 0x0226, 0x0470, 0x0322 }, // Type J
    { 0x0074, 0x0622, 0x0170, 0x0223 }, // Type L
    { 0x0036, 0x0462, 0x0360, 0x0231 }, // Type S
    { 0x0063, 0x0264, 0x0630, 0x0132 }, // Type Z
    { 0x0072, 0x0262, 0x0270, 0x0232 }, // Type T
};
*/
////////////////////////////////////////////////////////////////////////////////////////////////////
static uint8_t  g_field[FIELD_SIZE_X][FIELD_SIZE_Y];
static int      g_timeMS = 0;
static int      g_thisTetrominoID = 6;
static int      g_nextTetrominoID = 0;
static int      g_thisTetrominoRotation = 0;
static int      g_nextTetrominoRotation = 0;
static int      g_posX = 0;
static int      g_posY = 0;
static int      g_delayTimeMS = 500;
////////////////////////////////////////////////////////////////////////////////////////////////////
static void ShowTetromino( const TTetromino tetromino, int posX, int posY, int idOffset )
{
    int offset = 0;
    int id = 0;
    for( int y = 0; y < 4; ++y )
        for( int x = 0; x < 4; ++x )
        {
            if( tetromino[offset] > 0 )
            {
                ShowBlockForeground(id + idOffset, posX + x, posY + y, tetromino[offset]);
                ++id;
            }
            ++offset;
        }
}
/*
////////////////////////////////////////////////////////////////////////////////////////////////////
static void ShowTetromino(const uint16_t code, int posX, int posY, int idOffset )
{
    int offset = 0;
    int id = 0;
    for( int y = 0; y < 4; ++y )
        for( int x = 0; x < 4; ++x )
        {
            if( code & g_tetrominoMask[offset] )
            {
                ShowBlockForeground(id + idOffset, posX + x, posY + y);
                ++id;
            }
            ++offset;
        }
}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////
static void ShowThisTetromino(const TTetromino tetromino, int posX, int posY )
{
    ShowTetromino(tetromino, posX + 10, posY, 0);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static void ShowNextTetromino(const TTetromino tetromino)
{
    ShowTetromino(tetromino, NEXT_TETRAMINO_BLOCK_X, NEXT_TETRAMINO_BLOCK_Y, 4);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static void SetupNewTetromino()
{
    g_thisTetrominoID = 1;//g_nextTetrominoID;
    g_thisTetrominoRotation = 0;// g_nextTetrominoRotation;
    g_nextTetrominoID = 1;//rand() % TERMINO_COUNT;
    g_nextTetrominoRotation = 0;//rand() % ROTATION_COUNT;
    g_posX = 3;
    g_posY = 0;//-4;
    ShowNextTetromino(g_colorTetromino[g_nextTetrominoID][g_nextTetrominoRotation]);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void InitGame()
{
    InitGraphics();
    SetupNewTetromino();
    SetupNewTetromino();

    for( int y = 0; y < FIELD_SIZE_Y; ++y )
        for( int x = 0; x < FIELD_SIZE_X; ++x )
            g_field[x][y] = 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static uint8_t CanMoveTetromino(const int deltaX, const int deltaY)
{
    /*
    const uint16_t code = g_tetromino[g_thisTetrominoID][g_thisTetrominoRotation];
    int offset = 0;
    for( int y = 0; y < 4; ++y )
        for( int x = 0; x < 4; ++x )
        {
            if( code & g_tetrominoMask[offset] )
            {
                const int posX = g_posX + x + deltaX;
                const int posY = g_posY + y + deltaY;
                if( posX < 0 || posX >= FIELD_SIZE_X || posY >= FIELD_SIZE_Y )
                    return FALSE;

                if( g_field[posX][posY] > 0 )
                    return FALSE;
            }
            ++offset;
        }
        */

    return TRUE;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static void RestTetromino()
{

}
////////////////////////////////////////////////////////////////////////////////////////////////////
static void UpdateInput()
{
    PollHardwareButtons();

    if( WasKeyPressed( KEY_B ) )
    {
        g_thisTetrominoRotation += 3;
        g_thisTetrominoRotation %= 4;
    }

    if( WasKeyPressed( KEY_A ) )
    {
        g_thisTetrominoRotation += 1;
        g_thisTetrominoRotation %= 4;
    }

    /*
    if( WasKeyPressed( KEY_SELECT ) )
    {
        g_thisTetrominoRotation = 0;
    }
    */

    
    if( WasKeyReleased( KEY_RIGHT ) && CanMoveTetromino(1, 0) )
        ++g_posX;

    if( WasKeyReleased( KEY_LEFT ) && CanMoveTetromino(-1, 0) )
        --g_posX;
        

    /*
    if( WasKeyReleased( KEY_RIGHT ) )
        ++g_posX;

    if( WasKeyReleased( KEY_LEFT ) )
        --g_posX;

    if( WasKeyPressed( KEY_UP ) )
        --g_posY;

    if( WasKeyPressed( KEY_DOWN ) )
        ++g_posY;
        */
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static void UpdateTimer()
{
    if( g_timeMS >= g_delayTimeMS )
    {
        /*    
        if( CanMoveTetromino(0, 1) )
            ++g_posY;
        else
        {
            RestTetromino();
            SetupNewTetromino();
        }
        */
        g_timeMS = 0;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void UpdateGame(int timeMS)
{
    g_timeMS += timeMS;
    UpdateInput();
    UpdateTimer();
    ShowThisTetromino(g_colorTetromino[g_thisTetrominoID][g_thisTetrominoRotation], g_posX, g_posY);
}
////////////////////////////////////////////////////////////////////////////////////////////////////