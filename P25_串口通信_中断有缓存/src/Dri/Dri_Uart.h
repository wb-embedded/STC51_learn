#ifndef __DRI_UART_H__
#define __DRI_UART_H__

#include "STC89C5xRC.H"

void Dri_Uart_Init();
unsigned char Dri_Uart_Rdata();
void Dri_Uart_Tdata(unsigned char tdada);

#endif