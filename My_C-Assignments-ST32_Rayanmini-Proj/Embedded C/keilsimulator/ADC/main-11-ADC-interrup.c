#define RCC_AHB1ENR *((int *)(0x40023830))
#define RCC_APB2ENR *((int *)(0x40023844))	
#define GPIOC_MODER *((int *)(0x40020800))
#define ADC_SQR3 *((int *)(0x40012034))	
#define ADC_SMPR1 *((int *)(0x4001200C))	
#define ADC_CR1 *((int *)(0x40012004))	
#define ADC_CR2 *((int *)(0x40012008))	
#define ADC_SR *((int *)(0x40012000))
#define ADC_DR *((int *)(0x4001204C))
	
#define NVIC_ISER0 *((int *)(0xE000E100))

int temp;
int ADC_FLAG=0;
	

void PORTC_Init(void)
{
	RCC_AHB1ENR |= (0x1 << 2);
	while(!(RCC_AHB1ENR & 0x4))
	{
		;
	}
	
	GPIOC_MODER &= ~(0x3 << 10);
	GPIOC_MODER |= (0x3) << 10;      //LOAD 11 BITS IN 11-10 TO SET PC5 ANALOG MODE
}


void ADC_Init(void)
{
	RCC_APB2ENR |= (0x1 << 8);
	while(!(RCC_APB2ENR &(0x1 << 8)))
	{
		;
	}
	
	ADC_SQR3 &= 0xFFFFFFF5;
	ADC_SQR3 |= 0x0000000A;      //LOAD 1010 BITS INTO 3,2,1,0 TO ENABLE 10TH CHANNEL
  
	ADC_SMPR1 |= 0x00000007;     //LOAD 111 IN BIT 0,1,2 TO SELECT 480 CYCLES

  ADC_CR1 |= 0x00C00020;       //LOAD 00 IN 24-25 TO SET 12-BIT RESOLUTION,SET BIT 5 TO INTERRUPT ENABLE    
	
	ADC_CR2 |= 0X00000403;       //LOAD 1 INTO 10,1,0 POS TO ENABLE EOSC,CONTINIOUS MODE,ADON 

	NVIC_ISER0 |= 0x1 << 18;          // SET 18TH BIT TO ENABLE ADC interrupt in NVIC side
}

int main()
{
	PORTC_Init();
	ADC_Init();
	while(1)
	{
		ADC_CR2 |= (0x1 << 30);         //SET 30TH BIT TO REGULLAR CHANNEL CONVERSION
		while(ADC_FLAG==0)              //WAIT UNTILL ADC DATA 
		{
			;
		}
		ADC_FLAG = 0;                  //CLEAR ADC FLAG
		temp = ADC_DR ;                //ADC DATA INTO TEMP GLOBAL VARIABLE
	}
	return 0;
}

void ADC_IRQHandler(void)
{
		if((ADC_SR & 0x2))
		{
			ADC_FLAG = 1;
		}
}
