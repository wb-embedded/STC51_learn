#include "STC89C5XRC.H"
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
    // 流水灯 左到右
    // unsigned char i = 0xFE;
    // while(1)
	// {
	// 	if(i == 0xFF)
	// 		i = 0xFE;
	// 	P0 = i;
	// 	i = (i << 1) + 1;
	// 	Delay500ms();
	// }

	//流水灯 右到左
	// unsigned char i = 0x7F;
	// while(1)
	// {
	// 	if(i == 0xFF)
	// 		i = 0x7F;
	// 	P0 = i;
	// 	i = (i >> 1) + 0x80;
	// 	Delay500ms();
	// }

	// 正反流水灯
	unsigned char i = 0xFE, j = 0;
	while(1)
	{
		if(i == 0xFE)
			j = 0;
		if(i == 0x7F)
			j = 1;
		P0 = i;
		if(j == 0)
		{
			i = (i << 1) + 1;
		}
		else if(j == 1)
		{
			i = (i >> 1) + 0x80;
		}
		Delay500ms();
	}
}