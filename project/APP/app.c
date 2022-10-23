/*
 * app.c
 *
 * Created: 9/28/2022 6:06:41 PM
 *  Author: M.shokri
 */ 
#include "app.h"
//#include <avr/delay.h>
uint8_t car_led=0; //0 green 1 yellow 2 red
uint8_t prev_car_led=1;
uint8_t normalmode = 0; //1 normal 0 pedestrian

void APP_init(void)
{
	
	//Car LED initialization
	LED_init(PORT_A,0);
	LED_init(PORT_A,1);
	LED_init(PORT_A,2);

	//Pedestrian LED initialization
	LED_init(PORT_B,0);
	LED_init(PORT_B,1);
	LED_init(PORT_B,2);
	
	//Button initialization
	push_int(PORT_D , 2);
	
	//Timer initialization
	TIMER_init();
	
	//Enable Global interrupts & setup rising edge detection for button
	sei();
	RISING_EDGE_SETUP();
	SETUP_INT0();
}
void APP_start(void){
	//variable to be used in for loop
	uint8_t i;
	
	//if normal mode or need transition (i.e. car green led or yellow is on)
	if(normalmode || car_led==0 || car_led==1){
		if(!normalmode){
			car_led=1;
		}
		//Configuring Pedestrian LEDs
		LED_off(PORT_B,0);
		LED_off(PORT_B,1);
		//LED_on(PORT_B,2);
		
		
		switch(car_led){
			//Case GREEN LED
			case 0:
			LED_on(PORT_A,0);
			LED_off(PORT_A,1);
			LED_off(PORT_A,2);
			
			for(i=0;i<74;i++){
				TIMER_delay(68);
				if(!normalmode)break;//check if ISR was called
			}
			car_led=1;  // IF !normalmode Y_CAR 
			prev_car_led=0;
			break;
			//Case YELLOW LED
			case 1:
			//if PED then we need to blink both(PRESS WHEN Y --> PED R & BLINK BOTH Y)
			
			if(!normalmode){
				// TIME BTWEEN Y -- R (BLINKED OF Y)
				if(prev_car_led!=2){  
					LED_on(PORT_B,2);
					//blink both yellow leds
					for(i=0;i<5;i++){
						LED_on(PORT_A,1);
						LED_on(PORT_B,1);
						TIMER_delay(500);
						LED_off(PORT_A,1);
						LED_off(PORT_B,1);
						TIMER_delay(500);
						//LED_on(PORT_A,1);
						//LED_on(PORT_B,1);
						//TIMER_delay(390);
					}
				}
				prev_car_led=1;
				car_led=2;
				LED_on(PORT_A,2);
				}
				else{
				//blink car yellow led
				for(i=0;i<5;i++){
					LED_on(PORT_A,1);
					TIMER_delay(500);
					LED_off(PORT_A,1);
					TIMER_delay(500);
					//LED_on(PORT_A,1);
					//TIMER_delay(380);
					if(!normalmode){//check if ISR was called
						prev_car_led=1;
						LED_on(PORT_A,1); 
						break;
					}
				}
			}
			LED_off(PORT_A,1);
			LED_off(PORT_B,1);
			//Configure variables for correct switching
			if(prev_car_led==0){
				car_led=2;
				prev_car_led=1;
				}else if(prev_car_led==2){
				car_led=0;
				prev_car_led=1;
			}
			break;
			//Case RED LED
			case 2:
			LED_off(PORT_A,0);
			LED_off(PORT_A,1);
			LED_on(PORT_A,2);
			for(i=0;i<50;i++){
				TIMER_delay(68);
				if(!normalmode)break;
			}
			prev_car_led=2;
			car_led=1;
			break;
			default:        //START FROM GREEN 
			car_led=2;
			prev_car_led=1;
			break;
		}
		
		}
		// IF CARLED=2  && !NORMALMODE 
		else{ 
		//Configure PEDES LEDs
		LED_on(PORT_B,0);
		LED_off(PORT_B,1);
		LED_off(PORT_B,2);
		
		//Configure CAR LEDs
		LED_off(PORT_A,0);
		LED_off(PORT_A,1);
		LED_on(PORT_A,2);
		TIMER_delay(5000);//5 sec delay
		
		//make sure car red light is off
		LED_off(PORT_A,2);
		
		//blink both yellow while ped green is on
		for(i=0;i<5;i++){
			LED_on(PORT_A,1);
			LED_on(PORT_B,1);
			TIMER_delay(500);
			LED_off(PORT_A,1);
			LED_off(PORT_B,1);
			TIMER_delay(500);
		}
		//Turn off yellow LEDs
		LED_off(PORT_A,1);
		LED_off(PORT_B,1);
		//turn on PED red LED
		LED_on(PORT_B,2);
		//reset normalmode
		normalmode=1;
		//Configure car_led variables
		car_led=0;
		prev_car_led=1;
	}
	
}


ISR(EXT_INT_0){
	normalmode=0 ; 
}