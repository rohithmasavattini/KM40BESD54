#define RCC_AHB1ENR *((int *)(0x40023830))
#define GPIOC_MODER *((int *)(0x40020800))
#define GPIOC_PUPDR *((int *)(0x4002080C))
#define GPIOC_ODR *((int *)(0x40020814))
#define GPIOC_IDR *((int *)(0x40020810))
	
void SW1_SW2_REDLED_Init(void);
void delay(void);


int main()
{
	SW1_SW2_REDLED_Init();
	
	while(1)
	{
		if(!(GPIOC_IDR & 0x00000200))
		{
			GPIOC_ODR &= ~(0x1 << 5);
		}
		if(!(GPIOC_IDR & 0x00000100))
		{
			GPIOC_ODR |= 0x1 << 5;
		}
		
		delay();
	}
	return 0;
}
	


void SW1_SW2_REDLED_Init(void)
{
	RCC_AHB1ENR |= (0x1 << 2);
	while(!(RCC_AHB1ENR & 0x4))
	{
		;
	}
	GPIOC_PUPDR &= 0xFFF0FFFF;
	GPIOC_PUPDR |= 0x00050000;
	
	GPIOC_MODER |= (0x1) << 10;
}


void delay (void)
{
	int i;
	for(i=0;i<320000;i++)
	{
		;
	}
}


