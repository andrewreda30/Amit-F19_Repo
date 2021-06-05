/*
 * Timer.c
 *
 * Created: 5/25/2021 4:35:37 PM
 *  Author: Andrew
 */ 

#include "Timer.h"
#include "Inturpt.h"

void timer_inti() // timer initialize   to activate interrupt
{
	DDRA=0XFF;// WE MAKE L
	sei();
	TCCR0=0X85;
	TIMSK=0X01;
}

void timer_stopinti()
{
	DDRA=0XFF;
	TCCR0=0X00;
	TIMSK=0X00;
}

void timer_dcmotor_start()
{
	if(tc>20&&tc<40)
	{
		PORTA&=!(1<<PIN5);
		PORTA=PORTA^(1<<PIN6);
		PORTA=PORTA^(1<<PIN7);
		PORTA=PORTA^(1<<PIN4);
	}
	if(tc<20&&tc>=0)
	{
		PORTA&=!(1<<PIN6);
		PORTA=PORTA^(1<<PIN5);
		PORTA=PORTA^(1<<PIN7);
		PORTA=PORTA^(1<<PIN4);
	}
	tc++;
	if(tc>=40)
	{
		tc=0;
		timer_stopinti();
		PORTA=0x00;
	}
	
}