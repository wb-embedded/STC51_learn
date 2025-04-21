#include "Dri_Timer0.h"

static unsigned int s_ms_count = 0;

void Dri_Time0_Init()
{
    //���ж�����λ
    EA = 1;
    //��ʱ��0�жϿ���
    ET0 = 1;
    //����TMOD
    TMOD &= 0xF0;
    TMOD |= 0x01;
    //����TR0
    TR0 = 1;
    //���������������ֵ,����Ƶ�ʺ�ʱ���������Ӱ��
    TL0 = 64614 % 256;
    TH0 = 64614 / 256;
}

static void Dri_Time0_Func() interrupt 1
{
    TL0 = 64614 % 256;
    TH0 = 64614 / 256;

    s_ms_count++;

    if(s_ms_count == 1000)
    {
        P00 = ~P00;
        s_ms_count = 0;
    }
}