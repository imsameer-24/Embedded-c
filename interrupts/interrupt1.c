#include<LPC21xx.H>
#define IRQ_slot_en 0x20
#define EINT0_num 14
#define LED1 1<<0
void config_EINT0(void);
void ext_int0_isr(void) __irq
{
EXTINT = 0X01;
IOSET0 = LED1;
IOCLR0 = LED1;
VICVectAddr = 0;
}

int main()
{
unsigned int count = 0;
PINSEL1 |= 0X1;
IODIR0 = LED1;
config_EINT0();
EXTMODE = 0X00;
EXTPOLAR = 0X00;
VICIntEnable = 1<<EINT0_num;
while(1)
{
count++;
}
}
void config_EINT0(void)
{
VICIntSelect = 0;
VICVectCntl0 = IRQ_slot_en | EINT0_num;
VICVectAddr0 = (int)ext_int0_isr;
}
