
/*
 * Rutinas.c
 *
 * Created: 10/11/2018 08:41:29 p. m.
 *  Author: user
 */ 

// ejemplo del argumento motor_right (comando adelante o atras o se detiene ,  velocidad)

#include <avr/io.h>
#include <avr/interrupt.h>
#include "MOTORs.h"


void motor_turnr(void){
	
	
	
	motor_right(MOTOR_BACKWARD,90);
	motor_left(MOTOR_FORWARD,70);
	
	}
	
	void motor_turnl(void){
		
	motor_right(MOTOR_BACKWARD,70);
	motor_left(MOTOR_FORWARD,90); 
		
	}
	
	void motor_f(void){
		
		motor_right(MOTOR_BACKWARD,100);
		motor_left(MOTOR_FORWARD,100);
		
	}

    void motor_b(void){
	
	motor_right(MOTOR_FORWARD,100);
	motor_left(MOTOR_BACKWARD,100);
    }
	
    void motor_s(void){
	
	motor_right(MOTOR_STOP,1);
	motor_left(MOTOR_STOP,1);
    }


