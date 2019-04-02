/*
 * MOTORs.c
 *
 * Created: 09/11/2018 01:57:56 p. m.
 *  
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "MOTORs.h"

/****************************************************************
* Activa se�al pwm para el control de velocidad
*
*****************************************************************/

void init_timer1()
{
	TCCR1A |= (1<<WGM10);//WGM10=1 PWM, Phase Correct, 8-bit (pag.97 tabla 39)
	TCCR1A |= (1<<COM1A1)|(1<<COM1B1);//Env�a nivel bajo por OC1A/OC1B on Compare Match(Pag.96 tabla 36)
	//when up-counting. Env�a nivel alto por OC1A/OC1B on Compare
	//Match when downcounting.
	//Ver figura 40 en p�gina 93

	TCCR1B |= (1<<CS12)|(1<<CS10); //frecuencia=fcpu/64 ~ 15Khz (frecuencia para los motores)
	//tabla 40, pag.99
}

/****************************************************************
* Establece rotaci�n de motor DERECHO en una direcci�n y velocidad
* Inputs:
* dir = MOTOR_FORWARD, MOTOR_BACKWARD or MOTOR_STOP
* speed = cualquier valor de 0 a 255
* Ejemplo:
* MotorA(MOTOR_FORWARD,120);
*****************************************************************/



void motor_right(uint8_t dir,uint8_t speed)
{
	//Direcci�n
	if(dir == MOTOR_STOP)
	{
		PORTB &= (~(1<<PB0));
		PORTB &= (~(1<<PB4));
	}

	else if(dir == MOTOR_BACKWARD)
	{
		PORTB &= (~(1<<PB0));
		PORTB |= (1<<PB4);
	}
	else if(dir == MOTOR_FORWARD)
	{
		PORTB &= (~(1<<PB4));
		PORTB |= (1<<PB0);
	}

	//Velocidad
	uint8_t sreg = SREG;//Status Register

	cli();

	OCR1A = (uint8_t)(((float)speed/255.0)*ROBO_SPEED);
	SREG = sreg;
}

/****************************************************************
* Establece rotaci�n de motor IZQUIERDO en una direcci�n y velocidad
* Inputs:
* dir = MOTOR_FORWARD, MOTOR_BACKWARD or MOTOR_STOP
* speed = cualquier valor de 0 a 255
* Ejemplo:
* MotorA(MOTOR_FORWARD,120);
*****************************************************************/
void motor_left(uint8_t dir,uint8_t speed)
{
	//Direcci�n
	if(dir == MOTOR_STOP)
	{
		PORTC &= (~(1<<PC0));
		PORTC &= (~(1<<PC1));
	}

	else if(dir == MOTOR_FORWARD)
	{
		PORTC &= (~(1<<PC1));
		PORTC |= (1<<PC0);
	}
	else if(dir == MOTOR_BACKWARD)
	{
		PORTC &= (~(1<<PC0));
		PORTC |= (1<<PC1);
	}

	//Velocidad
	uint8_t sreg = SREG;

	cli();

	OCR1B = (uint8_t)(((float)speed/255.0)*ROBO_SPEED);

	SREG = sreg;
}
