#include <REGX52.H>

sbit OneWire_DQ=P3^7;

/**
  * @brief OneWire初始化
  * @param 无
  * @retval AckBit 应答位
  */
unsigned char OneWire_Init(void)
{
	unsigned char data i;
	unsigned char AckBit;
	
	OneWire_DQ=1;
	OneWire_DQ=0;
	i = 227;while (--i);//Delay 500us
	OneWire_DQ=1;
	i = 29;while (--i);//Delay 70us
	AckBit=OneWire_DQ;//从机拉低总线后会自动释放总线
	i=227;while(--i);//Delay 500us
	return AckBit;
}

/**
  * @brief OneWire 发送一位
  * @param Bit要发送的数据
  * @retval 无
  */
void OneWire_SendBit(unsigned char Bit)
{

	unsigned char data i;

	OneWire_DQ=0;
	i = 3;while (--i);//Delay10us
	OneWire_DQ=Bit;
	i = 22;while (--i);//Delay50us
	OneWire_DQ=1;
}

/**
  * @brief OneWire接受一位
  * @param 无
  * @retval bit接收到的数据
  */
unsigned char OneWire_ReceiveBit(void)
{
	unsigned char Bit;
	unsigned char i;
	
	OneWire_DQ=0;
	i = 1;while (--i);//Delay5us
	OneWire_DQ=1;
	i = 1;while (--i);//Delay5us
	Bit=OneWire_DQ;
	i = 20;while (--i);//Delay50us
	return Bit;
}

/**
  * @brief OneWire发送一个字节
  * @param Byte 要发送的字节
  * @retval 无
  */
void OneWire_SendByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		OneWire_SendBit(Byte&(0x01<<i));
	}
}

/**
  * @brief OneWire接收一个字节
  * @param 无
  * @retval Byte要接收的数据
  */
unsigned char OneWire_ReceiveByte(void)
{
	unsigned char i;
	unsigned char Byte=0x00;
	for(i=0;i<8;i++)
	{
		if(OneWire_ReceiveBit()){Byte|=(0x01<<i);}
	}
	return Byte;
}