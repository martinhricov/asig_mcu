/*
 * gpio.c
 *
 *  Created on: 20. 2. 2022
 *      Author: martinhricov
 */
#include <F2837xD_device.h>
#include "gpio.h"


void gpio_init(void){
    EALLOW; // Povolenie pre editaciu chranenych registrov

    GpioCtrlRegs.GPBMUX2.bit.GPIO62 = 0; // nastavenie registra GPBMUX2, GPBGMUX2 ako vystup
    GpioCtrlRegs.GPBGMUX2.bit.GPIO62 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO62 = 1; // nastavenie smeru pinu GPIO62 (1 - vystup, 0 - vstup)

    GpioCtrlRegs.GPBMUX2.bit.GPIO63 = 0; // nastavenie registra GPBMUX2 a GPBGMUX2 ako vystup
    GpioCtrlRegs.GPBGMUX2.bit.GPIO62 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO63 = 1;  // nastavenie smeru pinu GPIO62 (1 - vystup, 0 - vstup)

    EDIS;
}

