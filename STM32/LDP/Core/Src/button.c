/*
 * button.c
 *
 *  Created on: Oct 7, 2022
 *      Author: dell
 */

#include "button.h"

/*--------------- Set times -----------------------------------------------------*/
int longkeyPress = 1500;
int change_statelongkey = 200;


/*--------------- Set up variables ----------------------------------------------*/
// Create a list of variables for vibrations, signals processing, and handles
// 	push button for two modes (bouncePress and longPress)
int KeyReg0[NUM_OF_BUTTONS] = {NORMAL_STATE};
int KeyReg1[NUM_OF_BUTTONS] = {NORMAL_STATE};
int KeyReg2[NUM_OF_BUTTONS] = {NORMAL_STATE};
int KeyReg3[NUM_OF_BUTTONS] = {NORMAL_STATE};

// Initial flags for each mode button (button_flag (bouncePress) and buttonlong_flag (longPress))
int button_flag[NUM_OF_BUTTONS] = {0};
int buttonlong_flag[NUM_OF_BUTTONS] = {0};

// Initial cycle counter variable to to determine two possible events of the button press
int TimeOutForKeyPress[NUM_OF_BUTTONS] = {0};


/*--------------- Functions -----------------------------------------------------*/
// Determine if button_flag == 1
int isButtonPressed(int index) {
	if (button_flag[index] == 1) {
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

// Set flag = 1
void subKeyProcess(int index){
	button_flag[index] = 1;
}

void getKeyInput() {
	for (int i = 0; i < NUM_OF_BUTTONS; i++) {
		KeyReg0[i] = KeyReg1[i];	// Vibrations
		KeyReg1[i] = KeyReg2[i];
		// Read signals from buttons
		if (i == 0) {
			KeyReg2[i] = HAL_GPIO_ReadPin(MODE_GPIO_Port, MODE_Pin); 				// MODE
		}
		else if (i == 1) {
			KeyReg2[i] = HAL_GPIO_ReadPin(START_UP_GPIO_Port, START_UP_Pin); 		// START_UP
		}
		else if (i == 2) {
			KeyReg2[i] = HAL_GPIO_ReadPin(STOP_DOWN_GPIO_Port, STOP_DOWN_Pin); 		// STOP_DOWN
		}
		else if (i == 3) {
			KeyReg2[i] = HAL_GPIO_ReadPin(SAVE_SET_GPIO_Port, SAVE_SET_Pin); 		// SAVE_SET
		}
		else if (i == 4) {
			KeyReg2[i] = HAL_GPIO_ReadPin(CLEAR_GPIO_Port, CLEAR_Pin); 				// CLEAR
		}
		else {
			KeyReg2[i] = HAL_GPIO_ReadPin(MEMCALL_GPIO_Port, MEMCALL_Pin); 			// MEMCALL
		}
		// Signal processing
		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
			if (KeyReg3[i] != KeyReg2[i]){
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg2[i] == PRESSED_STATE){
					subKeyProcess(i);	// Kich timer_flag[i] = 1;
					if (buttonlong_flag[i] == 0) {
						TimeOutForKeyPress[i] = longkeyPress / TIME_CYCLE; 			// Set timer for longPress event
					}
					else {
						TimeOutForKeyPress[i] = change_statelongkey / TIME_CYCLE;  	// Set timer for change_statelongPress
					}
				}
			} else {
				TimeOutForKeyPress[i]--;
				// If after the TimeOutForKeyPress first period, the button is open, then buttonlong_flag[i] = 1, otherwise it = 0.
				if (TimeOutForKeyPress[i] == 0){
					KeyReg3[i] = NORMAL_STATE;
					buttonlong_flag[i] = 1;
				}
			}
		}
		else {
			buttonlong_flag[i] = 0;
		}
	}
}

