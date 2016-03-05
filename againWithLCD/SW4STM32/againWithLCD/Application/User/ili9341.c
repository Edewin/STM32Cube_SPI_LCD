/**
  ******************************************************************************
  * @file    ili9341.c
  * @author  MCD Application Team
  * @version V1.0.2
  * @date    02-December-2014
  * @brief   This file includes the LCD driver for ILI9341 LCD.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2014 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "ili9341.h"
#include "stm32f4xx_hal.h"

//extern void CS_Set(uint8_t state);
/** @addtogroup BSP
  * @{
  */ 

/** @addtogroup Components
  * @{
  */ 
  
/** @addtogroup ILI9341
  * @brief This file provides a set of functions needed to drive the 
  *        ILI9341 LCD.
  * @{
  */

/** @defgroup ILI9341_Private_TypesDefinitions
  * @{
  */ 
/**
  * @}
  */ 

/** @defgroup ILI9341_Private_Defines
  * @{
  */
/**
  * @}
  */ 
  
/** @defgroup ILI9341_Private_Macros
  * @{
  */
/**
  * @}
  */  

/** @defgroup ILI9341_Private_Variables
  * @{
  */ 

LCD_DrvTypeDef   ili9341_drv = 
{
  ili9341_Init,
  ili9341_ReadID,
  ili9341_DisplayOn,
  ili9341_DisplayOff,
  0,
  0,
  0,
  0,
  0,
  0,
  ili9341_GetLcdPixelWidth,
  ili9341_GetLcdPixelHeight,
  0,
  0,    
};

/**
  * @}
  */ 
  
/** @defgroup ILI9341_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */ 
  
/** @defgroup ILI9341_Private_Functions
  * @{
  */   

/**
  * @brief  Power on the LCD.
  * @param  None
  * @retval None
  */
