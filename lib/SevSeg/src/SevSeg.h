#ifndef SEV_SEG_H
#define SEV_SEG_H
/*
 * Includes
 */
#include <stdint.h> /* For standard type definitions */

#define SEVSEG_A SevSeg_font[10][0]
#define SEVSEG_F SevSeg_font[15][0]
#define SEVSEG_U SevSeg_font[18][0]
#define SEVSEG_D SevSeg_font[19][0]
#define SEVSEG_BLANK SevSeg_font[17][0]
#define SEVSEG_DOT SevSeg_font[16][0]

#define SEVSEG_DIGITS_COUNT 3
#define SEVSEG_MAX_BRIGHTNESS 0xFFu
#define SEVSEG_NO_DEC_POINT -1

extern uint8_t SevSeg_digits[SEVSEG_DIGITS_COUNT];
extern const uint8_t SevSeg_font[19][2];

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    /*
     * All of your legacy C code here
     */
    void SevSeg_Init(void);
    void SevSeg_SetNumber(uint16_t inputNumber, int8_t decPointDigit);
    void SevSeg_SetChar(char inputChar, int8_t digit);
    void SevSeg_SetBrightness(uint8_t brightness);
    void SevSeg_RefreshDisplay(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SEV_SEG_H */