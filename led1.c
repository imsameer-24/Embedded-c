#include<LPC21xx.H>
#define LED1 1<<17
void delay_ms(int);
int main()
{
	PINSEL1=0;
	IODIR0=LED1;
	while(1)
	{
		IOCLR0=LED1;
		delay_ms(500);
		IOSET0=LED1;
		delay_ms(500);
	}
 }
 void delay_ms(int dly)
 {
	 int i;
	 for(;dly>0;dly--)
	 	for(i=12000;i>0;i--);
}	
