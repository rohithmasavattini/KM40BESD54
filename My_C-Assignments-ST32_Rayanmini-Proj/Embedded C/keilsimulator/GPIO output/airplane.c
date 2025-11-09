#define RCC_AHB1ENR *((int *)(0x40023830))
#define GPIOA_MODER *((int *)(0x40020000))
#define GPIOA_ODR *((int *)(0x40020014))	
#define GPIOC_MODER *((int *)(0x40020800))
#define GPIOC_ODR *((int *)(0x40020814))

void GREEN_LED_Init(void);
void RED_LED_Init(void);
void delay(void);
void delay1(void);
void delay2(void);
void delay3(void);

int main()
{
	GREEN_LED_Init();
	RED_LED_Init();
	while(1)
	{
		
		GPIOA_ODR &= ~(0x1 << 8);
		delay();
		GPIOA_ODR |= (0x1 << 8);
		delay();
		GPIOA_ODR &= ~(0x1 << 8);
		delay();
		GPIOA_ODR |= (0x1 << 8);
		delay1();
		
		
	
		GPIOC_ODR &= ~(0x1 << 5);
		delay();
		GPIOC_ODR |= (0x1 << 5);
		delay2();
		GPIOC_ODR &= ~(0x1 << 5);
		delay();
		GPIOC_ODR |= (0x1 << 5);
		delay3();
		
	}
	return 0;
}
	

void GREEN_LED_Init(void)
{
	RCC_AHB1ENR |= (0X01 << 0);
	while(!(RCC_AHB1ENR & 0x1))
	{
		;
	}
	GPIOA_MODER &= ~(0x03 << 16);
	GPIOA_MODER |= (0x1 << 16);
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
	for(i=0;i<85000;i++)
	{
		;
	}
}

void delay1(void)
{
	int i;
	for(i=0;i<255000;i++)
	{
		;
	}
}

void delay2(void)
{
	int i;
	for(i=0;i<425000;i++)
	{
		;
	}
}

void delay3(void)
{
	int i;
	for(i=0;i<850000;i++)
	{
		;
	}
}

