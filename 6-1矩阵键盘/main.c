#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNumber=0;

void main()
{
	LCD_Init();
	LCD_ShowString(1,2,"MatrixKey");
	while(1)
	{
		KeyNumber=MatrixKey();
		if(KeyNumber)
		{
			LCD_ShowNum(2,1,KeyNumber,2);
		}
	}
}