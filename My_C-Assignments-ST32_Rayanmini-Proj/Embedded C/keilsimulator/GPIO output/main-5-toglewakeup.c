#define RCC_AHB1ENR *((int *)(0x40023830))
#define GPIOC_MODER *((int *)(0x40020800))
#define GPIOC_ODR *((int *)(0x40020814))
#define GPIOA_IDR *((int *)(0x40020010))
#define GPIOA_PUPDR *((int *)(0x4002000C))
	
void WAKEUP_REDLED_Init(void);
void delay(void);


int main()
{
	WAKEUP_REDLED_Init();
	
	while(1)
	{
		if(!(GPIOA_IDR & 0x1))
		{
			GPIOC_ODR ^= (0x1 << 5);
	    delay();
		}
		
	}
	return 0;
}
	


void WAKEUP_REDLED_Init(void)
{
	RCC_AHB1ENR |= 0X00000005;
	while(!(RCC_AHB1ENR & 0x5))
	{
		;
	}
	
	GPIOC_MODER &= ~(0x3 << 10);    
	GPIOC_MODER |= (0x1) << 10;         //LOAD 01 BITS IN 11-10 PC5 O/P  
	
	
	GPIOA_PUPDR &= 0xFFFFFFF0;           
	GPIOA_PUPDR |= 0x00000001;          //LOAD 01 BITS 1-0 TO ENABLE PA0 PULLUP
	
}


void delay (void)
{
	int i;
	for(i=0;i<3200000;i++)
	{
		;
	}
}


