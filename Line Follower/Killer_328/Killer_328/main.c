
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
	
	
	while (1)
	{
		
		  if( PIND & (1<<PD2)){
			
motor_right(MOTOR_BACKWARD,120);
motor_left(MOTOR_FORWARD,30);

		                      }
		 
		 
		    else if( PIND & (1<<PD3)){
		                motor_turnr();
		                              }
								
		
	            else if( PIND & (1<<PD4)){
				
			      motor_turnl();
				  
		                            }
			
			
		          else if( PIND & (1<<PD5)){
				
			         motor_right(MOTOR_BACKWARD,30);
			         motor_left(MOTOR_FORWARD,120);
					 
				  }
				  
		/*motor_turnl();
		_delay_ms(1200);
		motor_s(); 
		_delay_ms(600);		
		  
		motor_turnr();
		_delay_ms(1200);
		motor_s();
		_delay_ms(600); */
		
									   	
									   
				
	}
	
}