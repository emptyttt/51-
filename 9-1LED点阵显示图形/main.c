#include <REGX52.H>
#include "Delay.h"

sbit RCK=P3^5;
sbit SCK=P3^6;
sbit SER=P3^4;

#define MATRIX_LED_PORT P0

/**
  * @brief 74HC595写入一个字节
  * @param 要写入的字节
  * @retval 无
  */
void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SER=Byte&(0x80>>i);
		SCK=1;//将数据移进去
		SCK=0;//为下一次移进去做准备
	}
	RCK=1;
	RCK=0;
//	SER=Byte&0x80;
//	SCK=1;//将数据移进去
//	SCK=0;//为下一次移进去做准备
//	SER=Byte&0x40;
//	SCK=1;//将数据移进去
//	SCK=0;//为下一次移进去做准备
//	SER=Byte&0x20;
//	SCK=1;//将数据移进去
//	SCK=0;//为下一次移进去做准备
}

/**
  * @brief LED点阵屏显示一列数据
  * @param Column 列，范围：0~7，0在最左边
  * @param Data 选择列要显示的数据，高位在上，1亮，0灭
  * @retval 无
  */
void MatrixLED_ShowColumn(unsigned char Column,Data)
{
	_74HC595_WriteByte(Data);
	MATRIX_LED_PORT=~(0x80>>Column);//位选
	Delay(1);
	MATRIX_LED_PORT=0xFF;
}
void main()
{
	SCK=0;
	RCK=0;
	while(1)
	{
		MatrixLED_ShowColumn(0,0x30);
		MatrixLED_ShowColumn(1,0x48);
		MatrixLED_ShowColumn(2,0x44);
		MatrixLED_ShowColumn(3,0x22);
		MatrixLED_ShowColumn(4,0x22);
		MatrixLED_ShowColumn(5,0x44);
		MatrixLED_ShowColumn(6,0x48);
		MatrixLED_ShowColumn(7,0x30);
	}
}