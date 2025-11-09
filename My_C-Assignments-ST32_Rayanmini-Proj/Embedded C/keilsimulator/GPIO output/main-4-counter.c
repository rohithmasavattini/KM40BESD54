#define RCC_AHB1ENR *((int *)(0x40023830))
#define GPIOC_MODER *((int *)(0x40020800))
#define GPIOC_ODR *((int *)(0x40020814))
#define GPIOA_IDR *((int *)(0x40020010))
#define GPIOA_PUPDR *((int *)(0x4002000C))
	
void WAKEUP_REDLED_Init(void);
void delay(void);
int counter = 0;

int main()
{
	WAKEUP_REDLED_Init();
	
	while(1)
	{
		GPIOC_ODR |= (0x1 << 5);
		if(!(GPIOA_IDR & 0x1))
		{
			counter++;
			GPIOC_ODR &= ~(0x1 << 5);
		}
		
		delay();
	}
	return 0;
}
	


void WAKEUP_REDLED_Init(void)
{
	RCC_AHB1ENR |= 0x00000005;
	while(!(RCC_AHB1ENR & 0x5))
	{
		;
	}
	
	GPIOC_MODER &= ~(0x3 << 10);       
	GPIOC_MODER |= (0x1) << 10;               //LOAD 01 BITS IN 11-10 TO SET PC5 O/P
	
	GPIOA_PUPDR &= 0xFFFFFFF0;
	GPIOA_PUPDR |= 0x00000001;                //LOAD O1 BITS IN 1-0 TO ENABLE PULLUP PA0
	
	//GPIOA_PUPDR &= ~(0x1 << 0);
	//GPIOA_PUPDR |= (0x1) << 0;
	
}


void delay (void)
{
	int i;
	for(i=0;i<350000;i++)
	{
		;
	}
}


