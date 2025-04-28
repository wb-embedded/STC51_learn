#include "STC89C5XRC.H"
#include "Dri_Uart.h"

void main()
{
    unsigned char res;
    Dri_Uart_Init();
    while (1) {
        if (RI) {
            res = SBUF;
            RI  = 0;
            while (!TI) {};
            TI = 0;
            SBUF = res + 1;
        }
    }
}
