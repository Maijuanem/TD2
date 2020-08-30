/*
7- Investigue como realizar la lectura de un teclado matricial de 4x4, es decir de 16 teclas,
	e implemente una función que permita leer la tecla presionada. Se deben utilizar las
	interrupciones externas.

8- En base al ejercicio anterior implemente un panel de alarma básico que cumpla con el
	siguiente funcionamiento:
		 Una vez iniciado el sistema la alarma debe estar en estado DESARMADO,
		indicado con un LED a tal fin.
		 Si se escribe el código correcto de 4 dígitos y se presiona la tecla ARMAR, la
		alarma pasa a estado ARMADO, encendiendo un LED indicador y apagando el
		LED anterior. Caso contrario enciende un led de error quedando a la espera de
		un nuevo código.
		 Si en estado ARMADO se escribe el código correcto y se presiona la tecla
		DESARMAR, la alarma pasa a estado DESARMADO encendiendo el LED
		apropiado. Caso contrario enciende un led de error quedando a la espera de un
		nuevo código. Si se ingresa el código de forma incorrecta por tercera vez
		consecutiva, la alarma debe comenzar a sonar lo cual se indicara con un led a
		tal fin.
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include "MyDefs.h"
#include "MyInt.h"
#include <string.h>

#define FILA1           0x7F
#define FILA2           0xBF
#define FILA3           0xDF
#define FILA4           0xEF

typedef enum
{
	ALARMADO,
	DESALARMADO,
	COD_INCORRECTO,
	ALARMA,
}ESTADO;

char pass[4],valid[4]="2020";
unsigned char desplazador, tecla, estado=0, n=0, num_error=0;

void Validar(void);
void Salida(unsigned char);

ISR(INT7_vect){
	if(PORTD == FILA4)	pass[n]='/';//tecla=15;
	if(PORTD == FILA3)	pass[n]='x';//tecla=11;
	if(PORTD == FILA2)	pass[n]='-';//tecla=7;
	if(PORTD == FILA1)	pass[n]='+';//tecla=3;
	n++;
	PORTF=n;
	if(n>4) Validar();
	PORTA=1;
	while(!TestBit(PINE,7));

}
ISR(INT6_vect){
	if(PIND == FILA4)	pass[n]='9';//tecla=14;
	if(PIND == FILA3)	pass[n]='6';//tecla=10;
	if(PIND == FILA2)	pass[n]='3';//tecla=6;
	if(PIND == FILA1)	pass[n]='=';//tecla=2;
	n++;
	PORTF=n;
	if(n>4) Validar();
	PORTA=1;
	while(!TestBit(PINE,6));
}
ISR(INT5_vect){
	if(PIND == FILA4)	pass[n]='8';//tecla=13;
	if(PIND == FILA3)	pass[n]='5';//tecla=9;
	if(PIND == FILA2)	pass[n]='2';//tecla=5;
	if(PIND == FILA1)	pass[n]='0';//tecla=1;
	n++;
	PORTF=n;
	if(n>4) Validar();
	PORTA=1;
	while(!TestBit(PINE,5));
}
ISR(INT4_vect){
	if( PIND == FILA1 ){
		PORTA=0;
		pass[n]='\0';					//tecla=0;
		Validar();
	}else{
		PORTA=1;
		if(PIND == FILA4)	pass[n]='7';//tecla=12;
		if(PIND == FILA3)	pass[n]='4';//tecla=8;
		if(PIND == FILA2)	pass[n]='1';//tecla=4;
		n++;
		PORTF=n;
		if(n>4) Validar();
	}
	while(!TestBit(PINE,4));
}

int main(void)
{
	DDRD=0xF0;
	PORTD=0x10;
	DDRA=1;
	PORTA=1;
	DDRG=255;
	DDRF=255;
	DDRE|= (1<<0)|(1<<1)|(1<<2)|(1<<3);
	PORTE=0xF0;
	SET_INT4567_ON;
	SET_INT4_FALLING;
	SET_INT5_FALLING;
	SET_INT6_FALLING;
	SET_INT7_FALLING;
	estado=0;
	Salida(ALARMADO);
	sei();
	while(1)
	{

		PORTD=~desplazador;
		desplazador=(desplazador<<1);
		if(desplazador==0x00) desplazador=0x10;
		_delay_ms(10);
	}
}
void Validar(){
	if(!strcmp(pass,valid)){
		switch(estado){
		case ALARMADO:
			estado=1;
			Salida(DESALARMADO);
			n=0;
			num_error=0;
			PORTG=num_error;
			break;
		case DESALARMADO:
			estado=0;
			Salida(ALARMADO);
			n=0;
			num_error=0;
			PORTG=num_error;
			break;
		}
	}else{
		num_error++;
		PORTG=num_error;
		if(num_error>2){
			estado=3;
			Salida(ALARMA);
			while(1);
			n=0;
		}else{
			//estado=2;
			Salida(COD_INCORRECTO);
			n=0;
		}
	}
}
void Salida(unsigned char comando){
	if(comando==ALARMADO) {
		PORTE|= (1<<0)|(1<<1)|(1<<2)|(1<<3);
		PORTE&=~(1<<0);
	}
	if(comando==DESALARMADO) {
		PORTE|= (1<<0)|(1<<1)|(1<<2)|(1<<3);
		PORTE&=~(1<<1);
	}
	if(comando==COD_INCORRECTO) {
		PORTE&=~(1<<2);
	}
	if(comando==ALARMA) {
		PORTE|= (1<<0)|(1<<1)|(1<<2)|(1<<3);
		PORTE&=~(1<<3);
	}

}

/*
 * PE0--> ALARMADO 			--> estado=0
 * PE1--> DESALARMADO		--> estado=1
 * PE2--> CODIGO INCORRECTO --> estado=2
 * PE3--> ALARMA SONORA		--> estado=3
 */
