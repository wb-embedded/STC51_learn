# STM-51学习

1.keil编写程序和编译（后期用vscode编写，keil编译）

2.使用ISP烧录，要检查串口以及晶振频率

3.keil中没有STC89C5XRC.H文件，需要进入isp中导入

## Chapter 1 点亮LED

##### 硬件原理图

![image-20250414220832607](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20250414220832607.png)

​	可知当P00为低电平时，二极管导电，LED被点亮

##### 在keil5中创建项目并创建.c文件

```c
sfr P0 = 0x80; // sfr代表寄存器，0x80表示地址

sbit P00 = P0 ^ 0 // 或者直接导入STC89C5XRC.H

void main()

{

​	P00=0; // 根据电路设置P0.0引脚为低电平，点亮LED

​	while(1)

​	{} //创建死循环确保LED常亮

}
```



**注**：只有GPIO这类能位寻址的引脚才能直接对位进行操作，引脚名为***PXX***的都为GPIO





## **Chapter 2 LED闪烁**

***时钟周期 = 1 / 晶振频率 ≈ 0.09μs***

***机器周期 = 12 时钟周期***

***指令周期 = 1 条指令完成所需要的时钟周期（一般12/24/48）***

```c
#include <STC89C5XRC.H>
#include <intrins.h> # 包含_nop_()函数的头文件

# 可以在SPI中的软件延时计算器直接生成
void Delay500ms()		//@11.0592MHz延时500ms
{
	unsigned char data i, j, k;

​	_nop_();
​	i = 4;
​	j = 129;
​	k = 119;
​	do
​	{
​		do
​		{
​			while (--k);
​		} while (--j);
​	} while (--i);

}

void main()
{
	while(1)
	{
		P00 = 0; // 也可以直接对P00进行取反操作，可以使代码变得更加简洁
		Delay500ms();
		P00 = 1;
		Delay500ms(); // 需要两次延时，否则熄灭时间太短，无法观测到
	}
}
```





## Chapter 3 LED流水灯

##### 硬件原理图

![image-20250414214944294](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20250414214944294.png)

**注**：由原理图可知，要只使最低位LED亮，应该使P0=0xFE(1111 1110)，第二位亮则为0xFD(1111 1101)，即先左移一位再加1。然而当一轮过去，会发生数据溢出，P0会变成0xFF(1111 1111)，所以需要重置P0。

```c
#include <STC89C5XRC.H>
#include <intrins.h>

void Delay500ms()		//@11.0592MHz
{
	unsigned char data i, j, k;

​	_nop_();
​	i = 4;
​	j = 129;
​	k = 119;
​	do
​	{
​		do
​		{
​			while (--k);
​		} while (--j);
​	} while (--i);

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
```





## Chapter 4 正反流水灯

```c
#include <STC89C5XRC.H>
#include <intrins.h>

void Delay500ms()		//@11.0592MHz
{
	unsigned char data i, j, k;

​	_nop_();
​	i = 4;
​	j = 129;
​	k = 119;
​	do
​	{
​		do
​		{
​			while (--k);
​		} while (--j);
​	} while (--i);

}

void main()
{
	// 创建一个标志变量，用来表示当前灯光流向，当j=0时表示向右流，j=1时表示向左流
	unsigned char i = 0xFE, j = 0; // j = 0表示向右
	while(1)
	{
		if(i == 0xFE) //当i=0xFE时，表示最左边灯亮，应该向右流，j=0
			j = 0;
		if(i == 0x7F) //当i=0x7F时，表示最右边灯亮，应该向左流，j=1
			j = 1;
		

​		P0 = i;
​	
​		if (!j)
​		{
​			i = (i << 1) + 1;
​		}
​		else
​		{
​			i = (i >> 1) + 0x80;
​		}
​		Delay500ms();
​	}

}
```





## Chapter 5 切换vscode

安装完vscode之后，需要安装对应的插件，如下

![image-20250415195015928](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20250415195015928.png)

再将解压后的文件放置在 ***C:\Users\Administrator*** 下，同时安装运行环境

![image-20250415195219730](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20250415195219730.png)

安装完成后，打开vscode

![image-20250415195329284](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20250415195329284.png)

