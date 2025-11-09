void I2C_Init(void);
void I2C_Config(void);

int KM_I2C_Mem_Write(short int DevAddress,short int MemAddress,short int MemAddsize,unsigned char *pData,short int len);
int KM_I2C_Mem_Read(short int DevAddress,short int MemAddress,short int MemAddsize,unsigned char *Rx,short int size);

void LCD_TIME(void);
void LCD_DATE(void);	

void USART1_Init(void);
void USART1_Config(void);


int WIFI_SERVER(void);
int WIFI_ONOFF(void);

void GREEN_LED_Init(void);
void RED_LED_Init(void);
