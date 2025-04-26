#include "STC89C5XRC.H"
#include "Dri_Timer0.h"
#include "Int_Key.h"
#include "Com_Util.h"

void do_func()
{
    P46 = ~P46;
    Delay10us(24);
}

void re_func()
{
    P46 = ~P46;
    Delay10us(21);
}

void mi_func()
{
    P46 = ~P46;
    Delay10us(19);
}

void fa_func()
{
    P46 = ~P46;
    Delay10us(17);
}

void main()
{
    Dri_Timer0_Init();
    Int_Key_Init();
    while (1) {
        if (Int_Key_GetSw3Status() == 1) {
            while (1) {
                do_func();
                if (Int_Key_GetSw3Status() == 2) {
                    break;
                }
            }
        }
        if (Int_Key_GetSw4Status() == 1) {
            while (1) {
                re_func();
                if (Int_Key_GetSw4Status() == 2) {
                    break;
                }
            }
        }
        if (Int_Key_GetSw5Status() == 1) {
            while (1) {
                mi_func();
                if (Int_Key_GetSw5Status() == 2) {
                    break;
                }
            }
        }
        if (Int_Key_GetSw6Status() == 1) {
            while (1) {
                fa_func();
                if (Int_Key_GetSw6Status() == 2) {
                    break;
                }
            }
        }
    }
}