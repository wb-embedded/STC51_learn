#include "Com_Util.h"

void Delay10ms()		//@11.0592MHz
{
	unsigned char data i, j;

	i = 18;
	j = 235;
	do
	{
		while (--j);
	} while (--i);
}
