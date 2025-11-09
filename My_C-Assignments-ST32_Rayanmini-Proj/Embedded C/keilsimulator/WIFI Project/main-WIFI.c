#include<stdio.h>
#define RCC_AHB1ENR *((int *)(0x40023830))
#define GPIOA_MODER *((int *)(0x40020000))
#define RCC_APB2ENR *((int *)(0x40023844))
#define GPIOA_AFRH *((int *)(0x40020024))	

#define USART_CR1 *((int *)(0x4001100C))
#define USART_BRR *((int *)(0x40011008))
#define USART_SR *((int *)(0x40011000))
#define USART_DR *((int *)(0x40011004))

char USART1_Inchar(void);
int USART1_InString_OK(void);

char FETCH[100];
char RX[550];

void USART1_Init(void)
{
	RCC_AHB1ENR |= (0x01 << 0);
	while(!(RCC_AHB1ENR & 0x1))
	{
		;
	}
	GPIOA_MODER |= 0x2 << 20;
	GPIOA_MODER |= 0x2 << 18;      //LOAD 10 BITS IN 21,20,19,18 TO SET PA10,PA9 ALTERNATE FUNCTION MODE
	
}
	
	
void USART1_Config(void)
{
	RCC_APB2ENR |= 0x1 << 4;             //SET 4TH BIT TO ENABLE USART1 CLOCK
	while(!(RCC_APB2ENR & (0x1 << 4)))  
	{
		;
	}           
	GPIOA_AFRH |= 0x00000770;            //LOAD 0111 BITS IN 11-4 TO CHOOSE PA10.PA9 ALTERNATE FUNCTION PORT
	 
	USART_CR1  |= 0x0000200C;            //SET 13,3,2 BITS TO ENABLE USART,TX,RX 
	USART_BRR |= 0x8B; 

}
	

char USART1_Inchar(void)
{	
		while (!(USART_SR & (0x1 << 5)))       //READ STATUS REGISTER
		{
			;
		}
		 return USART_DR;                //DR ASSIGN TO VARIABLE
	}		
	

void USART1_OUTChar(unsigned char data)
{	
		while(!(USART_SR &(0x1 << 7)))       //READ STATUS REGISTE
		{
			;
		}
		 USART_DR = data;                //DATA ASSIGN TO DR		
}		

	
void USART1_OutString(char str[])	
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
	  USART1_OUTChar(str[i]);
	}
}


int USART1_WIFI_Responce_OK()
{
	int i;
	for(i=0;i<500;i++)
	{
		RX[i] = USART1_Inchar();
		if(RX[i-1] == 'O' && RX[i] == 'K')
		{
			return 1;
		}
	}
		return 0;
}

int delay(int ms)
{
	int i;
	for(i=0;i<1670*ms;i++);
  
} 

	
void Clear_Buff(void)
{
	int i;
	for(i=0;i<550;i++)
	RX[i]=0;
}

int main()
{
	int i;
	USART1_Init();
  USART1_Config();
	Clear_Buff();
	
		USART1_OutString("AT\r\n");	
	  if(USART1_WIFI_Responce_OK()==0)
		return 1;
		Clear_Buff();
		
		USART1_OutString("AT+RST\r\n");
	//	if(USART1_WIFI_Responce_OK()==0)
	//	return 1;
		delay(1000);
		Clear_Buff();
	  
		
		USART1_OutString("AT+CWMODE=3\r\n");
		if(USART1_WIFI_Responce_OK()==0)
		return 1;
		Clear_Buff();
	
		USART1_OutString("AT+CWJAP=\"Masavattini\",\"9441357279\"\r\n");
		if(USART1_WIFI_Responce_OK()==0)
		return 1;
		Clear_Buff();
	
		USART1_OutString("AT+CIFSR\r\n");
	  if(USART1_WIFI_Responce_OK()==0)
		return 1;
		Clear_Buff();
	
		USART1_OutString("AT+CIPMUX=0\r\n");
		if(USART1_WIFI_Responce_OK()==0)
		return 1;
		Clear_Buff();
		
	/*	USART1_OutString("AT+CWLAP\r\n");
		if(USART1_WIFI_Responce_OK()==0)
		return 1;
		Clear_Buff(); */
	
		USART1_OutString("AT+CIPMODE=0\r\n");
		if(USART1_WIFI_Responce_OK()==0)
		return 1;
		
		while(1)
		{
		Clear_Buff();	
		USART1_OutString("AT+CIPSTATUS\r\n");
		if(USART1_WIFI_Responce_OK()==0)
		return 1;
		Clear_Buff();
		
		USART1_OutString("AT+CIPSTART=\"TCP\",\"142.93.218.33\",80\r\n");
		if(USART1_WIFI_Responce_OK()==0)
		return 1;
		sprintf(FETCH,"GET /page.php?temp=27&hum=50&dev=54\r\n\r\n");
		USART1_OutString("AT+CIPSEND=39\r\n");
		for(i=0;i<100;i++)
		{
			RX[i]= 	USART1_Inchar();
		  if(RX[i] == '>')
			{
				USART1_OutString(FETCH);
				break;
			}
		}
		delay(4000);
		Clear_Buff();
			
		USART1_OutString("AT+CIPCLOSE\r\n");
		delay(4000);	
		for(i=0;i<50;i++)
		delay(100);
		
	}
		return 0;
}