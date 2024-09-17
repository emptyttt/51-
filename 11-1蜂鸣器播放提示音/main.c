#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"
#include "Buzzer.h"

sbit Buzzer=P2^5;

unsigned char KeyNum;

void main()
{
	Nixie(1,0);
	while(1)
	{
		KeyNum=Key();
		if(KeyNum)
		{
			Buzzer_Time(1000);
			Nixie(1,KeyNum);
		}
	}
}