#define RCC_AHB1ENR *((int *)(0x40023830))
#define GPIOB_MODER *((int *)(0x40020400))
#define GPIOB_ODR *((int *)(0x40020414))

void LCD_PORTB_Init(void);
void LCD_Init(void);
void LCD_Write_Cmd(unsigned char);
void LCD_Write_Data(unsigned char);
void Write_High_nibble(unsigned char);
void Write_Low_nibble(unsigned char);

char a[2];

void LCD_PORTB_Init(void)
{
	RCC_AHB1ENR |= (0x1 << 1);
	while(!(RCC_AHB1ENR & 0x2))
	{
		;
	}
	GPIOB_MODER &= 0xFFFEF500;
	GPIOB_MODER |= 0x00010555;        
}


void delay3(void)
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
	delay3();
	LCD_Write_Cmd(0x33);
	delay1(10);
	LCD_Write_Cmd(0x32);
	delay1(10);
	LCD_Write_Cmd(0x28);
	delay1(10);
  LCD_Write_Cmd(0x0C);
  LCD_Write_Cmd(0x01);
}


void LCD_Write_Cmd(unsigned char cmd)
{
  GPIOB_ODR &= ~(0x01 << 4);
	
	Write_High_nibble(cmd);
	Write_Low_nibble(cmd);
	
}


void LCD_Write_Data(unsigned char data)
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

void LCD_String(char *str)
{
	int i;
	for(i=0;str[i]!=0;i++)
	{
		LCD_Write_Data(str[i]);
	}		
}

void i2a(int d)
{
int i;
for(i=0;d>0;i++)
{
	a[i] = d%10 + 0x30;
	d=d/10;
}
for(i=i-1;i>=0;i--)
{
	LCD_Write_Data(a[i]);
}
}

/*
void i22a(int d)
{
int i=0;
LCD_Write_Data(a[i]+1);
}*/


