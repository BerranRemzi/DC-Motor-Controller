/** @file dio_cfg.h
 *  @brief This module contains interface definition for the Dio configuration.
 *
 *  This is the header file for the definition of the interface for retrieving
 *  the digital input/output configuration table.
 */
#ifndef DIO_CFG_H
#define DIO_CFG_H

/*
 * Includes
 */

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
 * Defines the possible states for a digital output pin.
 */
typedef enum
{
    DIO_LOW,          /** Defines digital state ground */
    DIO_HIGH,         /** Defines digital state power */
    DIO_PIN_STATE_MAX /** Defines the maximum digital state */
} DioPinState_t;

/**
 * Defines an enumerated list of all the channels (pins) on the MCU device.
 * The last element is used to specify the maximum number of enumerated labels.
 */
typedef enum
{
    SOFTSPI_MOSI,      /**< PORT1_0 */
    SOFTSPI_CLK,       /**< PORT1_1 */
    SOFTSPI_CS,        /**< PORT1_2 */
    BUTTON_UP,         /**< PORT1_3 */
    BUTTON_DOWN,       /**< PORT1_4 */
    BUTTON_RIGHT,      /**< PORT1_5 */
    BUTTON_LEFT,       /**< PORT1_6 */
    BUTTON_STOP,       /**< PORT1_7 */
    DIO_MAX_PIN_NUMBER /**< MAX CHANNELS */
} DioChannel_t;

/**
 * Defines the possible states of the channel pull-ups
 */
typedef enum
{
    DIO_PULLUP_DISABLED, /*< Used to disable the internal pull-ups */
    DIO_PULLUP_ENABLED,  /*< Used to enable the internal pull-ups */
    DIO_MAX_RESISTOR     /*< Resistor states should be below this value */
} DioResistor_t;

/**
 *
 */
typedef enum
{
    DIO_DIR_OUTPUT,
    DIO_DIR_INPUT,
    DIO_DIR_UNDEF
} DioDirection_t;

/**
 * Constants: I/O Pin Modes
 */
typedef enum
{
    OUTPUT, /**< Reserved word representing the mode of an I/O pin or an I/O port as an input */
    INPUT   /**< Reserved word representing the mode of an I/O pin or an I/O port as an output */
} PinModeEnum_t;

/**
 * Defines the digital input/output configuration table elements that are used
 * by Dio_Init to configure the Dio peripheral.
 */
typedef struct
{
    DioChannel_t Channel;     /**< The I/O pin								*/
    DioResistor_t Resistor;   /**< Pullup/Pulldown Resistor - ENABLED or DISABLED	*/
    DioDirection_t Direction; /**< Data Direction      - OUTPUT or INPUT			*/
    DioPinState_t Data;       /**< Data                - HIGH or LOW				*/
} DioConfig_t;

#endif /* DIO_CFG_H */