/*
 * Inturpt.c
 *
 * Created: 5/25/2021 4:29:02 PM
 *  Author: Andrew
 */ 

#include "Inturpt.h"

int f1=1 , m=0 , tc=0 , f , c_u=0 , counter_if_wrong=0;
uint8* b;

void sci_initilized()
{
	sei();
	UCSRA|=0x00;
	UCSRB|=(1<<RXCIE)|(1<<RXEN)|(1<<TXEN);
	UCSRC|=(1<<UCSRC_URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UBRRH=0x00;
	UBRRL=103;
}

void UART_sendbyte( char data)
{
	while (!(UCSRA&(1<<UDRE)))
	{
	}
	
	UDR=data;
}
void start_checkpassword()
{
	
	if (f1==1)
	{
		
		if(b[8]==3)
		{
			for( f=0;f<4;f++)
			{
				if(b[f]==b[f+4])
				{
					m++;
					if(m==4)
					{
						f1=2;
						timer_inti();
						m=0;
					}
					
				}
				else
				{
					f1=3;
				}
				
			}
		}
	}
	if (f1==2)
	{
		UART_sendbyte('2');
		_delay_ms(10000);
		UART_sendbyte('1');
		f1=1;
		b[8]=2;
		counter_if_wrong=0;
	}
	if (f1==3)
	{
		PORTA |=(1<<PIN4);
		UART_sendbyte('3');
		if(counter_if_wrong<2)
		{
			_delay_ms(10000);
			UART_sendbyte('1');
		}
		f1=1;
		b[8]=1;
		if(counter_if_wrong==2)
		{
			f1=4;
			counter_if_wrong=0;
		}
		counter_if_wrong++;
	}
	if (f1==4)
	{
		UART_sendbyte('4');
	}
	
}
