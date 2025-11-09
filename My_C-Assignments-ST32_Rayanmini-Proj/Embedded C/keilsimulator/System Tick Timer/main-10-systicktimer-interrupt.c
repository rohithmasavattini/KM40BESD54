#define RCC_AHB1ENR *((int *)(0x40023830))
#define GPIOC_MODER *((int *)(0x40020800))
#define GPIOC_ODR *((int *)(0x40020814))
		
#define STK_CTRL *((volatile int *)(0xE000E010))
#define STK_LOAD *((volatile int *)(0xE000E014))
#define STK_VAL *((volatile int *)(0xE000E018))


void RED_LED_Init(void)
{
	RCC_AHB1ENR |= (0x1 << 2);           //SET 2nd bit position to enable to PORT C clock
 	while(!(RCC_AHB1ENR & 0x4))          //wait untill PORT C clock enable 
	{
		;
	}
	GPIOC_MODER &= ~(0x03 << 10);        //clear 11-10 bits
	GPIOC_MODER |= (0x1 << 10);          //load 01 bits in 11,10 to PC5 o/p direction 

}

void Sys_Tick_Init(void)
{
	
	STK_CTRL |= 0x7;     // Interrupt ,SYS clock 16MHZ,TIMER ENABLE
	STK_VAL = 0x1;
	STK_LOAD = 1600000;   //100msec
}


int main()
{
	RED_LED_Init();
	Sys_Tick_Init();
	while(1)
	{
    ;
	}
		return 0;
}
	
	
void SysTick_Handler(void)
{
		GPIOC_ODR ^= (0x1 << 5);       //toggle PC5 bit
		
}
