/*
 * ISR.h
 *
 *  Created on: 19 may. 2020
 *      Author: Juan 
 */

#ifndef ISR_H_
#define ISR_H_
#define SET_INT0_ON  	   EIMSK|=(1<<INT0)
#define SET_INT0_OFF 	   EIMSK&=~(1<<INT0)
#define SET_INT0_FALLING   EICRA|=(1<<ISC01)|(0<<ISC00)
#define SET_INT0_RISING    EICRA|=(1<<ISC01)|(1<<ISC00)
#define SET_INT0_CHGLOG    EICRA|=(0<<ISC01)|(1<<ISC00)
#define SET_INT0_LOWLEVEL  EICRA|=(0<<ISC01)|(0<<ISC00)

#define SET_INT1_ON  	   EIMSK|=(1<<INT1)
#define SET_INT1_OFF 	   EIMSK&=~(1<<INT1)
#define SET_INT1_FALLING   EICRA|=(1<<ISC11)|(0<<ISC10)
#define SET_INT1_RISING    EICRA|=(1<<ISC11)|(1<<ISC10)
#define SET_INT1_CHGLOG    EICRA|=(0<<ISC11)|(1<<ISC10)
#define SET_INT1_LOWLEVEL  EICRA|=(0<<ISC11)|(0<<ISC10)

#define SET_INT2_ON  	   EIMSK|=(1<<INT2)
#define SET_INT2_OFF 	   EIMSK&=~(1<<INT2)
#define SET_INT2_FALLING   EICRA|=(1<<ISC21)|(0<<ISC20)
#define SET_INT2_RISING    EICRA|=(1<<ISC21)|(1<<ISC20)
#define SET_INT2_CHGLOG    EICRA|=(0<<ISC21)|(1<<ISC20)
#define SET_INT2_LOWLEVEL  EICRA|=(0<<ISC21)|(0<<ISC20)

#define SET_INT3_ON  	   EIMSK|=(1<<INT3)
#define SET_INT3_OFF 	   EIMSK&=~(1<<INT3)
#define SET_INT3_FALLING   EICRA|=(1<<ISC31)|(0<<ISC30)
#define SET_INT3_RISING    EICRA|=(1<<ISC31)|(1<<ISC30)
#define SET_INT3_CHGLOG    EICRA|=(0<<ISC31)|(1<<ISC30)
#define SET_INT3_LOWLEVEL  EICRA|=(0<<ISC31)|(0<<ISC30)



#define SET_INT4_ON  	   EIMSK|=(1<<INT4)
#define SET_INT4_OFF 	   EIMSK&=~(1<<INT4)
#define SET_INT4_FALLING   EICRB|=(1<<ISC41)|(0<<ISC40)
#define SET_INT4_RISING    EICRB|=(1<<ISC41)|(1<<ISC40)
#define SET_INT4_CHGLOG    EICRB|=(0<<ISC41)|(1<<ISC40)
#define SET_INT4_LOWLEVEL  EICRB|=(0<<ISC41)|(0<<ISC40)

#define SET_INT5_ON  	   EIMSK|=(1<<INT5)
#define SET_INT5_OFF 	   EIMSK&=~(1<<INT5)
#define SET_INT5_FALLING   EICRB|=(1<<ISC51)|(0<<ISC50)
#define SET_INT5_RISING    EICRB|=(1<<ISC51)|(1<<ISC50)
#define SET_INT5_CHGLOG    EICRB|=(0<<ISC51)|(1<<ISC50)
#define SET_INT5_LOWLEVEL  EICRB|=(0<<ISC51)|(0<<ISC50)

#define SET_INT6_ON  	   EIMSK|=(1<<INT6)
#define SET_INT6_OFF 	   EIMSK&=~(1<<INT6)
#define SET_INT6_FALLING   EICRB|=(1<<ISC61)|(0<<ISC60)
#define SET_INT6_RISING    EICRB|=(1<<ISC61)|(1<<ISC60)
#define SET_INT6_CHGLOG    EICRB|=(0<<ISC61)|(1<<ISC60)
#define SET_INT6_LOWLEVEL  EICRB|=(0<<ISC61)|(0<<ISC60)

#define SET_INT7_ON  	   EIMSK|=(1<<INT7)
#define SET_INT7_OFF 	   EIMSK&=~(1<<INT7)
#define SET_INT7_FALLING   EICRB|=(1<<ISC71)|(0<<ISC70)
#define SET_INT7_RISING    EICRB|=(1<<ISC71)|(1<<ISC70)
#define SET_INT7_CHGLOG    EICRB|=(0<<ISC71)|(1<<ISC70)
#define SET_INT7_LOWLEVEL  EICRB|=(0<<ISC71)|(0<<ISC70)

#define SET_INT4567_ON 	   EIMSK|=(1<<INT4)|(1<<INT5)|(1<<INT6)|(1<<INT7)
#define SET_INT567_ON 	   EIMSK|=(1<<INT5)|(1<<INT6)|(1<<INT7)


#endif /* ISR_H_ */
