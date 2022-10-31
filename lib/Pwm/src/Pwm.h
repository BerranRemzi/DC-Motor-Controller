#ifndef PWM_H
#define PWM_H
/*
 * Includes
 */
#include <stdint.h>    /* For standard type definitions */
//#include "Dio_cfg.h"   /* For dio configuration */
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
    void Pwm_Init(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* PWM_H */