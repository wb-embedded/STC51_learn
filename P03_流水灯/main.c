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
	unsigned char i = 0xFE;
	while(1)
	{
		if(i == 0xFF)
		{
			i = 0xFE;
		}
		P0 = i;
		i = (i << 1) + 1;
		Delay500ms();
	}
}