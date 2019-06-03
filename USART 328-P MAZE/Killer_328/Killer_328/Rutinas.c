
/*
 * Rutinas.c
 *
 * Created: 10/11/2018 08:41:29 p. m.
 *  Author: user
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "MOTORs.h"


void motor_turnr(void){
	
	// ejemplo del argumento motor_right (comando adelante o atras o se detiene ,  velocidad)
	
	motor_right(MOTOR_BACKWARD,255);
	motor_left(MOTOR_FORWARD,200);
	
	}
	
	void motor_turnl(void){
		
	motor_right(MOTOR_BACKWARD,200);
	motor_left(MOTOR_FORWARD,255); 
		
	}
	
	void motor_f(void){
		
		motor_right(MOTOR_FORWARD,255);
		motor_left(MOTOR_FORWARD,255);
		
	}

    void motor_b(void){
	
	motor_right(MOTOR_BACKWARD,200);
	motor_left(MOTOR_BACKWARD,200);
    }
	
    void motor_s(void){
	
	motor_right(MOTOR_STOP,1);
	motor_left(MOTOR_STOP,1);
    }


