#include "Dri_Uart.h"

void Dri_Uart_Init()
{
    // ����SM0,SM1,SM2,ѡ�÷�ʽ1,SM0 = 0,SM1 = 1,SM2 = 0
    SM0 = 0;
    SM1 = 1;
    SM2 = 0;

    // ���ý���ʹ�ܶ�
    REN = 1;

    // �����ж�����λRI��TI
    RI = 0;
    TI = 1;

    // ���ݲ���������SMOD
    PCON &= 0x7F;

    // ���ö�ʱ��
    TMOD &= 0x0F;
    TMOD |= 0x20;
    TH1 = TL1 = 0xFD;
    TR1       = 1;
}