/*
 * hal.c
 *
 *  Created on: Mar 20, 2016
 *      Author: shapa
 */

#include "stm32f4xx_hal.h"

static void initGPIO_USART1_Trace(void);
static void initGPIO_USART2(void);
static void initGPIO_UART4(void);
static void initGPIO_CAN(void);
static void initGPIO_PWM(void);
static void initGPIO_USB(void);
static void initGPIO_Spi5(void);
static void initGPIO_LTDC(void);

void HAL_USART_MspInit(USART_HandleTypeDef *husart) {

	if (husart->Instance == USART1) {
		__HAL_RCC_GPIOA_CLK_ENABLE();
		__HAL_RCC_USART1_CLK_ENABLE();
		__HAL_RCC_DMA2_CLK_ENABLE();
		initGPIO_USART1_Trace();
	} else if (husart->Instance == USART2) {
		__HAL_RCC_GPIOD_CLK_ENABLE();
		__HAL_RCC_USART2_CLK_ENABLE();
		initGPIO_USART2();
	}
}

void HAL_UART_MspInit(UART_HandleTypeDef *husart) {

	if (husart->Instance == UART4) {
		__HAL_RCC_GPIOC_CLK_ENABLE();
		__HAL_RCC_UART4_CLK_ENABLE();
		initGPIO_UART4();
	}
}

void HAL_CAN_MspInit(CAN_HandleTypeDef *hcan) {

	if (hcan->Instance == CAN1) {
		__HAL_RCC_GPIOD_CLK_ENABLE();
		__HAL_RCC_CAN1_CLK_ENABLE();
		initGPIO_CAN();
	}
}

void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim) {
	if (htim->Instance == TIM1) {
		__HAL_RCC_GPIOA_CLK_ENABLE();
		__HAL_RCC_TIM1_CLK_ENABLE();
		initGPIO_PWM();
	}
}

void HAL_PCD_MspInit(PCD_HandleTypeDef *hpcd) {
	if (hpcd->Instance == USB_OTG_FS) {
		__HAL_RCC_USB_OTG_FS_CLK_ENABLE();
	} else if (hpcd->Instance == USB_OTG_HS) {
		__HAL_RCC_USB_OTG_HS_CLK_ENABLE();
	}
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	initGPIO_USB();
}

void HAL_PCD_MspDeInit(PCD_HandleTypeDef *hpcd) {
	if (hpcd->Instance == USB_OTG_FS) {
		__HAL_RCC_USB_OTG_FS_CLK_DISABLE();
	} else if (hpcd->Instance == USB_OTG_HS) {
		__HAL_RCC_USB_OTG_HS_CLK_DISABLE();
	} else {
		__HAL_RCC_USB_OTG_FS_CLK_DISABLE();
		__HAL_RCC_USB_OTG_HS_CLK_DISABLE();
	}
}

void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi) {
	if (hspi->Instance == SPI5) {
		initGPIO_Spi5();
		__HAL_RCC_SPI5_CLK_ENABLE();
	}
}

void HAL_LTDC_MspInit(LTDC_HandleTypeDef* hltdc) {
	if (hltdc->Instance == LTDC) {
		RCC_PeriphCLKInitTypeDef phClk;
		__HAL_RCC_PLLSAI_ENABLE();
		__HAL_RCC_LTDC_CLK_ENABLE();
		__HAL_RCC_DMA2D_CLK_ENABLE();
		initGPIO_LTDC();
		HAL_RCCEx_GetPeriphCLKConfig(&phClk);
		phClk.PeriphClockSelection = RCC_PERIPHCLK_LTDC;
		phClk.PLLSAIDivR = RCC_PLLSAIDIVR_16;
		HAL_RCCEx_PeriphCLKConfig(&phClk);
	}
}


static void initGPIO_USART1_Trace(void) {

	GPIO_InitTypeDef iface = {
			GPIO_PIN_9 | GPIO_PIN_10,
			GPIO_MODE_AF_PP,
			GPIO_NOPULL,
			GPIO_SPEED_FREQ_HIGH,
			GPIO_AF7_USART1
	};
	HAL_GPIO_Init(GPIOA, &iface);
}

static void initGPIO_USART2(void) {

	GPIO_InitTypeDef iface = {
			GPIO_PIN_5 | GPIO_PIN_6,
			GPIO_MODE_AF_PP,
			GPIO_NOPULL,
			GPIO_SPEED_FREQ_HIGH,
			GPIO_AF7_USART2
	};
	HAL_GPIO_Init(GPIOD, &iface);
}

