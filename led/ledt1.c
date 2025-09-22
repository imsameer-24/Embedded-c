#include<LPC21xx.H>
typedef unsigned int U32;
#define LED1 1<<14
void delay_miliseconds(U32 ms)
{
T0PR = 15000-1;
T0TCR = 0X01;
while(T0TC<ms);
T0TCR =	0X03;
T0TCR =	0X00;
}
int main()
{
IODIR0 = LED1;
while(1)
{
IOSET0 = LED1;
delay_miliseconds(500);
IOCLR0 = LED1;
delay_miliseconds(500);
}
}