新建配置文件，复制来源选择***默认***，然后安装vscode插件，如下

![image-20250415195457547](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20250415195457547.png)

新建项目，选择8位MCU项目，再选择对应芯片

在  **src ** 文件夹下新建  ***App，Com，Dri，Int，Min***  文件夹

从keil中将STC89C5XRC.H复制到项目下

点击编译，将文件路径改成实际安装路径

烧录时注意看通信端口，如果端口与isp中扫描到的端口不一致，需要修改，将-p后的端口改成实际通信端口

![image-20250415200122553](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20250415200122553.png)

![image-20250415200142772](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20250415200142772.png)

然后点击烧录按钮，此时应该结果如下

![image-20250415200626807](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20250415200626807.png)

项目建立完成后，可以将其导出为模板

![image-20250415200604750](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20250415200604750.png)

会在项目下生成ept文件，移到上级目录



往后新建项目时，直接选择本地项目模板

![image-20250415200921276](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20250415200921276.png)





## Chapter 6 静态数码管显示

#### PCB原理图

由线路图以及芯片功能表可知CS1，CS2，CS3为 **HHL**

DIR为H，An为输入，Bn为输出

![image-20250415210311650](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20250415210311650.png)

![image-20250415210436526](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20250415210436526.png)

![image-20250415210631711](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20250415210631711.png)

![image-20250415213221450](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20250415213221450.png)

因为所使用数码管为共阴极数码管，所以当Dig为低电平，另一端至少有一个高电平时有显示![image-20250415213528306](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20250415213528306.png)![image-20250415220106181](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20250415220106181.png)

***注：***需要设置***P34***和***P36***的值，其中***P34***是LED使能端，高电平有效，***P36***是数码管使能端，低电平有效

##### 程序如下

```c
#include "STC89C5XRC.H"
#include <INTRINS.H>

#define SMG_EN P36
#define LED_EN P34

void Delay500ms()    //@11.0592MHz
{
  unsigned char data i, j, k;
  _nop_();
  i = 4;
  j = 129;
  k = 119;
  do
  {
​    do
​    {
​      while (--k);
​    } while (--j);
  } while (--i);
}

//数码管显示数组
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
  //片选
  //将P13，P14，P15清零
  P1 &= 0xC7;
  //设置P13，P14，P15的值
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
  
  //段选
  P0 = digtal_codes[num];
}

void main()
{
  SMG_EN = 0; //SMG_EN 低电平有效
  LED_EN = 0; //LED_EN 高电平有效
  
  DisplaySingle(0,0);//第0个数码管显示0

  while(1)
  {}
}
```





## Chapter 7 动态数码管显示

```c
#include "STC89C5XRC.H"
#include <INTRINS.H>

#define SMG_EN P36
#define LED_EN P34

void Delay500ms()    //@11.0592MHz
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

//数码管显示数组
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
  //片选
  //将P13，P14，P15清零
  P1 &= 0xC7;
  //设置P13，P14，P15的值
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

  //段选
  P0 = digtal_codes[num];
}

void main()
{
  unsigned char i = 3;
  SMG_EN = 0; //SMG_EN 低电平有效
  LED_EN = 0; //LED_EN 高电平有效
  while(1)
  {
   //关闭数码管，防止上一次的影响
   //显示12345
   P0 = 0x00;
   if(i > 7)
​    i = 3;
   DisplaySingle(i, i - 2);
   i++;
  }
}
```

#### 随意显示数字

```c
#include "STC89C5XRC.H"
#define SMG_EN P36
#define LED_EN P34
//数码管显示数组
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
 //片选
 //将P13，P14，P15清零
 P1 &= 0xC7;
 //设置P13，P14，P15的值
 P1 |= (n << 3);
 /*
 0  ABCDEF  	0011 1111  0x3F
 1  BC			0000 0110  0x06
 2  ABDEG   	0101 1011  0x5B
 3  ABCDG   	0100 1111  0x4F
 4  BCFG   		0110 0110  0x66
 5  ABDEG   	0110 1101  0x6D
 6  ACDEFG  	0111 1101  0x7D
 7  ABC    		0000 0111  0x07
 8  ABCDEFG  	0111 1111  0x7F
 9  ABCDFG  	0110 1111  0x6F
 */

 //段选
 P0 = digtal_codes[num];
}

void ShowDigtalNum(unsigned long num)
{
 unsigned char i = 7, j;
 while(num != 0)
 {
  j = num % 10;
  DisplaySingle(i, j);
  i--;
  num /= 10;
 }
}

void main()
{
  SMG_EN = 0; //SMG_EN 低电平有效
  LED_EN = 0; //LED_EN 高电平有效
  while(1)
  {
   ShowDigtalNum(12345678);
  }
}
```

