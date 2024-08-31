/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-08-31 10:07:19
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-08-31 10:51:57
 * @FilePath: \H7xx_Cmake_2\App\lcd_driver\QSPI.c
 * @Description:
 *
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved.
 */
#include "QSPI.h"
#include "main.h"
QSPI_HandleTypeDef QSPI_Handler;
QSPI_CommandTypeDef QSPI_CmdInitStructure;

void QSPI_GPIOInit(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	__HAL_RCC_GPIOE_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_QSPI_CLK_ENABLE();

	GPIO_InitStructure.Pin = GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13;
	GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStructure.Alternate = GPIO_AF9_QUADSPI;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = GPIO_PIN_2;
	GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStructure.Alternate = GPIO_AF9_QUADSPI;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = GPIO_PIN_6;
	GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStructure.Alternate = GPIO_AF10_QUADSPI;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = GPIO_PIN_2;
	GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStructure.Alternate = GPIO_AF9_QUADSPI;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStructure);
}

void QSPI_Init(void)
{
	QSPI_Handler.Instance = QUADSPI;
	QSPI_Handler.Init.ChipSelectHighTime = QSPI_CS_HIGH_TIME_1_CYCLE; // ƬѡΪ����ʱ
	QSPI_Handler.Init.ClockMode = QSPI_CLOCK_MODE_3;				  // ����ʱ��ģʽ
	QSPI_Handler.Init.ClockPrescaler = 8 - 1;						  // ����ʱ�ӷ�Ƶ��
	QSPI_Handler.Init.DualFlash = QSPI_DUALFLASH_DISABLE;			  // ����˫����ģʽ״̬
	QSPI_Handler.Init.FifoThreshold = 32;							  // ����FIFO���ֽ���ֵ�����ڼ��ģʽʹ�ã�
	QSPI_Handler.Init.FlashID = QSPI_FLASH_ID_1;					  // ����ʹ�õ�����
	QSPI_Handler.Init.FlashSize = 20;								  // ���������С
	QSPI_Handler.Init.SampleShifting = QSPI_SAMPLE_SHIFTING_NONE;	  // ���ò�����λ
	HAL_QSPI_Init(&QSPI_Handler);

	QSPI_CmdInitStructure.Instruction = 0x32;
	QSPI_CmdInitStructure.Address     = 0x000000;
	QSPI_CmdInitStructure.DummyCycles = 0;
	QSPI_CmdInitStructure.InstructionMode = QSPI_INSTRUCTION_1_LINE;
	QSPI_CmdInitStructure.AddressMode  = QSPI_ADDRESS_1_LINE;
	QSPI_CmdInitStructure.AddressSize  = QSPI_ADDRESS_24_BITS;
	QSPI_CmdInitStructure.DataMode     = QSPI_DATA_NONE;
	QSPI_CmdInitStructure.NbData       = 0;
	QSPI_CmdInitStructure.SIOOMode     = QSPI_SIOO_INST_EVERY_CMD;
	QSPI_CmdInitStructure.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
	QSPI_CmdInitStructure.DdrMode      = QSPI_DDR_MODE_DISABLE;
	QSPI_CmdInitStructure.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
	
	HAL_NVIC_SetPriority(QUADSPI_IRQn, 0x0f, 0);
	HAL_NVIC_EnableIRQ(QUADSPI_IRQn);
}

void HAL_QSPI_MspDeInit(QSPI_HandleTypeDef* qspiHandle)
{

  if(qspiHandle->Instance==QUADSPI)
  {
    /* Peripheral clock disable */
    __HAL_RCC_QSPI_CLK_DISABLE();

    HAL_GPIO_DeInit(GPIOE, GPIO_PIN_2);

    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_2|GPIO_PIN_6);

    HAL_GPIO_DeInit(GPIOD, GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13);
	  
	 /* ��λQSPI */
	__HAL_RCC_QSPI_FORCE_RESET();
	__HAL_RCC_QSPI_RELEASE_RESET();

    /* QUADSPI MDMA DeInit */
    HAL_MDMA_DeInit(qspiHandle->hmdma);

    /* QUADSPI interrupt Deinit */
    HAL_NVIC_DisableIRQ(QUADSPI_IRQn);
	  
	/* MDMA interrupt Deinit */
    HAL_NVIC_DisableIRQ(MDMA_IRQn);
  }
}

