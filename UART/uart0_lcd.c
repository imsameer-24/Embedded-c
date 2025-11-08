#include<lpc21xx.h>
#include"lcd.h"
void UART0_CONFIG(void);
void UART0_TX(unsigned char);
unsigned char UART0_RX(void);
void UART0_STR(unsigned char *);
int main()
{
  int i=0;
  unsigned char rxbytes;
  unsigned char p[20];
  UART0_CONFIG();
  LCD_INIT();
  while(1)
  {
    rxbytes = UART0_RX();
	if((rxbytes=='\n')||(rxbytes=='\r'))
	{
	p[i]='\0';
	 LCD_COMMAND(0x01);
	 LCD_COMMAND(0x80);
	 LCD_STR(p);
	 delay_miliseconds(700);
	 i=0;
	}
	else
	{
      p[i++]=rxbytes;
	  UART0_TX(rxbytes);
	  }
	 delay_miliseconds(500);   
  }
}
void UART0_CONFIG(void)
{
 PINSEL0|=0x05;
 U0LCR=0X83;
 U0DLL=97;
 U0LCR=0X03;
}

void UART0_TX(unsigned char x)
{
 U0THR=x;
 while(((U0LSR>>5)&1)==0);
 }
unsigned char UART0_RX(void)
{ 
  while((U0LSR&1)==0);
     return U0RBR;
}

