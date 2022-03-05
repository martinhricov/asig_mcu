
#include <dispCtrl.h>
#include "spiCom.h"

void dispCtrl_SendData(unsigned int u16RW, unsigned int u16RS, char data){

    char Msg[3];
    Msg[0] = 0xF8 | (u16RW << 2) | (u16RS << 1);

    Msg[1] = ((data & 0x01) << 7) | ((data & 0x02) << 5) | ((data & 0x04) << 3) | ((data & 0x08) << 1);

    Msg[2] = ((data & 0x10) << 3) | ((data & 0x20) << 1) | ((data & 0x40) >> 1) | ((data & 0x80) >> 3);
    spi_send_string(Msg, data);
    DELAY_US(5000);
}

void dispCtrl_Init(void){
    dispCtrl_SendData(0,0,0x3A);
    dispCtrl_SendData(0,0,0x09);
    dispCtrl_SendData(0,0,0x06);
    dispCtrl_SendData(0,0,0x1E);
    dispCtrl_SendData(0,0,0x39);
    dispCtrl_SendData(0,0,0x1B);
    dispCtrl_SendData(0,0,0x6C);
    dispCtrl_SendData(0,0,0x57);
    dispCtrl_SendData(0,0,0x74);
    dispCtrl_SendData(0,0,0x38);
    dispCtrl_SendData(0,0,0x0E);

}

void dispCtrl_sendChar(char cZnak){
    dispCtrl_SendData(0, 1, cZnak);
}

void dispCtrl_sendString(char *pcText){
    int i = 0;
    for(int = 0l (pcText[i] != '\0') || (i<16); i++){
        dispCtrl_sendChar(pcText[i]);
    }
}

unsigned dispCtrl_setCursor(unsigned int u16row, unsigned int u16column){
    unsigned int adress;

    //
    if((u16row>4) || (u16row==0))
        return 0;


    if((u16column>16) || (u16column==0))
        return 0;


    if(u16row==1){
        adress = 0x00+(u16colum-1);

    }

    if(u16row==2){
        adress=0x20+(u16colum-1);
    }

    if(u16row==3){
        adress = 0x40+(u16colum-1);
    }

    if(u16row==4){
        adress = 0x60+(u16colum-1);
    }


    dispCtrl_sendData(0,0, (0x80 | adresa)); // 8x80 kvoli 1 na 7 bite.
    return 1;
}
