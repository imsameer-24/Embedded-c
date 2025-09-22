	#include<LPC21XX.H>
	#define LED1 1<<9
	#define LED2 1<<10
	#define LED3 1<<11
	#define LED4 1<<12
	void delay_ms(int);
      	int main()
	{
		PINSEL1=0;
		IODIR0=LED1|LED2|LED3|LED4;
		while(1)
		{
			IOCLR0=LED1|LED2|LED3|LED4;
			delay_ms(500);
			IOSET0=LED1|LED2|LED3|LED4;
			delay_ms(500);
		}
	}
	void delay_ms(int dly)
	{
		int i;
		for(;dly>0;dly--)
			for(i=12000;i>0;i--);
	}
