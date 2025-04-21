#include "STC89C5XRC.H"
#include "Dri_Timer0.h"
#include "Int_Key.h"

void main()
{
    Dri_Timer0_Init();
    Int_Key_Init();
    while (1) {
        if (Int_Key_GetSw1Status() == 1) {
            P00 = ~P00;
        }
        if (Int_Key_GetSw2Status() == 1) {
            P01 = ~P01;
        }
        if (Int_Key_GetSw3Status() == 1) {
            P02 = ~P02;
        }
        if (Int_Key_GetSw4Status() == 1) {
            P03 = ~P03;
        }
    }
}
