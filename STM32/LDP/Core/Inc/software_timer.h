 /*
 * software_timer.h
 *
 *  Created on: Sep 30, 2022
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

/*--------------- Defines ----------------------------------------*/
#define NUM_OF_TIMERS 	5  				// Number of Timers to use
/* We have 5 timers:
	Timer 1 (index = 0): Update RTC (1s)
	Timer 2 (index = 1): Update Sport-time clock (Mode 2) (1s)
	Timer 3 (index = 2): Max time to signal buzzer (Mode 3) (30s)
	Timer 4 (index = 3): Time to set on buzzer (1s)
	Timer 5 (index = 4): Time to set off buzzer (1s)

	Function of timer 4 and 5 same as toggle buzzer
*/

/*--------------- Public variables ----------------------------------------*/
extern int TIME_CYCLE;					// Time cycle
extern int timer_flag[NUM_OF_TIMERS];	// Flag


/*--------------- Public functions ----------------------------------------*/
void setTimer(int index, int duration);
void clearTimer(int index);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
