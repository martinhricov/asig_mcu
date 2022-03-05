/*
 * dispCtrl.h
 *
 *  Created on: 3. 3. 2022
 *      Author: martinhricov
 */

#ifndef DISPCTRL_H_
#define DISPCTRL_H_

extern void F28x_usDelay(long LoopCount);
#define CPU_RATE 5.0L //!< Sets CPU rate for DELAY_US macro.
#define DELAY_US(A)  F28x_usDelay(((((long double) A * 1000.0L) / (long double)CPU_RATE) - 9.0L) / 5.0L) //!< Sets CPU rate for DELAY_US macro.

void dispCtrl_SendData(unsigned int u16RW, unsigned int u16RS, char cData);

void displCtrl_Init(void);

void dispCtrl_sendChar(char cZnak);

void dispCtrl_sendString(char *pcText);

unsigned dispCtrl_setCursor(unsigned int u16row, unsigned int u16column);

#endif /* DISPCTRL_H_ */
