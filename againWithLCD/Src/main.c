/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 STMicroelectronics
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
#include "stm32f4xx_hal.h"
#include "cmsis_os.h"

/* USER CODE BEGIN Includes */

#include "ili9341.h"
#include <string.h>

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;
DMA_HandleTypeDef hdma_spi1_tx;
DMA_HandleTypeDef hdma_spi1_rx;

UART_HandleTypeDef huart2;

osThreadId defaultTaskHandle;
osThreadId myTaskSPIHandle;
osTimerId myTimer01Handle;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */
	
	
	/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */

PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
  HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1,0xffff); 

  return ch;
}


typedef enum {
	TM_ILI9341_Orientation_Portrait_1,  /*!< Portrait orientation mode 1 */
	TM_ILI9341_Orientation_Portrait_2,  /*!< Portrait orientation mode 2 */
	TM_ILI9341_Orientation_Landscape_1, /*!< Landscape orientation mode 1 */
	TM_ILI9341_Orientation_Landscape_2  /*!< Landscape orientation mode 2 */
} TM_ILI9341_Orientation_t;


/**
 * @brief  Orientation
 * @note   Used private
 */
typedef enum {
	TM_ILI9341_Landscape,
	TM_ILI9341_Portrait
} TM_ILI9341_Orientation;

/**
 * @brief  LCD options
 * @note   Used private
 */
typedef struct {
	uint16_t width;
	uint16_t height;
	TM_ILI9341_Orientation orientation; // 1 = portrait; 0 = landscape
} TM_ILI931_Options_t;


/* Pin functions */
uint16_t ILI9341_x;
uint16_t ILI9341_y;
TM_ILI931_Options_t ILI9341_Opts;
uint8_t ILI9341_INT_CalledFromPuts = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_SPI1_Init(void);
static void MX_USART2_UART_Init(void);
void StartDefaultTask(void const * argument);
void StartTask02(void const * argument);
void Callback01(void const * argument);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

