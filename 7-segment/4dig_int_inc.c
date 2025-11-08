#include<lpc21xx.h>
#define seg_d 0xff<<0
#define seg_1 1<<8
#define seg_2 1<<9
#define seg_3 1<<10
#define seg_4 1<<11

void fourdigit_display(int);
unsigned char seg_lut[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
void delay_ms(unsigned int ms)
{
	T0PR=15000-1;
	T0TCR=0X01;
	while(T0TC<ms);
	T0TCR=0X03;
	T0TCR=0X00;
}

int main()
{
	int n=0;
	IODIR0=seg_d|seg_1|seg_2|seg_3|seg_4;
	while(1)
	{
		fourdigit_display(n++);
		if(n==9999)
			n=0;
	}
}

void fourdigit_display(int n)
{
	unsigned char dly;
	for(dly=0;dly<5;dly++)
	{
 	IOCLR0=seg_d;
	IOSET0=seg_lut[n/1000];
	IOCLR0=seg_1;
	delay_ms(5);
	IOSET0=seg_1;

	IOCLR0=seg_d;
	IOSET0=seg_lut[(n/100)%10];
	IOCLR0=seg_2;
	delay_ms(5);
	IOSET0=seg_2;

	IOCLR0=seg_d;
	IOSET0=seg_lut[(n/10)%10];
	IOCLR0=seg_3;
	delay_ms(5);
	IOSET0=seg_3;

	IOCLR0=seg_d;
	IOSET0=seg_lut[n%10];
	IOCLR0=seg_4;
	delay_ms(5);
	IOSET0=seg_4;
	}
}

