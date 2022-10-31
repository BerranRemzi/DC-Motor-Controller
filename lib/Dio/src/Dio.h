#ifndef DIO_H
#define DIO_H
/*
 * Includes
 */
#include <stdint.h>    /* For standard type definitions */
#include "Dio_cfg.h"   /* For dio configuration */
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
    void Dio_Init(void);
    DioPinState_t Dio_ChannelRead(DioChannel_t Channel);
    void Dio_ChannelWrite(DioChannel_t Channel, DioPinState_t State);
    void Dio_ChannelToggle(DioChannel_t Channel);
    void Dio_ChannelDirectionSet(DioChannel_t Channel, PinModeEnum_t Mode);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* DIO_H */