#### 进阶版

```c
#include "STC89C5XRC.H"
#define SMG_EN P36
#define LED_EN P34
//数码管显示数组
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
 //片选
 //将P13，P14，P15清零
 P1 &= 0xC7;
 //设置P13，P14，P15的值
 P1 |= (n << 3);
 
 //段选
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
  SMG_EN = 0; //SMG_EN 低电平有效
  LED_EN = 0; //LED_EN 高电平有效
  SetCache(100);
  while(1)
  {
   FlushDigtal();
  }
}
```



## Chapter 8 模块化设计

分模块编写代码

数码管显示代码

##### Int_Digtal.h

```
#ifndef __INT_DIGTAL_H__
#define __INT_DIGTAL_H__
#include "../STC89C5XRC.H"

#define SMG_EN P36
#define LED_EN P34

//将待显示的数字加载到缓存
void Int_Digtal_SetCache(unsigned long num);

//将缓存中的数字刷写到数码管
void Int_Digtal_FlushDigtal();

#endif
```

##### Int_Digtal.c

```
#include "Int_Digtal.h"
//数码管显示数组
static unsigned char s_digtal_codes[10] = {
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

static unsigned char s_buff[8];

static void Int_Digtal_DisplaySingle(unsigned char n, unsigned char num)
{
 P0 = 0;
 //片选
 //将P13，P14，P15清零
 P1 &= 0xC7;
 //设置P13，P14，P15的值
 P1 |= (n << 3);
 
 //段选
 P0 = num;
}

void Int_Digtal_SetCache(unsigned long num)
{
 unsigned char i;
 for(i = 0; i < 8; i++)
 {
  s_buff[i] = 0x00;
 }
 if(num == 0)
 {
  s_buff[7] = s_digtal_codes[0];
  return;
 }
 i = 7;
 while(num != 0)
 {
  s_buff[i] = s_digtal_codes[num % 10];
  num /= 10;
  i--;
 }
}

void Int_Digtal_FlushDigtal()
{
 unsigned char i;
 for(i = 0; i < 8; i++)
 {
  Int_Digtal_DisplaySingle(i, s_buff[i]);
 }
}
```

再在主函数中调用相关的文件和函数



## Chapter 9 动态数码管_100到0的倒计数

#### 编写延时函数

##### Com_Util.h

```
#ifndef __Com_Util_H__
#define __Com_Util_H__

void Delay1ms();

#endif
```

##### Com_Util.c

```
#include "Com_Util.h"
#include <INTRINS.H>

void Delay1ms()   //@11.0592MHz
{
  unsigned char data i, j;
  _nop_();
  i = 2;
  j = 199;
  do
  {
​    while (--j);
  } while (--i);
}
```

#### 编写主函数

```
#include "STC89C5XRC.H"
#include "./Int/Int_Digtal.h"
#include <INTRINS.H>
#include "./Com/Com_Util.h"

void main()
{
 int i = 100, j = 0;
 SMG_EN = 0; //SMG_EN 低电平有效
 LED_EN = 0; //LED_EN 高电平有效
 while(1)
 {
  if(j == 1000)
  {
   j = 0;
   if(i >= 0)
   {
​    Int_Digtal_SetCache(i);
​    i--;
   }
  }
  j++;
  Int_Digtal_FlushDigtal();
 }
}
```



## Chapter 10 独立按键

#### 硬件原理图

![image-20250417152840258](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20250417152840258.png)

由原理图可知，当按键未被按下时，引脚为高电平，被按下时为低电平。

按一次按键是先从高变成低，再从低变成高的过程。

