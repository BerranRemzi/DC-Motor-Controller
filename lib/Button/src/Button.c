/** @file Button.c
 *  @brief The implementation for the Button.
 */

/**
 * Includes
 */
#include "Button.h"
#include "Menu.h"
#include "Dio.h"

typedef struct
{
    const void (*CallbackFunction)(void);
    uint16_t minCount;
    uint16_t maxCount;
    uint16_t repeatPeriod;
} Button_Callback_t;

typedef struct
{
    Button_t button;
    DioChannel_t dioChannel;
} Button_Dio_t;

#define BUTTON_DIO_COUNT 4
Button_Dio_t Button_Dio_cfg[BUTTON_DIO_COUNT] = {
    {BUTTON_UP, DIO_BUTTON_UP},
    {BUTTON_DOWN, DIO_BUTTON_DOWN},
    {BUTTON_ENTER, DIO_BUTTON_RIGHT},
    {BUTTON_START_STOP, DIO_BUTTON_LEFT},
};

#define BUTTON_DEBOUNCE_MS(A) (A / 10u)
#define BUTTON_CALLBACK_COUNT 4
Button_Callback_t Button_Callback_cfg[BUTTON_CALLBACK_COUNT] = {
    {&Menu_Callback_SinglePress, 1u, 2u, 0u},
    {&Menu_Callback_SinglePress, 30u, 50u, 0u},
    {&Menu_Callback_LongPress, 50u, 200u, 50u},
    {&Menu_Callback_ContinuousPress, 200u, 0xFFFFu, 50u},
};

static Button_t Button_lastPressed = BUTTON_MAX_NUMBER;
static uint16_t Button_pressCounter = 0u;

void Button_Init(void)
{
}

void Button_Task(void)
{
    Button_t current = BUTTON_MAX_NUMBER;

    for (uint8_t i = 0u; i < BUTTON_DIO_COUNT; i++)
    {
        if (DIO_LOW == Dio_ChannelRead(Button_Dio_cfg[i].dioChannel))
        {
            current = Button_Dio_cfg[i].button;
        }
    }
    if ((Button_lastPressed == current) && (BUTTON_MAX_NUMBER != current))
    {
        Button_pressCounter++;
        for (uint8_t i = 0u; i < BUTTON_CALLBACK_COUNT; i++)
        {
            if ((Button_Callback_cfg[i].minCount <= Button_pressCounter) && (Button_Callback_cfg[i].maxCount > Button_pressCounter))
            {
                if ((((Button_pressCounter - Button_Callback_cfg[i].minCount) % Button_Callback_cfg[i].repeatPeriod) == 0u) || (Button_Callback_cfg[i].repeatPeriod == 0))
                {
                    Button_Callback_cfg[i].CallbackFunction();
                }
            }
        }
    }
    else
    {
        Button_pressCounter = 0u;
    }

    Button_lastPressed = current;
}

Button_t Button_GetLastPressed(void)
{
    return Button_lastPressed;
}