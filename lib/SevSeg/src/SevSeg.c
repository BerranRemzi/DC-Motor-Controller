/** @file SevSeg.c
 *  @brief The implementation for the SevSeg.
 */

/**
 * Includes
 */
#include "SevSeg.h"
#include "Spi.h"

uint8_t SevSeg_digits[SEVSEG_DIGITS_COUNT];
static uint8_t SevSeg_brightness = 0xFFu;

const uint8_t SevSeg_font[19][2] = {
    {0x3f, '0'}, // [0] => "0"
    {0x06, '1'}, // [1] => "1"
    {0x5b, '2'}, // [2] => "2"
    {0x4f, '3'}, // [3] => "3"
    {0x66, '4'}, // [4] => "4"
    {0x6d, '5'}, // [5] => "5"
    {0x7d, '6'}, // [6] => "6"
    {0x07, '7'}, // [7] => "7"
    {0x7f, '8'}, // [8] => "8"
    {0x6f, '9'}, // [9] => "9"
    {0x77, 'A'}, // [10] => "A"
    {0x7C, 'b'}, // [11] => "b"
    {0x39, 'C'}, // [12] => "C"
    {0x5E, 'd'}, // [13] => "d"
    {0x79, 'E'}, // [14] => "E"
    {0x71, 'F'}, // [15] => "F"
    {0x80, '.'}, // [16] => "dash"
    {0x00, ' '}, // [17] => "blank"
    {0x50, 'u'}, // [18]  'u'
};

void SevSeg_Init(void)
{
}

void SevSeg_SetNumber(uint16_t inputNumber, int8_t decPointDigit)
{
    for (uint8_t i = 0; i < SEVSEG_DIGITS_COUNT; i++)
    {
        SevSeg_digits[i] = SevSeg_font[inputNumber % 10][0];

        if (inputNumber > 0)
        {
            inputNumber /= 10;
        }
        else if (decPointDigit >= i)
        {
            SevSeg_digits[i] = SevSeg_font[0][0];
        }
        else
        {
            SevSeg_digits[i] = SEVSEG_BLANK;
        }

        if (decPointDigit >= 0)
        {
            SevSeg_digits[decPointDigit] |= SEVSEG_DOT;
        }
    }
}

void SevSeg_SetChar(char inputChar, int8_t digit)
{
}

void SevSeg_SetBrightness(uint8_t brightness)
{
}

void SevSeg_RefreshDisplay(void)
{
    uint8_t temp[SEVSEG_DIGITS_COUNT];

    for (uint8_t i = 0; i < SEVSEG_DIGITS_COUNT; i++)
    {
        if (SEVSEG_MAX_BRIGHTNESS == SevSeg_brightness)
        {
            temp[i] = (uint8_t)(~SevSeg_digits[i]);
        }
        else
        {
            temp[i] = (uint8_t)(~SEVSEG_BLANK);
        }
    }
    Spi_Transmit(temp, SEVSEG_DIGITS_COUNT);
}