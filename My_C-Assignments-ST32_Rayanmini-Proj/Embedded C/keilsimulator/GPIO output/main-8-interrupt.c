#define RCC_AHB1ENR *((int *)(0x40023830))
#define RCC_APB2ENR *((int *)(0x40023844))	
#define SYSCFG_EXTICR1 *((int *)(0x40013808))
#define SYSCFG_EXTICR3 *((int *)(0x40013810))	

#define GPIOA_MODER *((int *)(0x40020000))
#define GPIOC_MODER *((int *)(0x40020800))
#define GPIOC_PUPDR *((int *)(0x4002080C))
#define GPIOA_PUPDR *((int *)(0x4002000C))	
#define GPIOC_ODR *((int *)(0x40020814))
#define GPIOA_ODR *((int *)(0x40020014))	
#define GPIOC_IDR *((int *)(0x40020810))	

#define EXTI_IMR *((int *)(0x40013C00))
#define EXTI_FTSR *((int *)(0x40013C0C))
#define EXTI_SWIER *((int *)(0x40013C10))	
#define EXTI_PR *((int *)(0x40013C14))	
#define NVIC_ISER0 *((int *)(0xE000E100))
	
int counter=0;
void delay (void);


void SW1_Init(void)
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
	
	GPIOC_PUPDR &= 0xFFF3FFFF;
	GPIOC_PUPDR |= 0x00040000;        //LOAD 01 BITS IN 19-18 TO ENABLE PULLUP TO PC9
}


void SW2_Init(void)
{
	RCC_AHB1ENR |= (0x1 << 0);
	while(!(RCC_AHB1ENR & 0x1))
	{
		;
	}
	GPIOA_MODER &= ~(0x3 << 16);
	GPIOA_MODER |= (0x1 << 16);      //LOAD 01 BITS IN 17-16 TO SET PA8 O/P
		
	GPIOA_PUPDR &= 0xFFFCFFFF;
	GPIOA_PUPDR |= 0x00010000;

}




void EXTI9_Init(void)
{
	RCC_APB2ENR |= (0x1 << 14);        //ENABLE SYSCFG CLOCK
	while(!(RCC_APB2ENR & 0x4000))     //WAIT UNTILL PORT A CLOCK ENABLE   
	{
		;
	}
	
	SYSCFG_EXTICR3 &= 0xFFFFFF2F;      //CLEAR 7-4 BITS TO CHOOSE PC9
	
	/* ENABLE PC9 INTERRUPT IN EXTERNALL INTERRUPT SIDE */
	
	EXTI_IMR |= 0x1 << 9;                 // SET 9TH BIT TO ENABLE PC9 INTERRUPT
	EXTI_FTSR |= 0x1 << 9;                // SET 9TH BIT TO SET PC9 AS FALLING EDGE TRIGGER INTERRUPT
	
	
	/* ENABLE EXTI0 INTERRUPT IN NVIC SIDE */
	NVIC_ISER0 |= 0x1 << 23;          // SET 23TH BIT TO ENABLE EXTI9
}
	


void EXTI8_Init(void)
{
	RCC_APB2ENR |= (0x1 << 14);        //ENABLE SYSCFG CLOCK
	while(!(RCC_APB2ENR & 0x4000))     //WAIT UNTILL PORT A CLOCK ENABLE   
	{
		;
	}
	
	SYSCFG_EXTICR3 &= 0xFFFFFFF2;      //CLEAR 3-0 BITS TO CHOOSE PC9
	
	/* ENABLE PC8 INTERRUPT IN EXTERNALL INTERRUPT SIDE */
	
	EXTI_IMR |= 0x1 << 8;                 // SET 8TH BIT TO ENABLE PC8 INTERRUPT
	EXTI_FTSR |= 0x1 << 8;                // SET 8TH BIT TO SET PC8 AS FALLING EDGE TRIGGER INTERRUPT
	
	
	/* ENABLE EXTI0 INTERRUPT IN NVIC SIDE */
	NVIC_ISER0 |= 0x1 << 23;          // SET 23TH BIT TO ENABLE EXTI8
}



int main()	
{
	EXTI9_Init();
	SW1_Init();
	EXTI8_Init();
	SW2_Init();
	while(1)
	{
		;
	}
	return 0;
}
	

void EXTI9_5_IRQHandler(void)
{
	if(EXTI9_5_IRQHandler)
	{
	if(EXTI_PR & 0x00000200)
	{
		//counter++;
	  GPIOC_ODR ^= (0x1 << 5);
		
		EXTI_PR |= 0x1 << 9;          //CLEAR PR INTERRUPT ACKNOLEDGMENT
	}
	else if(EXTI_PR & (0x1 << 8))
	{
		//counter++;	
		GPIOA_ODR ^= (0x1 << 8);
		EXTI_PR |= 0x1 << 8;
	}
}
	delay();
}




void delay (void)
{
	int i;
	for(i=0;i<320000;i++)
	{
		;
	}
}
