#include "Game.h"
#include "Graphics.h"
#include "../Core/Input.h"
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
#define GAME_MODE_LIVE 0
#define GAME_MODE_DEAD 1
////////////////////////////////////////////////////////////////////////////////////////////////////
#define TERMINO_COUNT 7
#define ROTATION_COUNT 4
#define FIELD_SIZE_X 10
#define FIELD_SIZE_Y 20
#define SCORES_FULL_LAYER 100
#define SCORES_DOWN 100
#define LAYERS_PER_SPEED 10
////////////////////////////////////////////////////////////////////////////////////////////////////
typedef uint8_t TTetromino[16];
////////////////////////////////////////////////////////////////////////////////////////////////////
static const int g_delayTimeArrayMS[] =
{
    1000,//800,
    600,
    400,
    200,
    100,
    80,
    60,
    50,
    40,
    30
};
////////////////////////////////////////////////////////////////////////////////////////////////////
static const int SPEED_COUNT = sizeof( g_delayTimeArrayMS ) / sizeof( g_delayTimeArrayMS[0] );
////////////////////////////////////////////////////////////////////////////////////////////////////
static const int g_tetromoniStartY[TERMINO_COUNT][ROTATION_COUNT] =
{
    {-2, -2, -2, -2 }, // Type O
    {-1, -3, -2, -3 }, // Type I
    {-1, -2, -2, -2 }, // Type T
    {-1, -2, -2, -2 }, // Type J
    {-1, -2, -2, -2 }, // Type L
    {-1, -2, -2, -2 }, // Type Z
    {-1, -2, -2, -2 }, // Type S
};
////////////////////////////////////////////////////////////////////////////////////////////////////
static const TTetromino g_tetromino[TERMINO_COUNT][ROTATION_COUNT] =
{    
    {
        // Type O
        {0,0,0,0,0,4,5,0,0,6,7,0,0,0,0,0},
        {0,0,0,0,0,4,5,0,0,6,7,0,0,0,0,0},
        {0,0,0,0,0,4,5,0,0,6,7,0,0,0,0,0},
        {0,0,0,0,0,4,5,0,0,6,7,0,0,0,0,0},
    },    
    {
        // Type I
        {0,0,0,0,11,13,13,10,0,0,0,0,0,0,0,0},
        {0,0,9,0,0,0,12,0,0,0,12,0,0,0,8,0},
        {0,0,0,0,0,0,0,0,11,13,13,10,0,0,0,0},
        {0,9,0,0,0,12,0,0,0,12,0,0,0,8,0,0},
    },
    {
        // Type T
        {0,14,0,0,17,21,15,0,0,0,0,0,0,0,0,0},
        {0,14,0,0,0,18,15,0,0,16,0,0,0,0,0,0},
        {0,0,0, 0,17,19,15,0,0,16,0,0,0,0,0,0},
        {0,14,0,0,17,20,0,0,0,16,0,0,0,0,0,0},
    },
    {
        // Type J
        {22,0,0,0,29,30,23,0,0,0,0,0,0,0,0,0},
        {0,26,23,0,0,31,0,0,0,24,0,0,0,0,0,0},
        {0,0,0,0,25,30,27,0,0,0,24,0,0,0,0,0},
        {0,22,0,0,0,31,0,0,25,28,0,0,0,0,0,0},
    },
    {
        // Type L
        {0,0,32,0,35,40,38,0,0,0,0,0,0,0,0,0},
        {0,32,0,0,0,41,0,0,0,39,33,0,0,0,0,0},
        {0,0,0,0,36,40,33,0,34,0,0,0,0,0,0,0},
        {35,37,0,0,0,41,0,0,0,34,0,0,0,0,0,0},
    },
    {
        // Type Z
        {0,49,43,0,45,47,0,0,0,0,0,0,0,0,0,0},
        {0,42,0,0,0,48,46,0,0,0,44,0,0,0,0,0},
        {0,0,0,0,0,49,43,0,45,47,0,0,0,0,0,0},
        {42,0,0,0,48,46,0,0,0,44,0,0,0,0,0,0},
    },
    {
        // Type S
        {53,54,0,0,0,56,51,0,0,0,0,0,0,0,0,0},
        {0,0,50,0,0,57,55,0,0,52,0,0,0,0,0,0},
        {0,0,0,0,53,54,0,0,0,56,51,0,0,0,0,0},
        {0,50,0,0,57,55,0,0,52,0,0,0,0,0,0,0},
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////
static uint8_t  g_field[FIELD_SIZE_X][FIELD_SIZE_Y];
static int      g_mode = GAME_MODE_LIVE;
static int      g_timeMS = 0;
static int      g_thisTetrominoID = 0;
static int      g_nextTetrominoID = 0;
static int      g_thisTetrominoRotation = 0;
static int      g_nextTetrominoRotation = 0;
static int      g_posX = 0;
static int      g_posY = 0;
static int      g_delayTimeMS = 1000;
static int      g_layersCount = 0;
static int      g_scoresCount = 0;
static int      g_speedCoef = 0;
static BOOL     g_bIsFastDownAllowed = TRUE;
static BOOL     g_bIsPaused = FALSE;
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
////////////////////////////////////////////////////////////////////////////////////////////////////
static void ShowThisTetromino(const TTetromino tetromino, int posX, int posY )
{
    ShowTetromino(tetromino, posX + 10, posY, 0);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static void ShowNextTetromino()
{
    ShowTetromino(g_tetromino[g_nextTetrominoID][g_nextTetrominoRotation], NEXT_TETRAMINO_BLOCK_X, NEXT_TETRAMINO_BLOCK_Y, 4);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static void SetupNewRound()
{
    g_thisTetrominoID = g_nextTetrominoID;
    g_thisTetrominoRotation = g_nextTetrominoRotation;
    g_nextTetrominoID = rand() % TERMINO_COUNT;
    g_nextTetrominoRotation = rand() % ROTATION_COUNT;
    g_posX = 3;
    g_posY = g_tetromoniStartY[g_thisTetrominoID][g_thisTetrominoRotation];
    g_speedCoef = g_layersCount / LAYERS_PER_SPEED;
    if( g_speedCoef >= SPEED_COUNT )
        g_speedCoef = SPEED_COUNT - 1;
    g_delayTimeMS = g_delayTimeArrayMS[g_speedCoef];
    g_bIsFastDownAllowed = FALSE;
    ShowNextTetromino();
    ShowScores(g_scoresCount);
    ShowLayers(g_layersCount);
    ShowSpeed(g_speedCoef + 1);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static void RestartGame()
{
    CreateBackground();
    g_mode = GAME_MODE_LIVE;
    g_timeMS = 0;
    g_layersCount = 0;
    g_scoresCount = 0;
    g_speedCoef = 0;

    for( int y = 0; y < FIELD_SIZE_Y; ++y )
        for( int x = 0; x < FIELD_SIZE_X; ++x )
            g_field[x][y] = 0;
    
    SetupNewRound();
    SetupNewRound();
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void InitGame()
{    
    RestartGame();
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static uint8_t CanMoveTetromino(const TTetromino tetromino, const int deltaX, const int deltaY)
{
    int offset = 0;
    for( int y = 0; y < 4; ++y )
        for( int x = 0; x < 4; ++x )
        {
            if( tetromino[offset] > 0 )
            {
                const int posX = g_posX + x + deltaX;
                const int posY = g_posY + y + deltaY;
                if( posX < 0 || posX >= FIELD_SIZE_X || posY >= FIELD_SIZE_Y )
                    return FALSE;

                if( posY >= 0 )
                {
                    if( g_field[posX][posY] > 0 )
                        return FALSE;
                } 
            }
            ++offset;
        }

    return TRUE;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static void GameOver()
{
    // Hide sprites
    for( int i = 0; i < 8; ++i )
        ShowBlockForeground(i, -1, -1, 0 );

    // Draw black background
    for( int y = 0; y < FIELD_SIZE_Y; ++y )
        for( int x = 0; x < FIELD_SIZE_X; ++x )
        {
            const int posX = x + START_FIELD_POS_X;
            ShowBlockBackground(2, posX, y);
        }

    // Draw game over sign
    const int gameOverPosX = 12;
    const int gameOverPosY = 9;
    const int gameOverStartTileID = 74;
    for( int i = 0; i < 6; ++i )
    {
        const int x = gameOverPosX + i;
        const int y = gameOverPosY;
        const int tileID = gameOverStartTileID + i;
        ShowBlockBackground(tileID, x, y);
    }

    g_mode = GAME_MODE_DEAD;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static void RestTetromino(const TTetromino tetromino)
{
    int offset = 0;
    for( int y = 0; y < 4; ++y )
        for( int x = 0; x < 4; ++x )
        {
            if( tetromino[offset] > 0 )
            {
                const int posX = g_posX + x;
                const int posY = g_posY + y;
                if( posX >= 0 && posX < FIELD_SIZE_X && posY >= 0 && posY < FIELD_SIZE_Y )
                    g_field[posX][posY] = tetromino[offset];

                if( 0 == posY)
                {
                    GameOver();
                    return;
                }
            }
            ++offset;
        }
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static void CheckFullLayers()
{
    uint8_t field[FIELD_SIZE_X][FIELD_SIZE_Y];

    int posY = FIELD_SIZE_Y - 1;
    for( int y = FIELD_SIZE_Y - 1; y >= 0; --y )
    {
        BOOL bHasFullRow = TRUE;
        for( int x = 0; x < FIELD_SIZE_X; ++x )
        {
            if( 0 == g_field[x][y] )
                bHasFullRow = FALSE;

            field[x][posY] = g_field[x][y];
        }

        if( bHasFullRow )
        {
            ++g_layersCount;
            g_scoresCount += SCORES_FULL_LAYER;
        }
        else
            --posY;
    }

    memcpy(&g_field[0][0], &field[0][0], FIELD_SIZE_X * FIELD_SIZE_Y);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static void CheckGameOver()
{
    for( int x = 0; x < FIELD_SIZE_X; ++x )
        if( g_field[x][0] != 0 )
        {
            GameOver();
            return;
        }
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static void SetupBackground()
{
    for( int y = 0; y < FIELD_SIZE_Y; ++y )
        for( int x = 0; x < FIELD_SIZE_X; ++x )
        {
            const int posX = x + START_FIELD_POS_X;
            if( 0 == g_field[x][y] )
                ShowBlockBackground(1, posX, y);
            else
                ShowBlockBackground(g_field[x][y], posX, y);
        }
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static void FinishRound()
{
    RestTetromino(g_tetromino[g_thisTetrominoID][g_thisTetrominoRotation]);
    CheckFullLayers();
    CheckGameOver();

    if( GAME_MODE_LIVE == g_mode )
    {
        SetupBackground();
        SetupNewRound();
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static void UpdateInput()
{
    PollHardwareButtons();

    if( GAME_MODE_DEAD == g_mode )
    {
        if( WasKeyPressed( KEY_START ) || WasKeyPressed( KEY_A ) || WasKeyPressed( KEY_B ))
            RestartGame();
        return;
    }

    if( WasKeyPressed( KEY_START ) )
    {
        if( g_bIsPaused )
            g_bIsPaused = FALSE;
        else
            g_bIsPaused = TRUE;
    }

    if( WasKeyReleased( KEY_DOWN ) || !IsKeyPressed( KEY_DOWN ) )
        g_bIsFastDownAllowed = TRUE;

    if( g_bIsFastDownAllowed && IsKeyPressed( KEY_DOWN ) )
    {
        if( CanMoveTetromino(g_tetromino[g_thisTetrominoID][g_thisTetrominoRotation], 0, 1) )
        {
            ++g_posY;
        }
        else
        {
            FinishRound();
            g_scoresCount += SCORES_DOWN;
            return;
        }
    }

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

    if( WasKeyPressed( KEY_START ) )
    {
        ++g_thisTetrominoID;
        g_thisTetrominoID %= TERMINO_COUNT;
    }
    //*/

    
    
        
    
    if( WasKeyPressed( KEY_RIGHT ) && CanMoveTetromino(g_tetromino[g_thisTetrominoID][g_thisTetrominoRotation], 1, 0) )
        ++g_posX;

    if( WasKeyPressed( KEY_LEFT ) && CanMoveTetromino(g_tetromino[g_thisTetrominoID][g_thisTetrominoRotation], -1, 0) )
        --g_posX;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static void UpdateTimer(const int timeMS)
{
    if( g_bIsPaused )
        return;

    g_timeMS += timeMS;

    if( g_timeMS >= g_delayTimeMS )
    {    
        if( CanMoveTetromino(g_tetromino[g_thisTetrominoID][g_thisTetrominoRotation], 0, 1) )
            ++g_posY;
        else
            FinishRound();

        g_timeMS = 0;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static void Render()
{
    ShowThisTetromino(g_tetromino[g_thisTetrominoID][g_thisTetrominoRotation], g_posX, g_posY);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void UpdateGame(const int timeMS)
{
    UpdateInput();
    UpdateTimer(timeMS);
    if( GAME_MODE_LIVE == g_mode )
        Render();
}
////////////////////////////////////////////////////////////////////////////////////////////////////