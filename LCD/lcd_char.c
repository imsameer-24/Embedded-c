#include<lpc21xx.h>
#include"lcd-8bit.h"

void LCD_INIT(void);
void LCD_COMMAND(unsigned char);
void LCD_DATA(unsigned char);
int main()
{
 LCD_INIT();
 LCD_COMMAND(0X80);
 LCD_DATA('A');
 }

