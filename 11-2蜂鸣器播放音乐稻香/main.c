#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"

sbit Buzzer=P2^5;

#define SPEED  500 
#define P   	0
#define L1 		1
#define L1_  	2
#define L2 		3
#define L2_  	4
#define L3  	5
#define L4  	6
#define L4_  	7
#define L5  	8
#define L5_  	9
#define L6  	10
#define L6_  	11
#define L7  	12
#define M1  	13
#define M1_  	14
#define M2  	15
#define M2_  	16
#define M3  	17
#define M4  	18
#define M4_  	19
#define M5  	20
#define M5_  	21
#define M6  	22
#define M6_  	23
#define M7  	24
#define H1  	25
#define H1_  	26
#define H2  	27
#define H2_  	28
#define H3  	29
#define H4  	30
#define H4_  	31
#define H5  	32
#define H5_  	33
#define H6  	34
#define H6_  	35
#define H7  	36


unsigned char KeyNum;

unsigned int FreqTable[]={0,
	63777,63872,63967,64053,64139,64214,64290,64359,64424,64488,64546,64606,
	64654,64703,64750,64794,64836,64875,64912,64947,64980,65012,65041,65069,
	65094,65119,65142,65165,65186,65205,65223,65241,65258,65273,65288,65302
};
unsigned char code Music[]=
{
	0,4,
	0,4,
	0,4,
	0,1,
	M1,1,
	M1,1,
	L6,1,
	
	M1,2,
	L6,1,
	M1,3,
	M1,1,
	M2,1,
	M2,1,
	M2,1,
	M2,1,
	M2,1,
	M2,1,
	M3,1,
	M1,2,
	
	M1,2,
	L6,1,
	M1,3,
	M1,1,
	M2,1,
	M2,1,
	M2,1,
	M2,1,
	M2,1,
	M2,1,
	M3,1,
	M1,2,
	
	M1,2,
	L6,1,
	M1,3,
	M1,1,
	M1,1,
	M2,1,
	M2,1,
	M2,1,
	M2,1,
	M1,2,
	M2,1,
	M3,1,
	
	

	0xFF
};
unsigned int FreqSelect,MusicSelect;

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