/*
 * KeyPad_Cfg.h
 *
 * Created: 5/21/2021 11:02:13 AM
 *  Author: Andrew
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#include "DIO.h"

#define   Col_INIT            0
#define   COL_FINAL           3

#define   ROW_INIT            4
#define   ROW_FINAL           7



#define   KEYPAD_COL_PORT     DIO_PORTD
#define   KEYPAD_ROW_PORT     DIO_PORTD

#define   KEYPAD_COL0         DIO_PIN0
#define   KEYPAD_COL1         DIO_PIN1
#define   KEYPAD_COL2         DIO_PIN2
#define   KEYPAD_COL3         DIO_PIN3

#define   KEYPAD_ROW0         DIO_PIN4
#define   KEYPAD_ROW1         DIO_PIN5
#define   KEYPAD_ROW2         DIO_PIN6
#define   KEYPAD_ROW3         DIO_PIN7

#endif /* KEYPAD_CFG_H_ */