static void initGPIO_UART4(void) {

	GPIO_InitTypeDef iface = {
			GPIO_PIN_10 | GPIO_PIN_11,
			GPIO_MODE_AF_PP,
			GPIO_NOPULL,
			GPIO_SPEED_FREQ_HIGH,
			GPIO_AF8_UART4
	};
	HAL_GPIO_Init(GPIOC, &iface);
}

static void initGPIO_CAN() {
	GPIO_InitTypeDef iface = {
			GPIO_PIN_0 | GPIO_PIN_1,
			GPIO_MODE_AF_PP,
			GPIO_NOPULL,
			GPIO_SPEED_FREQ_LOW,
			GPIO_AF9_CAN1
	};
	HAL_GPIO_Init(GPIOD, &iface);
}

static void initGPIO_PWM(void) {
	GPIO_InitTypeDef iface = {
			GPIO_PIN_8,
			GPIO_MODE_AF_PP,
			GPIO_NOPULL,
			GPIO_SPEED_FREQ_LOW,
			GPIO_AF1_TIM1
	};
	HAL_GPIO_Init(GPIOA, &iface);
}

static void initGPIO_USB(void) {
//	PB12 - USB_OTG_ID
//	PB13 - USB_OTG_VBUS
//	PB14 - USB_OTG_DM
//	PB15 - USB_OTG_DP
//	PC4 - USB_PSO
//	PC5 - USB_OC

	GPIO_InitTypeDef iface = {
			GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15,
			GPIO_MODE_AF_PP,
			GPIO_NOPULL,
			GPIO_SPEED_FREQ_VERY_HIGH,
			GPIO_AF12_OTG_HS_FS
	};
	GPIO_InitTypeDef ifacePSO = {
			GPIO_PIN_4,
			GPIO_MODE_OUTPUT_PP,
			GPIO_NOPULL,
			GPIO_SPEED_FREQ_LOW,
			0
	};
	GPIO_InitTypeDef ifaceOC = {
			GPIO_PIN_5,
			GPIO_MODE_INPUT,
			GPIO_NOPULL,
			GPIO_SPEED_FREQ_LOW,
			0
	};
	HAL_GPIO_Init(GPIOB, &iface);
	HAL_GPIO_Init(GPIOC, &ifacePSO);
	HAL_GPIO_Init(GPIOC, &ifaceOC);
}

static void initGPIO_Spi5(void) {
	GPIO_InitTypeDef iface = {
			GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9,
			GPIO_MODE_AF_PP,
			GPIO_NOPULL,
			GPIO_SPEED_FREQ_HIGH,
			GPIO_AF5_SPI5
	};

	__HAL_RCC_GPIOF_CLK_ENABLE();
	HAL_GPIO_Init(GPIOF, &iface);
}



static void initGPIO_LTDC(void) {
	GPIO_InitTypeDef iface = {
			GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_6 | GPIO_PIN_11 | GPIO_PIN_12,
			GPIO_MODE_AF_PP,
			GPIO_NOPULL,
			GPIO_SPEED_FREQ_HIGH,
			GPIO_AF14_LTDC
	};

	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOF_CLK_ENABLE();
	__HAL_RCC_GPIOG_CLK_ENABLE();

	HAL_GPIO_Init(GPIOA, &iface);

	iface.Pin = GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11;
	HAL_GPIO_Init(GPIOB, &iface);
	iface.Pin = GPIO_PIN_0 | GPIO_PIN_1;
	iface.Alternate = GPIO_AF9_LTDC;
	HAL_GPIO_Init(GPIOB, &iface);

	iface.Pin = GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_10;
	iface.Alternate = GPIO_AF14_LTDC;
	HAL_GPIO_Init(GPIOC, &iface);

	iface.Pin = GPIO_PIN_3 | GPIO_PIN_6;
	HAL_GPIO_Init(GPIOD, &iface);

	iface.Pin = GPIO_PIN_10 | GPIO_PIN_6;
	HAL_GPIO_Init(GPIOF, &iface);

	iface.Pin = GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_11;
	HAL_GPIO_Init(GPIOG, &iface);

	iface.Pin = GPIO_PIN_10 | GPIO_PIN_12;
	iface.Alternate = GPIO_AF9_LTDC;
	HAL_GPIO_Init(GPIOG, &iface);
}

