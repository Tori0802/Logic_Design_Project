/*
 * software_timer.c
 *
 *  Created on: Sep 30, 2022
 *      Author: Admin
 */

#include "software_timer.h"

/*--------------- Setup varables ------------------------------------------------ */
int TIME_CYCLE; 	// Time cycle

// Initialize arrays timer_counter and timer_flag with the number of elements each new array is NUM_OF_TIMERS
int timer_counter[NUM_OF_TIMERS] = {0};
int timer_flag[NUM_OF_TIMERS] = {0};


/*--------------- Functions ------------------------------------------------ */
// setTimer (index: Timer is considered; duration: setTimer time (unit: ms))
void setTimer(int index, int duration) {
	timer_counter[index] = duration / TIME_CYCLE;
	timer_flag[index] = 0;
}

// clearTimer (timer_flag[index] = 0, timer_counter[index] = 0)
void clearTimer(int index) {
	timer_counter[index] = 0;
	timer_flag[index] = 0;
}

// timerRun
void timerRun(){
	// Use "for" loop to see if it's time to use the Timer
	// With every Timer, the timer_counter cycle will be reduce, if timer_counter == 0 then the timer is disabled, timer_flag is set to state 1.
	for (int i = 0; i < NUM_OF_TIMERS; i++) {
		if (timer_counter[i] > 0){
			timer_counter[i]--;
			if (timer_counter[i] <= 0){
				timer_flag[i] = 1;
			}
		}
	}
}
