#include <STC89C5XRC.H>
#include <intrins.h>

void Delay500ms()		//@11.0592MHz
{
	unsigned char data i, j, k;

	_nop_();
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void main()
{
	unsigned char i = 0xFE, j = 0; // j = 0±Ì æœÚ”“
	while(1)
	{
		if(i == 0xFE)
			j = 0;
		if(i == 0x7F)
			j = 1;
		
		P0 = i;
		
		if (!j)
		{
			i = (i << 1) + 1;
		}
		else
		{
			i = (i >> 1) + 0x80;
		}
		Delay500ms();
	}
}