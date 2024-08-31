/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-08-31 10:07:19
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-08-31 10:33:45
 * @FilePath: \H7xx_Cmake_2\App\lcd_driver\lcd_init.h
 * @Description: 
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */
#ifndef _LCD_INIT_H_
#define _LCD_INIT_H_

#include "QSPI.h"

/*
//SPD2010 ��֧�ֵ�������һ�����ص�
//��ϸ������ο� SPD2010 datasheet
//P15  QSPI Timing ʱ��˵�� 
//P48  14.1.18 Set Column(2AH) �Ĵ�������
*/
#include "stdint.h"

#define LCD_W 412
#define LCD_H 412


#define LCD_RES_Set() HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_SET);
#define LCD_RES_Clr() HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);


void LCD_WR_REG(uint8_t reg);
void LCD_Transmit_Byte(uint8_t reg,uint8_t dat);
void LCD_Transmit_DATA(uint8_t reg,uint32_t len,uint8_t *dat);
void LCD_4LineTransmit_Byte(uint8_t reg,uint8_t dat);
void LCD_4LineTransmit_DATA(uint8_t reg,uint32_t len,uint8_t *dat);
void LCD_Address_Set(uint16_t xs,uint16_t ys,uint16_t xe,uint16_t ye);

void LCD_Init(void);

#endif



