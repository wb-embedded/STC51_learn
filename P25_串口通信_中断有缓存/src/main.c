#include "STC89C5XRC.H"
#include "Dri_Uart.h"

void main()
{
    unsigned char res;
    Dri_Uart_Init();
    while (1) {
        res = Dri_Uart_Rdata();
        if (res) {
            Dri_Uart_Tdata('a');
        }
    }
}
