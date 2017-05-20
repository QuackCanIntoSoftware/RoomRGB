#pragma once

#include "Constants.h"
#include "stm32f4xx_hal.h"

//modules enable
#define MODULE_STATUS_LED

#ifdef MODULE_STATUS_LED
#include "statusLED.h"
#endif // MODULE_STATUS_LED


void SC_Init(void);
void SC_Run(void);  


E_TYPE checkStatus();