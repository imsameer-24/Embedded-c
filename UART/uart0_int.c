#include<LPC21xx.H>
void UART0_CONFIG(void);
void UART0_TX(short int );
int main()
{
 int n=24;
 UART0_CONFIG();
 while(1)
 {
   UART0_TX((n/10)+48);
   UART0_TX((n%10)+48);
 }
}

void UART0_CONFIG(void)
{
 PINSEL0=0x05;
 U0LCR=0X83;
 U0DLL=96;
 U0LCR=0X03;
}

void UART0_TX(short int x)
{
 U0THR=x;
 while(((U0LSR>>5)&1)==0);
}
