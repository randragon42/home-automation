/*
 *  RASPBERRY PI HOME AUTOMATION REMOTE FUNCTIONS
 *
 *	This file contains functions to perform operations
 *	to turn lights on and off.
 *
 *
 *
 *	Typical input looks like:
 *
 *	remote 1 ON
 */
 
#include <pigpio.h>

//match light number with gpio pin
#def LIGHT1_ON 5
#def LIGHT2_ON 6
#def LIGHT3_ON 12
#def LIGHT4_ON 13
#def LIGHT5_ON 16

#def LIGHT1_OFF 18
#def LIGHT2_OFF 19
#def LIGHT3_OFF 20
#def LIGHT4_OFF 21
#def LIGHT5_OFF 26

#def WAIT_TIME 250



int initialize(){
	
	// Call this necessary function
	if (gpioInitialise() < 0)
	{
		// pigpio initialisation failed.
		return -1;
	}
	
	// Set all GPIO pins to be used as outputs
	gpioSetMode(LIGHT1_ON, PI_OUTPUT);
	gpioSetMode(LIGHT2_ON, PI_OUTPUT);
	gpioSetMode(LIGHT3_ON, PI_OUTPUT);
	gpioSetMode(LIGHT4_ON, PI_OUTPUT);
	gpioSetMode(LIGHT5_ON, PI_OUTPUT);
	gpioSetMode(LIGHT1_OFF, PI_OUTPUT);
	gpioSetMode(LIGHT2_OFF, PI_OUTPUT);
	gpioSetMode(LIGHT3_OFF, PI_OUTPUT);
	gpioSetMode(LIGHT4_OFF, PI_OUTPUT);
	gpioSetMode(LIGHT5_OFF, PI_OUTPUT);
	
	return 0;
}

/*
	Turns on a specified light.
 */
void turnOn(int GPIO_num){
	if(GPIO_num == LIGHT1_ON || GPIO_num == LIGHT2_ON || GPIO_num == LIGHT3_ON || GPIO_num == LIGHT4_ON || GPIO_num == LIGHT5_ON){
		gpioWrite(GPIO_num, 1); // Set gpio high.
		delay(WAIT_TIME);
		gpioWrite(GPIO_num, 0); // Set gpio low.
	}
}

/*
	Turns off a specified light.
*/
void turnOff(int GPIO_num){
	if(GPIO_num == LIGHT1_OFF || GPIO_num == LIGHT2_OFF || GPIO_num == LIGHT3_OFF || GPIO_num == LIGHT4_OFF || GPIO_num == LIGHT5_OFF){
		gpioWrite(GPIO_num, 1); // Set gpio high.
		delay(WAIT_TIME)
		gpioWrite(GPIO_num, 0); // Set gpio low.
	}
}


int main(int argc, char *argv[]){
	
	// Check for correct number of arguments
	if(argc != 3){
		return(-1)
	}
	int GPIO_num = *(argv[1])[1]
	
	if(strcmp(argv[2], "ON\0") == 0){
		turnOn(argv[1])
	}
	else if(strcmp(argv[2], "OFF\0") == 0){
		turnOff(argv[1]);
	}
	else{
		return(-1)
	}
	
	return 0;
}