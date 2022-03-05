/*
 * spiCom.c
 *
 *  Created on: 24. 2. 2022
 *      Author: martinhricov
 */

#include <F2837xD_device.h>
#include "spiCom.h"


void spi_init(void){
  EALLOW;

  CpuSysRegs.PCLKCR8.bit.SPI_B = 0b01; // Zapnutie Clokov pre SPI

//#if SPI_GPIOS == 1

    GpioCtrlRegs.GPBGMUX2.bit.GPIO58 = 0b01;
    GpioCtrlRegs.GPBMUX2.bit.GPIO58 = 0b10; // CLK

    GpioCtrlRegs.GPBGMUX2.bit.GPIO59 = 0b01; // STE
    GpioCtrlRegs.GPBMUX2.bit.GPIO59 = 0b10;

    GpioCtrlRegs.GPBGMUX2.bit.GPIO60 = 0b01;
    GpioCtrlRegs.GPBMUX2.bit.GPIO60 = 0b10; // SPI - MOSI

    GpioCtrlRegs.GPBGMUX2.bit.GPIO61 = 0b01;
    GpioCtrlRegs.GPBMUX2.bit.GPIO61 = 0b10; // SPI - MISO
    GpioCtrlRegs.GPBQSEL2.bit.GPIO61 = 0b11;


    SpibRegs.SPICCR.bit.SPISWRESET = 0b00; // CLEAR the SPI Software Reset Bit

    SpibRegs.SPICTL.bit.MASTER_SLAVE = 0b10; //Select Eithe MASTER OR SLAVE mode
    SpibRegs.SPICCR.bit.CLKPOLARITY = 0b01;
    SpibRegs.SPICTL.bit.CLK_PHASE = 0b00;
    SpibRegs.SPIBRR.bit.SPI_BIT_RATE = (LSPCLK/SPI_BAUD)-1; // SETUP
    //SpibRegs.SPICCR.bit.HS_MODE = 0b00;
    SpibRegs.SPICCR.bit.SPICHAR = 0x7;
    //SpibRegs.SPISTS.bit.INT_FLAG = ;
    //SpibRegs.SPISTS.bit.OVERRUN_FLAG ;
    SpibRegs.SPICCR.bit.SPISWRESET = 0b01;

//#endif
    EDIS;

}

void spi_send_byte(char cData){
    while(SpibRegs.SPISTS.bit.BUFFULL_FLAG == 0x01);
    if(SpibRegs.SPISTS.bit.BUFFULL_FLAG == 0x0)
    {
        cData &= 0xff;
        cData = cData<< 0x8;
        SpibRegs.SPITXBUF = cData;
    }

}

void spi_send_string(char *p_cData, unsigned int length){
    int i = 0;
    for(i = 0; i<length; i++){
        spi_send_byte(p_cData[i]);
    }
}



