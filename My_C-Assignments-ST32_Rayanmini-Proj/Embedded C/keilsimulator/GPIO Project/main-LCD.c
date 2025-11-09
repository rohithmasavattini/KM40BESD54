#define RCC_AHB1ENR *((int *)(0x40023830))
#define GPIOB_MODER *((int *)(0x40020400))
#define GPIOB_ODR *((int *)(0x40020414))


void delay1(int);
void PORTB_Init(void);
void LCD_Init(void);
void Write_High_nibble(unsigned char);
void Write_Low_nibble(unsigned char);

void KM_LCD_Write_Cmd(unsigned char);
void KM_LCD_Write_Data(unsigned char);

	

void PORTB_Init(void)
{
	RCC_AHB1ENR |= (0x1 << 1);
	while(!(RCC_AHB1ENR & 0x2))
	{
		;
	}
	GPIOB_MODER &= 0xFFFEF500;
	GPIOB_MODER |= 0x00010555;        
	

}


void delay(void)
{
	int i;
	for(i=0;i<8500;i++)
	{
		;
	}
}

void delay1(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
	for(i=0;i<1700;i++)
	{
		;
	}
}
}
void delay2(void)
{
	int i;
	for(i=0;i<17000;i++)
	{
		;
	}
}



void LCD_Init(void)
{
	delay();
	KM_LCD_Write_Cmd(0x33);
	delay1(10);
	KM_LCD_Write_Cmd(0x32);
	delay1(10);
	KM_LCD_Write_Cmd(0x28);
	delay1(10);
  KM_LCD_Write_Cmd(0x0C);
  KM_LCD_Write_Cmd(0x01);
}



void KM_LCD_Write_Cmd(unsigned char cmd)
{
  GPIOB_ODR &= ~(0x01 << 4);
	
	Write_High_nibble(cmd);
	Write_Low_nibble(cmd);
	
}


void KM_LCD_Write_Data(unsigned char data)
{
	
	GPIOB_ODR |= (0x01 << 4);
	
	Write_High_nibble(data);
	Write_Low_nibble(data);
	
}
	

void Write_High_nibble(unsigned char data)
{
	GPIOB_ODR &= ~(0x0F);
	GPIOB_ODR |= ((data>>4) & 0x0F);
	GPIOB_ODR |= 0x1<<8;
	delay1(5);
	GPIOB_ODR &= ~(0x01<<8);
}
	

	
void Write_Low_nibble(unsigned char data)
{
	GPIOB_ODR &= ~(0x0F); 
	GPIOB_ODR |=(data & 0x0F);
	GPIOB_ODR |= 0x1 << 8;
	delay1(5);
	GPIOB_ODR &= ~(0x01 << 8);
}



int main()
{
	PORTB_Init();
	LCD_Init();
	KM_LCD_Write_Cmd(0x01);
	KM_LCD_Write_Cmd(0x80);
	KM_LCD_Write_Data('A');
	
	return 0;
}
	
