/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint16_t adc_value;
float Vadc;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void Gpio_Config(void);
void Adc_Config(void);
void Read_Adc(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();
  Gpio_Config();

  /* USER CODE BEGIN Init */
  Adc_Config();

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  Read_Adc();
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
	RCC->CR |= 0x03;                                     // hsi and hsiready on
	while(!(RCC->CR & (1<<1)));                         //wait hsi ready
	RCC->CR |= (1 << 19);								 // CSS ON
	RCC->CFGR &= ~(1 << 16);                             // HSI SOURCE HSI
	RCC->CFGR |= 0x0140000;								// pll x7
	RCC->CFGR |= (1<<1);								//PLL AS SYSTEM CLOCK
	RCC->CFGR |= (1 << 14);                             // ADC PRESCALER /4
	RCC->CIR  &= 0x0840000;								//flag reset(css and hsi)

}

/* USER CODE BEGIN 4 */
void Gpio_Config(){
	RCC->APB2ENR |= (1 << 2);                            //GPIOA CLOCK ENABLE
	GPIOA->CRL = 0x44444444;
	GPIOA->CRH = 0x44444444;
	GPIOA->CRL &= ~(0x0F);                             // GPIOA pin 0 analog input
}

void Adc_Config(void){
	RCC->APB2ENR |= (1<<9); 							//ADC CLOCK ENABLE
//	RCC->APB2ENR &= ~(1<<0);							//RESET AFIOEN CLOCK
	ADC1->CR1 &= ~(0x0F0000);							//ADC MODE SELECTİON
	ADC1->CR2 |= (1<<1);								//CONTİNUOUS MODE
	ADC1->CR2 &= ~(1<<11);								// LEFT ALLIGN
																										//!! CATİONNN ÖNEMLİ{
	ADC1->CR2 |= (1<<20);							//triger ENABLE
	ADC1->CR2 |= (0xE0000);							//triger swsstar selection
																										// !! CATİON ÖNEMLİ{

}

void Read_Adc(){

	HAL_Delay(500);

	ADC1->CR2 |= (1<<0);					//ADC ON

	ADC1->CR2 |= (0x400000);               //START CONVERSİON

	while(!(ADC1->SR & (1<<1)));        // wait end of conversion to get out

	adc_value = ADC1->DR;				// adc data register

	Vadc = 2.02 *  adc_value / 4095 ;

	ADC1->CR2 &= ~(1<<0);				//ADC OFF



}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
