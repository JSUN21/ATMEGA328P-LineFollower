
 /* Killer_328.c
 *
 * Created: 13/11/2018 08:45:45 p. m.

 */ 
 
#include <util/delay.h>
#include <avr/io.h>
#include "PORTs.h"
#include "MOTORs.h"

#include "Rutinas.h"


int sensor_ulright=0;
int sensor_uleft=0;
int sensor_left=0;
int sensor_right=0;
int sensor_front=0;
int sensor_bleft=0;
int sensor_bright=0;


int main(void)
{
	init_ports();
	init_timer1();
	
	
	

	while (1)
	{
		
		 sensor_ulright=PIND & (1<<PD2);
		 sensor_uleft  =PIND & (1<<PD5);
		 sensor_left   =PIND & (1<<PD3);
		 sensor_right  =PIND & (1<<PD4);
		 
		 sensor_front  =!(PIND & (1<<PD0));
		 sensor_bleft  =PIND & (1<<PD6);
		 sensor_bright =PIND & (1<<PD7);
		
		  if( PIND & (1<<PD2)){
			  
			  motor_right(MOTOR_BACKWARD,170);
			  motor_left(MOTOR_FORWARD,30);

		  }
		  
		  else if ( (sensor_ulright == 0x01) & (sensor_left==0x01) ) 
		  {
			  
			  motor_right(MOTOR_BACKWARD,170);
			  motor_left(MOTOR_FORWARD,30);

		  }
		  
		   else if ( (sensor_ulright == 0x01) & (sensor_left==0x01) & (sensor_right==0x01) )
		   {
			   
			   motor_right(MOTOR_BACKWARD,170);
			   motor_left(MOTOR_FORWARD,30);

		   }
		  
		else if ( PIND & (1<<PD3)){
			motor_turnr();
			
		}
		
		
		else if ( PIND & (1<<PD4)){
			
			motor_turnl();
			
			}
			
			 
			    if( PIND & (1<<PD5)){
				   
				   motor_right(MOTOR_BACKWARD,30);
				   motor_left(MOTOR_FORWARD,170);
				   _delay_ms(10);
				   
			   } 
			   
			  
			   
			    if ( (sensor_uleft==0x01) && ( sensor_right==0x01) && ( sensor_left==0x01)  ) 
			  {
				  
				  motor_right(MOTOR_BACKWARD,30);
				  motor_left(MOTOR_FORWARD,170);
				  
				  
				  
				 
			  }
			  
			     if ((sensor_uleft==0x01) && ( sensor_right==0x01) ) 
			    {
				   
				   motor_right(MOTOR_BACKWARD,30);
				   motor_left(MOTOR_FORWARD,170);
				  
				  
			   } 
			  
			  
			 if (!(PIND & (1<<PD0)))
			 {  
				
		 	
		 	motor_b();
		 	_delay_ms(500);
		 	_delay_ms(250);
		 	
		 	motor_s();
		 	_delay_ms(500);
		 	_delay_ms(500);
		 	_delay_ms(500);
		 	
		 	
		 	motor_right(MOTOR_BACKWARD,225);
		 	motor_left(MOTOR_FORWARD,25);
		 	_delay_ms(500);
		 	motor_s();
		 	_delay_ms(500);
		 	_delay_ms(500);
		 	_delay_ms(500);
		 	
		 	motor_f();
		 	_delay_ms(500);
		 	_delay_ms(500);
		 	motor_s();
		 	_delay_ms(500);
		 	
		 	//gira contrario
		 	
		 	motor_right(MOTOR_BACKWARD,25);
		 	motor_left(MOTOR_FORWARD,225);
		 	_delay_ms(500);
		 	motor_s();
		 	_delay_ms(500);
		 	_delay_ms(500);
		 	_delay_ms(500);
		 	
		 	motor_f();
		 	_delay_ms(500);
		 	_delay_ms(500);
		 	motor_s();
		 	_delay_ms(500);
		 	_delay_ms(500);
		 	
		 	//gira contrario disque reposisiona
		 	
		 	motor_right(MOTOR_BACKWARD,28);
		 	motor_left(MOTOR_FORWARD,225);
		 	_delay_ms(500);
		 	motor_s();
		 	_delay_ms(500);
		 	_delay_ms(500);
		 	_delay_ms(500);
		 	
		 	motor_f();
		 	
		 	
			   
			 			 
			 }
			 
			  
				
				if ( (sensor_front==0x01) && ( ( sensor_ulright==0x01) || (sensor_uleft=0x01)  || (sensor_right=0x01)  || (sensor_left=0x01) ) )
				{ 
					motor_b();
					_delay_ms(500);
					_delay_ms(250);
					
					motor_s();
					_delay_ms(500);
					_delay_ms(500);
					_delay_ms(500);
					
					
					motor_right(MOTOR_BACKWARD,225);
					motor_left(MOTOR_FORWARD,25);
					_delay_ms(500);
					motor_s();
					_delay_ms(500);
					_delay_ms(500);
					_delay_ms(500);
					
					motor_f();
					_delay_ms(500);
					_delay_ms(500);
					motor_s();
					_delay_ms(500);
					
					//gira contrario
					
					motor_right(MOTOR_BACKWARD,25);
					motor_left(MOTOR_FORWARD,225);
					_delay_ms(500);
					motor_s();
					_delay_ms(500);
					_delay_ms(500);
					_delay_ms(500);
					
					motor_f();
					_delay_ms(500);
					_delay_ms(500);
					motor_s();
					_delay_ms(500);
					_delay_ms(500);
					
					//gira contrario disque reposisiona
					
					motor_right(MOTOR_BACKWARD,28);
					motor_left(MOTOR_FORWARD,225);
					_delay_ms(500);
					motor_s();
					_delay_ms(500);
					_delay_ms(500);
					_delay_ms(500);
					
					motor_f();
					
				}						   
				
		 }
	
}