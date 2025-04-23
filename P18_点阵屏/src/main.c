#include "STC89C5XRC.H"
#include "Int_MatrixLed.h"

unsigned char g_pics[8] = {
    0x01,
    0x02,
    0x04,
    0x08,
    0x10,
    0x20,
    0x40,
    0x80,
};

void main()
{
    LED_MATRIX_EN = 0;
    LED_EN        = 0;
    Int_MatrixLed_SetCache(g_pics);
    while (1) {
        Int_MatrixLed_Flush();
    }
}
