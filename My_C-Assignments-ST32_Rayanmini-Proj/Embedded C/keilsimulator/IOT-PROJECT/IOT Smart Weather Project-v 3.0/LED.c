#define RCC_AHB1ENR *((int *)(0x40023830))
#define GPIOA_MODER *((int *)(0x40020000))
#define GPIOA_ODR *((int *)(0x40020014))	
#define GPIOC_MODER *((int *)(0x40020800))
#define GPIOC_ODR *((int *)(0x40020814))


void GREEN_LED_Init(void)
{
	RCC_AHB1ENR |= (0X01 << 0);
	while(!(RCC_AHB1ENR & 0x1))            
	{
		;
	}
	GPIOA_MODER &= ~(0x03 << 16);
	GPIOA_MODER |= (0x1 << 16);           //LOAD 01 BITS IN 17-16 TO SET PA8 O/P
}
	


void RED_LED_Init(void)
{
	RCC_AHB1ENR |= (0x1 << 2);
	while(!(RCC_AHB1ENR & 0x4))             
	{
		;
	}
	GPIOC_MODER &= ~(0x03 << 10);         //LOAD 01 BITS IN 11-10 TO SET PC5 O/P  
	GPIOC_MODER |= (0x1 << 10);
}










/*
	
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
		
	*/
	