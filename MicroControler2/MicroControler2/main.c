/*
 * MicroControler2.c
 *
 * Created: 5/25/2021 4:09:00 PM
 * Author : Andrew
 */ 

#include "eeprom.h"
#include "Inturpt.h"
#include "Timer.h"
#include "SPI.h"

char x[4];
int i=0,c=0,n=0;
uint8 *b;
uint8 Received = 0;
//ISR(TIMER0_OVF_vect)
//{
	//timer_dcmotor_start();
//}
//
//ISR(USART_RXC_vect)
//{
	//Received = SPI_TranSiver('2');
	//EEpromWriteByte(i, Received);
	//_delay_ms(10);
	//EEpromReadByte(i); // Read 0xFF from the external EEPROM
	//_delay_ms(10);
	//EEpromWriteByte(0x0008, 0xFF); // Write 0xFF in the external EEPROM
	//_delay_ms(10);
	//EEpromReadByte(0x0008); // Read 0xFF from the external EEPROM
	//_delay_ms(10);
	//if (i<3)
	//SPI_TranSiver('1');
	//i++;
	//if(i==4)
	//{
		//i=0;
	//}
//
//}

int main(void)
{
	//DDRA=0xff;
	//DDRC=0xff;
	
	//sci_initilized ();
	//EEpromInit();
	SPI_Master_Init();
	LCD_Init();
	
	SPI_Master_InitTrans(); 
	
	Received = SPI_TranSiver('1');
	
	while (1)
	{
		uint8 Rec_Handshake = SPI_TranSiver('1');
		//start_checkpassword();
		LCD_WriteChar(Rec_Handshake);
		
		
		Received = SPI_TranSiver('1');
		LCD_WriteChar(Received);
		EEpromWriteByte(i, Received);
		_delay_ms(10);
		EEpromReadByte(i); // Read 0xFF from the external EEPROM
		_delay_ms(10);
		EEpromWriteByte(0x0008, 0xFF); // Write 0xFF in the external EEPROM
		_delay_ms(10);
		EEpromReadByte(0x0008); // Read 0xFF from the external EEPROM
		_delay_ms(10);
		if (i<3)
		Received = SPI_TranSiver('1');
		i++;
		if(i==4)
		{
		i=0;
		}
	}
	

}
