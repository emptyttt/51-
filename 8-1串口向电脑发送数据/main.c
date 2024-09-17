#include <REGX52.H>
#include "Delay.h"
#include "UART.h"

unsigned char Sec;

void main()
{
	Sec = 0; 
	Uart1_Init();
//	UART_SendByte(0x11);
	while(1)
	{
		UART_SendByte(Sec);
		Sec++;
		Delay(1000);
	}
}