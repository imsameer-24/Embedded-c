	#include<LPC21xx.H>
	typedef unsigned int U32;
	void delay_seconds(U32);
	void delay_miliseconds(U32);
	void delay_microseconds(U32);
	int main()
	{
		delay_miliseconds(500);
		while(1);
	}
	void delay_seconds(U32 seconds)
	{
		T0PR=15000000-1;
		T0TCR=0X01;
		while(T0TC<seconds);
		T0TCR=0X03;
		T0TCR=0X00;
	}
	void delay_miliseconds(U32 ms)
	{
		T0PR=15000-1;
		T0TCR=0X01;
		while(T0TC<ms);
		T0TCR=0X03;
		T0TCR=0X00;
	}
	void delay_microseconds(U32 us)
	{
		T0PR=15-1;
		T0TCR=0X01;
		while(T0TC<us);
		T0TCR=0X03;
		T0TCR=0X00;
	}
	 
