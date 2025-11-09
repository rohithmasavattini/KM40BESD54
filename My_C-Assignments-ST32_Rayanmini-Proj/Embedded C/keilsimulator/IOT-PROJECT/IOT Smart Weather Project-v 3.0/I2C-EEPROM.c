#include "Lcdh.h"
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


//char Buff1[10]={0x10,0x32,0x11,0x7,0x1,0x5,0x21};    //SEC,MIN,HOUR,WEEK DAY,DATE,MON,YEAR


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
		
 
void delay5(int ms)
{
	int i;
	for(i=0;i<1650*ms;i++);
}


int KM_I2C_Mem_Write(short int DevAddress,short int MemAddress,short int MemAddSize,unsigned char *pData,short int len)
{
	int temp;
	short int MemAddSize_temp=0;
	int i=0;
		
		while (len > 0)
		{
					MemAddSize_temp = MemAddSize;	
	 
			
	  I2C_CR1 &= ~(0x1);               //PE DS
		I2C_CR1 |= 0x1;                  //PE EN
	  
		I2C_CR1 &= ~(0x1 << 8);
    while ((I2C_SR2 &(0x1 << 1))==1);    //READ STATUS REGISTE BUSY bit
 	  
		//I2C_start();
		I2C_CR1 |= 0x1 << 8;                //SET 8 BIT TO ENABLE START COND
    while ((I2C_SR1 & 0x01)==0);        //SB bit
	  temp = I2C_SR1;                     //Read SR1 to clear START bit    
	  
		 I2C_DR = DevAddress << 1;           //Slave address with Write mode		
	   while(!(I2C_SR1 & (0x02)));        //wait untill ADDR bit set
		
    if(I2C_SR1 & (0x1 << 1))             //if ADRESS SET
	   {
  		temp= I2C_SR1;            //Read SR1 to clear ADDR bit
	  	temp= I2C_SR2;            //Read SR2 to clear ADDR bit 
		
	 	while(!(I2C_SR1 & (0x1 << 7)));     //Wait until TX bit set
		I2C_DR = MemAddress;                //Register address	
	  		
			while ((MemAddSize_temp > 0) && (len > 0)) 
		  				{
											while(!(I2C_SR1 & (0x01<<7)));   //TXE BIT
											I2C_DR = pData[i];
											delay5(1);
											MemAddSize_temp--;
											len--;
											i++;
							}
							
							I2C_SR1 &=~(0x1<<10);  //clear AF bit in SR1
							I2C_CR1 |=(0x0200);    //Set STOP bit 9 in CR1
						//I2C1_CR1 &=~(0X01);    //Reset PE bit in CR1
							delay5(200);
							MemAddress = MemAddress + MemAddSize;										
							//return 1;
	     }
	 		 else // Not Ack
			 {	 
					 I2C_SR1 &=~(0x1<<10);     //clear AF bit in SR1
					 I2C_CR1 |=(0x1 << 9);    //Set STOP bit 9 in CR1
					 I2C_CR1 &=~(0X01);      //Reset PE bit in CR1
					 delay5(100);
					 return 0;
			 }
		}
		return 1;
} 
			

	 
int KM_I2C_Mem_Read(short int DevAddress, short int MemAddress,short int MemAddSize, unsigned char *Data, short int Size)
{
	int temp;
	int K=0;
	
	I2C_CR1 |= 0x1;//Start peripheral(PE)
	I2C_CR1 |= (0x1<<10);//Enable ACK 
	
	while(I2C_SR2 &0x2); //Check BUSY bit wait untill it will become ZERO

	I2C_CR1 |= 1<<8;	// Set start bit
	while(!(I2C_SR1 & 0x1));//Wait Untill SB bit is set
	temp=I2C_SR1;	     //Read SR1 to clear START bit
	 
  I2C_DR = (DevAddress << 1);  //Slave address with Write mode                             
	     while((!(I2C_SR1 & (0x1<<1)) && (!(I2C_SR1 & (0x1<<10))))); //wait untill ADDR bit set
	 
			if(I2C_SR1 & (0x1<<1)) // if ADDR bit is set
			{
					 temp=I2C_SR1; //Read SR1 to clear ADDR bit
					 temp=I2C_SR2; //Read SR2 to clear ADDR bit
					 
					 while(!(I2C_SR1 & (0x01<<7))); //Wait until TX bit set
					 I2C_DR = (MemAddress);         //Register address
					 
					 
					 I2C_CR1 |= 1<<8;	//Re-Start Communication
					 while(!(I2C_SR1 & 0x1));//Wait Untill SB bit is set
					 temp=I2C_SR1;	     //Read SR1 to clear START bit
				 
					 
					 I2C_DR = (DevAddress << 1 )+ 1;  //SLAVE address with RIGHT mode 
					 while((!(I2C_SR1 & (0x1<<1)) && (!(I2C_SR1 & (0x1<<10))))); //wait untill ADDR bit set
				 
					 if(I2C_SR1 & (0x1<<1)) // if ADDR bit is set
					 {
							temp=I2C_SR1; //Read SR1 to clear ADDR bit
							temp=I2C_SR2; //Read SR2 to clear ADDR bit
						 
							for(K=0;K<Size;K++)
							{
										 while(!(I2C_SR1 & (0x01<<6))); //checking RXNE
								 	 Data[K]=I2C_DR;
							}
					}
					
						I2C_CR1 &= ~(0x1<<10);//Disable ACK bit 
						I2C_CR1 |= (0x1<<9);//SET STOP bit CR1
						I2C_CR1 &= ~0x1;//RESET peripheral(PE) Bit	
						//delay5(200);
						return 1;
		  } 
				else
				{	
				 
						I2C_CR1 &= ~(0x1<<10);//Disable ACK bit 
						I2C_CR1 |= (0x1<<9);//SET STOP bit CR1
						I2C_CR1 &= ~0x1;//RESET peripheral(PE) Bit
						delay5(500);
						return 0;
				}	
}


