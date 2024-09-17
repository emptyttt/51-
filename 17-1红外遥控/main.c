#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"

unsigned char Num;

void main()
{
	LCD_Init();
	
	IT0=1;
	IE0=0;
	EX0=1;
	EA=1;
	PX0=1;
	while(1)
	{
		
	}
}