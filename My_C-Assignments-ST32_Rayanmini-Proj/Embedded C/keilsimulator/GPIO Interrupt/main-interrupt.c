#define RCC_AHB1ENR *((int *)(0x40023830))
#define GPIOA_PUPDR *((int *)(0x4002000C))
#define RCC_APB2ENR *((int *)(0x40023844))	
#define SYSCFG_EXTICR1 *((int *)(0x40013808))
	
#define EXTI_IMR *((int *)(0x40013C00))
#define EXTI_FTSR *((int *)(0x40013C0C))
#define EXTI_SWIER *((int *)(0x40013C10))	
#define EXTI_PR *((int *)(0x40013C14))	
#define NVIC_ISER0 *((int *)(0xE000E100))
	
int counter=0;

void wakeup_sw_Init(void)
{
	RCC_AHB1ENR |= (0x1 << 0);        //SET 0 BIT TO ENABLE PORT A CLOCK
	while(!(RCC_AHB1ENR & 0x1))       
	{
		;
	}
	
	GPIOA_PUPDR &= 0xFFFFFFFC;        //CLEAR BIT 1-0
	GPIOA_PUPDR |= 0x00000001;        //LOAD 01 BITS IN 1-0 TO ENABLE PULLUP TO PA0 
}


void EXTI0_Init(void)
{
	RCC_APB2ENR |= (0x1 << 14);        //ENABLE SYSCFG CLOCK
	while(!(RCC_APB2ENR & 0x4000))     //WAIT UNTILL PORT A CLOCK ENABLE   
	{
		;
	}
	
	SYSCFG_EXTICR1 &= 0xFFFFFFF0;      //CLEAR 3-0 BITS TO CHOOSE PA0
	
	/* ENABLE PA0 INTERRUPT IN EXTERNALL INTERRUPT SIDE */
	
	EXTI_IMR |= 0x1;                 // SET OTH BIT TO ENABLE PA0 INTERRUPT
	EXTI_FTSR |= 0x1;                // SET OTH BIT TO SET PA0 AS FALLING EDGE TRIGGER INTERRUPT
	
	
	/* ENABLE EXTI0 INTERRUPT IN NVIC SIDE */
	NVIC_ISER0 |= 0x1 << 6;          // SET 6TH BIT TO ENABLE EXTI0
}
	

void delay (void)
{
	int i;
	for(i=0;i<320000;i++)
	{
		;
	}
}


int main()
{
	wakeup_sw_Init();
	EXTI0_Init();
	while(1)
	{
		;
	}
	return 0;
}
	
void EXTI0_IRQHandler(void)
{
	if(EXTI_PR & 0x1)
	{
		counter++;
		EXTI_PR |= 0x1;          //CLEAR PR INTERRUPT ACKNOLEDGMENT
	}
}
