/** @file Dio.c
 *  @brief The implementation for the Dio.
 */

/**
 * Includes
 */
#include "Dio.h"
#include <Arduino.h>

void Dio_Init(void)
{
    Dio_ChannelDirectionSet(DIO_D0, INPUT_PULLUP);
    Dio_ChannelDirectionSet(DIO_D1, INPUT_PULLUP);
    Dio_ChannelDirectionSet(DIO_BUTTON_UP, INPUT_PULLUP);
    Dio_ChannelDirectionSet(DIO_BUTTON_DOWN, INPUT_PULLUP);
    Dio_ChannelDirectionSet(DIO_BUTTON_RIGHT, INPUT_PULLUP);
    Dio_ChannelDirectionSet(DIO_BUTTON_LEFT, INPUT_PULLUP);
    Dio_ChannelDirectionSet(DIO_SOFTSPI_CLK, OUTPUT);
    Dio_ChannelDirectionSet(DIO_SOFTSPI_MOSI, OUTPUT);
    Dio_ChannelDirectionSet(DIO_SOFTSPI_CS, OUTPUT);
    Dio_ChannelDirectionSet(DIO_BUTTON_STOP, INPUT_PULLUP);
    Dio_ChannelDirectionSet(DIO_10, INPUT_PULLUP);
    Dio_ChannelDirectionSet(DIO_11, INPUT_PULLUP);
    Dio_ChannelDirectionSet(DIO_12, INPUT_PULLUP);
    Dio_ChannelDirectionSet(DIO_LED, OUTPUT);
}

DioPinState_t Dio_ChannelRead(DioChannel_t Channel)
{
    return (DioChannel_t)digitalRead((uint8_t)Channel);
}

void Dio_ChannelWrite(DioChannel_t Channel, DioPinState_t State)
{
    digitalWrite((uint8_t)Channel, (uint8_t)State);
}

void Dio_ChannelToggle(DioChannel_t Channel)
{
    digitalWrite((uint8_t)Channel, !digitalRead((uint8_t)Channel));
}

void Dio_ChannelDirectionSet(DioChannel_t Channel, PinModeEnum_t Mode)
{
    pinMode((uint8_t)Channel, (uint8_t)Mode);
}