#include "Com_Util.h"
#include <INTRINS.H>

void Delay1ms()		//@11.0592MHz
{
	unsigned char data i, j;

	_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}
