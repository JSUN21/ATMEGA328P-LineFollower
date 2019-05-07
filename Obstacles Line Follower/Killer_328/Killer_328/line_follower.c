/*
 * line_follower.c
 *
 * Created: 25/04/2019 10:50:38 p. m.
 *  Author: user
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include "Rutinas.h"
#include "MOTORs.h"

void line_follower(void){
	
	  if( PIND & (1<<PD2)){
			
motor_right(MOTOR_BACKWARD,255);
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



