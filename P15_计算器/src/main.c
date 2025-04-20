#include "STC89C5XRC.H"
#include "Int_Digtal.h"
#include "Int_MatrixKey.h"

unsigned long g_num1 = 0, g_num2 = 0, g_result = 0;
unsigned char g_op = 0;

//输入数字0~9
void IntputNum(unsigned char num)
{
  //当未输入操作符时，对第一位数进行操作
  if(g_op == 0)
  {
    g_num1 *= 10;
    g_num1 += num;
    //考虑到只输入一个数字情况
    g_result = g_num1;
    Int_Digtal_SetCache(g_num1);
  }
  //当已经输入了操作符后，应该对第二个数进行操作
  else
  {
    g_num2 *= 10;
    g_num2 += num;
    Int_Digtal_SetCache(g_num2);
  }
}

void InputEq()
{
  if(g_op == 10)
  {
    g_result += g_num2;
  }
  else if(g_op == 20)
  {
    g_result -= g_num2;
  }
  else if(g_op == 30)
  {
    g_result *= g_num2;
  }
  else if(g_op == 40)
  {
    g_result /= g_num2;
  }
  Int_Digtal_SetCache(g_result);
  g_op = 0;
}

void IntputOp(unsigned char op)
{
  InputEq();
  g_op = op;
  g_num2 = 0;
  g_num1 = 0;
}

void InputC()
{
  g_num1 = 0;
  g_num2 = 0;
  g_result = 0;
  g_op = 0;
  Int_Digtal_SetCache(0);
}

void main()
{
  unsigned char idx;
  SMG_EN = 0; //SMG_EN 低电平有效
  LED_EN = 0; //LED_EN 高电平有效
  while(1)
  {
    idx = Int_MatrixKey_GetPressedKey();
    if(idx != 255)
    {
      if(idx >=0 && idx <=9)
      {
        IntputNum(idx);
      }
      else if(idx >= 10 && idx <= 40)
      {
        IntputOp(idx);
      }
      else if(idx == 50)
      {
        InputC();
      }
      else if(idx == 60)
      {
        InputEq();
      }
    }
    Int_Digtal_FlushDigtal();
  }
}
