#include "STC89C5XRC.H"
#include "Dri_Timer0.h"

void LED()
{
    static unsigned int s_num = 0;
    if(s_num == 1000)
    {
        P00 = ~P00;
        s_num = 0;
    }
    s_num++;
}

void main()
{
    Dri_Timer0_Init();
    Dri_Timer0_RegisterCallbackFunc(LED);
    while (1) {
    }
}
