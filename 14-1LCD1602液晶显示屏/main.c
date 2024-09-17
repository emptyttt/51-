#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"

void main()
{
	LCD_Init();
	LCD_ShowChar(1,1,'s');
	LCD_ShowString(2,1,"Hello");
	LCD_ShowNum(1,3,65,2);
	LCD_ShowSignedNum(1,6,-88,2);
	LCD_ShowHexNum(1,12,0xA5,2);
	LCD_ShowBinNum(2,8,0xA5,8);
	LCD_ShowChar(1,10,0xDF);
	LCD_ShowString(1,16,"Welcome to China");


	while(1)
	{
		LCD_WriteCommand(0x18);
		Delay(1000);
	}
}