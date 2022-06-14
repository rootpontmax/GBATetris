#include "Input.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
static const uint16_t KEY_MASK = 0xFC00;
static uint16_t     g_thisKeyState = 0;
static uint16_t     g_prevKeyState = 0;
////////////////////////////////////////////////////////////////////////////////////////////////////
void PollHardwareButtons()
{
    g_prevKeyState = g_thisKeyState;
    g_thisKeyState = REG_KEYINPUT | KEY_MASK;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
uint32_t WasKeyPressed(uint16_t keyCode)
{
    return (~g_thisKeyState & g_prevKeyState) & keyCode;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
uint32_t WasKeyReleased(uint16_t keyCode)
{
    return (g_thisKeyState & ~g_prevKeyState) & keyCode;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
uint32_t IsKeyPressed(uint16_t keyCode)
{
    return !( keyCode & g_thisKeyState );
}
////////////////////////////////////////////////////////////////////////////////////////////////////