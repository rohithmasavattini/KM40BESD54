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


/*
void delay (void)
{
	int i;
	for(i=0;i<170000;i++)
	{
		;
	}
}
*/

void Sys_Tick_Init(void)
{
	STK_LOAD = 1600000;   //100msec
	STK_VAL = 10;
	STK_CTRL = 0X05;     // POLLING ,SYS clock 16MHZ,TIMER ENABLE
	
}


int main()
{
	RED_LED_Init();
	Sys_Tick_Init();
	while(1)
	{
		GPIOC_ODR ^= (0x1 << 5);       //Clear PC5 bit to RED LED ON
		//delay();
		while(!(STK_CTRL & 0x10000))    //wait untill 100ms delay
		{
			;
		}	
		GPIOC_ODR ^= (0x1 << 5);        //SET PC5 bit to RED LED OFF
	
		while(!(STK_CTRL & 0x10000))    //wait untill 100ms delay
		{
			;
		}	
	}
	
	return 0;
}
