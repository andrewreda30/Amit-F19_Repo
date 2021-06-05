/*
 * Delay_counter.c
 *
 * Created: 5/25/2021 7:27:14 AM
 *  Author: Andrew
 */ 

#include "Delay_counter.h"


/*Make delay of keypad*/
void  delaycounter (void) 
{
	int counter=0;
	while (counter<=10000)
	{
		counter++;
	}
}
