
/*
 * PORTs.c
 *
 * Created: 17/10/2018 07:40:47 p. m.
 *  
 */ 
#include <avr/io.h>

// adelante van en sentido contrrio, vuelta derechasi es ese motor pero en direccion contraria,
//el boton de izquierda esta mal puesto, avanzan ambos motores y en sentido opuesto,y el boton de back va en sentiod opuesto ese motor
//ademas sigue corriendo libre cada instruccion.

/****************************************
* Definición de los recursos Atmega328
*****************************************/


void init_ports(void)
{
	/*****************************************************************
	* Definición de puertos hacia el puente H y de éste a los motores
	******************************************************************
	* MPU		H BRIDGE
	* --------------
	* PB0		IN1 -
	* PB1		ENA	 |--> RIGHT MOTOR
	* PB4		IN2 -
	* --------------
	* PB2		ENB -
	* PC0		IN3	 |--> LEFT MOTOR
	* PC1		IN4 -
	* --------------
	*/
	//Salidas para PWM
	DDRB |= (1<<PB1); //OC1A Control de velocidad para motor Derecho
	DDRB |= (1<<PB2); //OC1B Control de velocidad para motor izquierdo 
	
	//Salidas para dirección
	DDRB |= (1 << PB0); //Control de avance motor derecho
	DDRB |= (1 << PB4); //Control de reversa motor derecho
	DDRC |= (1 << PC0); //Control de avanza motor izquierdo
	DDRC |= (1 << PC1); //Control de reversa motor izquierdo
	
	//Entradas sensor IR
	
	DDRD &= ~(1 << PD2);
	DDRD &= ~(1 << PD3);
	DDRD &= ~(1 << PD4);
	DDRD &= ~(1 << PD5);
	/*****************************************************************/

		
	/*****************************************************************
	* Definición de puertos hacia LEDs
	*******************************************************************/										
	DDRB |= 1 << PB5; //PB5 
	
		
		
}