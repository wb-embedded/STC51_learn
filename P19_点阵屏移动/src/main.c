#include "STC89C5XRC.H"
#include "Int_MatrixLed.h"

unsigned char pics[26] = {0xF8, 0x0A, 0xEC, 0xAF, 0xEC, 0x8A, 0xF8, 0x00,
                          0x10, 0xF9, 0x97, 0xF1, 0x88, 0xAA, 0xFF, 0xAA,
                          0x88, 0x00, 0x14, 0x0A, 0xF5, 0x92, 0x92, 0xF5,
                          0x0A, 0x14};

void main()
{
    unsigned int i = 0, j;
    MATRIX_LED_EN   = 0;
    LED_EN          = 0;
    while (1) {
        j = 0;
        if (i < 26) {
            Int_MatrixLed_Move(pics[i]);
        } else if (i >= 26 && i < 30) {
            Int_MatrixLed_Move(0x00);
        } else {
            i = 0;
        }
        while (j < 1000) {
            Int_MatrixLed_Flush();
            j++;
        }
        i++;
    }
}