void ili9341_Init(void)
{
  /* Initialize ILI9341 low level bus layer ----------------------------------*/
  LCD_IO_Init(); // aici ar trebui adaugate hardware reset LCD si-un delay
  
  /* Configure LCD */
  ili9341_WriteReg(LCD_SWRESET);
  LCD_Delay(50);
  ili9341_WriteReg(LCD_DISPLAY_OFF); //display off
 
	/*
	//----------------------------------
  ili9341_WriteReg(LCD_POWERB);	//0xCF
  ili9341_WriteData(0x00);
  ili9341_WriteData(0x83);
  ili9341_WriteData(0x30);
	
  
  ili9341_WriteReg(LCD_POWER_SEQ);  //0xED
  ili9341_WriteData(0x64);
  ili9341_WriteData(0x03);
  ili9341_WriteData(0x12);
  ili9341_WriteData(0x81);
  
  ili9341_WriteReg(LCD_DTCA);  //0xE8
  ili9341_WriteData(0x85);
  ili9341_WriteData(0x01);
  ili9341_WriteData(0x79);
 
  ili9341_WriteReg(LCD_POWERA); //0xCB
  ili9341_WriteData(0x39);
  ili9341_WriteData(0x2C);
  ili9341_WriteData(0x00);
  ili9341_WriteData(0x34);
  ili9341_WriteData(0x02);
  
  ili9341_WriteReg(LCD_PRC);	//0xF7
  ili9341_WriteData(0x20);
 
  ili9341_WriteReg(LCD_DTCB);	//0xEA
  ili9341_WriteData(0x00);
  ili9341_WriteData(0x00);
  

  
  
  ili9341_WriteReg(LCD_FRMCTR1);
  ili9341_WriteData(0x00);
  ili9341_WriteData(0x1B);
  ili9341_WriteReg(LCD_DFC);
  ili9341_WriteData(0x0A);
  ili9341_WriteData(0xA2);
  ili9341_WriteReg(LCD_POWER1);
  ili9341_WriteData(0x10);
  ili9341_WriteReg(LCD_POWER2);
  ili9341_WriteData(0x10);
  ili9341_WriteReg(LCD_VCOM1);
  ili9341_WriteData(0x45);
  ili9341_WriteData(0x15);
  ili9341_WriteReg(LCD_VCOM2);
  ili9341_WriteData(0x90);
  ili9341_WriteReg(LCD_MAC);
  ili9341_WriteData(0xC8);
  ili9341_WriteReg(LCD_3GAMMA_EN);
  ili9341_WriteData(0x00);
  ili9341_WriteReg(LCD_RGB_INTERFACE);
  ili9341_WriteData(0xC2);
  ili9341_WriteReg(LCD_DFC);
  ili9341_WriteData(0x0A);
  ili9341_WriteData(0xA7);
  ili9341_WriteData(0x27);
  ili9341_WriteData(0x04);
  */
  /* Colomn address set */
 /* ili9341_WriteReg(LCD_COLUMN_ADDR);
  ili9341_WriteData(0x00);
  ili9341_WriteData(0x00);
  ili9341_WriteData(0x00);
  ili9341_WriteData(0xEF);*/
  /* Page address set */
 /* ili9341_WriteReg(LCD_PAGE_ADDR);
  ili9341_WriteData(0x00);
  ili9341_WriteData(0x00);
  ili9341_WriteData(0x01);
  ili9341_WriteData(0x3F);
  ili9341_WriteReg(LCD_INTERFACE);
  ili9341_WriteData(0x01);
  ili9341_WriteData(0x00);
  ili9341_WriteData(0x06);
  
  ili9341_WriteReg(LCD_GRAM);
  LCD_Delay(200);
  
  ili9341_WriteReg(LCD_GAMMA);
  ili9341_WriteData(0x01);
  
  ili9341_WriteReg(LCD_PGAMMA);
  ili9341_WriteData(0x0F);
  ili9341_WriteData(0x31);
  ili9341_WriteData(0x2B);
  ili9341_WriteData(0x0C);
  ili9341_WriteData(0x0E);
  ili9341_WriteData(0x08);
  ili9341_WriteData(0x4E);
  ili9341_WriteData(0xF1);
  ili9341_WriteData(0x37);
  ili9341_WriteData(0x07);
  ili9341_WriteData(0x10);
  ili9341_WriteData(0x03);
  ili9341_WriteData(0x0E);
  ili9341_WriteData(0x09);
  ili9341_WriteData(0x00);
  ili9341_WriteReg(LCD_NGAMMA);
  ili9341_WriteData(0x00);
  ili9341_WriteData(0x0E);
  ili9341_WriteData(0x14);
  ili9341_WriteData(0x03);
  ili9341_WriteData(0x11);
  ili9341_WriteData(0x07);
  ili9341_WriteData(0x31);
  ili9341_WriteData(0xC1);
  ili9341_WriteData(0x48);
  ili9341_WriteData(0x08);
  ili9341_WriteData(0x0F);
  ili9341_WriteData(0x0C);
  ili9341_WriteData(0x31);
  ili9341_WriteData(0x36);
  ili9341_WriteData(0x0F);
  
  ili9341_WriteReg(LCD_SLEEP_OUT);
  LCD_Delay(200);
  ili9341_WriteReg(LCD_DISPLAY_ON);*/
  /* GRAM start writing */
 /* ili9341_WriteReg(LCD_GRAM);*/
 
 LCD_IO_WriteReg(LCD_POWERA);
	LCD_IO_WriteData(0x39);
	LCD_IO_WriteData(0x2C);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteData(0x34);
	LCD_IO_WriteData(0x02);
	LCD_IO_WriteReg(LCD_POWERB);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteData(0xC1);
	LCD_IO_WriteData(0x30);
	LCD_IO_WriteReg(LCD_DTCA);
	LCD_IO_WriteData(0x85);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteData(0x78);
	LCD_IO_WriteReg(LCD_DTCB);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteReg(LCD_POWER_SEQ);
	LCD_IO_WriteData(0x64);
	LCD_IO_WriteData(0x03);
	LCD_IO_WriteData(0x12);
	LCD_IO_WriteData(0x81);
	LCD_IO_WriteReg(LCD_PRC);
	LCD_IO_WriteData(0x20);
	LCD_IO_WriteReg(LCD_POWER1);
	LCD_IO_WriteData(0x23);
	LCD_IO_WriteReg(LCD_POWER2);
	LCD_IO_WriteData(0x10);
	LCD_IO_WriteReg(LCD_VCOM1);
	LCD_IO_WriteData(0x3E);
	LCD_IO_WriteData(0x28);
	LCD_IO_WriteReg(LCD_VCOM2);
	LCD_IO_WriteData(0x86);
	LCD_IO_WriteReg(LCD_MAC);
	LCD_IO_WriteData(0x48);
	LCD_IO_WriteReg(LCD_PIXEL_FORMAT);
	LCD_IO_WriteData(0x55);
	LCD_IO_WriteReg(LCD_FRMCTR1);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteData(0x18);
	LCD_IO_WriteReg(LCD_DFC);
	LCD_IO_WriteData(0x08);
	LCD_IO_WriteData(0x82);
	LCD_IO_WriteData(0x27);
	LCD_IO_WriteReg(LCD_3GAMMA_EN);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteReg(LCD_COLUMN_ADDR);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteData(0xEF);
	LCD_IO_WriteReg(LCD_PAGE_ADDR);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteData(0x01);
	LCD_IO_WriteData(0x3F);
	LCD_IO_WriteReg(LCD_GAMMA);
	LCD_IO_WriteData(0x01);
	LCD_IO_WriteReg(LCD_PGAMMA);
	LCD_IO_WriteData(0x0F);
	LCD_IO_WriteData(0x31);
	LCD_IO_WriteData(0x2B);
	LCD_IO_WriteData(0x0C);
	LCD_IO_WriteData(0x0E);
	LCD_IO_WriteData(0x08);
	LCD_IO_WriteData(0x4E);
	LCD_IO_WriteData(0xF1);
	LCD_IO_WriteData(0x37);
	LCD_IO_WriteData(0x07);
	LCD_IO_WriteData(0x10);
	LCD_IO_WriteData(0x03);
	LCD_IO_WriteData(0x0E);
	LCD_IO_WriteData(0x09);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteReg(LCD_NGAMMA);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteData(0x0E);
	LCD_IO_WriteData(0x14);
	LCD_IO_WriteData(0x03);
	LCD_IO_WriteData(0x11);
	LCD_IO_WriteData(0x07);
	LCD_IO_WriteData(0x31);
	LCD_IO_WriteData(0xC1);
	LCD_IO_WriteData(0x48);
	LCD_IO_WriteData(0x08);
	LCD_IO_WriteData(0x0F);
	LCD_IO_WriteData(0x0C);
	LCD_IO_WriteData(0x31);
	LCD_IO_WriteData(0x36);
	LCD_IO_WriteData(0x0F);
	LCD_IO_WriteReg(LCD_SLEEP_OUT);

	LCD_Delay(1000);

	LCD_IO_WriteReg(LCD_DISPLAY_ON);
	LCD_IO_WriteReg(LCD_GRAM);
 
 
}

