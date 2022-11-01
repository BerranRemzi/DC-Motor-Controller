/** @file Menu.c
 *  @brief The implementation for the Menu.
 */

/**
 * Includes
 */
#include "Menu.h"
#include "SevSeg.h"
#include "Button.h"

static uint16_t counter = 0u;

void Menu_ChangeDutyCycle(uint16_t value, int8_t dir);

void Menu_Init(void)
{
}


void Menu_Task(void)
{
    if (counter >= 1000u)
    {
        SevSeg_SetNumber(counter / 10u, SEVSEG_NO_DEC_POINT);
    }
    else
    {
        SevSeg_SetNumber(counter, 1);
    }
}

void Menu_Callback_SinglePress(void)
{
    switch (Button_GetLastPressed())
    {
    case BUTTON_UP:
        Menu_ChangeDutyCycle(1u, 1);
        break;
    case BUTTON_DOWN:
        Menu_ChangeDutyCycle(1u, -1);
        break;
    case BUTTON_ENTER:
        break;
    case BUTTON_START_STOP:
        break;
    default:
        break;
    }
}

void Menu_Callback_LongPress(void)
{
    switch (Button_GetLastPressed())
    {
    case BUTTON_UP:
        Menu_ChangeDutyCycle(10u, 1);
        break;
    case BUTTON_DOWN:
        Menu_ChangeDutyCycle(10u, -1);
        break;
    case BUTTON_ENTER:
        break;
    case BUTTON_START_STOP:
        break;
    default:
        break;
    }
}

void Menu_Callback_ContinuousPress(void)
{
    switch (Button_GetLastPressed())
    {
    case BUTTON_UP:
        Menu_ChangeDutyCycle(100u, 1);
        break;
    case BUTTON_DOWN:
        Menu_ChangeDutyCycle(100u, -1);
        break;
    case BUTTON_ENTER:
        break;
    case BUTTON_START_STOP:
        break;
    default:
        break;
    }
}

void Menu_ChangeDutyCycle(uint16_t value, int8_t dir)
{
    switch (dir)
    {
    case 1:
        counter += value;
        if (counter > 1000u)
        {
            counter = 1000u;
        }
        break;
    case -1:
        if (counter >= value)
        {
            counter -= value;
        }
        else
        {
            counter = 0u;
        }
        break;
    default:
        break;
    }
}