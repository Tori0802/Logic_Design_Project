/*
 * global.h
 *
 *  Created on: Sep 30, 2022
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "lcd1602.h"
#include "rtc.h"
#include "main.h"

/*---------------Define Mode----------------------------------------------------------*/
// Mode INIT
#define INIT				0

// Mode 1: REAL-TIME CLOCK
#define MODE1				1

// Mode 2: SPORT CLOCK
#define MODE2				2
#define COUNT_PER			21
#define COUNT_CHANGE		22
#define MEM1				23
#define MEM2				24
#define	MEM3				25

// Mode 3: ALARM CLOCK
#define MODE3				3
#define ALARM_CLOCK			31
#define SET_ALARM_HOUR		32
#define SET_ALARM_MINUTE	33
#define SET_ALARM_SECOND	34


/*---------------Define struct time and functions --------------------------------*/
/*---------------         (Use to FSM)         -----------------------------------*/
// Struct time
typedef struct {
	int	sec;
	int min;
	int hour;
}TIME_STRUCT;
// Functions
TIME_STRUCT time_init(TIME_STRUCT time);
TIME_STRUCT time_update(TIME_STRUCT time);


/*---------------Variables------------------------------------------------------------*/
// Real Time Clock
extern RTC_TimeTypeDef rTime;
extern RTC_DateTypeDef rDate;

// LCD 1602
extern Lcd_HandleTypeDef lcd;

// FSM Clock
extern TIME_STRUCT sport_time;		// Mode 2 - counter
extern TIME_STRUCT mem1_time;		// Mode 2 - memcall1
extern TIME_STRUCT mem2_time;		// Mode 2 - memcall2
extern TIME_STRUCT mem3_time;		// Mode 2 - memcall3
extern TIME_STRUCT alarm_time;		// Mode 3 - alarm
extern int alarm_flag;				// Flag alarm-clock

// Variables status
extern int status;
extern int m2_status;
extern int m3_status;
extern int m2_run;

#endif /* INC_GLOBAL_H_ */
