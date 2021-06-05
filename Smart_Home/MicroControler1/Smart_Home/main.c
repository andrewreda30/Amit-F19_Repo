/*
 * Smart_Home.c
 *
 * Created: 5/25/2021 5:58:50 AM
 * Author : Andrew
 */ 

#include "Main.h"
uint8 key,n;
uint8 x=1;

/*ask for password*/
void inti_of_program(void)
{
	while(n!='1');
	while(x!=0)
	{
		if(x==1)
		{
			LCD_Clear(); /*clear the LCD*/
			LCD_WriteCommand(0x80); /*make courser reach first row and first coloum*/
			LCD_WriteString("password:"); /*write on the LCD*/
		}
		x++;
		key = KeyPad_GetValue();
		delaycounter(); /*Make delay of keypad*/
		
		if((key >= '0') && (key <= '9'))
		{
			LCD_WriteChar(key);
			if(x==5)
			{
				x=0;
			}
		}
		SPI_TranSiver(key);
	}
}


void true_password()
{
	if (n=='2')
	{
		LCD_WriteCommand(0x80); /*make courser reach first row and first coloum*/
		LCD_WriteString("true password"); /*write on the LCD*/
	}
	
}


void false_password()
{
	if (n=='3')
	{
		LCD_WriteCommand(0x80); /*make courser reach first row and first coloum*/
		LCD_WriteString("wrong password"); /*write on the LCD*/
		_delay_ms(1000); 
	}
}

void reset_a_3times()
{
	if (n=='4')
	{
		LCD_WriteCommand(0x80); /*make courser reach first row and first coloum*/
		LCD_WriteString("wrong password "); /*write on the LCD*/
		LCD_GoToLocation(1,0);
		LCD_WriteString("3 times reset "); /*write on the LCD*/
	}
}

