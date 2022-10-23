/*
 * register.h
 *
 * Created: 9/26/2022 11:38:02 PM
 *  Author: M.shokri
 */ 


#ifndef REGISTER_H_
#define REGISTER_H_
typedef unsigned char uint8_t ;

// PORTA REGISTER
#define PORTA *((volatile uint8_t*)(0X3B)) // 8 bit register  ref to pointer
#define DDRA *((volatile uint8_t*)(0X3A))
#define PINA *((volatile uint8_t*)(0X39))
// PORTB REGISTER
#define PORTB *((volatile uint8_t*)(0X38)) // 8 bit register  ref to pointer
#define DDRB *((volatile uint8_t*)(0X37))
#define PINB *((volatile uint8_t*)(0X36))
// PORTC REGISTER
#define PORTC *((volatile uint8_t*)(0X35)) // 8 bit register  ref to pointer
#define DDRC *((volatile uint8_t*)(0X34))
#define PINC *((volatile uint8_t*)(0X33))
// PORTD REGISTER
#define PORTD *((volatile uint8_t*)(0X32)) // 8 bit register  ref to pointer
#define DDRD *((volatile uint8_t*)(0X31))
#define PIND *((volatile uint8_t*)(0X30))


// Timer0 REGISTERS

#define TCCR0 (*(volatile uint8_t*)(0x53))
#define TCNT0 (*(volatile uint8_t*)(0x52))
#define TIFR (*(volatile uint8_t*)(0x58))
//#define TIMSK (*(volatile uint8_t*)(0x59))



// Interrupt REGISTERS

#define SREG (*(volatile uint8_t*)(0x5F))
#define GICR (*(volatile uint8_t*)(0x5B))
#define MCUCR (*(volatile uint8_t*)(0x55))

#endif /* REGISTER_H_ */