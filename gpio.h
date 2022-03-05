/**
 * \file gpio.h
 * \brieg Header file Gpio
 *\author Martin Hricov
 *\ date 17.2.2022
 *
 *\defgroup group_gpio GPIO module
 * Module Containg initialization fuction for preripherities of MCU
 *\{

 */

#ifndef GPIO_H_
#define GPIO_H_

#include<F2837xD_device.h>

#define GPIO_LD1_ON GpioDataRegs.GPBCLEAR.bit.GPIO62 = 1;
#define GPIO_LD1_OFF GpioDataRegs.GPBSET.bit.GPIO62 = 1;
#define GPIO_LD1_TOGGLE GpioDataRegs.GPBTOGGLE.bit.GPIO62 = 1;

#define GPIO_LD2_ON GpioDataRegs.GPBCLEAR.bit.GPIO63 = 1;
#define GPIO_LD2_OFF GpioDataRegs.GPBSET.bit.GPIO63 = 1;
#define GPIO_LD2_TOGGLE GpioDataRegs.GPBTOGGLE.bit.GPIO63 = 1;


void gpio_init(void);
/** \} */ // end of group_mcu

#endif /* GPIO_H_ */
