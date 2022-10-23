/*
 * timers.c
 *
 * Created: 9/27/2022 5:45:39 PM
 *  Author: M.shokri
 */ 

#include "timers.h"
#include <math.h>

void TIMER_init(){
	TCCR0 = 0x00; //normal mode
	
}
void TIMER_delay(uint16_t Tdelay){
	uint16_t Noverflows,TimerInitial;
	double Tmaxdelay,Ttick;
	uint32_t overFlowcnt=0;
	
	Ttick = 256.0/1000.0; // Ttick = Presca/FCPU
	Tmaxdelay= 65.536; // Tmaxdelay = Ttick * 2^8
	
	if(Tdelay < Tmaxdelay){
		TimerInitial = (65.536 - Tdelay)/Ttick;
		Noverflows = 1;
		
		}
	if(Tdelay == Tmaxdelay){
		TimerInitial=0;
		Noverflows=1;
		}
	 if(Tdelay > Tmaxdelay){
		Noverflows = ceil((double)Tdelay/Tmaxdelay);
		TimerInitial = 256 - ((double)Tdelay/Ttick)/(Noverflows);
		
	}
	//timer set initial value 
	TCNT0 = TimerInitial;
	//start timer  --  set prescaler 256 
	TCCR0 |= (1<<2); 
	
	while(overFlowcnt < Noverflows){
		//busy wait
		while(((TIFR & (1<<0)) == 0));
		//clear overflow flag TOV0
		TIFR|=(1<<0);
		//increment counter
		overFlowcnt++;
	}
	//Timer stop to be  initial = 0 
	TCCR0 = 0x00;
}