/** @file Spi.c
 *  @brief The implementation for the Spi.
 */

/**
 * Includes
 */
#include "Spi.h"
#include "Dio.h"
#include <Arduino.h>

static inline void Spi_Delay(void)
{
    delayMicroseconds(100);
}

static inline void Spi_ToggleClock(void)
{
    Dio_ChannelWrite(DIO_SOFTSPI_CLK, DIO_HIGH);
    Spi_Delay();
    Dio_ChannelWrite(DIO_SOFTSPI_CLK, DIO_LOW);
    Spi_Delay();
}

static inline void Spi_ToggleOutput(void)
{
    Dio_ChannelWrite(DIO_SOFTSPI_CS, DIO_HIGH);
    Spi_Delay();
    Dio_ChannelWrite(DIO_SOFTSPI_CS, DIO_LOW);
    Spi_Delay();
}

void Spi_Transmit(uint8_t *pData, uint16_t size)
{
    for (uint8_t n = 0u; n < size; n++)
    {
        for (uint8_t i = 0u; i < 8u; i++)
        {
#ifdef SPI_MSB_FIRST
            Dio_ChannelWrite(SOFTSPI_MOSI, (pData[n] >> i) & 0x01u ? DIO_HIGH : DIO_LOW);
#else
            Dio_ChannelWrite(DIO_SOFTSPI_MOSI, (pData[n] << i) & 0x80u ? DIO_HIGH : DIO_LOW);
#endif
            Spi_ToggleClock();
        }
    }
    Spi_ToggleOutput();
}