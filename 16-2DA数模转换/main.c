#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"
#include "Timer0.h"

//sbit LED=P2^0;
sbit DA=P1^0;

unsigned char Counter,Compare;
unsigned char i;

void main()
{
	Timer0_Init();
	while(1)
	{
		for(i=0;i<100;i++)
		{
			Compare=i;
			Delay(10);
		}
		for(i=100;i>0;i--)
		{
			Compare=i;
			Delay(10);
		}
	}
}


void Timer0_Routine() interrupt 1
{
	TL0 = 0xA4;				//设置定时初始值
	TH0 = 0xFF;				//设置定时初始值
	Counter++;
	Counter%=100;
	if(Counter<Compare)
	{
		DA=0;//LED=0;
	}
	else
	{
		DA=1;//LED=1;
	}
}