#ifndef SOFT_TIMER_H
#define SOFT_TIMER_H

/*
 * Includes
 */
#include <stdint.h> /* For standard type definitions */

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
typedef struct
{
    const void (*CallbackFunction)(void);
    uint32_t period;
    uint32_t previousTime;
} SoftTimer_Task_t;

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
    void SoftTimer_Init(void);
    void SoftTimer_Task(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SOFT_TIMER_H */