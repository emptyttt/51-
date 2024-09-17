#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum=0;
unsigned int Password=0,Count=0;//0~65535

void main()
{
	LCD_Init();
	LCD_ShowString(1,2,"Password");
	while(1)
	{
		KeyNum=MatrixKey();
		if(KeyNum)
		{
			if(KeyNum<=10)//如果S1~S10按键按下，输入密码
			{
				if(Count<4)
				{
					Password*=10;//密码左移一位
					Password+=KeyNum%10;//获取一位密码
					Count++;//计次加一
				}
				LCD_ShowNum(2,1,Password,4);
			}
			if(KeyNum==11)//确认键
			{
				if(Password==2345)
				{
					LCD_ShowString(1,14,"OK ");
					Password=0;
					Count=0;
					LCD_ShowNum(2,1,Password,4);
				}
				else
				{
					LCD_ShowString(1,14,"ERR");
					Password=0;
					Count=0;
					LCD_ShowNum(2,1,Password,4);
				}
			}
			if(KeyNum==12)//取消键
			{
				Password=0;
				Count=0;
				LCD_ShowNum(2,1,Password,4);
			}
			
		}
	}
}
//0001
//0010
//0012
//0127
//1278