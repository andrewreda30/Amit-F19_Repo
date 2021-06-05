/*
 * Inturpt.h
 *
 * Created: 5/25/2021 4:28:41 PM
 *  Author: Andrew
 */ 


#ifndef INTURPT_H_
#define INTURPT_H_

//#include <avr/interrupt.h>
#include "LCD.h"
#include "eeprom.h"
#include "MCU.h"

void sci_initilized ();
void start_checkpassword();
void UART_sendbyte(char data);


extern int f1 ,tc;



#endif /* INTURPT_H_ */