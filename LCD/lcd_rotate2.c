#include"lcd-8bit.h"
int main()
{
int count=0;
LCD_INIT();
while(1)
{
LCD_COMMAND(0X80);
LCD_DATA('A');
delay_miliseconds(500);
LCD_COMMAND(0X1C);
count++;
if(count==16)
{
LCD_COMMAND(0x02);
count=0;
}
}
}

