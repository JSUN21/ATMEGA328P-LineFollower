
 /*line follower.c
 *
 * Created: 13/11/2018 08:45:45 p. m.

 */ 

#include <avr/io.h>
#include "PORTs.h"
#include "LEDs.h"
#include "MOTORs.h"
#include "USART.h"
#include "Rutinas.h"
#include <util/delay.h>


int main(void)
{
	init_ports();
	init_timer1();
		Init_USART(207); //De la tabla 19.12, pag.203 (atmega328 datasheet)
			// fosc=16MHz, BaudRate=9600, U2xn=1
	
	while (1)
	{
		
					   

	
		}
		
		}
		 