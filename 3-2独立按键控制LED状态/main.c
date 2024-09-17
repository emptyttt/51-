#include <REGX52.H>

void Delay(unsigned int xms)	//@11.0592MHz
{
    unsigned char i, j;
    while (xms)
    {
        i = 2;
        j = 199;
        do
        {
            while (--j);
        } while (--i);
        xms--;
    }
}

void main()
{
    while (1)
    {
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			
			P2_0=~P2_0;
		
		}
//        P2_0 = 0;      // Set P2_0 to 0 (LED on if active low)
//        Delay(500); // 500 ms delay
//        P2_0 = 1;      // Set P2_0 to 1 (LED off if active low)
//        Delay(500); // 500 ms delay

//        P2_1 = 0;      // Set P2_1 to 0 (LED on if active low)
//        Delay(500); // 500 ms delay
//        P2_1 = 1;      // Set P2_1 to 1 (LED off if active low)
//        Delay(500); // 500 ms delay
    }
}