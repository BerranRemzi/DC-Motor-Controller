#ifndef WATCHDOG_H
#define WATCHDOG_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    /*
     * All of your legacy C code here
     */
    void Watchdog_Init(void);
    void Watchdog_Task(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* WATCHDOG_H */