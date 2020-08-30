/*
 * MyDefs.h
 *
 *  Created on: 18 may. 2020
 *      Author: crixt
 */

#ifndef MYDEFS_H_
#define MYDEFS_H_


#define SetBit(reg,bit) reg|=(1<<bit)
#define ClrBit(reg,bit)	reg&=~(1<<bit)
#define TglBit(reg,bit)	reg^=(1<<bit)
#define TestBit(reg,bit)	(reg & (1<<bit))

#//DIRECCIONAMIENTO DDRD
#define PIN_D4_OUT Setbit(DDRD,4)
#define PIN_D5_OUT Setbit(DDRD,5)
#define PIN_D6_OUT Setbit(DDRD,6)
#define PIN_D7_OUT Setbit(DDRD,7)
#define PIN_D4_IN  Clrbit(DDRD,4)
#define PIN_D5_IN  Clrbit(DDRD,5)
#define PIN_D6_IN  Clrbit(DDRD,6)
#define PIN_D7_IN  Clrbit(DDRD,7)
//DIRECCIONAMIENTO DDRE
#define PIN_E0_OUT Setbit(DDRE,0)
#define PIN_E1_OUT Setbit(DDRE,1)
#define PIN_E2_OUT Setbit(DDRE,2)
#define PIN_E3_OUT Setbit(DDRE,3)
#define PIN_E4_OUT Setbit(DDRE,4)
#define PIN_E5_OUT Setbit(DDRE,5)
#define PIN_E6_OUT Setbit(DDRE,6)
#define PIN_E7_OUT Setbit(DDRE,7)
#define PIN_E0_IN  Clrbit(DDRE,0)
#define PIN_E1_IN  Clrbit(DDRE,1)
#define PIN_E2_IN  Clrbit(DDRE,2)
#define PIN_E3_IN  Clrbit(DDRE,3)
#define PIN_E4_IN  Clrbit(DDRE,4)
#define PIN_E5_IN  Clrbit(DDRE,5)
#define PIN_E6_IN  Clrbit(DDRE,6)
#define PIN_E7_IN  Clrbit(DDRE,7)
//SALIDA PORTD
#define PD4_ON  ClrBit(PORTD,4)
#define PD4_OFF SetBit(PORTD,4)
#define PD4_CHG TglBit(PORTD,4)
#define PD5_ON  ClrBit(PORTD,5)
#define PD5_OFF SetBit(PORTD,5)
#define PD5_CHG TglBit(PORTD,5)
#define PD6_ON  ClrBit(PORTD,6)
#define PD6_OFF SetBit(PORTD,6)
#define PD6_CHG TglBit(PORTD,6)
#define PD7_ON  ClrBit(PORTD,7)
#define PD7_OFF SetBit(PORTD,7)
#define PD7_CHG TglBit(PORTD,7)
//SALIDA PORTE
#define PE0_ON  ClrBit(PORTE,0)
#define PE0_OFF SetBit(PORTE,0)
#define PE0_CHG TglBit(PORTE,0)
#define PE1_ON  ClrBit(PORTE,1)
#define PE1_OFF SetBit(PORTE,1)
#define PE1_CHG TglBit(PORTE,1)
#define PE2_ON  ClrBit(PORTE,2)
#define PE2_OFF SetBit(PORTE,2)
#define PE2_CHG TglBit(PORTE,2)
#define PE3_ON  ClrBit(PORTE,3)
#define PE3_OFF SetBit(PORTE,3)
#define PE3_CHG TglBit(PORTE,3)
#define PE4_ON  ClrBit(PORTE,4)
#define PE4_OFF SetBit(PORTE,4)
#define PE4_CHG TglBit(PORTE,4)
#define PE5_ON  ClrBit(PORTE,5)
#define PE5_OFF SetBit(PORTE,5)
#define PE5_CHG TglBit(PORTE,5)
#define PE6_ON  ClrBit(PORTE,6)
#define PE6_OFF SetBit(PORTE,6)
#define PE6_CHG TglBit(PORTE,6)
#define PE7_ON  ClrBit(PORTE,7)
#define PE7_OFF SetBit(PORTE,7)
#define PE7_CHG TglBit(PORTE,7)


#endif /* MYDEFS_H_ */
