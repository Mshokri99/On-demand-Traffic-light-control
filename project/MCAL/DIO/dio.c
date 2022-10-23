/*
 * dio.c
 *
 * Created: 9/26/2022 11:40:35 PM
 *  Author: M.shokri
 */ 
// include low layer
//include .h
#include "dio.h"


// global variables
// func definition
void DIO_int(uint8_t portnumber , uint8_t pinnumber , uint8_t diriction){
	switch(portnumber){
		case PORT_A:
		if(diriction == IN){
			DDRA &= ~(1<<pinnumber); // clear (input)
		}
		else if(diriction == OUT){
			DDRA |= (1<<pinnumber);   // OUTPUT
		}
		break;
		case PORT_B:
		if(diriction == IN){
			DDRB &= ~(1<<pinnumber); // clear (input)
		}
		else if(diriction == OUT){
			DDRB |= (1<<pinnumber);   // OUTPUT
		}
		break;
		case PORT_C:
		if(diriction == IN){
			DDRC &= ~(1<<pinnumber); // clear (input)
		}
		else if(diriction == OUT){
			DDRC |= (1<<pinnumber);   // OUTPUT
		}
		break;
		case PORT_D:
		if(diriction == IN){
			DDRD &= ~(1<<pinnumber); // clear (input)
		}
		else if(diriction == OUT){
			DDRD |= (1<<pinnumber);   // OUTPUT
		}
		break;
		
		
	}
	
	
	
}
void DIO_write(uint8_t portnumber , uint8_t pinnumber , uint8_t value){
	
	switch(portnumber){
		case PORT_A:
		if(value == LOW){
			PORTA &= ~(1<<pinnumber); // WRITE 0
		}
		else if(value == HIGH){
			PORTA |= (1<<pinnumber);   // WRITE 1
		}
		break;
		case PORT_B:
		if(value == LOW){
			PORTB &= ~(1<<pinnumber); // WRITE 0
		}
		else if(value == HIGH){
			PORTB |= (1<<pinnumber);   // WRITE 1
		}
		break;
		case PORT_C:
		if(value == LOW){
			PORTC &= ~(1<<pinnumber); // WRITE 0
		}
		else if(value == HIGH){
			PORTC |= (1<<pinnumber);   // WRITE 1
		}
		break;
		case PORT_D:
		if(value == LOW){
			PORTD &= ~(1<<pinnumber); // WRITE 0
		}
		else if(value == HIGH){
			PORTD |= (1<<pinnumber);   // WRITE 1
		}
		break;
		
	}

}


uint8_t DIO_read(uint8_t portnumber , uint8_t pinnumber , uint8_t *value){
	
	switch(portnumber){
		case PORT_A:
			
			*value = ((PINA&(1<<pinnumber))>>pinnumber);
		break;
		case PORT_B:
			
			 *value = ((PINB&(1<<pinnumber))>>pinnumber);
		break;
		case PORT_C:
			
			 *value = ((PINC&(1<<pinnumber))>>pinnumber);
		break;
		case PORT_D:
			
			 *value = ((PIND&(1<<pinnumber))>>pinnumber);
		break;
	}
	
	
}

void DIO_toggle(uint8_t portnumber , uint8_t pinnumber) {
switch(portnumber){
	case PORT_A:
	PORTA ^= (1<<pinnumber);
		break;
	case PORT_B:
	PORTB ^= (1<<pinnumber);
	
	break;
	case PORT_C:
	PORTC ^= (1<<pinnumber);
	
	break;
	case PORT_D:
	PORTD ^= (1<<pinnumber);
	
	break;
}
}