/*
 * push.c
 *
 * Created: 9/27/2022 12:13:13 AM
 *  Author: M.shokri
 */ 

#include "push.h"



void push_int(uint8_t pushport , uint8_t pushpin){
	DIO_int(pushport , pushpin , IN );
	
}

void push_read(uint8_t pushport , uint8_t pushpin , uint8_t* value){
	 DIO_read(pushport , pushpin , value); 
	
	
}