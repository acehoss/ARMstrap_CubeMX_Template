/*
 * platform_config.h
 *
 *  Created on: Jan 2, 2015
 *      Author: aaron
 */

#ifndef PLATFORM_CONFIG_H_
#define PLATFORM_CONFIG_H_

#include <stm32f4xx_hal_gpio.h>
#include <stm32f4xx_hal_spi.h>

#define USER_BUTTON_PORT     GPIOC
#define USER_BUTTON_PIN      GPIO_PIN_0

#define USER_LED_PORT        GPIOC
#define USER_LED_PIN         GPIO_PIN_1

#define DEBUG_UART_DEVICE    (&huart2)
#define DEBUG_LED_PORT       USER_LED_PORT
#define DEBUG_LED_PIN        USER_LED_PIN

#define FLASH_CS_PORT        GPIOC
#define FLASH_CS_PIN         GPIO_PIN_13
#define FLASH_SPI_DEVICE     (&hspi3)

extern UART_HandleTypeDef huart2;
extern SPI_HandleTypeDef hspi3;

#endif /* PLATFORM_CONFIG_H_ */
