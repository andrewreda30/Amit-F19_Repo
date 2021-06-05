/*
 * F19_KeyPad.h
 *
 * Created: 5/21/2021 10:57:58 AM
 *  Author: Andrew
 */ 


#ifndef F19_KEYPAD_H_
#define F19_KEYPAD_H_

#include "KeyPad_Cfg.h"

void KeyPad_Init(void);

uint8 KeyPad_GetValue(void);

#endif /* F19_KEYPAD_H_ */