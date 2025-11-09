#include "LCDh.h"
#define RCC_APB2ENR *((int *)(0x40023844))	
#define ADC_SQR3 *((int *)(0x40012034))	
#define ADC_SMPR1 *((int *)(0x4001200C))	
#define ADC_CR1 *((int *)(0x40012004))	
#define ADC_CR2 *((int *)(0x40012008))	
#define ADC_SR *((int *)(0x40012000))
#define ADC_DR *((int *)(0x4001204C))

#define RCC_AHB1ENR *((int *)(0x40023830))
#define GPIOC_MODER *((int *)(0x40020800))


void ADC_PORT_Init(void)
{
	RCC_AHB1ENR |= (0x1 << 2);
	while(!(RCC_AHB1ENR & 0x4))
	{
		;
	}
	
	GPIOC_MODER &= 0xFFFFFFFC;
	GPIOC_MODER |= 0x00000003;      //LOAD 11 BITS IN 1-0 TO SET PC0(LM35) ANALOG MODE
}


void ADC_Init(void)
{
	RCC_APB2ENR |= (0x1 << 8);
	while(!(RCC_APB2ENR &(0x1 << 8)))
	{
		;
	}
	ADC_SQR3 &= 0xFFFFFFF5;
	ADC_SQR3 |= 0x0000000A;      //LOAD 1010 BITS INTO 3,2,1,0 TO ENABLE 10TH CHANNEL
	ADC_SMPR1 |= 0x00000007;     //LOAD 111 IN BIT 0,1,2 TO SELECT 480 CYCLES
 //ADC_CR1 |= 0x00C00000;       //OPTIONAL LOAD 00 IN 24-25 TO SET 12-BIT RESOLUTION   
	ADC_CR2 |= 0X00000403;       //LOAD 1 INTO 10,1,0 POS TO ENABLE EOSC,CONTINIOUS MODE,ADON 
  
  ADC_CR2 |= (0x1 << 30);         //SET 30TH BIT TO REGULLAR CHANNEL CONVERSION	
	while(!(ADC_SR & 0x2))
		{
			;
		}	 
}


int ADC_READTEMP(void)
  { 
       int temp,d;
			 temp = ADC_DR*290 ;
	     d=(temp/4096);		
	     return d;
	
  } 


void DISPLAY_TEMP(void)
{
  	int temp,d;
	  temp = ADC_DR ;
		temp=temp*290;
	  d=(temp/4096);
	
	 //LCD_Write_Cmd(0x01);
	 LCD_Write_Cmd(0x89);
	 LCD_String((unsigned char *)"T:");
  	
	 LCD_Write_Cmd(0x8B);
	 i22a(d);
	 LCD_Write_Cmd(0x8D);
 	 LCD_Write_Data(0xDF);	
   LCD_String((unsigned char *)"C");
}