由于硬件限制，所以要加入10ms的延时，排除硬件因素的误触发。

#### 编写按键函数

```
#ifndef __Int_Keyboard_H__
#define __Int_Keyboard_H__

#include "../STC89C5xRC.H"
#include "../Com/Com_Util.h"

bit Int_Keyboard_IsPressedBySw1();
bit Int_Keyboard_IsPressedBySw2();
bit Int_Keyboard_IsPressedBySw3();
bit Int_Keyboard_IsPressedBySw4();

#endif
```

```
#include "Int_Keyboard.h"

bit Int_Keyboard_IsPressedBySw1()
{
  if(P42)
  {
​    Delay10ms();//防止因为硬件原因的误触发
​    if(P42)
​    {
​      return 0;
​    }
  }
  while(1)//不确定什么时候松开按键，需要循环来一直扫描状态
  {
​    if(P42)
​    {
​      Delay10ms();
​      if(P42)
​      {
​        return 1;
​      }
​    }
  }
}

bit Int_Keyboard_IsPressedBySw2()
{
  if(P43)
  {
​    Delay10ms();
​    if(P43)
​    {
​      return 0;
​    }
  }
  while(1)
  {
​    if(P43)
​    {
​      Delay10ms();
​      if(P43)
​      {
​        return 1;
​      }
​    }
  }
}

bit Int_Keyboard_IsPressedBySw3()
{
  if(P32)
  {
​     Delay10ms();
​    if(P32)
​    {
​      return 0;
​    }
  }
  while(1)
  {
​    if(P32)
​    {
​      Delay10ms();
​      if(P32)
​      {
​        return 1;
​      }
​    }
  }
}

bit Int_Keyboard_IsPressedBySw4()
{
  if(P33)
  {
​    Delay10ms();
​    if(P33)
​    {
​      return 0;
​    }
  }
  while(1)
  {
​    if(P33)
​    {
​      Delay10ms();
​      if(P33)
​      {
​        return 1;
​      }
​    }
  }
}
```



## Chapter 11 按键计数

##### 需要同时用到按键，数码管以及延时

```c
#include "./Int/Int_Digtal.h"
#include "./Int/Int_Keyboard.h"

void main()
{
  unsigned long num = 0, i;
  SMG_EN = 0;
  LED_EN = 0;
  while(1)
  {
​    i = 0;
​    if(Int_Keyboard_IsPressedBySw1())
​    {
​      num += 1;
​    }
​    if(Int_Keyboard_IsPressedBySw2())
​    {
​      num += 10;
​    }
​    if(Int_Keyboard_IsPressedBySw3())
​    {
​      num += 100;
​    }
​    if(Int_Keyboard_IsPressedBySw4())
​    {
​      num += 1000;
​    }
​    Int_Digtal_SetCache(num);
​    while(i < 100)
​    {
​      Int_Digtal_FlushDigtal();
​      i++;
​    }
  }
}
```



## Chapter 12 独立按键左右移动

先将十进制数转换为二进制数，左移即为乘2，右移即为除二

##### 修改Int_Keyboard.c文件

```c
#include "Int_Keyboard.h"

bit Int_Keyboard_IsPressedBySw1()
{
  if(P42)
  {
​    return 0;
  }
  Delay10ms();
  if(P42)
  {
​    return 0;
  }
  while(1)
  {
​    if(P42)
​    {
​      Delay10ms();
​      if(P42)
​      {
​        return 1;
​      }
​    }
  }
}

bit Int_Keyboard_IsPressedBySw2()
{
  if(P43)
  {
​    return 0;
  }
  Delay10ms();
  if(P43)
  {
​    return 0;
  }
  while(1)
  {
​    if(P43)
​    {
​      Delay10ms();
​      if(P43)
​      {
​        return 1;
​      }
​    }
  }
}

bit Int_Keyboard_IsPressedBySw3()
{
  if(P32)
  {
​    return 0;
  }
  Delay10ms();
  if(P32)
  {
​    return 0;
  }
  while(1)
  {
​    if(P32)
​    {
​      Delay10ms();
​      if(P32)
​      {
​        return 1;
​      }
​    }
  }
}

bit Int_Keyboard_IsPressedBySw4()
{
  if(P33)
  {
​    return 0;
  }
  Delay10ms();
  if(P33)
  {
​    return 0;
  }
  while(1)
  {
​    if(P33)
​    {
​      Delay10ms();
​      if(P33)
​      {
​        return 1;
​      }
​    }
  }
}
```

