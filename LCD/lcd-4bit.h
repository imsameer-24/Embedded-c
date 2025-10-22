#include"delay.h"
#define LCD_D 0xf<<20
#define RS 1<<17
#define RW 1<<18
#define E 1<<19
void LCD_INIT(void);
void LCD_COMMAND(unsigned char);
void LCD_DATA(unsigned char);
void LCD_INIT(void)
{
IODIR1=LCD_D|RS|E|RW;
IOCLR1 = RW;
LCD_COMMAND(0X01);
LCD_COMMAND(0X02);
LCD_COMMAND(0X0C);
LCD_COMMAND(0X28);
}
void LCD_COMMAND(unsigned char cmd)
{
IOCLR1=LCD_D;
IOSET1=(cmd & 0xf0)<<16;
IOCLR1=RS;
IOSET1=E;
delay_miliseconds(2);
IOCLR1=E;

IOCLR1=LCD_D;
IOSET1=(cmd & 0x0f)<<20;
IOCLR1=RS;
IOSET1=E;
delay_miliseconds(2);
IOCLR1=E;
}
void LCD_DATA(unsigned char d)
{
IOCLR1=LCD_D;
IOSET1=(d & 0xf0)<<16;
IOSET1=RS;
IOSET1=E;
delay_miliseconds(2);
IOCLR1=E;

IOCLR1=LCD_D;
IOSET1=(d & 0x0f)<<20;
IOSET1=RS;
IOSET1=E;
delay_miliseconds(2);
IOCLR1=E;
}
void LCD_STR(unsigned char *s)
{
while(*s)
  LCD_DATA(*s++);
}

