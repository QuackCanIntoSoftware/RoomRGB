/**
  ******************************************************************************
  * @file	statusLED.c
  * @brief	Status leds controlling implementation.
  * @author	Quack
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "status/statusLED.h"

/* External variables --------------------------------------------------------*/
/* Internal variables --------------------------------------------------------*/
uint16_t cycleDelay;

/**
* @brief This function initializes status LEDs module
*/
void SLED_Init(uint16_t SMcycleTime)
{
	cycleDelay = SLED_ALV_DELAY_MS / SMcycleTime;
	SLED_setOWELeds();
	SLED_clearOWELeds();
}

/**
* @brief This function handles behavior of alive LED.
*/
void SLED_aliveRun()
{
	static uint16_t delay = 0;
	if (delay > cycleDelay)
	{
		HAL_GPIO_TogglePin(SLED_ALV_PORTPIN);
		delay = 0;
	}
	delay++;
	return;
}

/**
* @brief This function sets LEDs according to actual status
* @param E_TYPE Actual status of the device
*/
void SLED_setLeds(E_TYPE status)
{
	SLED_clearOWELeds();
	
	//Set proper led on
	if (status == E_OK)
	{
		SLED_setOKLed();
	}
	else if (status == E_WARNING)
	{
		SLED_setWarningLed();
	}
	else
	{
		SLED_setWarningLed();
	}
}

/**
* @brief This function turns off OK, Warning and Error LED
*/
void SLED_clearOWELeds(void)
{
	SLED_clearOKLed();
	SLED_clearWarningLed();
	SLED_clearErrorLed();
}

/**
* @brief This function turns on OK, Warning and Error LED
*/
void SLED_setOWELeds(void)
{
	SLED_setOKLed();
	SLED_setWarningLed();
	SLED_setErrorLed();
}

/**
* @brief This function turns on Error LED
*/
static inline void SLED_setErrorLed()
{
	HAL_GPIO_WritePin(SLED_ERR_PORTPIN, GPIO_PIN_SET);
}

/**
* @brief This function turns off Error LED
*/
static inline void SLED_clearErrorLed()
{
	HAL_GPIO_WritePin(SLED_ERR_PORTPIN, GPIO_PIN_RESET);
}

/**
* @brief This function turns on Warning LED
*/
static inline void SLED_setWarningLed()
{
	HAL_GPIO_WritePin(SLED_WARN_PORTPIN, GPIO_PIN_SET);
}

/**
* @brief This function turns off Warning LED
*/
static inline void SLED_clearWarningLed()
{
	HAL_GPIO_WritePin(SLED_WARN_PORTPIN, GPIO_PIN_RESET);
}

/**
* @brief This function turns on OK LED
*/
static inline void SLED_setOKLed()
{
	HAL_GPIO_WritePin(SLED_OK_PORTPIN, GPIO_PIN_SET);
}

/**
* @brief This function turns off OK LED
*/
static inline void SLED_clearOKLed()
{
	HAL_GPIO_WritePin(SLED_OK_PORTPIN, GPIO_PIN_RESET);
}

/* END OF FILE ****************************************************************/