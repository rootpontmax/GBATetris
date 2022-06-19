#include "Game.h"
#include "Graphics.h"
#include "../Core/Input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
#define GAME_MODE_LIVE 0
#define GAME_MODE_DEAD 1
////////////////////////////////////////////////////////////////////////////////////////////////////
#define TERMINO_COUNT 7
#define ROTATION_COUNT 4
////////////////////////////////////////////////////////////////////////////////////////////////////
#define FIELD_SIZE_X 10
#define FIELD_SIZE_Y 20
////////////////////////////////////////////////////////////////////////////////////////////////////
#define SCORES_FULL_LAYER 100
#define SCORES_DOWN_CONTROLLED 50
#define SCORES_DOWN_UNCONTROLLED 100
////////////////////////////////////////////////////////////////////////////////////////////////////
#define LAYERS_PER_SPEED 10
#define DELAY_INIT_MS 800
#define DELAY_LIMIT_MS 100
#define DELAY_STEP_MS 50
#define HOLD_MOVE_KEY_THRESHOLD_MS 112 // Time to recognise click from hold
#define TIME_BETWEEN_MOVEMENT_MS 24
////////////////////////////////////////////////////////////////////////////////////////////////////
typedef uint8_t TTetromino[16];
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
static int      g_fallTimeMS = 0;
static int      g_holdTimeMS = 0;   // Hold the move key
static int      g_moveTimeMS = 0;   // Time between movements by holding button
static int      g_thisTetrominoID = 0;
static int      g_nextTetrominoID = 0;
static int      g_prevTetrominoID = 0;
static int      g_thisTetrominoRotation = 0;
static int      g_nextTetrominoRotation = 0;
static int      g_posX = 0;
static int      g_posY = 0;
static int      g_fallDelayTimeMS;
static int      g_layersCount = 0;
static int      g_scoresCount = 0;
static int      g_speedCoef = 0;
static BOOL     g_bIsFastDownAllowed = TRUE;
static BOOL     g_bIsPaused = FALSE;
static BOOL     g_bHasMoveKeyHold = FALSE;
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
    g_prevTetrominoID = g_thisTetrominoID;
    g_thisTetrominoID = g_nextTetrominoID;

    // This dirty hack has to prevent three-the-same-in-row case
    do
    {
        g_nextTetrominoID = rand() % TERMINO_COUNT;
    }
    while( g_nextTetrominoID == g_thisTetrominoID && g_thisTetrominoID == g_prevTetrominoID );

    g_thisTetrominoRotation = g_nextTetrominoRotation;
    g_nextTetrominoRotation = rand() % ROTATION_COUNT;

    g_posX = 3;
    g_posY = g_tetromoniStartY[g_thisTetrominoID][g_thisTetrominoRotation];
    g_speedCoef = g_layersCount / LAYERS_PER_SPEED;
    g_fallDelayTimeMS = DELAY_INIT_MS - g_speedCoef * DELAY_STEP_MS;
    if( g_fallDelayTimeMS < DELAY_LIMIT_MS )
        g_fallDelayTimeMS = DELAY_LIMIT_MS;
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
    g_holdTimeMS = 0;
    g_fallTimeMS = 0;
    g_moveTimeMS = 0;
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
static BOOL CanMoveTetromino(const TTetromino tetromino, const int deltaX, const int deltaY)
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
static BOOL CanRotateTetromino(const TTetromino tetromino, int *pPosX, const int posY)
{
    if( CanMoveTetromino(tetromino, 0, 0 ) )
        return TRUE;

    for( int i = 1; i < 4; ++i )
    {
        if( CanMoveTetromino(tetromino, i, 0 ) )
        {
            *pPosX = *pPosX + i;
            return TRUE;
        }
        else if( CanMoveTetromino(tetromino, -i, 0 ) )
        {
            *pPosX = *pPosX - i;
            return TRUE;
        }
    }
    
    return FALSE;
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
static void HandleSideMovement(const uint32_t prevState, const uint32_t thisState, const int deltaX)
{
    if( thisState )
    {
        g_bHasMoveKeyHold = TRUE;
        if( prevState && CanMoveTetromino(g_tetromino[g_thisTetrominoID][g_thisTetrominoRotation], deltaX, 0) )
        {
            g_moveTimeMS = 0;
            g_posX += deltaX;
            return;
        }

        if( g_holdTimeMS >= HOLD_MOVE_KEY_THRESHOLD_MS &&
            g_moveTimeMS >= TIME_BETWEEN_MOVEMENT_MS &&
            CanMoveTetromino(g_tetromino[g_thisTetrominoID][g_thisTetrominoRotation], deltaX, 0))
        {
            g_moveTimeMS = 0;
            g_posX += deltaX;
            return;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static void UpdateInput()
{
    PollHardwareButtons();

    // Restart after game over
    if( GAME_MODE_DEAD == g_mode )
    {
        if( WasKeyPressed( KEY_START ) || WasKeyPressed( KEY_A ) || WasKeyPressed( KEY_B ))
            RestartGame();
        return;
    }

    // Pause
    if( WasKeyPressed( KEY_START ) )
    {
        if( g_bIsPaused )
            g_bIsPaused = FALSE;
        else
            g_bIsPaused = TRUE;
    }

    // Controlled falling
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
            g_scoresCount += SCORES_DOWN_CONTROLLED;
            return;
        }
    }

    // Uncontrolled falling
    if( WasKeyPressed( KEY_UP ) )
    {
        for( int i = 1; i < FIELD_SIZE_Y; ++i )
        {
            if( CanMoveTetromino(g_tetromino[g_thisTetrominoID][g_thisTetrominoRotation], 0, 1) )
            {
                ++g_posY;
            }
            else
            {
                FinishRound();
                g_scoresCount += SCORES_DOWN_UNCONTROLLED;
                return;
            }
        }
    }

    // Rotation
    int nextRotation = g_thisTetrominoRotation;
    if( WasKeyPressed( KEY_B ) )
        nextRotation += 3;

    if( WasKeyPressed( KEY_A ) )
        nextRotation += 1;

    if( nextRotation != g_thisTetrominoRotation )
    {
        nextRotation %= 4;
        int posX = g_posX;
        if( CanRotateTetromino(g_tetromino[g_thisTetrominoID][nextRotation], &posX, g_posY) )
        {
            g_posX = posX;
            g_thisTetrominoRotation = nextRotation;
        }
    }

    if( WasKeyReleased(KEY_RIGHT) || WasKeyReleased(KEY_LEFT) )
    {
        g_bHasMoveKeyHold = FALSE;
        g_holdTimeMS = 0;
    }
        
    // Side movement
    const uint32_t bWasPressedR = WasKeyPressed(KEY_RIGHT);
    const uint32_t bWasPressedL = WasKeyPressed(KEY_LEFT);
    const uint32_t bIsPressedR = IsKeyPressed(KEY_RIGHT);
    const uint32_t bIsPressedL = IsKeyPressed(KEY_LEFT);
    HandleSideMovement(bWasPressedR, bIsPressedR,  1);
    HandleSideMovement(bWasPressedL, bIsPressedL, -1);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static void UpdateTimer()
{
    if( g_bIsPaused )
        return;

    g_fallTimeMS += FIXED_TIME_STEP_MS;
    
    if( g_bHasMoveKeyHold )
    {
        g_holdTimeMS += FIXED_TIME_STEP_MS;
        g_moveTimeMS += FIXED_TIME_STEP_MS;
    }

    // Update block falling
    if( g_fallTimeMS >= g_fallDelayTimeMS )
    {    
        if( CanMoveTetromino(g_tetromino[g_thisTetrominoID][g_thisTetrominoRotation], 0, 1) )
            ++g_posY;
        else
            FinishRound();

        g_fallTimeMS = 0;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static void Render()
{
    ShowThisTetromino(g_tetromino[g_thisTetrominoID][g_thisTetrominoRotation], g_posX, g_posY);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void UpdateGameFixed()
{
    UpdateInput();
    UpdateTimer();
    if( GAME_MODE_LIVE == g_mode )
        Render();
}
////////////////////////////////////////////////////////////////////////////////////////////////////