/*
 * F19_KeyPad.c
 *
 * Created: 5/21/2021 10:57:32 AM
 *  Author: Andrew
 */ 

#include "F19_KeyPad.h"

#define  F_CPU  16000000
#include <util/delay.h>


uint8 KEYPAD_VALUES[4][4] = {{'7' , '8' , '9', '/'  },
                             {'4' , '5' , '6' , '*' },
							 {'1' , '2' , '3' , '-' },
							 {'c' , '0' , '=' , '+' }} ;
								 

void KeyPad_Init(void)
{
	DIO_SetPinDir(KEYPAD_COL_PORT , KEYPAD_COL0 , DIO_PIN_OUTPUT);
	DIO_SetPinDir(KEYPAD_COL_PORT , KEYPAD_COL1 , DIO_PIN_OUTPUT);
	DIO_SetPinDir(KEYPAD_COL_PORT , KEYPAD_COL2 , DIO_PIN_OUTPUT);
	DIO_SetPinDir(KEYPAD_COL_PORT , KEYPAD_COL3 , DIO_PIN_OUTPUT);
	
	DIO_SetPinDir(KEYPAD_ROW_PORT , KEYPAD_ROW0 , DIO_PIN_INPUT);
	DIO_SetPinDir(KEYPAD_ROW_PORT , KEYPAD_ROW1 , DIO_PIN_INPUT);
	DIO_SetPinDir(KEYPAD_ROW_PORT , KEYPAD_ROW2 , DIO_PIN_INPUT);
	DIO_SetPinDir(KEYPAD_ROW_PORT , KEYPAD_ROW3 , DIO_PIN_INPUT);
	
	DIO_SetPinValue(KEYPAD_COL_PORT , KEYPAD_COL0 , DIO_PIN_HIGH);
	DIO_SetPinValue(KEYPAD_COL_PORT , KEYPAD_COL1 , DIO_PIN_HIGH);
	DIO_SetPinValue(KEYPAD_COL_PORT , KEYPAD_COL2 , DIO_PIN_HIGH);
	DIO_SetPinValue(KEYPAD_COL_PORT , KEYPAD_COL3 , DIO_PIN_HIGH);
	
	DIO_SetPullUp(KEYPAD_ROW_PORT , KEYPAD_ROW0);
	DIO_SetPullUp(KEYPAD_ROW_PORT , KEYPAD_ROW1);
	DIO_SetPullUp(KEYPAD_ROW_PORT , KEYPAD_ROW2);
	DIO_SetPullUp(KEYPAD_ROW_PORT , KEYPAD_ROW3);
	
}

uint8 KeyPad_GetValue(void)
{
	uint8 Col_Loc = 0;
	uint8 Row_Loc = 0;
	
	uint8 Button_Value = 0;
	
	uint8 Temp = 1;
	
	for(Col_Loc = Col_INIT ; Col_Loc <= COL_FINAL ; Col_Loc++)
	{
		DIO_SetPinValue(KEYPAD_ROW_PORT , Col_Loc , DIO_PIN_LOW);
		
		for(Row_Loc = ROW_INIT ; Row_Loc <= ROW_FINAL ; Row_Loc++)
		{
			 DIO_ReadPinValue(KEYPAD_ROW_PORT , Row_Loc , &Temp);
			
			if(Temp == 0)
			{
				Button_Value = KEYPAD_VALUES[Row_Loc-ROW_INIT][Col_Loc-Col_INIT];
				
				while(Temp == 0)
				{
					 DIO_ReadPinValue(KEYPAD_ROW_PORT , Row_Loc , &Temp );
					 _delay_ms(30);
					
				}
				
				
			}
		}
		
		DIO_SetPinValue(KEYPAD_ROW_PORT , Col_Loc , DIO_PIN_HIGH);
		
	}
	 return Button_Value;
}
