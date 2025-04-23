#include "STC89C5XRC.H"
#include "Dri_Timer0.h"
#include "Int_MatrixLED.h"
#include "Com_Util.h"

unsigned char pics[32] = {0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00,
                          0x00, 0x00, 0x3C, 0x24, 0x24, 0x3C, 0x00, 0x00,
                          0x00, 0x7E, 0x42, 0x42, 0x42, 0x42, 0x7E, 0x00,
                          0xFF, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xFF};

void main()
{
    unsigned char i = 0;
    Dri_Timer0_Init();
    Int_MatrixLED_Init();
    while (1) {
        Int_MatrixLED_SetPics(pics + i);
        i += 8;
        Delay1ms(100);
        if (i == 32) {
            i = 0;
        }
    }
}
