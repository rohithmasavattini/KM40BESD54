#include "Lcd.h"
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
char Buff[7]={0x12,0x30,0x11,0x7,0x8,0x5,0x21};    //SEC,MIN,HOUR,WEEK DAY,DATE,MON,YEAR
char RX[7];

void I2C_Init(void)
{
	RCC_AHB1ENR |= (0x1 << 1);      //PORT B CLK            
	while(!(RCC_AHB1ENR & 0x2));    
	
	GPIOB_MODER |= 0x1 << 15;
	GPIOB_MODER |= 0x1 << 13;       //LOAD 10 BITS IN 15,14,13,12 TO SET PB7,PB6 
	
	GPIOB_PUPDR &= 0xFFFF0FFF;
	GPIOB_PUPDR |= 0x00005000;     //LOAD O1 BITS IN 15,14,13,12 TO ENABLE PULLUP PB7,PB6
	
	GPIOB_OTYPER |= 0x1 << 7;      //PB7 OPEN DRAIN
 	GPIOB_OTYPER |= 0x1 << 6;      //PB6 OPEN DRAIN
	
	
	GPIOB_AFRL |= 0x44000000;            //LOAD 0100 BITS IN 31-24 TO CHOOSE PB7.PB6 ALTERNATE I2C PORT
	

}
	
	
void I2C_Config(void)
{
	RCC_APB1ENR |= 0x1 << 21;             //SET 21st BIT TO ENABLE I2C1 CLOCK
	 while(!(RCC_APB1ENR & (0x1 << 21)));
	
 	I2C_CR1 &= ~(0x1);               //PE DS
	I2C_CR2 |= 0x10;              //16 MHZ FREQ 
	I2C_CCR = 0x50;                 //0x50 CLOCK 100KHZ                
 	I2C_TRISE = 0x11;                
	I2C_CR1 |= (0x1 << 10);
	I2C_CR1 |= 0x1;                   //PE EN
	
	//I2C_CR1 |= 0x1 << 8;            //SET 8 BIT TO ENABLE START COND 
	//I2C_CR1 |= 0x1 << 9;            //SET 9 BIT TO ENABLE STOP COND
	//I2C_CR1 |= 0x1 << 10;           //ACK BIT	
}
		

void I2C_start(void)
{	
 int t;
 I2C_CR1 |= 0x1 << 8;                //SET 8 BIT TO ENABLE START COND
 while (!(I2C_SR1 & 0x1))            //SB bit
{
	;
}
t = I2C_SR1;
}		


void I2C_stop(void)
{
	I2C_CR1 |= 0x1 << 9;            //SET 9 BIT TO ENABLE STOP COND
	I2C_SR1 &= ~(0x1 << 1);        //Clear Adress bit
	//I2C_CR1 &= ~(0x1);
}
 
void delay5(int ms)
{
	for(i=0;i<1650*ms;i++)
	{
		;
	}
}


void RTC_write(void)
{
	int temp2;
	I2C_CR1 &= ~(0x1);               //PE DS
	I2C_CR1 |= 0x1;                   //PE EN
	I2C_CR1 &= ~(0x1 << 8);
	
  while ((I2C_SR2 &(0x1 << 1))==1);    //READ STATUS REGISTE BUSY bit
 	//I2C_start();
		I2C_CR1 |= 0x1 << 8;                //SET 8 BIT TO ENABLE START COND
   while ((I2C_SR1 & 0x01)==0)            //SB bit
   {
	  ;
   }
  
	 temp = I2C_SR1;
	 I2C_DR = 0xD0;            //adress ASSIGN TO DR		
	
	 //while ((!(I2C_SR1 & (0x1 << 10)) && (!(I2C_SR1 & (0x1 << 1)))))     //ACK,ADRESS BIT
	 while(!(I2C_SR1 & (0x02)));     //ADDR
		
	 if(I2C_SR1 & (0x1 << 1))     //if ADRESS SET
		{
		temp2= I2C_SR1;
		temp2= I2C_SR2;
	 	while(!(I2C_SR1 & (0x1 << 7)));     //TXE BIT
		I2C_DR = 0x00;                      //MEMORY adress ASSIGN TO DR	
		for(i=0;i<7;i++)
		{
		while(!(I2C_SR1 & (0x1 << 7)));     //TXE BIT
		I2C_DR = Buff[i]; 
		}
  }
	I2C_stop();
	delay5(1000);
}



void RTC_read(void)
{
	I2C_CR1 &= ~(0x1);                 //PE dis
	I2C_CR1 |= (0x1);                  //PE EN
	I2C_CR1 |= (0x1 << 10);           //SET ACK bit	
	while((I2C_SR2 & (0x01 << 1))==1);     //BUSY bit
	//I2C_start();
	I2C_CR1 |= 0x1 << 8;                //SET 8 BIT TO ENABLE START COND
  while (!(I2C_SR1 & 0x1))            //SB bit
  {
	;
  }
  temp = I2C_SR1;
	
	//SEND ADRESS
	 I2C_DR = (0xD0);
		//delay5(500);
	  while(!(I2C_SR1 & 0x02))     //ADDR
	  {
		 ;
	  }	
  temp = I2C_SR1;          //CLEAR ADR bit 
	temp = I2C_SR2; 	
	 if(!(I2C_SR1 & (0x1 << 1)))
		{	
   while(!(I2C_SR1 & (0x01 << 7)));  //CHECK TXE
   I2C_DR = (0x00);                   //send addrs
	 I2C_start();
	 I2C_DR = (0xD1);	
	// while(!(I2C_SR1 & (0x01 << 1)));     //ADDR
		}
		 while(!(I2C_SR1 & (0x01 << 1)));     //ADDR
		
  	if(I2C_SR1 & (0x1 << 1))
		{
		temp = I2C_SR1;           //CLEAR ADR,AF bit
		temp = I2C_SR2;
			for(i=0;i<7;i++)
		{
			while(!(I2C_SR1 & (0x01 << 6)));   //RXE
			RX[i] = I2C_DR;
		}
		I2C_CR1 &= ~(0x1<<10);   //ACK
		I2C_stop();
		I2C_CR1 &= ~(0x01);    //PE disble
	//while(I2C_SR2 & (0x01 << 1));      //BUSY bit
		delay5(500);
	}
}
	
void LCD_TIME(void)
{
	LCD_Write_Cmd(0x01);
	LCD_Write_Cmd(0x80);
	LCD_String("Time");
	for(i=2;i>=0;i--)
	{
		LCD_Write_Data(':');
		LCD_Write_Data((RX[i]>>4)+'0');
		LCD_Write_Data((RX[i] & 0x0F)+'0');	
	}
}
	
void LCD_DATE(void)
{
	LCD_Write_Cmd(0xC0);
	LCD_String("Date:");
	for(i=4;i<7;i++)
	{
		LCD_Write_Data((RX[i]>>4)+'0');
		LCD_Write_Data((RX[i] & 0x0F)+'0');	
		LCD_Write_Data('/');
	}
	LCD_Write_Cmd(0xCD);
	LCD_Write_Data(' ');
	
}
	

int main()
{
	I2C_Init();
  I2C_Config();
	LCD_PORTB_Init();
	LCD_Init();
	RTC_write();
	while(1)
	{
		RTC_read();
		LCD_TIME();
		LCD_DATE();	
		//delay(1000);
	}	
	return 0;
}

