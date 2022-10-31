#ifndef SPI_H
#define SPI_H
/*
 * Includes
 */
#include <stdint.h>    /* For standard type definitions */

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    /*
     * All of your legacy C code here
     */
    void Spi_Transmit(uint8_t *pData, uint16_t size);
    
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SPI_H */