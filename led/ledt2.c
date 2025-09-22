#include<LPC21xx.H>
typedef unsigned int U32;
#define LED0 1<<14
#define LED1 1<<15
#define LED2 1<<16
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
int LED[]={LED0,LED1,LED2};
int i;

IODIR0 = LED0|LED1|LED2;

while(1)
{
for(i=0;i<3;i++)
{
IOCLR0 = LED[i];
delay_miliseconds(500);
IOSET0 = LED[i];
}
}
}
