#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"
#include "Timer0.h"

//sbit LED=P2^0;
sbit Motor=P1^0;

unsigned char Counter,Compare;
unsigned KeyNum,Speed;

void main()
{
	Timer0_Init();
	while(1)
	{
		KeyNum=Key();
		if(KeyNum==1)
		{
			Speed++;
			Speed%=4;
			if(Speed==0){Compare=0;}
			if(Speed==1){Compare=5;}
			if(Speed==2){Compare=40;}
			if(Speed==3){Compare=100;}

		}
		Nixie(1,Speed);
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
		Motor=0;//LED=0;
	}
	else
	{
		Motor=1;//LED=1;
	}
}