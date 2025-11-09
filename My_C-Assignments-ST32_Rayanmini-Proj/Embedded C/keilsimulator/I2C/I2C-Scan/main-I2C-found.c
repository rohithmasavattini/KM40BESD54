#include "Lcd.h"
#include<stdio.h>
#define RCC_AHB1ENR *((int *)(0x40023830))
#define GPIOB_MODER *((int *)(0x40020400))
#define GPIOB_PUPDR *((int *)(0x4002040C))
#define GPIOB_OTYPER *((int *)(0x40020404))
#define RCC_APB1ENR *((int *)(0x40023840))
#define GPIOB_AFRL *((int *)(0x40020420))	

#define I2C_CR1 *((int *)(0x40005400))
#define I2C_CR2 *((int *)(0x40005404))
#define I2C_TRISE *((int *)(0x40005420))	
#define I2C_SR1 *((int *)(0x40005414))
#define I2C_SR2 *((int *)(0x40005418))
#define I2C_DR *((int *)(0x40005410))
#define I2C_CCR *((int *)(0x4000541C))	

int i,temp;
char s[50];
char RX;

void I2C_Init(void)
{
	RCC_AHB1ENR |= (0x1 << 1);      //PORT B CLK            
	while(!(RCC_AHB1ENR & 0x2));    
	
	GPIOB_MODER |= 0x1 << 15;
	GPIOB_MODER |= 0x1 << 13;       //LOAD 01 BITS IN 15,14,13,12 TO SET PB7,PB6 
	
	GPIOB_PUPDR &= 0xFFFF0FFF;
	GPIOB_PUPDR |= 0x00005000;     //LOAD O1 BITS IN 15,14,13,12 TO ENABLE PULLUP PB7,PB6
	
	GPIOB_OTYPER |= 0x1 << 7;      //PB7 OPEN DRAIN
 	GPIOB_OTYPER |= 0x1 << 6;      //PB6 OPEN DRAIN
	
	RCC_APB1ENR |= 0x1 << 21;             //SET 21st BIT TO ENABLE I2C1 CLOCK
	while(!(RCC_APB1ENR & (0x1 << 21)));
	
	GPIOB_AFRL |= 0x44000000;            //LOAD 0100 BITS IN 31-24 TO CHOOSE PB7.PB6 ALTERNATE I2C PORT
	
}
	
	
void I2C_Config(void)
{
	 
 	I2C_CR1 |= 0x1 << 0;             //PE ENABLE
	I2C_CR2 |= 0x1 << 4;             //16 MHZ FREQ 
	//I2C_CCR |= 0x1 << 4;            //0x50 CLOCK 100KHZ
	//I2C_CCR |= 0x1 << 6;
	I2C_CCR |= 0x50;                
 	I2C_TRISE = 0x11;           
	
	//I2C_CR1 |= 0x1 << 8;            //SET 8 BIT TO ENABLE START COND 
	//I2C_CR1 |= 0x1 << 9;            //SET 9 BIT TO ENABLE STOP COND
	//I2C_CR1 |= 0x1 << 10;           //ACK BIT	
}
		

void I2C_start(void)
{	
int t;
I2C_CR1 |= 0x1 << 8;                //SET 8 BIT TO ENABLE START COND
while (!(I2C_SR1 & 0x1))           //check SB bit
{
	;
}
t = I2C_SR1;
}		


void I2C_stop(void)
{
	I2C_CR1 |= 0x1 << 9;            //SET 9 BIT TO ENABLE STOP COND
	I2C_SR1 &= ~(0x1 << 1);         //CLEAR Adress bit
}
 
void delay(int ms)
{
	int i;
	for(i=0;i<ms*1670;i++)
	{
		;
	}
}


int main()
{
	I2C_Init();
  I2C_Config(); 		
	LCD_PORTB_Init();
	LCD_Init();
	
	while(1)
	{
	 
	 for(i=0;i<128;i++)
	 {
		 while ((I2C_SR2 &(0x1 << 1))==1);    //READ STATUS REGISTE BUSY bit
	  I2C_start();
		I2C_DR = i<<1;            //Peripheral adress 
		while ((!(I2C_SR1 & (0x1 << 10)) && (!(I2C_SR1 & (0x1 << 1)))))     //ACK,ADRESS BIT
	  {
		 ;
	  }
	
	if(I2C_SR1 & (0x1 << 1))
	{
		I2C_stop();
		//temp = I2C_SR1;   //CLEAR ADDR
		//temp = I2C_SR2;   //CLEAR ADDR	
 	  sprintf(s,"%d",i);
		temp = i;
	 LCD_Write_Cmd(0x01);
	 LCD_Write_Cmd(0x80);
	if(temp==80)
	 {
	 LCD_String("EEPROM FOUND: ");	
	 LCD_Write_Cmd(0x8D);
	 i2a(temp);	
	 delay(1000);
	 }
	 LCD_Write_Cmd(0x01);
	 LCD_Write_Cmd(0x80);
	 if(temp==104)
	 {
	 LCD_String("RTC FOUND: ");	
	 LCD_Write_Cmd(0x8A);
	 i2a(temp);
	 delay(1000);
	 }		 
	}
 else
 {
	I2C_stop();
	I2C_SR1 &= ~(0x0400);   //**CLEAR AF BIT		
 }
 }
}
}
