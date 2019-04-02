/*
 * MOTORs.h
 *
 * Created: 09/11/2018 01:58:15 p. m.
 *  
 */ 


#ifndef MOTORS_H_
#define MOTORS_H_

//Definici�n de par�metros del motor
#define MOTOR_STOP 	0
#define MOTOR_BACKWARD	1
#define MOTOR_FORWARD	2
#define ROBO_SPEED 150 //0-255

void init_timer1();
void motor_right(uint8_t dir,uint8_t speed);
void motor_left(uint8_t dir,uint8_t speed);

#endif /* MOTORS_H_ */