/**
  ******************************************************************************
  * Ten Tep		:		  main.h
  * Tac Gia		:	  	LE ANH QUANG
  * Cong Ty		:			MinhHaGroup
  *	Website 	:			MinhHaGroup.com
  * Phien Ban	:			V1.0.0
  * Ngay			:    	19-10-2012
  * Tom Tat   :     Chuong trinh chinh, thuc hien cac chuc nang cua KIT89s52 V3
  *           
  *
  ******************************************************************************
  * Chu Y		:
  *							 
  ******************************************************************************
  */
	

#include <main.h>	
#include <var.h>

void main()
{
	unsigned char hour,minute,second,day,date,month,year;
	lcd1602_init();
	lcd1602_clear();
	lcd1602_gotoxy(0,0);
	lcd1602_puts("  THALEGROUP");
	lcd1602_gotoxy(0,1);
	lcd1602_puts(" TEST KIT 89S52"); 


while(1)
{
	KEY = mtp_quetphim();
	

// AN SW0: TEST MA TRAN BAN PHIM ==============================================
	if(KEY=='0')	
	{
		lcd1602_init();
		lcd1602_clear();
		lcd1602_gotoxy(0,0);
		while(1)
		{
			KEY = mtp_quetphim();
			if(KEY)
			{
				lcd1602_putchar(KEY);
			}
		}
	}

if(KEY=='1')
{
	unsigned int k;
    lcd1602_init();
	sprintf(Lcd_Buff,"TEST KEY DON");
	lcd1602_gotoxy(0,0);
    lcd1602_puts(Lcd_Buff);
    while(1)
    {
        k=get_key();
        if(k)
        {
            sprintf(str,"KEY=%2u",k);
            lcd1602_gotoxy(0,1);
            lcd1602_puts(str);
        }
    }
}

// AN SW1: TEST LED DON ========================================================	
	if(KEY=='2')	// SW1: TEST LED DON
	{
		while(1)
		{
		for (i=0;i<8;i++)
		{
			LED_DON = ~(0x80>>i);
			delay_ms(300);
		}
		}
	}

// AN SW2: TEST COI CHIP & RELAY ================================================			
	if(KEY=='3')	
	{
		COI = 0;
		RELAY = 0;
		//FLAG = 0;
		while(1)
		{
			/*
			if(!KEY0)		// AN SW16
			{
				delay_ms(3000);
				COI=~COI;		
				RELAY =~RELAY ;
				delay_ms(10000);
				//TODO
				KEY0 = 1;
				if(!KEY0)
				{
					while(!KEY0);
					COI=~COI;		
					RELAY =~RELAY ;
					delay_ms(3000);
				}
				
			}
			*/
			if(COI) {
				COI=~COI;		
				RELAY =~RELAY ;
				lcd1602_init();
				sprintf(Lcd_Buff,"WAIT 10s");
				lcd1602_gotoxy(0,0);
			    lcd1602_puts(Lcd_Buff);	
			//	LED7_DATA = 0;
			//	LED7_SEG = 0x0077; //0x0A<<3; 10s
				delay_ms(9000);			
			} else { 
				COI=~COI;		
				RELAY =~RELAY ;
				lcd1602_init();
				sprintf(Lcd_Buff,"WAIT 3s");
				lcd1602_gotoxy(0,0);
			    lcd1602_puts(Lcd_Buff);
			//	LED7_DATA = 3;
			//	LED7_SEG = 0x0079; //0x0003<<4; 
				delay_ms(2700);
			}
		}
	}
	
// AN SW3: TEST DS18B20 =========================================================	
	if(KEY=='4')	
	{
		lcd1602_init();
		lcd1602_clear();
		while(1)
		{
			Nhiet_Do = ds18b20_readtemp();		
			sprintf(Lcd_Buff," TEMP: %2.2f^C",Nhiet_Do);
			lcd1602_gotoxy(0,0);
			lcd1602_puts(Lcd_Buff);
			delay_ms(300);
		}
	}
	
// AN SW3: TEST LED7 THANH ======================================================	
	if(KEY=='5')	
	{
			while(1)
			{
			LED7_DATA=0;
			
			for (i=0;i<2;i++)
			{
				LED7_SEG= ~(0x80>>6);
				//delay_ms(300);
			}
			
			/*
			LED7_SEG=0;
			for (i=0;i<2;i++)
			{
				LED7_DATA= ~(0x01<<i);
				delay_ms(300);
			} */
		    }
	}

// AN SW3: TEST UART =============================================================			
	if(KEY=='6')	
	{
			UART_Init();
			lcd1602_init();
			lcd1602_clear();
			EA=1;
			UART_Puts("MINHHAGROUP");
			
			while(1)
			{
			    Uart_char = UART_GetChar();
				if(Uart_char)
				{
				//UART_PutChar(Uart_char);
				lcd1602_gotoxy(3,1);
				lcd1602_putchar(Uart_char);
				}
			}
	}
	
//=============================================================================		
	if(KEY=='7')	// SW18: TEST DS1302
	{ 
			lcd1602_init();
			lcd1602_clear();
			DS1302_Init();	
			DS1302_SetTime(14,00,00);
	        DS1302_SetDate(6,7,5,13); 
			while(1)
			{  
				DS1302_GetTime(&hour,&minute,&second);
				DS1302_GetDate(&day, &date, &month, &year);
				sprintf(Lcd_Buff,"%2u:%2u:%2u",(unsigned int)hour,(unsigned int)minute,(unsigned int)second);
				lcd1602_gotoxy(0,0);
				lcd1602_puts(Lcd_Buff);
				sprintf(Lcd_Buff,"%2u:%2u:20%u",(unsigned int)date,(unsigned int)month,(unsigned int)year);
				lcd1602_gotoxy(0,1);
				lcd1602_puts(Lcd_Buff);
				delay_ms(250);
			}	
		}
	}
}