/**
  * @brief  Disables the Display.
  * @param  None
  * @retval LCD Register Value.
  */
uint16_t ili9341_ReadID(void)
{
  LCD_IO_Init();
  return ((uint16_t)ili9341_ReadData(LCD_READ_ID4, LCD_READ_ID4_SIZE));
}

/**
  * @brief  Enables the Display.
  * @param  None
  * @retval None
  */
void ili9341_DisplayOn(void)
{
  /* Display On */
  ili9341_WriteReg(LCD_DISPLAY_ON);
}

/**
  * @brief  Disables the Display.
  * @param  None
  * @retval None
  */
void ili9341_DisplayOff(void)
{
  /* Display Off */
  ili9341_WriteReg(LCD_DISPLAY_OFF);
}

/**
  * @brief  Writes  to the selected LCD register.
  * @param  LCD_Reg: address of the selected register.
  * @retval None
  */
void ili9341_WriteReg(uint8_t LCD_Reg)
{
  LCD_IO_WriteReg(LCD_Reg);
}

/**
  * @brief  Writes data to the selected LCD register.
  * @param  LCD_Reg: address of the selected register.
  * @retval None
  */
void ili9341_WriteData(uint16_t RegValue)
{
  LCD_IO_WriteData(RegValue);
}

/**
  * @brief  Reads the selected LCD Register.
  * @param  RegValue: Address of the register to read
  * @param  ReadSize: Number of bytes to read
  * @retval LCD Register Value.
  */
uint32_t ili9341_ReadData(uint16_t RegValue, uint8_t ReadSize)
{
  /* Read a max of 4 bytes */
  return (LCD_IO_ReadData(RegValue, ReadSize));
}

/**
  * @brief  Get LCD PIXEL WIDTH.
  * @param  None
  * @retval LCD PIXEL WIDTH.
  */
uint16_t ili9341_GetLcdPixelWidth(void)
{
  /* Return LCD PIXEL WIDTH */
  return ILI9341_LCD_PIXEL_WIDTH;
}

/**
  * @brief  Get LCD PIXEL HEIGHT.
  * @param  None
  * @retval LCD PIXEL HEIGHT.
  */
uint16_t ili9341_GetLcdPixelHeight(void)
{
  /* Return LCD PIXEL HEIGHT */
  return ILI9341_LCD_PIXEL_HEIGHT;
}

/**
  * @}  LCD_Delay Implementation --> by Ed
  */ 
void LCD_Delay (uint32_t delay)
{
	HAL_Delay(delay);
}

/**
  * @}void     LCD_IO_Init(void);
  */ 
  __weak void LCD_IO_Init(void)
	{
		
	}
/**
  * @}
  */ 
__weak void     LCD_IO_WriteData(uint16_t RegValue)
{
	
}

__weak void     LCD_IO_WriteReg(uint8_t Reg)
{
	
}

__weak uint32_t LCD_IO_ReadData(uint16_t RegValue, uint8_t ReadSize)
{
//	uint32_t r;
//	return r;
}
/**
  * @}
  */
  
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