main.c文件

```c
#include "./Int/Int_Digtal.h"
#include "./Int/Int_Keyboard.h"

void coverNumToBin(unsigned char num, unsigned char* p_data)
{
  unsigned char i;
  for(i = 0; i < 8; i++)
  {
​    p_data[i] = 0;
  }
  i = 7;
  while(num != 0)
  {
​    p_data[i] = num % 2;
​    num /= 2;
​    i--;
  }
}

void main()
{
  unsigned char num = 255;
  unsigned char str[8];
  SMG_EN = 0;
  LED_EN = 0;
  coverNumToBin(num, str);
  Int_Digtal_SetCacheByBin(str);
  while(1)
  {
​    if(Int_Keyboard_IsPressedBySw1())
​    {
​      num *= 2;
​      coverNumToBin(num, str);
​      Int_Digtal_SetCacheByBin(str);
​    }
​    if(Int_Keyboard_IsPressedBySw2())
​    {
​      num /= 2;
​      coverNumToBin(num, str);
​      Int_Digtal_SetCacheByBin(str);
​    }
​    if(Int_Keyboard_IsPressedBySw3())
​    {
​      num += 1;
​      coverNumToBin(num, str);
​      Int_Digtal_SetCacheByBin(str);
​    }
​    if(Int_Keyboard_IsPressedBySw4())
​    {
​      num = 0;
​      coverNumToBin(num, str);
​      Int_Digtal_SetCacheByBin(str);
​    }
​    Int_Digtal_FlushDigtal();
  }
}
```



## Chapter 13 矩阵按键

因为锁存器特性，引脚需先置为1才能读到外部正确的状态

##### 接线原理图

![image-20250419152245174](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20250419152245174.png)

当P20为低，其他为高时，按下(1,1)按钮，P24被拉低，可以通过P24状态判断按钮状态，其他同理

##### 代码

