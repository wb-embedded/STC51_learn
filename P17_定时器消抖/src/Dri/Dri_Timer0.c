#include "Dri_Timer0.h"

static CallbackFunc s_func[MAX_CALLBACK_SIZE];

// ��ʼ����ʱ��0
void Dri_Timer0_Init()
{
    unsigned char i;
    EA  = 1;
    ET0 = 1;
    TMOD &= 0xF0;
    TMOD |= 0x01;
    TR0 = 1;
    TL0 = 64614;
    TH0 = 64614 >> 8;
    for (i = 0; i < MAX_CALLBACK_SIZE; i++) {
        s_func[i] = NULL;
    }
}

// ���ûص�������ע�ắ��
void Dri_Timer0_RegisterCallbackFunc(CallbackFunc func)
{
    unsigned char i;
    for (i = 0; i < MAX_CALLBACK_SIZE; i++) {
        if (s_func[i] == func)
            return;
    }
    for (i = 0; i < MAX_CALLBACK_SIZE; i++) {
        if (s_func[i] == NULL) {
            s_func[i] = func;
            return;
        }
    }
}

// ���ûص�������ȡ��ע�ắ��
void Dri_Timer0_DeRegisterCallbackFunc(CallbackFunc func)
{
    unsigned char i;
    for (i = 0; i < MAX_CALLBACK_SIZE; i++) {
        if (s_func[i] == func) {
            s_func[i] = NULL;
            return;
        }
    }
}

// ���ö�ʱ��0�Ĵ�������
static void Dri_Timer0_func() interrupt 1
{
    unsigned char i;
    TL0 = 64614;
    TH0 = 64614 >> 8;

    for (i = 0; i < MAX_CALLBACK_SIZE; i++) {
        if (s_func[i] != NULL)
            s_func[i]();
    }
}