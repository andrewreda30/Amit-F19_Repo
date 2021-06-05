/*
 * Main.h
 *
 * Created: 5/25/2021 7:23:43 AM
 *  Author: Andrew
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#include "Delay_counter.h"
#include "F19_KeyPad.h"
#include "LCD.h"
#include "UART.h"
#include "STD.h"
#include "SPI.h"

void inti_of_program();
void true_password();
void false_password();
void reset_a_3times(); 
extern uint8 key,n;



#endif /* MAIN_H_ */