/*
 * MicroControler1.c
 *
 * Created: 5/25/2021 7:19:03 AM
 *  Author: Andrew
 */ 

#include "Main.h"
extern uint8 n;
int main(void)
{
	SPI_Slave_Init();
	LCD_Init();
	
	KeyPad_Init();
	while(1)
	{
		n= SPI_TranSiver('2');
		inti_of_program();
		true_password();
		false_password();
		reset_a_3times();
	}
}
