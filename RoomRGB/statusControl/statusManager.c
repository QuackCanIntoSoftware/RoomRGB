/**
  ******************************************************************************
  * @file    statusControl.c
  * @brief   Contolling of the devices'status
  ******************************************************************************
  */
#include "statusControl.h"


void SC_Init()
{
#ifdef MODULE_STATUS_LED
	SLED_Init();
#endif // MODULE_STATUS_LED
	
	HAL_Delay(1000);
	return;
}


void SC_Run()
{
	E_TYPE status =	checkStatus();
	
#ifdef MODULE_STATUS_LED
	SLED_setLeds(status);
	SLED_aliveRun();
	
#endif // MODULE_STATUS_LED
	
	return;

}

E_TYPE checkStatus()
{
	return E_OK;
}