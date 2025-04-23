#include "Dri_Timer0.h"

static Callback s_func[MAX_CALLBACKFUNC_SIZE];

void Dri_Timer0_Init()
{
    unsigned char i;
    EA = 1;
    ET0 = 1;
    TMOD &= 0xF0;
    TMOD |= 0x01;
    TR0 = 1;
    TL0 = 64614;
    TH0 = 64614 >> 8;
    for(i = 0; i < MAX_CALLBACKFUNC_SIZE; i++)
    {
        s_func[i] = NULL;
    }
}

void Dri_Timer0_RegisterCallbackFunc(Callback func)
{
    unsigned char i;
    //检查函数是否已经注册
    for(i = 0; i < MAX_CALLBACKFUNC_SIZE; i++)
    {
        if(s_func[i] == func)
        {
            return;
        }
    }
    //注册函数
    for(i = 0; i < MAX_CALLBACKFUNC_SIZE; i++)
    {
        if(s_func[i] == NULL)
        {
            s_func[i] = func;
            return;
        }
    }
}

void Dri_Timer0_DeRegisterCallbackFunc(Callback func)
{
    unsigned char i;
    for(i = 0; i < MAX_CALLBACKFUNC_SIZE; i++)
    {
        if(s_func[i] == func)
        {
            s_func[i] = NULL;
            return;
        }
    }
}

static void Dri_Timer0_Func() interrupt 1
{
    unsigned char i;
    TL0 = 64614;
    TH0 = 64614 >> 8;
    for(i = 0; i < MAX_CALLBACKFUNC_SIZE; i++)
    {
        if(s_func[i] != NULL)
        {
            s_func[i]();
        }
    }
}