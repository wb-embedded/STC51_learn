#include "Dri_Interrupt.h"

void Dri_Interrupt_Init()
{
    //���ж��������λ
    EA = 1;

    //�ⲿ�ж�0�������λ
    EX0 = 1;

    //�ⲿ�ж�0�ж�Դ����ѡ��λ
    IT0 = 1;
}

static void Dri_Interrupt_Func() interrupt 0
{
    P00 = ~P00;
}