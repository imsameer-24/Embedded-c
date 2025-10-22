#include<lpc21xx.h>
#include"lcd-4bit.h"
int main()
{
	LCD_INIT();
	LCD_COMMAND(0X81);
	LCD_STR("SAMEER");
	LCD_COMMAND(0X89);
	LCD_STR("KUMAR");
	LCD_COMMAND(0XC3);
	LCD_STR("PATTANAIK");
}

