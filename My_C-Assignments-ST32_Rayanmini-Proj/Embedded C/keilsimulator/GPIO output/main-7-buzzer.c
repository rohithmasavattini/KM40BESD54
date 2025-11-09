#define RCC_AHB1ENR *((int *)(0x40023830))
#define GPIOB_MODER *((int *)(0x40020400))
#define GPIOA_IDR *((int *)(0x40020010))
#define GPIOA_PUPDR *((int *)(0x4002000C))
#define GPIOB_ODR *((int *)(0x40020414))
	
void BUZZER(void);
void delay(void);


int main()
{
	BUZZER();
	
	while(1)
	{
		GPIOB_ODR &= ~(0x1 << 12);
		if(!(GPIOA_IDR & 0x1))
		{
			GPIOB_ODR |= (0x1 << 12);
		
		delay();
		}
	}
	return 0;
}
	


void BUZZER(void)
{
	RCC_AHB1ENR |= 0x00000003;
	while(!(RCC_AHB1ENR & 0x3))
	{
		;
	}
	
	GPIOB_MODER &= ~(0x1 << 24);
	GPIOB_MODER |= (0x1) << 24;      //load 01 bits in 25-24
	
	//GPIOB_MODER &= 0xF0FFFFFF;
	//GPIOB_MODER |= 0x01000000;
	
	GPIOA_PUPDR &= 0xFFFFFFF0;
	GPIOA_PUPDR |= 0x00000001;        // LOAD 01 BITS IN 1-0 TO ENABLE WAKEUP SW PULLUP
	
	//GPIOA_PUPDR &= ~(0x1 << 0);
	//GPIOA_PUPDR |= (0x1) << 0;
	
}


void delay (void)
{
	int i;
	for(i=0;i<425000;i++)
	{
		;
	}
}


