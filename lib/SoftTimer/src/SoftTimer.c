/** @file SoftTimer.c
 *  @brief The implementation for the SoftTimer.
 */

/**
 * Includes
 */
#include "SoftTimer.h" /* For this modules definitions */
#include "SoftTimer_cfg.h"
#include "Dio.h"

#ifdef ARDUINO
#include <Arduino.h> /* For Hardware definitions     */
#else
extern uint32_t millis(void);
#endif

/**
 * @brief
 *
 */
void SoftTimer_Init(void)
{
}

/**
 * @brief
 *
 */
void SoftTimer_Task(void)
{
    uint32_t currentTime = millis();

    for (uint8_t i = 0u; i < TASK_COUNT; i++)
    {
        uint32_t timePassed = (uint32_t)(currentTime - SoftTimer_task[i].previousTime);
        if (timePassed >= SoftTimer_task[i].period)
        {
            SoftTimer_task[i].previousTime = currentTime;
            SoftTimer_task[i].CallbackFunction();
        }
    }
}

void SoftTimer_HeartBeat(void)
{
    Dio_ChannelToggle(DIO_LED);
}