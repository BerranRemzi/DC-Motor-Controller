#ifndef BUTTON_H
#define BUTTON_H
/*
 * Includes
 */
#include <stdint.h>  /* For standard type definitions */
#include <stdbool.h> /* For standard type definitions */
// #include "constants.h" /* For HIGH, LOW, etc */

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
/**
 * Button_State_t defines the possible states that a button may be in.
 * Additional button states can be added to this enumeration.  Button_State_t
 * also defines a maximum value that can be used for boundary checking.
 */
typedef enum
{
    BUTTON_STATE_PRESSED,     /**< The pressed electrical state */
    BUTTON_STATE_NOT_PRESSED, /**< The not pressed electrical state */
    BUTTON_STATE_MAX          /**< Maximum number of button states */
} Button_State_t;

/**
 * Button_t defines the buttons that exist within the embedded system.
 * Additional buttons can be added by adding to this enumeration.
 * It also defines a maximum value that can be used for boundary checking.
 */
typedef enum
{
    BUTTON_UP,   /**< The menu button */
    BUTTON_DOWN, /**< The enter button */
    BUTTON_ENTER,
    BUTTON_START_STOP,
    BUTTON_MAX_NUMBER /**< Number of buttons in the system */
} Button_t;

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
    Button_t Button_GetLastPressed(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* BUTTON_H */