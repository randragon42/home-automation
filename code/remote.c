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
#def LIGHT3_ON 13
#def LIGHT4_ON 19
#def LIGHT5_ON 26

#def LIGHT1_OFF 12
#def LIGHT2_OFF 16
#def LIGHT3_OFF 20
#def LIGHT4_OFF 21
#def LIGHT5_OFF 25

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

/*
	Input should look like: "remote.cgi 1 ON"
*/
int main(int argc, char *argv[]){
	
	initialize();
	
	// Check for correct number of arguments
	if(argc != 3){
		return(-1);
	}
	int GPIO_num = *(argv[1])[1];
	

	
	
	if(strcmp(argv[2], "ON\0") == 0){
		switch (GPIO_num){
			case 1:
				GPIO_num = LIGHT1_ON;
				break;
			case 2:
				GPIO_num = LIGHT2_ON;
				break;
			case 3:
				GPIO_num = LIGHT3_ON;
				break;
			case 4:
				GPIO_num = LIGHT4_ON;
				break;
			case 5:
				GPIO_num = LIGHT5_ON;
				break
			default:
				return -1;
		}
		
		turnOn(GPIO_num);
	}
	else if(strcmp(argv[2], "OFF\0") == 0){
				switch (GPIO_num){
			case 1:
				GPIO_num = GPIO_num = LIGHT1_OFF;
				break;
			case 2:
				GPIO_num = GPIO_num = LIGHT1_OFF;
				break;
			case 3:
				GPIO_num = GPIO_num = LIGHT1_OFF;
				break;
			case 4:
				GPIO_num = GPIO_num = LIGHT1_OFF;
				break;
			case 5:
				GPIO_num = GPIO_num = LIGHT1_OFF;
				break;
			default:
				return(-1);
		}
		
		turnOff(GPIO_num);
	}
	else{
		return(-1);
	}
	
	return(0);
}