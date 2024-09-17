#include <REGX52.H>
/**
  * @brief 串口初始化，4800bps@11.0592MHz
  * @param	无
  * @retval 无
  */
void Uart1_Init(void)	//
{
	PCON &= 0x7F;		//波特率不倍速
	SCON = 0x50;		//8位数据,可变波特率
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xFA;			//设置定时初始值
	TH1 = 0xFA;			//设置定时重载值
	ET1 = 0;			//禁止定时器中断
	TR1 = 1;			//定时器1开始计时
}
/**
  * @brief 串口发送一个字节数据
  * @param Byte要发送的一个字节数据
  * @retval
  */
void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
}
//void UART_Init()
//{
//	SCON=0x40;
//	PCON=0;					//默认定时器为1
//	TMOD &= 0x0F;			//设置定时器模式
//	TMOD |= 0x20;			//设置定时器模式
//	TL1 = 0x66;				//设置定时初始值
//	TH1 = 0xFC;				//设置定时初始值
//	TF1 = 0;				//清除TF0标志
//	TR1 = 1;				//定时器0开始计时

//}