#define RCC_AHB1ENR *((int *)(0x40023830))
#define GPIOC_MODER *((int *)(0x40020800))
#define RCC_APB2ENR *((int *)(0x40023844))
#define GPIOC_AFRL *((int *)(0x40020820))	
#define USART_CR1 *((int *)(0x4001140C))
#define USART_BRR *((int *)(0x40011408))
#define USART_SR *((int *)(0x40011400))
#define USART_DR *((int *)(0x40011404))
#define NVIC_ISER2 *((int *)(0xE000E108))
	
volatile int RX_Flag=0;
char RX_Buff;
char RX_Buff2;


void PORTC_Init(void)
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
	USART_BRR |= 0x683;                  //BPS 
}

void USART6_IntInit(void)    //INTERRUPR INITIALIZATION
{
	USART_CR1 |= 0x1<<5;       //ENABLE RXNEIE INTERREPT 
	NVIC_ISER2 |=0x1<<7;       //USART6 INTERRUPT NVIC SIDE
}
	
void USART6_IRQHandler(void)
{
		if (USART_SR & 0x20)       //READ STATUS REGISTER  RXNE INTERUPT OCCURE
		{
			RX_Buff = USART_DR;
			RX_Flag = 1;
		}	
}

	
int main()
{
	PORTC_Init();
	USART6_Config();	
	USART6_IntInit();
	while(1)
	{
		while(RX_Flag == 0)
		{
			;
		}
		
		RX_Flag =0;
		RX_Buff2 = RX_Buff;	
	}
}

