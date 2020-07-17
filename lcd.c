/* This is lcd.h file */
/* lcd connected to Port 1 */
/* lcd data pins P1.16 to P1.23*/
/* rs = P1.25, en = P1.26 */

#include <lpc214x.h>

void lcdinit(void);
void cmdlcd(unsigned char);
void datalcd(unsigned char);
void delay(void);
void lcd_str(unsigned char *Str);


//unsigned char arr[8]="WELCOME";
int i;

void lcdinit(void)
{
	IO0DIR=0xFFFFFFFF;   
	   cmdlcd(0x38);
	   cmdlcd(0x01);
	   cmdlcd(0x80);
	   cmdlcd(0x06);
	   cmdlcd(0x0e);
}


// int main()
// {
//    IO1DIR=0xFFFFFFFF;
//    lcdinit();
// 	
// 	  lcd_str("Hello vivek ");
//    
//      for(i=0;arr[i]!='\0';i++)
// 	  {
// 	   datalcd(arr[i]);
//     }
//}

void cmdlcd(unsigned char ch)
{
  IO0PIN=(ch<<16);
	IO0CLR|=(1<<10); //rs=0
  IO0CLR|=(1<<12);
  IO0SET|=(1<<13); //en=1
	delay();
	IO0CLR |=(1<<13); //en=0
}

void datalcd(unsigned char ch)
{
  IO0PIN=(ch<<16);
	IO0SET|=(1<<10); //rs=1
  IO0CLR|=(1<<12);
  IO0SET|=(1<<13); //en=1
	delay();
	IO0CLR |=(1<<13);//en=0
}

void delay(void)
{
   int i,j;
   for(i=0;i<300;i++)
   for(j=0;j<300;j++);
}


void lcd_str(unsigned char *str)
{
	while(*str)
		datalcd(*str++);
	
}
