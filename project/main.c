/*
 * GccApplication2.c
 *
 * Created: 9/26/2022 11:24:13 PM
 * Author : M.shokri
 */ 

//#include <avr/io.h>
/*#include "MCAL/DIO/dio.h"
#include "ECUAL/LED/led.h"
#include "ECUAL/PUSH/push.h"
#include "ECUAL/TIMERS/timers.h"
#include "Utilities/register.h"*/
 #include "APP/app.h"
 
 int main(void){
	    //Initialize
	    APP_init();
	    
	    //Main loop
	    while(1){
		    APP_start();
	    }
 }
