/*
 * spiCom.h
 *
 *  Created on: 24. 2. 2022
 *      Author: Martin Hricov
 */

#ifndef SPICOM_H_
#define SPICOM_H_

#define SPI_GPIOS 1 //!< macro for GPIO selection,

#define LSPCLK 50000000
#define SPI_BAUD 50000

#include <F2837xD_device.h>

/**
 * CLK GPIO58 SPI – hodinový signál
 * STE GPIO59 SPI – chip select
 * MOSI GPIO60 SPI – MOSI
 * MISO GPIO61 SPI – MISO
 *
 */

void spi_init(void);

/**
 * \brief Transmit 1 character
 *
 */
void spi_send_byte(char cData);

void spi_send_string(char *p_cData, unsigned int length);
#endif /* SPICOM_H_ */
