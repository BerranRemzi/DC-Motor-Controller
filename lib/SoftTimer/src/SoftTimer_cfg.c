#include "SoftTimer_cfg.h"
#include "SoftTimer.h"
#include <SevSeg.h>
#include <Menu.h>
#include <Button.h>
#include <TimerCounter.h>
#include <Watchdog.h>

SoftTimer_Task_t SoftTimer_task[TASK_COUNT] = {
    {&SevSeg_RefreshDisplay, 10u},
    {&Menu_Task, 10u},
    {&Button_Task, 10u},
    {&TimerCounter_Task, 10u},
    {&Watchdog_Task, 50u},
    {&SoftTimer_HeartBeat, 500u},
};