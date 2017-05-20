#pragma once

#include "stm32f4xx_hal_gpio.h"

#include "Constants.h"

#define SLED_ALV_PORTPIN GPIOD, GPIO_PIN_15
#define SLED_ALV_DELAY_MS 1000

#define SLED_OK_PORTPIN GPIOD, GPIO_PIN_12
#define SLED_WARN_PORTPIN GPIOD, GPIO_PIN_13
#define SLED_ERR_PORTPIN GPIOD, GPIO_PIN_14

void SLED_Init(void);

void SLED_aliveRun(void);

void SLED_setLeds(E_TYPE status);

void SLED_setOWELeds(void);
void SLED_clearOWELeds(void);


static inline void SLED_setErrorLed();
static inline void SLED_clearErrorLed();

static inline void SLED_setWarningLed();
static inline void SLED_clearWarningLed();

static inline void SLED_setOKLed();
static inline void SLED_clearOKLed();