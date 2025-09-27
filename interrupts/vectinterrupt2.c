#include<LPC21xx.H>
#define IRQ_slot_en 0x20
#define EINT0_num 14
#define EINT1_num 15
#define LED1 1<<0
#define LED2 1<<1
void config_interrupts(void);
void ext_int0_isr(void) __irq
{
EXTINT = 0X01;
IOSET0 = LED1;
IOCLR0 = LED1;
VICVectAddr = 0;
}
void ext_int1_isr(void) __irq
{
EXTINT = 0X02;
IOSET0 = LED2;
IOCLR0 = LED2;
VICVectAddr = 0;
}
int main()
{
unsigned int count = 0;
PINSEL1 |= 0X1;
PINSEL0 |= 1<<29;
IODIR0 = LED1;
IODIR0 = LED2;
config_interrupts();
EXTMODE = 0X03;
EXTPOLAR = 0X00;
VICIntEnable = 1<<EINT0_num;
VICIntEnable = 1<<EINT1_num;
while(1)
{
count++;
}
}
void config_interrupts(void)
{
VICIntSelect = 0;
VICVectCntl0 = IRQ_slot_en | EINT0_num;
VICVectAddr0 = (int)ext_int0_isr;
VICVectCntl1 = IRQ_slot_en | EINT1_num;
VICVectAddr1 = (int)ext_int1_isr;
}
