/** @file Menu.c
 *  @brief The implementation for the Menu.
 */

/**
 * Includes
 */
#include "Menu.h"
#include "SevSeg.h"

void Menu_Init(void)
{
}
static uint16_t counter = 0u;

void Menu_Task(void)
{
    SevSeg_SetNumber(counter, SEVSEG_NO_DEC_POINT);

    if (counter < 999u)
    {
        counter++;
    }
    else
    {
        counter = 0u;
    }
}