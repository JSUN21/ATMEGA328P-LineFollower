/*
 * LEDs.c
 *
 * Created: 17/10/2018 07:54:44 p. m.
 *  
 */ 
#include <avr/io.h>
#include <util/delay.h>


void on_off_led(void)
{
	
	int i;
	for (i=0;i<=5;i++)
	{
		PORTB ^= 1 << PB2;
		_delay_ms(100);	
	}
}
