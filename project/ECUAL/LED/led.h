/*
 * led.h
 *
 * Created: 9/27/2022 12:02:00 AM
 *  Author: M.shokri
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO/dio.h"

void LED_init(uint8_t ledport,uint8_t ledpin );
void LED_on(uint8_t ledport,uint8_t ledpin );
void LED_off(uint8_t ledport,uint8_t ledpin );
void LED_toggle(uint8_t ledport,uint8_t ledpin );







#endif /* LED_H_ */