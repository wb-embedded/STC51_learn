#include "Int_Digtal.h"
#include "Dri_Timer0.h"

// �������ʾ����
static unsigned char s_digtal_codes[10] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};

static unsigned char s_buff[8];
static unsigned char s_num;

static void Int_Digtal_DisplaySingle(unsigned char n, unsigned char num)
{
    P0 = 0;
    // Ƭѡ
    // ��P13��P14��P15����
    P1 &= 0xC7;
    // ����P13��P14��P15��ֵ
    P1 |= (n << 3);

    // ��ѡ
    P0 = num;
}

void Int_Digtal_SetCache(unsigned long num)
{
    unsigned char i;
    for (i = 0; i < 8; i++) {
        s_buff[i] = 0x00;
    }
    if (num == 0) {
        s_buff[7] = s_digtal_codes[0];
        return;
    }
    i = 7;
    while (num != 0) {
        s_buff[i] = s_digtal_codes[num % 10];
        num /= 10;
        i--;
    }
}

void Int_Digtal_FlushDigtal()
{
    unsigned char i;
    for (i = 0; i < 8; i++) {
        Int_Digtal_DisplaySingle(i, s_buff[i]);
    }
}

void Int_Digtal_Callback()
{
    Int_Digtal_DisplaySingle(s_num, s_buff[s_num]);
    s_num++;
    if (s_num >= 8)
        s_num = 0;
}

void Int_Digtal_Init()
{
    SMG_EN = 0; // SMG_EN �͵�ƽ��Ч
    LED_EN = 0; // LED_EN �ߵ�ƽ��Ч
    s_num  = 0;
    Dri_Timer0_RegisterCallbackFunc(Int_Digtal_Callback);
}