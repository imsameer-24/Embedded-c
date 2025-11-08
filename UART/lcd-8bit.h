#include"delay.h"
#define LCD_D 0xff<<20
#define RS 1<<8
#define E 1<<9
void LCD_INIT(void);
void LCD_COMMAND(unsigned char);
void LCD_DATA(unsigned char);


void LCD_INIT(void)
{
IODIR0=LCD_D|RS|E;
LCD_COMMAND(0X01);
LCD_COMMAND(0X02);
LCD_COMMAND(0X0C);
LCD_COMMAND(0X38);
}


void LCD_COMMAND(unsigned char cmd)
{
IOPIN0=(IOPIN0 & 0XFFFFFF00)|cmd;
IOCLR0=RS;
IOSET0=E;
delay_miliseconds(2);
IOCLR0=E;
}


void LCD_DATA(unsigned char d)
{
IOPIN0=(IOPIN0 & 0XFFFFFF00) | d;
IOSET0=RS;
IOSET0=E;
delay_miliseconds(2);
IOCLR0=E;
}


void LCD_STR(unsigned char *s)
{
while(*s)
  LCD_DATA(*s++);
}

void LCD_INT(int n)
{
unsigned char arr[5];
signed char i=0;
if(n==0)
   LCD_DATA('0');
else{
   if(n<0)
   {
	LCD_DATA('-');
	n=-n;
   }
   while(n>0)
   {
	arr[i++]=n%10;
	n/=10;
   }
   for(--i;i>=0;i--)
	LCD_DATA(arr[i]+48);
   }
}
