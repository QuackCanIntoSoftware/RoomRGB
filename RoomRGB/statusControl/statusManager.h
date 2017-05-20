#pragma once

#include "Constants.h"
#include "stm32f4xx_hal.h"

//modules enable
#define MODULE_STATUS_LED
#define MODULE_MAIN_LEDS


#ifdef MODULE_STATUS_LED
#include "statusLED.h"
#endif // MODULE_STATUS_LED

struct internalStatus_t
{
	uint8_t status;
	uint8_t errors;
};



void SC_Init(void);
void SC_Run(void);  


E_TYPE checkStatus();