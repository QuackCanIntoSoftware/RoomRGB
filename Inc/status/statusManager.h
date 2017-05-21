/**
  ******************************************************************************
  * @file	statusManager.h
  * @brief	Status manager header.
  * @author	Quack
  ******************************************************************************
  */

/* Prevent recursive inclusion ----------------------------------------------*/
#pragma once

#ifdef __cplusplus
extern "C" {
#endif 
	 
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

#include "mxconstants.h"
#include "statusLED.h"

/* Exported types ------------------------------------------------------------*/
struct internalStatus_t
{
	uint8_t status;
	uint8_t errors;
};
	 
/* Exported constants --------------------------------------------------------*/
#define SM_CHECK_DELAY 100
/* Exported functions ------------------------------------------------------- */
void SC_Init(void);
uint16_t SC_Run(uint16_t timer);  

E_TYPE checkStatus();
	
	 
#ifdef __cplusplus
}
#endif

/* END OF FILE ****************************************************************/