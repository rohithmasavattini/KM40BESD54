#define RCC_AHB1ENR *((int *)(0x40023830))
#define GPIOA_MODER *((int *)(0x40020000))
#define GPIOC_MODER *((int *)(0x40020800))
#define GPIOC_PUPDR *((int *)(0x4002080C))
#define GPIOA_ODR *((int *)(0x40020014))
#define GPIOA_IDR *((int *)(0x40020010))
#define GPIOC_ODR *((int *)(0x40020814))
#define GPIOC_IDR *((int *)(0x40020810))
//#define GPIOA_PUPDR *((int *)(0x4002000C))	
	
void SW1_REDLED_Init(void);
void SW2_GREENLED_Init(void);
void delay(void);


int main()
{
	SW1_REDLED_Init();
	SW2_GREENLED_Init();
	while(1)
	{
		GPIOC_ODR |= (0x1 << 5);
		GPIOA_ODR |= (0x1 << 8);
		if(!(GPIOC_IDR & 0x00000200))
		{
			GPIOC_ODR &= ~(0x1 << 5);
		}
		
		if(!(GPIOC_IDR & 0x00000100))
		{
			GPIOA_ODR &= ~(0x1 << 8);
		}
		
		delay();
	}
	return 0;
}
	


void SW1_REDLED_Init(void)
{
	RCC_AHB1ENR |= (0x1 << 2);
	while(!(RCC_AHB1ENR & 0x4))
	{
		;
	}
	GPIOC_MODER &= ~(0x3 << 10);
	GPIOC_MODER |= (0x1) << 10;      //LOAD 01 BITS IN 11-10 TO SET PC5 O/P
		
	 //GPIOC_PUPDR &= ~(0x5 << 16);
 	//GPIOC_PUPDR |= (0x5 << 16);
	
	GPIOC_PUPDR &= 0xFFF0FFFF;
	GPIOC_PUPDR |= 0x00050000;        //LOAD 01 BITS IN 19-16 TO ENABLE PULLUP TO PC9 & PC8 
}


void SW2_GREENLED_Init(void)
{
	RCC_AHB1ENR |= (0x1 << 0);
	while(!(RCC_AHB1ENR & 0x1))
	{
		;
	}
	GPIOA_MODER &= ~(0x3 << 16);
	GPIOA_MODER |= (0x1 << 16);      //LOAD 01 BITS IN 17-16 TO SET PA8 O/P
	
}


void delay (void)
{
	int i;
	for(i=0;i<340000;i++)
	{
		;
	}
}