```c
#include "Int_MatrixKey.h"
unsigned char Int_MatrixKey_GetPressedKey()
{
  P2 = 0xFE; // 1111 1110 第一行
  if(P24 == 0)
  {
​    Delay10ms();
​    if(P24 == 0)
​    {
​      while(1)
​      {
​        if(P24 == 1)
​        {
​          Delay10ms();
​          if(P24 == 1)
​          {
​            return 7;
​          }
​        }
​      }
​    }
  }
  if(P25 == 0)
  {
​    Delay10ms();
​    if(P25 == 0)
​    {
​      while(1)
​      {
​        if(P25 == 1)
​        {
​          Delay10ms();
​          if(P25 == 1)
​          {
​            return 8;
​          }
​        }
​      }
​    }
  }
  if(P26 == 0)
  {
​    Delay10ms();
​    if(P26 == 0)
​    {
​      while(1)
​      {
​        if(P26 == 1)
​        {
​          Delay10ms();
​          if(P26 == 1)
​          {
​            return 9;
​          }
​        }
​      }
​    }
  }
  if(P27 == 0)
  {
​    Delay10ms();
​    if(P27 == 0)
​    {
​      while(1)
​      {
​        if(P27 == 1)
​        {
​          Delay10ms();
​          if(P27 == 1)
​          {
​            return 10;
​          }
​        }
​      }
​    }
  }
  P2 = 0xFD; // 1111 1101 第二行
  if(P24 == 0)
  {
​    Delay10ms();
​    if(P24 == 0)
​    {
​      while(1)
​      {
​        if(P24 == 1)
​        {
​          Delay10ms();
​          if(P24 == 1)
​          {
​            return 11;
​          }
​        }
​      }
​    }
  }
  if(P25 == 0)
  {
​    Delay10ms();
​    if(P25 == 0)
​    {
​      while(1)
​      {
​        if(P25 == 1)
​        {
​          Delay10ms();
​          if(P25 == 1)
​          {
​            return 12;
​          }
​        }
​      }
​    }
  }
  if(P26 == 0)
  {
​    Delay10ms();
​    if(P26 == 0)
​    {
​      while(1)
​      {
​        if(P26 == 1)
​        {
​          Delay10ms();
​          if(P26 == 1)
​          {
​            return 13;
​          }
​        }
​      }
​    }
  }
  if(P27 == 0)
  {
​    Delay10ms();
​    if(P27 == 0)
​    {
​      while(1)
​      {
​        if(P27 == 1)
​        {
​          Delay10ms();
​          if(P27 == 1)
​          {
​            return 14;
​          }
​        }
​      }
​    }
  }
  P2 = 0xFB; // 1111 1011 第三行
  if(P24 == 0)
  {
​    Delay10ms();
​    if(P24 == 0)
​    {
​      while(1)
​      {
​        if(P24 == 1)
​        {
​          Delay10ms();
​          if(P24 == 1)
​          {
​            return 15;
​          }
​        }
​      }
​    }
  }
  if(P25 == 0)
  {
​    Delay10ms();
​    if(P25 == 0)
​    {
​      while(1)
​      {
​        if(P25 == 1)
​        {
​          Delay10ms();
​          if(P25 == 1)
​          {
​            return 16;
​          }
​        }
​      }
​    }
  }
  if(P26 == 0)
  {
​    Delay10ms();
​    if(P26 == 0)
​    {
​      while(1)
​      {
​        if(P26 == 1)
​        {
​          Delay10ms();
​          if(P26 == 1)
​          {
​            return 17;
​          }
​        }
​      }
​    }
  }
  if(P27 == 0)
  {
​    Delay10ms();
​    if(P27 == 0)
​    {
​      while(1)
​      {
​        if(P27 == 1)
​        {
​          Delay10ms();
​          if(P27 == 1)
​          {
​            return 18;
​          }
​        }
​      }
​    }
  }
  P2 = 0xF7; // 1111 0111
  if(P24 == 0)
  {
​    Delay10ms();
​    if(P24 == 0)
​    {
​      while(1)
​      {
​        if(P24 == 1)
​        {
​          Delay10ms();
​          if(P24 == 1)
​          {
​            return 19;
​          }
​        }
​      }
​    }
  }
  if(P25 == 0)
  {
​    Delay10ms();
​    if(P25 == 0)
​    {
​      while(1)
​      {
​        if(P25 == 1)
​        {
​          Delay10ms();
​          if(P25 == 1)
​          {
​            return 20;
​          }
​        }
​      }
​    }
  }
  if(P26 == 0)
  {
​    Delay10ms();
​    if(P26 == 0)
​    {
​      while(1)
​      {
​        if(P26 == 1)
​        {
​          Delay10ms();
​          if(P26 == 1)
​          {
​            return 21;
​          }
​        }
​      }
​    }
  }
  if(P27 == 0)
  {
​    Delay10ms();
​    if(P27 == 0)
​    {
​      while(1)
​      {
​        if(P27 == 1)
​        {
​          Delay10ms();
​          if(P27 == 1)
​          {
​            return 22;
​          }
​        }
​      }
​    }
  }
  return 0;
}
```

## Chapter 14 外部中断

STC89C52有8个中断，可设置4个优先级，高优先级中断可以打断低优先级中断，当两个中断平级时，按照查询顺序决定哪一个中断先被响应

外部中断0(0)，1(2)，2(6)，3(7)

定时器中断0(1)，1(3)，2(5)

串口中断(4)

##### 注：括号内为对应序号

EA：所有终端总开关

EX0：外部中断0允许控制位

IT0：外部中断0中断源类型选择位

IE0/P3.2：外部中断请求源

```c
#include "Dri_Interrupt.h"
void Dri_Interrupt_Init()
{
  //总中断允许控制位
  EA = 1;

  //外部中断0允许控制位
  EX0 = 1;

  //外部中断0中断源类型选择位
  IT0 = 1;
}

static void Dri_Interrupt_Func() interrupt 0
{
  P00 = ~P00;
}
```



## Chapter 15 计算器

##### 代码如下

```c
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

```



## Chapter 16 定时器
