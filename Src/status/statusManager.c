/**
  ******************************************************************************
  * @file    statusControl.c
  * @brief   Contolling of the devices's status implementation.
  * @author	Quack
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "status/statusManager.h"

/* External variables --------------------------------------------------------*/
/* Internal variables --------------------------------------------------------*/

/**
* @brief This function initializes status manager module
*/
void SC_Init()
{
	SLED_Init(SM_CHECK_DELAY);
	
	HAL_Delay(1000);
	return;
}

/**
* @brief This function makes cyclic operations of status manager
* @param Actual sysTic timer
* @return Time of next execution
*/
uint16_t SC_Run(uint16_t timer)
{
	// Check device's status
	E_TYPE status =	checkStatus();
	
	// Set LEDs according to status
	SLED_setLeds(status);
	SLED_aliveRun();
	
	return (u_int16_t)(timer + SM_CHECK_DELAY);
}

/**
* @brief This function checks the status of device
* @return E_TYPE general state of device
*/
E_TYPE checkStatus()
{
	return E_OK;
}

/* END OF FILE ****************************************************************/