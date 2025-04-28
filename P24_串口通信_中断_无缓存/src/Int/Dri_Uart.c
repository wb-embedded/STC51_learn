#include "Dri_Uart.h"

static char s_res;
// û��������Ϊ0����������Ϊ1�����ڷ���Ϊ0���������Ϊ1
static bit s_rdata_flag = 0, s_tdata_flag = 0;

void Dri_Uart_Init()
{
    // �ж��ܿ���
    EA = 1;
    // �����жϿ���
    ES = 1;

    // ���ڹ���ģʽ
    SM0 = 0;
    SM1 = 1;
    SM2 = 0;
    REN = 1;
    TI  = 1;
    RI  = 0;

    // ���ô��ڹ���Ƶ�� SMOD
    PCON &= 0x7F;

    // ���ö�ʱ��1����ģʽ
    TMOD &= 0x0F;
    TMOD |= 0x20;
    TH1 = TL1 = 0xFD;
    TR1       = 1;
}

static void Dri_Uart_Func() interrupt 4
{
    if (RI) {
        s_res        = SBUF;
        s_rdata_flag = 1;
        RI           = 0;
    } else {
        s_tdata_flag = 1;
        TI           = 0;
    }
}

unsigned char Dri_Uart_Rdata()
{
    if (s_rdata_flag) {
        s_rdata_flag = 0;
        return s_res;
    }
    return 0;
}

void Dri_Uart_Tdata(unsigned char tdata)
{
    while (!s_tdata_flag);
    s_tdata_flag = 0;
    SBUF         = tdata;
}