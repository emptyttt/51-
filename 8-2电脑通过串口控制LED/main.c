#include <REGX52.H>
#include "Delay.h"
#include "UART.h"



void main()
{
	Uart1_Init();
	while(1)
	{
		
	}
}

void UART_Routine(void) interrupt 4
{
	if(RI==1)
	{
		P2=~SBUF;
		UART_SendByte(SBUF);
		RI=0;
	}
}