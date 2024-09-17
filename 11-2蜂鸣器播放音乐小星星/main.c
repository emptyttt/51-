#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"

sbit Buzzer=P2^5;

#define SPEED  500 

unsigned char KeyNum;

unsigned int FreqTable[]={0,
	63777,63872,63967,64053,64139,64214,64290,64359,64424,64488,64546,64606,
	64654,64703,64750,64794,64836,64875,64912,64947,64980,65012,65041,65069,
	65094,65119,65142,65165,65186,65205,65223,65241,65258,65273,65288,65302
};
unsigned char Music[]={
13,4,
13,4,
20,4,
20,4,
22,4,
22,4,
20,8,
18,4,
18,4,
17,4,
17,4,
15,4,
15,4,
13,8,
0xFF
};
unsigned char FreqSelect,MusicSelect;

void main()
{
	Timer0_Init();
	while(1)
	{
		if(Music[MusicSelect]!=0xFF)
		{
			FreqSelect=Music[MusicSelect];
			MusicSelect++;
			Delay(SPEED/4*Music[MusicSelect]);
			MusicSelect++;
			TR0=0;
			Delay(5);
			TR0=1;
		}
		else
		{
			TR0=0;
			while(1);
		}
	}
}

void Timer0_Routine() interrupt 1
{
	TL0 = FreqTable[FreqSelect]%256;				//设置定时初始值
	TH0 = FreqTable[FreqSelect]/256;				//设置定时初始值
	Buzzer=!Buzzer;//1ms翻转一次，周期2ms，产生了500hz的频率
}