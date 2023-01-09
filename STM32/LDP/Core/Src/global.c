/*
 * global.c
 *
 *  Created on: Sep 30, 2022
 *      Author: Admin
 */


#include "global.h"

/*---------------Function init time -------------------------------------------------------*/
// Init or clear time
TIME_STRUCT time_init(TIME_STRUCT time) {
	time.sec = 0;
	time.min = 0;
	time.hour = 0;
	return time;
}

// Update time (+1s)
TIME_STRUCT time_update(TIME_STRUCT time) {
	time.sec++;
	if (time.sec >= 60) {
		time.sec = 0;
		time.min++;
		if (time.min >= 60) {
			time.min = 0;
			time.hour++;
			if (time.hour >= 24) time.hour = 0;
		}
	}
	return time;
}


/*--------------- Init variables ----------------------------------------------------------*/
// RTC
RTC_TimeTypeDef rTime;
RTC_DateTypeDef rDate;

// LCD 1602
Lcd_HandleTypeDef lcd;

// FSM Clock
TIME_STRUCT sport_time;		// Mode 2 - counter
TIME_STRUCT mem1_time;		// Mode 2 - memcall1
TIME_STRUCT mem2_time;		// Mode 2 - memcall2
TIME_STRUCT mem3_time;		// Mode 2 - memcall3
TIME_STRUCT alarm_time;		// Mode 3 - alarm
int alarm_flag = 0;			// Flag alarm-clock

// Variables status
int status = INIT;
int m2_status = COUNT_PER;
int m3_status = ALARM_CLOCK;
int m2_run = 0;
