#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include <INTRINS.H>
//void Timer0_Init()
//{
////	TMOD=0x01;//0000 0001
//	TMOD&=0xF0;//把TMOD低四位清零，高四位保持不变
//	TMOD|=0x01;//按位或，任何数或上0等于任何数前，前7位不变，最后一位为1
//	TF0=0;
//	TR0=1;
//	TH0=64613/256;
//	TL0=64613%256;//101
//	ET0=1;
//	EA=1;
//	PT0=0;
//}

unsigned char KeyNum,LEDMode;

void main()
{
	P2=0xFE;
	Timer0_Init();
	
	while(1)
	{
		KeyNum=Key();
		if(KeyNum)
		{
			if(KeyNum==1) 
			{
				LEDMode++;
				if(LEDMode>=2)
					LEDMode=0;//让LED在0、1之间变化
			}
			
			
		}
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0count;//静态局部变量，否则每次进入函数就会清零
	TL0 = 0x66;				//设置定时初始值//102
	TH0 = 0xFC;				//设置定时初始值//252
	T0count++;
	if(T0count>=500)
	{
		T0count=0;
		if(LEDMode==0)
			P2=_crol_(P2,1);
		if(LEDMode==1)
			P2=_cror_(P2,1);
	}
}