/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
#include "main.h"

#include "config.h"
#include "ov7670.h"

#include <stdio.h>
#include <string.h>



uint16_t snapshot_buff[IMG_ROWS * IMG_COLS];

uint8_t dma_flag = 0;

uint16_t NUM_BYTES = 25056;


void print_buf(void);


int main(void)
{
  /* Reset of all peripherals */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_DCMI_Init();
  MX_USART3_UART_Init();
  MX_USB_OTG_FS_PCD_Init();
  MX_I2C2_Init();
  MX_TIM1_Init();
  MX_TIM6_Init();

  char msg[100];

  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	
  ov7670_init();

  // Your start up code here
  print_msg("poop pooop!\r\n");

  
	
	
	const char PRE[]="\r\nPREAMBLE!\r\n";

  HAL_UART_Transmit(&huart3, (uint8_t*)PRE, sizeof(PRE)-1, HAL_MAX_DELAY);

  for (int i = 0; i < NUM_BYTES; i++) {
	  uint8_t zero = 0xFF;
		HAL_UART_Transmit(&huart3, &zero, 1, HAL_MAX_DELAY);
  }
	
  while (1){
    // Your code here
    if (HAL_GPIO_ReadPin(USER_Btn_GPIO_Port, USER_Btn_Pin)) {
      HAL_Delay(100);  // debounce
			
			ov7670_snapshot(snapshot_buff);
      print_msg("Snap!\r\n");
			
			// wait for dma_flag
			while (!dma_flag) {
				HAL_Delay(50);
			} 
			
			dma_flag = 0; // reset dma_flag
			// print_msg("dmg_flag triggered");
			
			print_buf();
		}
	}
}

// Send image data through serial port.
void print_buf() {
	
	const char PRE[]="\r\nPREAMBLE!\r\n";
	HAL_UART_Transmit(&huart3, (uint8_t*)PRE, sizeof(PRE)-1, HAL_MAX_DELAY);


	for (int i = 0; i < NUM_BYTES; i++) {
    // &snapshot_buff[i] provides the memory address of the byte
    // 1 is the size (sending 1 byte at a time)
		uint8_t *pixel_bytes = (uint8_t *)&snapshot_buff[i];
		
    HAL_UART_Transmit(&huart3, &pixel_bytes[1], 1, HAL_MAX_DELAY);
	}

	
/*
	 for (int i = 0; i < NUM_BYTES; i++) {
	  uint8_t zero = 0x00;
	  HAL_UART_Transmit(&huart3, &zero, 1, HAL_MAX_DELAY);
  }
	*/


  // Your code here
}
