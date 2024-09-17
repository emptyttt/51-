#include<REGX52.H>

void Delay(unsigned int xms)	//@11.0592MHz
{
	unsigned char i, j;

	while(xms--){
    i = 2;
	j = 199;

	do
	{
	while (--j);
	} while (--i);

  }
	
}

void main()
{
	unsigned char LEDNum=0;//0000 0000
		
	while(1)
	{
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			//1111 1111 0xFF
			//P2++;//0000 0000
			LEDNum++;
			P2=~LEDNum;
		
		}
	}
	
		
	
		
}
