#include "status/statusLED.h"




void SLED_Init()
{
	SLED_setOWELeds();
	SLED_clearOWELeds();
}

void SLED_aliveRun()
{
	static uint16_t delay;
	if (delay > SLED_ALV_DELAY_MS)
	{
		HAL_GPIO_TogglePin(SLED_ALV_PORTPIN);
		delay = 0;
	}
	delay++;
	return;
}


void SLED_setLeds(E_TYPE status)
{
	SLED_clearOWELeds();
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

void SLED_clearOWELeds(void)
{
	SLED_clearOKLed();
	SLED_clearWarningLed();
	SLED_clearErrorLed();
}


void SLED_setOWELeds(void)
{
	SLED_setOKLed();
	SLED_setWarningLed();
	SLED_setErrorLed();
}

static inline void SLED_setErrorLed()
{
	HAL_GPIO_WritePin(SLED_ERR_PORTPIN, GPIO_PIN_SET);
}

static inline void SLED_clearErrorLed()
{
	HAL_GPIO_WritePin(SLED_ERR_PORTPIN, GPIO_PIN_RESET);
}

static inline void SLED_setWarningLed()
{
	HAL_GPIO_WritePin(SLED_WARN_PORTPIN, GPIO_PIN_SET);
}

static inline void SLED_clearWarningLed()
{
	HAL_GPIO_WritePin(SLED_WARN_PORTPIN, GPIO_PIN_RESET);
}

static inline void SLED_setOKLed()
{
	HAL_GPIO_WritePin(SLED_OK_PORTPIN, GPIO_PIN_SET);
}

static inline void SLED_clearOKLed()
{
	HAL_GPIO_WritePin(SLED_OK_PORTPIN, GPIO_PIN_RESET);
}

