#define RCC_AHB1ENR *((int *)(0x40023830))
#define GPIOC_MODER *((int *)(0x40020800))
#define GPIOC_ODR *((int *)(0x40020814))
	
void RED_LED_Init(void);
void delay(void);


int main()
{
	RED_LED_Init();
	
	while(1)
	{
		GPIOC_ODR &= ~(0x1 << 5);
		delay();
		GPIOC_ODR |= (0x1 << 5);
		delay();
	}
	return 0;
}
	


void RED_LED_Init(void)
{
	RCC_AHB1ENR |= (0x1 << 2);
	while(!(RCC_AHB1ENR & 0x4))
	{
		;
	}
	GPIOC_MODER &= ~(0x03 << 10);
	GPIOC_MODER |= (0x1 << 10);
}


void delay (void)
{
	int i;
	for(i=0;i<170000;i++)
	{
		;
	}
}


