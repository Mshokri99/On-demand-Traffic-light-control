/*
 * app.h
 *
 * Created: 9/28/2022 6:06:27 PM
 *  Author: M.shokri
 */ 


#ifndef APP_H_
#define APP_H_
#include "../MCAL/DIO/dio.h"
#include "../ECUAL/LED/led.h"
#include "../ECUAL/PUSH/push.h"
#include "../ECUAL/TIMERS/timers.h"
#include "../Utilities/register.h"
#include "../Utilities/interrupts.h"
#include "../Utilities/types.h"


void APP_init(void);
void APP_start(void);




#endif /* APP_H_ */