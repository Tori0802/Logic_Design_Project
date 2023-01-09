/*
 * rtc.h
 *
 *  Created on: Jan 9, 2023
 *      Author: dell
 */

#ifndef INC_RTC_H_
#define INC_RTC_H_

#include "main.h"
#include "lcd1602.h"
#include "global.h"

/*---------------- Public functions -----------------------------------*/
void set_time(void);
void get_time(void);
void display_time(void);


#endif /* INC_RTC_H_ */
