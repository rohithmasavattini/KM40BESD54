#include "LCD.h"
#include "ADC.h"

//#define RCC_AHB1ENR *((int *)(0x40023830))
//#define GPIOC_MODER *((int *)(0x40020800))
//#define RCC_APB2ENR *((int *)(0x40023844))	
//#define ADC_SQR3 *((int *)(0x40012034))	
//#define ADC_SMPR1 *((int *)(0x4001200C))	
//#define ADC_CR1 *((int *)(0x40012004))	

#define ADC_CR2 *((int *)(0x40012008))	
#define ADC_SR *((int *)(0x40012000))
#define ADC_DR *((int *)(0x4001204C))

void i2a(int);
unsigned int temp,d;
//unsigned char a,b;
int main()
{
	
  //ADC Init
	PORTC_Init();
  ADC_Init();

  //LCD Init	
	PORTB_Init();
	LCD_Init();

  while(1)
	{
		ADC_CR2 |= (0x1 << 30);         //SET 30TH BIT TO REGULLAR CHANNEL CONVERSION	
		while(!(ADC_SR & 0x2))
		{
			;
		}
	  temp = ADC_DR ;
		temp=temp*290;
	  d=(temp/4096);
	
	
	 KM_LCD_Write_Cmd(0x01);
	 KM_LCD_Write_Cmd(0x80);
	 KM_LCD_String("Temp: ");
      
		
	KM_LCD_Write_Cmd(0x86);
	i2a(d);

	KM_LCD_Write_Cmd(0x88);
	KM_LCD_Write_Data(0xDF);	
  KM_LCD_String("C");		
		
	}
	return 0;
}

			

void i2a(int d)
{
int i,j;
char a[2];
for(i=0;d>0;i++)
{
	a[i] = d%10 + 0x30;
	d=d/10;
}

for(i=i-1;i>=0;i--)
{
	KM_LCD_Write_Data(a[i]);
}
}