void mputs( uint8_t *desired_string );
void CS_Set(uint8_t state);
void DC_Set(uint8_t state);
void ili9341_DrawPixel(uint16_t x, uint16_t y, uint32_t color);
void ili9341_DrawHLine(uint16_t x0, uint16_t x1, uint16_t y0, uint32_t color);
void ili9341_DrawVLine(uint16_t x, uint16_t y0, uint16_t y1, uint32_t color);
void ILI9341_SetCursorPosition(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void ili9341_Rotate(TM_ILI9341_Orientation_t orientation);
void SetSpiDataSize(uint8_t size);
void TM_ILI9341_INT_Fill(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color) ;
void ili9341_Fill(uint32_t color);


/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

unsigned char counter = 0;

uint8_t TxBuff[4], RxBuff[4];




/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_SPI1_Init();
  MX_USART2_UART_Init();

  /* USER CODE BEGIN 2 */
	
	
	ili9341_Init();
	ili9341_DisplayOn();
	ili9341_Rotate(TM_ILI9341_Orientation_Landscape_1);
	//ili9341_Fill(ILI9341_COLOR_BLUE);
	
	TxBuff[0] = 0;
	TxBuff[1] = 1;
	TxBuff[2] = 3;
	TxBuff[3] = 5;
	
	ili9341_Fill(ILI9341_COLOR_RED);


  /* USER CODE END 2 */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* Create the timer(s) */
  /* definition and creation of myTimer01 */
  osTimerDef(myTimer01, Callback01);
  myTimer01Handle = osTimerCreate(osTimer(myTimer01), osTimerPeriodic, NULL);

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
	
	//osTimerStart(myTimer01Handle, 1000);
	
  /* USER CODE END RTOS_TIMERS */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of myTaskSPI */
  osThreadDef(myTaskSPI, StartTask02, osPriorityNormal, 0, 128);
  myTaskSPIHandle = osThreadCreate(osThread(myTaskSPI), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */
 

  /* Start scheduler */
  osKernelStart();
  
  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */
		

  }
  /* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

  __PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2);

  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 15, 0);
}

/* SPI1 init function */
void MX_SPI1_Init(void)
{

  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_HIGH;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLED;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLED;
  hspi1.Init.CRCPolynomial = 10;
  HAL_SPI_Init(&hspi1);

}

/* USART2 init function */
void MX_USART2_UART_Init(void)
{

  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  HAL_UART_Init(&huart2);

}

/** 
  * Enable DMA controller clock
  */
void MX_DMA_Init(void) 
{
  /* DMA controller clock enable */
  __DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);
  HAL_NVIC_SetPriority(DMA2_Stream3_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream3_IRQn);

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __GPIOC_CLK_ENABLE();
  __GPIOH_CLK_ENABLE();
  __GPIOA_CLK_ENABLE();
  __GPIOB_CLK_ENABLE();

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : Reset_Pin */
  GPIO_InitStruct.Pin = Reset_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(Reset_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : DC_Pin */
  GPIO_InitStruct.Pin = DC_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(DC_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : SPI_CS_Pin */
  GPIO_InitStruct.Pin = SPI_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(SPI_CS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(Reset_GPIO_Port, Reset_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(DC_GPIO_Port, DC_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, GPIO_PIN_RESET);

}

/* USER CODE BEGIN 4 */

void mputs( uint8_t *desired_string )
{
	HAL_UART_Transmit(&huart2, (uint8_t*) desired_string, (uint16_t)strlen(desired_string), 1000 );
}

void ili9341_DrawPixel(uint16_t x, uint16_t y, uint32_t color) 
{
	ILI9341_SetCursorPosition(x, y, x, y);

	ili9341_WriteReg(LCD_GRAM);
	
	HAL_SPI_Transmit(&hspi1, (uint8_t *)&color, 2, 1000);
	
	//ili9341_WriteData(color >> 8);
	//ili9341_WriteData(color & 0xFF);
}

void ili9341_DrawHLine(uint16_t x0, uint16_t x1, uint16_t y0, uint32_t color) 
{
	ILI9341_SetCursorPosition(x0, y0, x0, y0);

	ili9341_WriteReg(LCD_GRAM);
	
	int i, w;
	
	w = x1 - x0 + 1;
	
	for( i = 0; i<w; i++)
	{
		ili9341_DrawPixel(i, y0, color);
		//HAL_SPI_Transmit(&hspi1, (uint8_t *)&color, 2, 1000);
	}
}

void ili9341_DrawVLine(uint16_t x, uint16_t y0, uint16_t y1, uint32_t color) 
{
	ILI9341_SetCursorPosition(x, y0, x, y1);

	ili9341_WriteReg(LCD_GRAM);
	
	int i, h;
	
	h = y1 - y0 + 1;
	
	for( i = 0; i<h; i++)
	{
		ili9341_DrawPixel(x, i, color);
		//HAL_SPI_Transmit(&hspi1, (uint8_t *)&color, 2, 1000);
	}
}


void ILI9341_SetCursorPosition(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) 
{
	ili9341_WriteReg(LCD_COLUMN_ADDR);
	ili9341_WriteData(x1 >> 8);
	ili9341_WriteData(x1 & 0xFF);
	ili9341_WriteData(x2 >> 8);
	ili9341_WriteData(x2 & 0xFF);

	ili9341_WriteReg(LCD_PAGE_ADDR);
	ili9341_WriteData(y1 >> 8);
	ili9341_WriteData(y1 & 0xFF);
	ili9341_WriteData(y2 >> 8);
	ili9341_WriteData(y2 & 0xFF);
}

void SetSpiDataSize(uint8_t size)
{
	//disable SPI
	__HAL_SPI_DISABLE(&hspi1);
	
	//--setDataSize
	
	if(size == 16)
		hspi1.Instance->CR1 |= SPI_DATASIZE_16BIT;
	
	else  // switch to 8 bits data format
		hspi1.Instance->CR1 &= SPI_DATASIZE_8BIT;
	
	//enable SPI
	__HAL_SPI_ENABLE(&hspi1);
}

void ili9341_Fill(uint32_t color) 
{
	/* Fill entire screen */
	TM_ILI9341_INT_Fill(0, 0, ILI9341_Opts.width - 1, ILI9341_Opts.height, color);
}

void TM_ILI9341_INT_Fill(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color) 
{
	//uint32_t pixels_count;
	
	/* Set cursor position */
	ILI9341_SetCursorPosition(x0, y0, x1, y1);

	/* Set command for GRAM data */
	LCD_IO_WriteReg(LCD_GRAM);
	
	/* Calculate pixels count */
	//pixels_count = (x1 - x0 + 1) * (y1 - y0 + 1);

	/* Send everything */
//	CS_Set(0);
//	DC_Set(1);
	
	/* Go to 16-bit SPI mode */
//	SetSpiDataSize(16);

	uint16_t i,j;
	//
		for(i=x0;i<=x1;i++)
			for(j=y0;j<=y1;j++)
		
			{
				//ili9341_DrawPixel(i,j,color);  // slowest method

				// slow method
				/*uint8_t bufX, bufY;
				bufX = color >> 8;
				bufY = color & 0xff;
				
				HAL_SPI_Transmit(&hspi1, &bufX, 1, 1000);
				HAL_SPI_Transmit(&hspi1, &bufY, 1, 1000);*/
				
				// fastest method without DMA
				HAL_SPI_Transmit(&hspi1, (uint8_t *)&color, 2, 1000);
			}			
		
	//CS_Set(1);
	/* Go back to 8-bit SPI mode */
//	SetSpiDataSize(8);
}

void CS_Set(uint8_t state)
{
	if(state == 0)
		HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin,GPIO_PIN_RESET);
	else
		HAL_GPIO_WritePin( SPI_CS_GPIO_Port, SPI_CS_Pin,GPIO_PIN_SET);
}

void DC_Set(uint8_t state)
{
	if(state == 0)
	HAL_GPIO_WritePin(DC_GPIO_Port, DC_Pin ,GPIO_PIN_RESET);
	else
		HAL_GPIO_WritePin(DC_GPIO_Port, DC_Pin, GPIO_PIN_SET);
		
}

void LCD_IO_Init(void)
	{	
		HAL_GPIO_WritePin(Reset_GPIO_Port, Reset_Pin,GPIO_PIN_RESET); // reset_LCD is active LOW!!!!
		HAL_Delay(100);
		HAL_GPIO_WritePin(Reset_GPIO_Port,Reset_Pin,GPIO_PIN_SET); // reset_LCD is active LOW!!!!
		
		/* Set default settings */
		ILI9341_x = ILI9341_y = 0;
		ILI9341_Opts.width = ILI9341_LCD_PIXEL_WIDTH;
		ILI9341_Opts.height = ILI9341_LCD_PIXEL_HEIGHT;
		ILI9341_Opts.orientation = TM_ILI9341_Portrait;
	}
	
	
void ili9341_Rotate(TM_ILI9341_Orientation_t orientation) {
	LCD_IO_WriteReg(LCD_MAC);
	if (orientation == TM_ILI9341_Orientation_Portrait_1) {
		LCD_IO_WriteData(0x58);
	} else if (orientation == TM_ILI9341_Orientation_Portrait_2) {
		LCD_IO_WriteData(0x88);
	} else if (orientation == TM_ILI9341_Orientation_Landscape_1) {
		LCD_IO_WriteData(0x28);
	} else if (orientation == TM_ILI9341_Orientation_Landscape_2) {
		LCD_IO_WriteData(0xE8);
	}
	
	if (orientation == TM_ILI9341_Orientation_Portrait_1 || orientation == TM_ILI9341_Orientation_Portrait_2) {
		ILI9341_Opts.width = ILI9341_LCD_PIXEL_WIDTH;
		ILI9341_Opts.height = ILI9341_LCD_PIXEL_HEIGHT;
		ILI9341_Opts.orientation = TM_ILI9341_Portrait;
	} else {
		ILI9341_Opts.width = ILI9341_LCD_PIXEL_HEIGHT;
		ILI9341_Opts.height = ILI9341_LCD_PIXEL_WIDTH;
		ILI9341_Opts.orientation = TM_ILI9341_Landscape;
	}
}

	
	void  LCD_IO_WriteData(uint16_t RegValue)
{
	CS_Set(0);
	HAL_SPI_Transmit(&hspi1,(uint8_t*)&RegValue,1,1000);
	CS_Set(1);
}

void     LCD_IO_WriteReg(uint8_t Reg)
{
	DC_Set(0);
	CS_Set(0);
	HAL_SPI_Transmit(&hspi1,&Reg,1, 1000);
	DC_Set(1);
}

uint32_t LCD_IO_ReadData(uint16_t RegValue, uint8_t ReadSize)
{
	uint8_t rx;
	uint8_t tx = (uint8_t) RegValue;
	HAL_SPI_Receive_DMA(&hspi1, &rx,1);
	return rx;
}


/* USER CODE END 4 */

/* StartDefaultTask function */
void StartDefaultTask(void const * argument)
{

  /* USER CODE BEGIN 5 */
  /* Infinite loop */

	uint8_t buff[100];

  for(;;)
  {
	sprintf( (char*)buff, "%d. hello World!\r\n", counter++);
	mputs(buff);


    osDelay(1000);
  }
  /* USER CODE END 5 */ 
}

/* StartTask02 function */
void StartTask02(void const * argument)
{
  /* USER CODE BEGIN StartTask02 */
	
	/****  LCD Task  ****/
	
	static int count = 0;
  
	/* Infinite loop */
  for(;;)
  {
    printf("%d. hello from LCD Task\r\n", count++);
		
	// ili9341_DrawPixel( (rand() % 320) , (rand() % 240), (rand() % 0xffff));
		
		int i;
		for(i=0; i<10; i++)
		{
			ili9341_DrawHLine(0, 320, (rand() % 240), ( rand() % 0x0000) );	// horizontal line
			
			ili9341_DrawVLine( (rand() % 320), 0, 240, ( rand() % 0x0000) ); // vertical line
		}
		
		osDelay(1000);
		ili9341_Fill((rand()%0xffff));
		
		osDelay(1);
  }
  /* USER CODE END StartTask02 */
}

/* Callback01 function */
void Callback01(void const * argument)
{
  /* USER CODE BEGIN Callback01 */
	
	//static int count = 0;	
	//printf("%d. timer callback\r\n", count++);
  
  /* USER CODE END Callback01 */
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
