/*
 * dio.h
 *
 * Created: 9/26/2022 11:40:49 PM
 *  Author: M.shokri
 */ 


#ifndef DIO_H_
#define DIO_H_
// include .h
#include "../../Utilities/register.h"
#include "../../Utilities/types.h"


//typedef
typedef unsigned char uint8_t ;
//macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'
//DIRICTION
#define IN  0
#define OUT 1
//VALUE
#define HIGH 1
#define LOW  0


// diver func prototypes



void DIO_int(uint8_t portnumber , uint8_t pinnumber , uint8_t diriction); // initialize dio direction
void DIO_write(uint8_t portnumber , uint8_t pinnumber , uint8_t value);
void DIO_toggle(uint8_t portnumber , uint8_t pinnumber) ;
uint8_t DIO_read(uint8_t portnumber , uint8_t pinnumber , uint8_t* value);








#endif /* DIO_H_ */