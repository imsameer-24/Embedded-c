#include<lpc21xx.h>
#define SW1 14
#define SW2 15
#define SW3 16
#define SW4 17
void UART0_CONFIG(void);
void UART0_str(char *);
void UART0_TX(char );
int main()
{
 UART0_CONFIG();
 while(1)
 {
  if(((IOPIN0>>SW1)&1)==0)
  { 
   UART0_str("SW1 is pressed"); 
   }
  if(((IOPIN0>>SW2)&1)==0)
  {
   UART0_str("SW2 is pressed");
   }
  if(((IOPIN0>>SW3)&1)==0)
  {
   UART0_str("SW3 is pressed");
   }
  if(((IOPIN0>>SW4)&1)==0)
  {
   UART0_str("SW4 is pressed");
   }
 }
}
void UART0_CONFIG(void)
{
 PINSEL0=0x05;
 U0LCR=0X83;
 U0DLL=96;
 U0LCR=0X03;
}

void UART0_str(char *x)
{
 while(*x)
 {
  UART0_TX(*x++);
  }
}

void UART0_TX(char x)
{
 U0THR=x;
 while(((U0LSR>>5)&1)==0);
 }
