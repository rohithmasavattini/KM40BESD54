#include "LCDh.h"
#include "ADCh.h"
#include "I2C.h"
#include<stdio.h>
#define GPIOC_ODR *((int *)(0x40020814))
#define GPIOA_ODR *((int *)(0x40020014))
	
void KM_rtc_print_lcd(void);
unsigned char Date[]={0x55,0x32,0x11,0x7,0x1,0x5,0x21};    //SEC,MIN,HOUR,WEEK DAY,DATE,MON,YEAR
unsigned char rtc_data[20];
unsigned char eeprom_buff[]={0x10,0x32,0x11};
unsigned char eeprom_data[20];
char Temp_Value[2];
unsigned int Temp,x;
int ret;
void i2afun();

void km_delay(int ms)
 {
	int i;
	for(i=0;i<1670*ms;i++);
 } 




void TASK_1(void)
 {
	 KM_I2C_Mem_Read(0x68,0x00,0x01,rtc_data,7); 
	 KM_rtc_print_lcd();
 }

 
void TASK_2(void)
 { 
	 if((rtc_data[0]%5) == 0)
	 {
	 Temp=ADC_READTEMP();					
	 } 
 }


void TASK_3(void)
{
	if((rtc_data[1]) != 0x32)
	{	
	ret=WIFI_ONOFF();          //WIFI CHECKING 	
			if(ret == 1)
			{
			GPIOA_ODR |= (0x1 << 8);	
			GPIOC_ODR &= ~(0x1 << 5);
			DISPLAY_TEMP();		
			LCD_Write_Cmd(0xCA);	
			LCD_String((unsigned char *)"ERROR");
			KM_I2C_Mem_Read(0x50,0x00,0x08,eeprom_data,7);	
			km_delay(500);
			}
	}	
}


void TASK_4(void)
{ 
	 ret=WIFI_ONOFF();   //WIFI CHECKING
	 if(ret == 0)
		 {
		  LCD_Write_Cmd(0xCA);
			GPIOA_ODR &= ~(0x1 << 8);
			GPIOC_ODR |= (0x1 << 5);		
			LCD_String((unsigned char *)"OK");
			DISPLAY_TEMP();
			km_delay(500);
		 }
 
}
	
	
int main()
{
	GREEN_LED_Init();
	RED_LED_Init();
	GPIOC_ODR |= (0x1 << 5);
	GPIOA_ODR |= (0x1 << 8);
	
	I2C_Init();
  I2C_Config();
	
	LCD_PORTB_Init();
	LCD_Init();
	
	ADC_PORT_Init();
	ADC_Init();
	
	USART1_Init();
  USART1_Config();
	
	 WIFI_SERVER();      //Please connect WIFI NETWORK-password
	 WIFI_ONOFF();
	
	x=ADC_READTEMP();
	i2afun(x);
	 
	   
 	  LCD_Write_Cmd(0x01);
    LCD_Write_Cmd(0x80);
  	LCD_String((unsigned char *) "KM40BESD54");
		LCD_Write_Cmd(0xC0);
		LCD_String((unsigned char *) "M ROHITH");
  	km_delay(1000);


    LCD_Write_Cmd(0x01);
    LCD_Write_Cmd(0x80);
  	LCD_String((unsigned char *) "Smart Weather");
  	LCD_Write_Cmd(0xC0);
		LCD_String((unsigned char *) "Project 3.0 Ver");
		km_delay(1000);

	
	ret = KM_I2C_Mem_Write(0x50,0x00,0x08,eeprom_buff,7);
	 if (ret == 0)
	 {
	  	LCD_Write_Cmd(0x01);
		  LCD_Write_Cmd(0x80);
			LCD_String((unsigned char *) "EEPROM NACK");
		 	km_delay(800);
	 }
	 else
	 {
	 	  LCD_Write_Cmd(0x01);
		  LCD_Write_Cmd(0x80);
			LCD_String((unsigned char *)"EEPROM WRITE");
			km_delay(800);
	 }
	 ret = KM_I2C_Mem_Write(0x68,0x00,0x01,Date,7);
	 if (ret == 0)
	 {
	  	LCD_Write_Cmd(0x01);
		  LCD_Write_Cmd(0x80);
			LCD_String((unsigned char *)"RTC NOT FOUND");
		 	km_delay(800);
	 }
	 else
	 {
	 	  LCD_Write_Cmd(0x01);
		  LCD_Write_Cmd(0x80);
			LCD_String((unsigned char *)"RTC WRITE DONE");
			km_delay(800);
	 }
		
	 
	 while(1)
	 { 
			
		 TASK_1(); 
		 TASK_2();
		 TASK_3();
		 TASK_4();	  
		
   }
		return 0;

}


void KM_rtc_print_lcd(void)
{
 		  LCD_Write_Cmd(0x01);
		  LCD_Write_Cmd(0x80);

		 	//LCD_String((unsigned char *)"TIME: ");
			sprintf(Temp_Value, "%d",rtc_data[2]-6*(rtc_data[2]>>4));
		  LCD_String((unsigned char *)Temp_Value);
		  LCD_Write_Data(':');
		  sprintf(Temp_Value, "%d",rtc_data[1]-6*(rtc_data[1]>>4));
		  LCD_String((unsigned char *)Temp_Value);
		  LCD_Write_Data(':');
			km_delay(10);
		  sprintf(Temp_Value, "%d",rtc_data[0]-6*(rtc_data[0]>>4));
		  LCD_String((unsigned char *)Temp_Value);
		
			LCD_Write_Cmd(0xC0);
			//LCD_String((unsigned char *)"DATE: ");
			sprintf(Temp_Value, "%d",rtc_data[4]-6*(rtc_data[4]>>4));
			LCD_String((unsigned char *) Temp_Value);
			LCD_Write_Data(':');
			sprintf(Temp_Value, "%d",rtc_data[5]-6*(rtc_data[5]>>4));
			LCD_String((unsigned char *)Temp_Value);
			LCD_Write_Data(':');
			sprintf(Temp_Value, "%d",rtc_data[6]-6*(rtc_data[6]>>4));
			LCD_String((unsigned char *)Temp_Value);
			

}


void i2afun(int d)
{
	
int i,j;
char arr[2];
for(i=0;d>0;i++)
{
	arr[i] = d%10 + '0';
	d=d/10;
}

for(i=i-1;i>=0;i--)
{
	int n=3;
	eeprom_buff[n]=arr[i];
}
}
