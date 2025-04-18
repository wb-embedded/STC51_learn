#include <STC89C5XRC.H>
#define SMG_EN P36
#define LED_EN P34

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

unsigned char buff[8];
void DisplaySingle(unsigned char n, unsigned char num)
{
  P0 = 0;
  //Ƭѡ
  //��P13��P14��P15����
  P1 &= 0xC7;
  //����P13��P14��P15��ֵ
  P1 |= (n << 3);
  
  //��ѡ
  P0 = num;
}

void ShowDigtalNum(unsigned long num)
{
  unsigned char i = 7, j;
  if(num == 0)
  {
    DisplaySingle(i, digtal_codes[num]);
    return;
  }
  while(num != 0)
  {
    j = num % 10;
    DisplaySingle(i, digtal_codes[j]);
    i--;
    num /= 10;
  }
}

void SetCache(unsigned long num)
{
  unsigned char i;
  for(i = 0; i < 8; i++)
  {
    buff[i] = 0x00;
  }
  if(num == 0)
  {
    buff[7] = digtal_codes[0];
    return;
  }
  i = 7;
  while(num != 0)
  {
    buff[i] = digtal_codes[num % 10];
    num /= 10;
    i--;
  }
}

void FlushDigtal()
{
  unsigned char i;
  for(i = 0; i < 8; i++)
  {
    DisplaySingle(i, buff[i]);
  }
}

void main()
{
    // unsigned char i = 3;
    SMG_EN = 0; //SMG_EN �͵�ƽ��Ч
    LED_EN = 0; //LED_EN �ߵ�ƽ��Ч
    SetCache(12345);
    while(1)
    {
      FlushDigtal();
    }
}
