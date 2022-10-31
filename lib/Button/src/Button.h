#ifndef BUTTON_H
#define BUTTON_H
/*
 * Includes
 */
#include <stdint.h>    /* For standard type definitions */
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
    void Button_Init(void);
    void Button_Task(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* BUTTON_H */