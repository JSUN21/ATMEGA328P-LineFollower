/*
 * USART.c
 *
 * Created: 25/03/2016 09:40:11 a. m.
 * 
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "USART.h"
#include "Rutinas.h"
#include "MOTORs.h"


//Global variables
volatile char USART_received_char;

// VUELTA NO DA UNA VUELTA BIEN, CADA QUE S EPREWCIONE UNA TECLA ACCIONA, PERP DURANTE EL TIEMPO QUE ESTE PRESIONADA, CONTROL DE VUELTAS, 
//ES DECIR MAS CERRADAS DISMINUIR VELOCIDAD DE UNA O AMBAS LLANTAS PRUEBA Y ENSAYO,ADEMAS NO LLAME LA RUTINA DE STOP EN USART
// TODO EN CICLO WHILE MIENTRAS UNA TECLA ESTE PRESIONADA HACE ESO, CUANDO  NO REGRESA A STOP.
// Y QUE SEA TOTLAMENTE CONTROLABLE, EN VELOCIDAD, COMO EN EL RESPUESTA AL PRESIOANR UN BOTON.

/************************************************************************
	Rutina de atención a las interrupciones del USART
*************************************************************************/

ISR (USART_RX_vect)
{
	USART_received_char=UDR0; //Lee un dato de la terminal
	//USART_transmit_string("El caracter tecleado es: "); //Envía el texto: "El caracter tecleado es: "
	//USART_transmit(USART_received_char); //Envía a la terminal el caracter:
	
	if(USART_received_char == 0x41)// 'A'
	{
		
		//USART_transmit_string(" AVANZA "); //Envía el texto 
			motor_f();
			

		
	}
	else if (USART_received_char == 0x53 )// ' S '
	{
		
		//USART_transmit_string(" RETROCEDE "); //Envía el texto
		motor_b();
	}
	else if (USART_received_char == 0x44 )// ' D '
	{
		
		//USART_transmit_string(" VUELTA A LA IZQUIERDA "); //Envía el texto
		motor_turnl();
		_delay_ms(273);
		motor_s();
	}
	else if (USART_received_char == 0x46 )// ' F '
	{
		
		//USART_transmit_string(" VUELTA A LA DERECHA "); //Envía el texto "
		motor_turnr();
		_delay_ms(280);
		motor_s();
	}
	
	 else if (USART_received_char == 0x47 ) //' G '
	{
	
		//USART_transmit_string(" SE DETIENE "); //Envía el texto
		motor_s();
	}
	
	 else if (USART_received_char == 0x48 ) //' H ' ----------------------------------------
	 {
		 
		 motor_turnr();
		 _delay_ms(135);
		 motor_s();
	 }
	 else if (USART_received_char == 0x42 ) //' B '
	 {
		 
		 motor_turnl();
		 _delay_ms(135);
		 motor_s();
	 }
	  else if (USART_received_char == 0x43 ) //' C '
	  {
		  
		  motor_turnr();
	  }
	   else if (USART_received_char == 0x45 ) //' E '
	   {
		   
		   motor_f();
		   _delay_ms(560);
		   motor_b();
		   _delay_ms(580);
		   motor_s();
	   }
	   
	    else if (USART_received_char == 0x49 ) //' I '
	    {
		    
		    	
		    	int i;
		    	for (i=0;i<=5;i++)
		    	{
			    	PORTB ^= 1 << PB3;
			    	_delay_ms(100);
		    	}
	    }
		 else if (USART_received_char == 0x61 ) //' a '
		 {
			 
			 motor_turnl();
			 _delay_ms(135);
			 motor_f();
			 _delay_ms(560);
			 motor_turnr();
			 _delay_ms(280);
			 motor_f();
			 _delay_ms(280);
			 motor_turnr();
			 _delay_ms(280);
			 motor_f();
			 _delay_ms(280);
			 motor_s();
			 
			 
		 }
		  else if (USART_received_char == 0x62 ) //'b'
		  {
			  
			  motor_turnl();
			  _delay_ms(135);
			  motor_f();
			  _delay_ms(400);
			  motor_turnr();
			  _delay_ms(150);
			  
			  
			  motor_s();
			  
			  
		  }
	 }






/************************************************************************
	Lee el byte que llega por el receptor
*************************************************************************/
unsigned char USART_receive( void )
{
  while ((UCSR0A & 0x80) == 0x00); // Espera por un dato (RXC=1)
  return UDR0;
   
}

/************************************************************************
	Transmite el dato que se pasa como argumento
*************************************************************************/
void USART_transmit( uint8_t data )
{
  while ((UCSR0A & 0x20) == 0x00);  // Espera hasta que el buffer del transmisor está vacío (UDRE=1)
  UDR0 = data; // Cuando el buffer está vacío, coloca el dato en el registro UDR
}

/************************************************************************
	Transmite una cadena de caracteres
*************************************************************************/
void USART_transmit_string( char s[] )
{	
	int i = 0;
  while (i < 64)
  {
	  if (s[i] == '\0') break;
	  USART_transmit(s[i++]);
  }
}
/******************************************************************************
* Inicializa el USART
* Entrada: valor de UBRR de las tablas de BAUDRATE
*
*******************************************************************************/
void Init_USART(unsigned int baudrate)
{
	//Escoge modo asíncrono: UMSEL01=0 & UMSEL00=0 (tabla 19.4 pag.197
	UCSR0C &= (0<<UMSEL00) & (0<<UMSEL01); 
	
	//Selecciona la velocidad: U2X0=0 normal, U2X0=1 doble
	UCSR0A = (1<<U2X0); // bit U2X0 = 1 doble
	
	//Baudrate ejemplo: fosc = 16 Mhz, U2X0= 1, BaudRate = 9600, entonces UBRR0= 207
	//Ver DataSheet pag.153
	UBRR0H = (unsigned char) (baudrate>>8); // Escribe (MSB) en la parte alta del registro
	UBRR0L = (unsigned char) (baudrate); //Escribe (LSB) el valor en la parte baja
	
	//Tamaño de los datos
	UCSR0C = (1<<UCSZ01) | (1<<UCSZ00); //8 bits (tabla 19.7 pag.198)
	
	//Habilitar el transmisor y receptor
	UCSR0B = (1<<RXEN0) | (1<<TXEN0);
		
	//Habilita bits de paro (tabla 19.6 pag.198)
	//UCSR0C = (1<<USBS0);
	
	sei(); //Activa interrupciones generales
	
	//Para activar/desactivar las interrupcines, sólo quitar/poner el símbolo de comentarios
	UCSR0B |= (1<<RXCIE0);	//Activa interrupciones de "recepción completada" (RXCIE0=1)
							//y "registro de datos vacío" (UDRIE0=1)	
							
	
}