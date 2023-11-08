/*
 * clock.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Ali
 */

#ifndef INC_CLOCK_H_
#define INC_CLOCK_H_
#include "main.h"

void clock_config (void);
void clock_Systickconfig (uint32_t array);

void clock_msinitticks (void);
uint32_t  clock_msgetticks (void);
void clock_msdelay (uint32_t ms);
#endif /* INC_CLOCK_H_ */
