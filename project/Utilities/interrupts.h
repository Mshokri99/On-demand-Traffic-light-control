/*
 * interrupts.h
 *
 * Created: 9/28/2022 5:58:30 PM
 *  Author: M.shokri
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "register.h"

//Interrupt vectors
#define EXT_INT_0 __vector_1
#define EXT_INT_1 __vector_2

//Enable interrupts
#define sei()  __asm__ __volatile__ ("sei" ::: "memory") //enable global interrupts
#define cli()  __asm__ __volatile__ ("cli" ::: "memory") //disable global interrupts

//Rising edge
#define RISING_EDGE_SETUP() MCUCR|= (1<<1) | (1<<0)

//Setup use INT0 bit 6
#define SETUP_INT0() GICR|=(1<<6)


//ISR macro
#define ISR(INT_VECT) \
void INT_VECT(void) __attribute__ ((signal,used)); \
void INT_VECT(void) 

/*#define ISR(vector, ...)            \
void vector (void) _attribute_ ((signal,_INTR_ATTRS)) __VA_ARGS_; \
void vector (void)*/

#endif /* INTERRUPTS_H_ */