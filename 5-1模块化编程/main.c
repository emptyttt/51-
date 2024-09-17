#include <REGX52.H>//在安装目录里寻找
#include "Delay.h"//在自己程序目录里寻找
#include "Nixie.h"

void main()
{
	
	while(1)
	{
		Nixie(1,1);
		Nixie(2,2);
		Nixie(3,3);
		Nixie(4,4);
		Nixie(5,5);
	}
}
	