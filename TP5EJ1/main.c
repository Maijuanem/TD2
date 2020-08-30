/*
3)7) Investigue como realizar la lectura de un teclado matricial de 4x4, es decir de 16 teclas,
	e implemente una función que permita leer la tecla presionada. Se deben utilizar las
	interrupciones externas.

3)8) En base al ejercicio anterior implemente un panel de alarma básico que cumpla con el
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
5)1)Implementar el contador del ejercicio 8 del TP 3 utilizando un display LCD.
		Dicho display se encuentra conectado al PORTC del Atmega128
 */
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include "MyDefs.h"
#include "MyInt.h"
#include "lcd_alfa.h"


#define FILA1           0x07
#define FILA2           0x0B
#define FILA3           0x0D
#define FILA4           0x0E

typedef enum
{
	ALARMADO,
	DESALARMADO,
	COD_INCORRECTO,
	ALARMA,
}ESTADO;

char pass[5],valid[5]="2020";
unsigned char desplazador=1, tecla, estado=0, n=0, num_error=0,cursor=0;
unsigned int valor=1247;
char cadena[]="1247";

void Validar(void);
void Salida(unsigned char);

ISR(INT7_vect){
	if((PINE & 0x0F) == FILA4)	pass[n]='/';//tecla=15;
	if((PINE & 0x0F) == FILA3)	pass[n]='x';//tecla=11;
	if((PINE & 0x0F) == FILA2)	pass[n]='-';//tecla=7;
	if((PINE & 0x0F) == FILA1)	pass[n]='+';//tecla=3;
	lcd_gotoxy(cursor,1);
	lcd_putc(pass[n]);
	cursor++;
	n++;
	if(n>4) Validar();
	while(!TestBit(PINE,7));

}
ISR(INT6_vect){
	if((PINE & 0x0F) == FILA4)	pass[n]='9';//tecla=14;
	if((PINE & 0x0F) == FILA2)	pass[n]='3';//tecla=6;
	if((PINE & 0x0F) == FILA3)	pass[n]='6';//tecla=10;
	if((PINE & 0x0F) == FILA1)	pass[n]='=';//tecla=2;
	lcd_gotoxy(cursor,1);
	lcd_putc(pass[n]);
	cursor++;
	n++;
	if(n>4) Validar();
	while(!TestBit(PINE,6));
}
ISR(INT5_vect){
	if((PINE & 0x0F) == FILA4)	pass[n]='8';//tecla=13;
	if((PINE & 0x0F) == FILA3)	pass[n]='5';//tecla=9;
	if((PINE & 0x0F) == FILA2)	pass[n]='2';//tecla=5;
	if((PINE & 0x0F) == FILA1)	pass[n]='0';//tecla=1;
	lcd_gotoxy(cursor,1);
	lcd_putc(pass[n]);
	cursor++;
	n++;
	if(n>4) Validar();
	while(!TestBit(PINE,5));
}
ISR(INT4_vect){
	if( (PINE & 0x0F) == FILA1 ){
		pass[n]='\0';					//tecla=0;
		Validar();
	}else{
		PORTA=1;
		if((PINE & 0x0F) == FILA4)	pass[n]='7';//tecla=12;
		if((PINE & 0x0F) == FILA3)	pass[n]='4';//tecla=8;
		if((PINE & 0x0F) == FILA2)	pass[n]='1';//tecla=4;
		lcd_gotoxy(cursor,1);
		lcd_putc(pass[n]);
		n++;
		cursor++;
		if(n>4) Validar();
	}
	while(!TestBit(PINE,4));
}

int main(void)
{
	DDRD=0x0F;
	DDRE=0x0F;
	PORTE=0xFF;
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
		PORTE = ~(0x0F & desplazador);
		desplazador=(desplazador<<1);
		if(desplazador== 0x10) desplazador=0x01;
		_delay_ms(10);
	}
}
void Validar(){
	lcd_gotoxy(cursor++,1);
	lcd_puts("..........");
	if(!strcmp(pass,valid)){
		switch(estado){
		case ALARMADO:
			estado=1;
			Salida(DESALARMADO);
			n=0;
			num_error=0;
			break;
		case DESALARMADO:
			estado=0;
			Salida(ALARMADO);
			n=0;
			num_error=0;
			break;
		}
	}else{
		num_error++;
		if(num_error>2){
			estado=3;
			Salida(ALARMA);
			while(1);
			n=0;
		}else{
			Salida(COD_INCORRECTO);
			n=0;
		}
	}
}
void Salida(unsigned char comando){
	if(comando==ALARMADO) {
		PORTD|= (1<<0)|(1<<1)|(1<<2)|(1<<3);
		PORTD&=~(1<<0);
		lcd_init(LCD_DISP_ON);
		lcd_gotoxy(0,0);
		lcd_puts("MODO ALARMADO");
		lcd_gotoxy(0,1);
		lcd_puts("CODIGO: ");
		lcd_gotoxy(8,1);
		cursor=9;
	}
	if(comando==DESALARMADO) {
		PORTD|= (1<<0)|(1<<1)|(1<<2)|(1<<3);
		PORTD&=~(1<<1);
		lcd_init(LCD_DISP_ON);
		lcd_gotoxy(0,0);
		lcd_puts("MODO DESALARMADO");
		lcd_gotoxy(0,1);
		lcd_puts("CODIGO: ");
		lcd_gotoxy(8,1);
		cursor=9;

	}
	if(comando==COD_INCORRECTO) {
		PORTD&=~(1<<2);
		lcd_init(LCD_DISP_ON);
		lcd_gotoxy(0,0);
		lcd_puts("COD ERRONEO");
		lcd_gotoxy(13,0);
		lcd_putc(num_error+48);
		lcd_gotoxy(0,1);
		lcd_puts("CODIGO: ");
		lcd_gotoxy(8,1);
		cursor=9;

	}
	if(comando==ALARMA) {
		PORTD|= (1<<0)|(1<<1)|(1<<2)|(1<<3);
		PORTD&=~(1<<3);
		lcd_init(LCD_DISP_ON);
		lcd_gotoxy(0,0);
		lcd_puts("SIST BLOQUEADO");
		lcd_gotoxy(0,4);
		lcd_puts("RESETEAR");
		lcd_gotoxy(8,1);
		cursor=9;
	}

}

/*
 * PE0--> ALARMADO 			--> estado=0
 * PE1--> DESALARMADO		--> estado=1
 * PE2--> CODIGO INCORRECTO --> estado=2
 * PE3--> ALARMA SONORA		--> estado=3
 */
