/**
  ******************************************************************************
  * @file	statusLED.h
  * @brief	Status leds controlling header.
  * @author	Quack
  ******************************************************************************
  */

/* Prevent recursive inclusion ----------------------------------------------*/
#pragma once

#ifdef __cplusplus
 extern "C" {
#endif 
	 
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal_gpio.h"

#include "mxconstants.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
	 
/* Delay between alive LED states */
#define SLED_ALV_DELAY_MS 1000

/* Exported macro ------------------------------------------------------------*/
/* Alive LED port and pin */
#define SLED_ALV_PORTPIN GPIOD, GPIO_PIN_15
/* OK State LED port and pin */
#define SLED_OK_PORTPIN GPIOD, GPIO_PIN_12
/* Warning LED port and pin */
#define SLED_WARN_PORTPIN GPIOD, GPIO_PIN_13
/* Error LED port and pin */
#define SLED_ERR_PORTPIN GPIOD, GPIO_PIN_14


/* Exported functions ------------------------------------------------------- */

void SLED_Init(uint16_t SMcycleTime);

void SLED_aliveRun(void);

void SLED_setLeds(E_TYPE status);

void SLED_setOWELeds(void);
void SLED_clearOWELeds(void);


/******************************************************************************/
/* Controll functions of single LEDs                                          */ 
/******************************************************************************/

static inline void SLED_setErrorLed();
static inline void SLED_clearErrorLed();

static inline void SLED_setWarningLed();
static inline void SLED_clearWarningLed();

static inline void SLED_setOKLed();
static inline void SLED_clearOKLed();

	 
#ifdef __cplusplus
}
#endif

/* END OF FILE ****************************************************************/