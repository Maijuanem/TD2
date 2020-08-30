/*
 * main.c
 *Se necesita implementar un temporizador que permita controlar el tiempo de un proceso químico.
 *Se Para tal fin se cuenta con un sistema con un Atmega128 y un display 7 segmentos de 4 dígitos,
 *Se  conectados como se indica en el ejercicio 6. El temporizador debe permitir configurar el tiempo
 *Se  con formato MM:SS en base a 2 pulsadores (INT5 incrementa 10 seg – INT6 incrementa 1 min) y
 *Se  debe tener un control de inicio/parada en base otro pulsador (INT7). También debe poder poner a cero el tiempo fijado,
 *Se  siempre cuando el timer está en reposo, presionando los dos pulsadores al mismo tiempo (INT5-INT6).
 *Se  Una vez iniciada la cuenta regresiva se debe activar una salida (PORTD.4) y al llegar al final de la cuenta
 *Se  se debe desactivar la misma, generando también una señal de alarma (PORTD.7) intermitente que controlará
 *Se  un buzzer para indicar el final del proceso (debe sonar 3 veces).

  Restricciones: implementar el sistema como una máquina de estados.
 *  Created on: 13 may. 2020
 *      Author: crixt
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "MyDefs.h"
#include "MyInt.h"
#include "Timer0.h"

typedef enum{
	SETEO,
	CONTANDO,
	FIN_CONTEO_ALARMA,
	PAUSA,
}ESTADO;
volatile unsigned char digito1, digito2, digito3, digito4,alarma_activada=0;
volatile int contador=0;
unsigned char estado;
volatile ESTADO state;

ISR(INT5_vect){
	if(state == SETEO) contador+=10;
	if(state == PAUSA ) {
		if( Setbit(PINE,6)==0){
			state=SETEO;
			contador=0;
		}
	}
}
ISR(INT6_vect){
	if(state == SETEO) contador+=60;
	if(state == PAUSA ) {
		if( Setbit(PINE,5)==0){
			state=SETEO;
			contador=0;
		}
	}
}
ISR(INT7_vect){
	switch(state){

	case CONTANDO:
		state = PAUSA;
		break;
	case FIN_CONTEO_ALARMA:
		state = SETEO;
		break;
	case PAUSA:
		state = CONTANDO;
		break;
	case SETEO:
		state = CONTANDO;
		break;
	default:
		state = PAUSA;
		break;
	}
}


int main(void){
	DDRA=255;
	DDRF=255;
	DDRD=255;
	DDRG=255;
	PIN_B4_OUT;
	Timer0_init(CTC,Timer0_Prescaler_32,Toggle_On_Comp_Match);
	TIMER0_COMP_Interrupt_ON;
	OCR0=124;
	SET_INT5_FALLING;
	SET_INT6_FALLING;
	SET_INT7_FALLING;
	SET_INT567_ON;
	state=SETEO;
	sei();
	while(1)
	{
		digito1=contador/600;
		digito2=(contador-(digito1*600))/60;
		digito3=(contador-((digito1*600+digito2)*60))/10;
		digito4=((contador%1000)%100)%10;
		PORTG=digito3;
		switch(state){
			case SETEO:
				PD4_OFF;
				PD7_ON;
				break;
			case CONTANDO:
				PD4_ON;
				PD7_ON;
				break;
			case FIN_CONTEO_ALARMA:
				PD4_OFF;
				alarma_activada=1;
				break;
			case PAUSA:
				PD4_OFF;
				PD7_ON;
				break;
		}

	}
	return 0;
}
// FCPU=8 MHz
// Prescaler 32 -> Fclk_timer0= 250 kHz -> Tclk_timer0 = 4 us
// El timer cuenta de hasta OCR0=249 y con el siguiente pulso (250 en total) genera la interrupción
// T_interrupcion = 250 * 4 us = 1 ms.
// Digito1 se enciende 1ms/4ms

