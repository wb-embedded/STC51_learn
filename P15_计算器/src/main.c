#include "STC89C5XRC.H"
#include "Int_Digtal.h"
#include "Int_MatrixKey.h"

unsigned long g_num1 = 0, g_num2 = 0, g_result = 0;
unsigned char g_op = 0;

//��������0~9
void IntputNum(unsigned char num)
{
  //��δ���������ʱ���Ե�һλ�����в���
  if(g_op == 0)
  {
    g_num1 *= 10;
    g_num1 += num;
    //���ǵ�ֻ����һ���������
    g_result = g_num1;
    Int_Digtal_SetCache(g_num1);
  }
  //���Ѿ������˲�������Ӧ�öԵڶ��������в���
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
  SMG_EN = 0; //SMG_EN �͵�ƽ��Ч
  LED_EN = 0; //LED_EN �ߵ�ƽ��Ч
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
