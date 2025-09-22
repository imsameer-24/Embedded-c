#include"lcd-8bit.h"
void LCD_STR(unsigned char*);
int main()
{
//char s[]={0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,
  //         0x8A,0x8B,0X8C,0X8C,0X8D,0X8E,0X8F};
LCD_INIT();
while(1)
{

LCD_COMMAND(0X80);
LCD_STR("EMBEDDED");
delay_miliseconds(100);

}
}
