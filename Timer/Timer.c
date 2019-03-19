#include "Timer.h"

// ARM A9 Private Timer Load
volatile unsigned int *private_timer_load      = (unsigned int *) 0xFFFEC600;
	    // ARM A9 Private Timer Value
volatile unsigned int *private_timer_value     = (unsigned int *) 0xFFFEC604;
	    // ARM A9 Private Timer Control
volatile unsigned int *private_timer_control   = (unsigned int *) 0xFFFEC608;
	    // ARM A9 Private Timer Interrupt
volatile unsigned int *private_timer_interrupt = (unsigned int *) 0xFFFEC60C;

int timerStartValue;

void timer_Start(){
//initialise
//start timer
	int timerS = 0;
	*private_timer_load = 100000000;
	    // Set the "Prescaler" value to 0, Enable the timer (E = 1), Set Automatic reload
	    // on overflow (A = 1), and disable ISR (I = 0)
	*private_timer_control = (0 << 8) | (0 << 2) | (1 << 1) | (1 << 0);

	timerS = *private_timer_value;

	timerStartValue = timerS;
}

int timer_Stop(){
//stop timer
//print timer end value
//print difference
	int timerEndValue = *private_timer_value;
	int timerDuration = timerStartValue - timerEndValue;
	int freqTimer =  1/225000000 * timerDuration;
	float FPS = 1/(4.44e-9 * timerDuration);
	int FPSint = FPS;
	int freq = freqTimer;

	*private_timer_control   = 0;

	return FPSint;
}
