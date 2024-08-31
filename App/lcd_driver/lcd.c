/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-08-31 10:07:19
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-08-31 15:04:34
 * @FilePath: \H7xx_Cmake_2\App\lcd_driver\lcd.c
 * @Description: 
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */
#include "lcd.h"

uint16_t LCD_RGB233toRGB565(uint8_t color)
{
  uint8_t  blue[] = {0,11,21,31}; //��ɫ2-5λ��ɫ���ұ�
  uint16_t color16 = 0;
  //        =====Green=====     ===============Red==============
  color16=(color & 0x1C)<<6|(color&0xC0)<<5|(color&0xE0)<<8;
  //        =====Green=====    =======Blue======
  color16|=(color&0x1C)<<3|blue[color&0x03];
  return color16;	
}
/******************************************************************************
      ����˵������ָ�����������ɫ
      ������ݣ�xs,ys   ��ʼ����
                xe,ye   ��ֹ����
								color       Ҫ������ɫ
      ����ֵ��  ��
******************************************************************************/
void LCD_Fill(uint16_t xs,uint16_t ys,uint16_t xe,uint16_t ye,uint32_t color)
{
	uint16_t i,j;
	uint8_t Color[2]={color>>8,color&0xff};
	LCD_Address_Set(xs,ys,xe-1,ye-1);
	LCD_WR_REG(0x2C);
	for(i=ys;i<ye;i++)
	{
		for(j=xs;j<xe;j++)
		{
			LCD_4LineTransmit_DATA(0x3C,2,Color);
		}
	}
}



