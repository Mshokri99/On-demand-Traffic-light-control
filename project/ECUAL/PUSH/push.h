/*
 * push.h
 *
 * Created: 9/27/2022 12:13:26 AM
 *  Author: M.shokri
 */ 


#ifndef PUSH_H_
#define PUSH_H_
#define HIGH_P 1 
#define LOW_P  0
#include "../../MCAL/DIO/dio.h"




 

void push_int(uint8_t pushport , uint8_t pushpin);
void push_read(uint8_t pushport , uint8_t pushpin , uint8_t *value);






#endif /* PUSH_H_ */