#include <STC89C5XRC.H>
#include <INTRINS.H>

#define SMG_EN P36
#define LED_EN P34

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


//�������ʾ����
unsigned char digtal_codes[10] = {
  0x3F,//0
  0x06,//1
  0x5B,//2
  0x4F,//3
  0x66,//4
  0x6D,//5
  0x7D,//6
  0x07,//7
  0x7F,//8
  0x6F//9
};

void DisplaySingle(unsigned char n, unsigned char num)
{
  //Ƭѡ
  //��P13��P14��P15����
  P1 &= 0xC7;
  //����P13��P14��P15��ֵ
  P1 |= (n << 3);
  // P13 = 0;
  // P14 = 0;
  // P15 = 1;
  /*
  0  ABCDEF  	0011 1111  	0x3F
  1  BC			0000 0110	0x06
  2  ABDEG  	0101 1011	0x5B
  3  ABCDG  	0100 1111	0x4F
  4  BCFG   	0110 0110	0x66
  5  ABDEG  	0110 1101	0x6D
  6  ACDEFG		0111 1101 	0x7D
  7  ABC   		0000 0111	0x07
  8  ABCDEFG 	0111 1111  	0x7F
  9  ABCDFG  	0110 1111  	0x6F
  */
  
  //��ѡ
  P0 = digtal_codes[num];
}

void main()
{
  SMG_EN = 0; //SMG_EN �͵�ƽ��Ч
  LED_EN = 0; //LED_EN �ߵ�ƽ��Ч
  
  DisplaySingle(0,0);//��0���������ʾ0

  while(1)
  {}
}
