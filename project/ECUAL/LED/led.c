/*
 * led.c
 *
 * Created: 9/27/2022 12:03:10 AM
 *  Author: M.shokri
 */ 
#include "led.h"


void LED_init(uint8_t ledport,uint8_t ledpin ){
	DIO_int(ledport, ledpin , OUT);
	
	
}
void LED_on(uint8_t ledport,uint8_t ledpin ){
	DIO_write(ledport , ledpin ,HIGH );
	
}
void LED_off(uint8_t ledport,uint8_t ledpin ){
	DIO_write(ledport , ledpin ,LOW );
	
	
}
void LED_toggle(uint8_t ledport,uint8_t ledpin ){
	DIO_toggle(ledport , ledpin) ; 
	
}
