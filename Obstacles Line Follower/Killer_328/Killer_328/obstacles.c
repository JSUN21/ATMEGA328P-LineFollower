/*

 * _2_axisObstacles.c
 *
 * Created: 25/04/2019 11:11:36 p. m.
 *  Author: user
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Rutinas.h"
#include "MOTORs.h"


 void obstacle (void){
	
    if (!(PIND & (1<<PD6)))
    {
		
		do 
		{
			motor_left(1,100);
			
		} while (!(PIND &(1<<PD7)));
		
		
		do 
		{
			motor_f();
			
		} while (!(PIND & (1<<PD7)));
		
		do 
		{
			motor_right(1,100);
			
			motor_f();
			
			//cuantos grados o tiempo*//

		} while (!(PIND & (1<<PD7)));
		
		motor_turnr();
		motor_f();
		
		
    


  }

		               }
					   
		