#define RCC_AHB1ENR *((int *)(0x40023830))
#define GPIOA_MODER *((int *)(0x40020000))
#define GPIOC_MODER *((int *)(0x40020800))
#define GPIOC_PUPDR *((int *)(0x4002080C))
#define GPIOA_ODR *((int *)(0x40020014))
#define GPIOA_IDR *((int *)(0x40020010))
#define GPIOC_ODR *((int *)(0x40020814))
#define GPIOC_IDR *((int *)(0x40020810))	
#define RCC_APB2ENR *((int *)(0x40023844))
#define GPIOC_AFRL *((int *)(0x40020820))	
#define USART_CR1 *((int *)(0x4001140C))
#define USART_BRR *((int *)(0x40011408))
#define USART_SR *((int *)(0x40011400))
#define USART_DR *((int *)(0x40011404))

char temp;
volatile char RX;
//char data ='R',data1='G';


void delay (void);


void SW_LED_Init(void)
{
	RCC_AHB1ENR |= (0x1 << 2);
	while(!(RCC_AHB1ENR & 0x4))
	{
		;
	}
	GPIOC_MODER &= ~(0x3 << 10);
	GPIOC_MODER |= (0x1) << 10;      //LOAD 01 BITS IN 11-10 TO SET PC5 O/P
	
	GPIOC_PUPDR &= 0xFFF0FFFF;
	GPIOC_PUPDR |= 0x00050000;        //LOAD 01 BITS IN 19-16 TO ENABLE PULLUP TO PC9 & PC8 

	RCC_AHB1ENR |= (0x1 << 0);
	while(!(RCC_AHB1ENR & 0x1))
	{
		;
	}
	GPIOA_MODER &= ~(0x3 << 16);
	GPIOA_MODER |= (0x1 << 16);      //LOAD 01 BITS IN 17-16 TO SET PA8 O/P
	
}


void UART6_Init(void)
{
	RCC_AHB1ENR |= 0x01 << 2;
	while(!(RCC_AHB1ENR & 0x4))
	{
		;
	}
	GPIOC_MODER &= 0xFFFF0FFF;
	GPIOC_MODER |= 0x0000A000;      //LOAD 10 BITS IN 15-11 TO SET PC7,PC6 ALTERNATE FUNCTION MODE
	
}
	
void USART6_Config(void)
{
	RCC_APB2ENR |= 0x1 << 5;             //SET 5TH BIT TO ENABLE USART CLOCK
	while(!(RCC_APB2ENR & (0x1 << 5)))  
	{
		;
	}
	GPIOC_AFRL &= 0x00FFFFFF;            
	GPIOC_AFRL |= 0x88000000;            //LOAD 1000 BITS IN 31-24 TO CHOOSE PC7.PC5 ALTERNATE FUNCTION PORT	 
	USART_CR1  |= 0x0000200C;            //SET 13,3,2 BITS TO ENABLE USART,TX,RX 
	USART_BRR |= 0x683; 

}
	



void USART6_OUTCHAR(unsigned char data)
{	
		while(!(USART_SR & (0x1<<7)))       //READ STATUS REGISTER
	  {
			;
		}
		USART_DR = data;
	  delay();
}

	
char USART6_INCHAR(void)
{
		while (!(USART_SR & (0x1 << 5)))       //READ STATUS REGISTER
		{
			;
		}
		 return USART_DR;                //DR ASSIGN TO VARIABLE
	}
	
void delay (void)
{
	int i;
	for(i=0;i<350000;i++)
	{
		;
	}
}

	
	
int main()
{
	char data='R';
	char data1='G';
	SW_LED_Init();
	UART6_Init();
	USART6_Config();	
	
  GPIOC_ODR |= (0x1 << 5);
	GPIOA_ODR |= (0x1 << 8);
		
	while(1)
	{	
		
		if(!(GPIOC_IDR & 0x00000200)) 
		{	
	    USART6_OUTCHAR(data);
		}
			
		 if(!(GPIOC_IDR & 0x00000100))
		{
			USART6_OUTCHAR(data1);			
		}
		//delay();
		
		
		temp=USART6_INCHAR();
		
			if(temp == 'R')
		{
			GPIOC_ODR &= ~(0x1 << 5);
		}
		  if(temp == 'G')
		{
			GPIOA_ODR &= ~(0x1 << 8);
		}
	}
	}

	