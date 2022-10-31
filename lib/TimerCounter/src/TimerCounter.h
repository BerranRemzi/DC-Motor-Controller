#ifndef TIMER_COUNTER_H
#define TIMER_COUNTER_H
/*
 * Includes
 */
#include <stdint.h>  /* For standard type definitions */
//#include "TimerCounter_cfg.h" /* For dio configuration */
//#include "constants.h" /* For HIGH, LOW, etc */

/*
 * Preprocessor Constants
 */

/*
 * Configuration Constants
 */

/*
 * Macros
 */

/*
 * Typedefs
 */

/*
 * Variables
 */

/*
 * Function Prototypes
 */
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    /*
     * All of your legacy C code here
     */
    void TimerCounter_Init(void);
    void TimerCounter_Task(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* TIMER_COUNTER_H */