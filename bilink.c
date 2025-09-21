#include"delay.h"
#define LED1 1<<17
#define LED2 1<<18
void delay_miliseconds(U32);
int main()
{
	PINSEL1=0;
	IODIR0=LED1|LED2;
	while(1)
	{
		IOCLR0=LED1;
		IOSET0=LED2;
		delay_miliseconds(500);
		IOSET0=LED1;
		IOCLR0=LED2;
		delay_miliseconds(500);
	}
}

