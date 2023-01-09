/*
 * mode2.h
 *
 *  Created on: Nov 1, 2022
 *      Author: dell
 */

#ifndef INC_FSM_CLOCK_H_
#define INC_FSM_CLOCK_H_

#include "global.h"
#include "rtc.h"
#include "lcd1602.h"
#include "button.h"
#include "software_timer.h"
#include "main.h"
#include "string.h"


/*--------------- Public functions --------------------------*/
void fsm_init();
void fsm_clock();
void fsm_sport_clock();
void fsm_alarm_clock();
void update_real_time();


#endif /* INC_FSM_CLOCK_H_ */
