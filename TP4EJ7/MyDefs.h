
/*
 * MyDefs.h
 *
 *  Created on: 18 may. 2020
 *      Author: Juan
 */

#ifndef MYDEFS_H_
#define MYDEFS_H_
//OPERACIONES NIVEL BIT
#define Setbit(reg,bit) reg|=(1<<bit)
#define Clrbit(reg,bit) reg&=~(1<<bit)
#define Tglbit(reg,bit) reg^=(1<<bit)
#define Testbit(reg,bit) (reg&(1<<bit))

//DIRECCIONAMIENTO DDRB
#define PIN_B0_OUT Setbit(DDRB,0)
#define PIN_B1_OUT Setbit(DDRB,1)
#define PIN_B2_OUT Setbit(DDRB,2)
#define PIN_B3_OUT Setbit(DDRB,3)
#define PIN_B0_IN  Clrbit(DDRB,0)
#define PIN_B1_IN  Clrbit(DDRB,1)
#define PIN_B2_IN  Clrbit(DDRB,2)
#define PIN_B3_IN  Clrbit(DDRB,3)
#define PIN_B4_OUT Setbit(DDRB,4)
#define PIN_B5_OUT Setbit(DDRB,5)
#define PIN_B6_OUT Setbit(DDRB,6)
#define PIN_B7_OUT Setbit(DDRB,7)
#define PIN_B4_IN  Clrbit(DDRB,4)
#define PIN_B5_IN  Clrbit(DDRB,5)
#define PIN_B6_IN  Clrbit(DDRB,6)
#define PIN_B7_IN  Clrbit(DDRB,7)
//DIRECCIONAMIENTO DDRD
#define PIN_D4_OUT Setbit(DDRD,4)
#define PIN_D5_OUT Setbit(DDRD,5)
#define PIN_D6_OUT Setbit(DDRD,6)
#define PIN_D7_OUT Setbit(DDRD,7)
#define PIN_D4_IN  Clrbit(DDRD,4)
#define PIN_D5_IN  Clrbit(DDRD,5)
#define PIN_D6_IN  Clrbit(DDRD,6)
#define PIN_D7_IN  Clrbit(DDRD,7)
//DIRECCIONAMIENTO DDRE
#define PIN_E5_OUT Setbit(DDRE,5)
#define PIN_E6_OUT Setbit(DDRE,6)
#define PIN_E7_OUT Setbit(DDRE,7)
#define PIN_E5_IN  Clrbit(DDRE,5)
#define PIN_E6_IN  Clrbit(DDRE,6)
#define PIN_E7_IN  Clrbit(DDRE,7)

#define PB4_ON Clrbit(PORTB,4)
#define PB4_OFF Setbit(PORTB,4)
#define PB4_CHG Tglbit(PORTB,4)
#define PD4_ON Clrbit(PORTD,4)
#define PD4_OFF Setbit(PORTD,4)
#define PD4_CHG Tglbit(PORTD,4)
#define PD5_ON Clrbit(PORTD,5)
#define PD5_OFF Setbit(PORTD,5)
#define PD5_CHG Tglbit(PORTD,5)
#define PD7_ON Clrbit(PORTD,7)
#define PD7_OFF Setbit(PORTD,7)
#define PD7_CHG Tglbit(PORTD,7)
#define PD6_CHG Tglbit(PORTD,6)

#endif /* MYDEFS_H_ */



