#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "Timer0.h"

unsigned char Sec,Min,Hour;

void main()
{
	LCD_Init();
	Timer0_Init();
	
	LCD_ShowString(1,1,"Clock:");
	LCD_ShowString(2,1,"  :  :");

	while(1)
	{
		LCD_ShowNum(2,1,Hour,2);
		LCD_ShowNum(2,4,Min,2);
		LCD_ShowNum(2,7,Sec,2);


	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0count;//静态局部变量，否则每次进入函数就会清零
	TL0 = 0x66;				//设置定时初始值//102
	TH0 = 0xFC;				//设置定时初始值//252
	T0count++;
	if(T0count>=1000)
	{
		T0count=0;
		Sec++;
		if(Sec>=60)
		{
			Sec=0;
			Min++;
			if(Min>=60)
			{
				Min=0;
				Hour++;
				if(Hour>=24)
				{
					Hour=0;
				}
			}
		}
	}
}