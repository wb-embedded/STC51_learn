#include "Dri_Timer0.h"

#define MAX_CALLBACK_SIZE 4

static CallbackFunction s_func[MAX_CALLBACK_SIZE];

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
    for(i = 0; i < MAX_CALLBACK_SIZE; i++)
    {
        s_func[i] = NULL;
    }
}

void Dri_Timer0_RegisterCallbackFunc(CallbackFunction func)
{
    unsigned char i;
    //判断之前是否注册过
    for(i = 0; i < MAX_CALLBACK_SIZE; i++)
    {
        if(s_func[i] == func)
        {
            return;
        }
    }
    for(i = 0; i < MAX_CALLBACK_SIZE; i++)
    {
        if(s_func[i] == NULL)
        {
            s_func[i] = func;
            return;
        }
    }
}

void Dri_Timer0_DeRegisterCallbackFunc(CallbackFunction func)
{
    unsigned char i;
    //判断之前是否注册过
    for(i = 0; i < MAX_CALLBACK_SIZE; i++)
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
    for(i = 0; i < MAX_CALLBACK_SIZE; i++)
    {
        if(s_func[i] != NULL)
        {
            s_func[i]();
        }
    }
}