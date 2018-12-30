/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
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
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "math.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
static void Calibration_process(void);
static void Rotation_degree(uint16_t rotate);
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
const int Degree_tbl[500] = {
	215, 131, 215, 164, 215, 171, 200, 215, 225, 235, 257, 238, 245, 250, 266, 265, 264, 294, 295, 313, 329, 333, 330, 333, 352, 
	368, 367, 387, 389, 403, 396, 430, 442, 456, 442, 440, 476, 470, 487, 504, 504, 516, 523, 526, 533, 569, 544, 577, 584, 590, 
	587, 606, 607, 611, 616, 622, 631, 648, 653, 648, 653, 667, 667, 677, 688, 689, 700, 705, 707, 722, 726, 727, 730, 734, 738, 
	750, 756, 752, 753, 762, 771, 777, 789, 792, 804, 802, 803, 815, 817, 816, 817, 824, 836, 838, 844, 858, 860, 852, 875, 888, 
	899, 898, 899, 909, 909, 913, 926, 934, 934, 952, 956, 952, 964, 975, 982, 975, 979, 992, 999, 1000, 1018, 1017, 1018, 1027, 
	1038, 1036, 1041, 1052, 1054, 1066, 1067, 1071, 1070, 1073, 1074, 1089, 1098, 1114, 1119, 1129, 1132, 1140, 1148, 1153, 1156, 
	1157, 1166, 1177, 1184, 1183, 1198, 1200, 1218, 1222, 1224, 1231, 1234, 1246, 1251, 1258, 1275, 1279, 1282, 1292, 1296, 1306, 
	1309, 1318, 1329, 1333, 1333, 1334, 1354, 1362, 1371, 1375, 1382, 1387, 1395, 1404, 1415, 1425, 1424, 1431, 1434, 1446, 1451, 
	1458, 1464, 1478, 1477, 1479, 1493, 1500, 1501, 1512, 1522, 1526, 1532, 1537, 1547, 1551, 1560, 1562, 1566, 1573, 1584, 1584, 
	1593, 1599, 1605, 1606, 1613, 1619, 1622, 1628, 1638, 1641, 1656, 1660, 1669, 1671, 1682, 1684, 1691, 1695, 1698, 1709, 1714, 
	1717, 1729, 1730, 1735, 1739, 1751, 1759, 1762, 1771, 1779, 1780, 1792, 1798, 1795, 1803, 1808, 1814, 1816, 1828, 1835, 1839, 
	1847, 1855, 1860, 1863, 1872, 1876, 1887, 1888, 1895, 1900, 1906, 1912, 1915, 1929, 1932, 1935, 1942, 1946, 1954, 1961, 1967, 
	1970, 1972, 1983, 1989, 1996, 1996, 2006, 2011, 2017, 2024, 2031, 2033, 2040, 2048, 2054, 2058, 2067, 2070, 2072, 2077, 2089, 
	2097, 2101, 2107, 2114, 2117, 2121, 2103, 2099, 2105, 2097, 2099, 2102, 2110, 2118, 2121, 2126, 2133, 2143, 2146, 2155, 2159, 
	2164, 2160, 2160, 2162, 2152, 2141, 2148, 2154, 2161, 2167, 2171, 2179, 2187, 2192, 2192, 2204, 2207, 2209, 2211, 2222, 2227, 
	2232, 2236, 2244, 2256, 2262, 2269, 2272, 2278, 2286, 2294, 2297, 2302, 2309, 2314, 2320, 2328, 2333, 2336, 2341, 2348, 2354, 
	2361, 2368, 2372, 2376, 2384, 2387, 2392, 2399, 2402, 2411, 2416, 2422, 2426, 2432, 2439, 2441, 2448, 2457, 2459, 2465, 2469, 
	2474, 2482, 2488, 2497, 2500, 2506, 2514, 2520, 2527, 2532, 2534, 2540, 2548, 2551, 2556, 2566, 2570, 2574, 2581, 2589, 2592, 
	2597, 2602, 2610, 2614, 2625, 2625, 2632, 2637, 2642, 2649, 2660, 2665, 2667, 2675, 2681, 2681, 2692, 2698, 2705, 2708, 2709, 
	2723, 2729, 2732, 2737, 2744, 2754, 2761, 2766, 2769, 2782, 2785, 2793, 2801, 2805, 2810, 2817, 2826, 2831, 2837, 2844, 2855, 
	2865, 2867, 2871, 2881, 2888, 2889, 2897, 2906, 2910, 2912, 2925, 2931, 2940, 2943, 2954, 2956, 2965, 2973, 2981, 2986, 2990, 
	2994, 3003, 3018, 3029, 3028, 3037, 3043, 3057, 3057, 3060, 3072, 3078, 3079, 3085, 3086, 3108, 3113, 3117, 3119, 3125, 3134, 
	3141, 3146, 3151, 3161, 3166, 3171, 3172, 3173, 3175, 3176, 3177, 3179, 3183, 3185, 3190, 3193, 3199, 3200 };
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

SDADC_HandleTypeDef hsdadc2;
DMA_HandleTypeDef hdma_sdadc2;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
__IO uint32_t InjectedConvData_SDADC1[512];
__IO float SDADC_Value = 0;
uint16_t Position_Dir = 0;
uint16_t Avg_degree;
uint16_t Pre_deg = 0, Now_deg = 0;
int Pt_value = 0;
char buffer_adc[128];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_ADC1_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_SDADC2_Init(void);
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

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_USART2_UART_Init();
  MX_SDADC2_Init();
  /* USER CODE BEGIN 2 */
	/* Start Calibration in polling mode */
	if(HAL_SDADC_CalibrationStart(&hsdadc2, SDADC_CALIBRATION_SEQ_1) != HAL_OK){
		Error_Handler();
	}
	/* Pool for the end of calibration */
	if(HAL_SDADC_PollForCalibEvent(&hsdadc2, HAL_MAX_DELAY) != HAL_OK){
		/* An error occurs while waiting for the end of the calibration */
		Error_Handler();
	}
	/* Start injected conversionin interrupt mode */
	if(HAL_SDADC_InjectedStart_DMA(&hsdadc2, (uint32_t *)InjectedConvData_SDADC1, 1024) != HAL_OK){
		/* An error occurs duringthe configuration of the injected conversion in interrupt mode */
		Error_Handler();
	}	
	/* ADC start calibration in interrupt mode */
	if(HAL_ADCEx_Calibration_Start(&hadc1) != HAL_OK){
		Error_Handler();
	}
	/* Start the first system calibration by Feedback signal */
	//Calibration_process();
  /* USER CODE END 2 */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */	
/*		HAL_GPIO_WritePin(GPIOA, MTR_L_Pin, GPIO_PIN_SET);
		for(int j = 0; j < 25; j++){
			HAL_ADC_Start(&hadc1);
			HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
			Pt_value += HAL_ADC_GetValue(&hadc1);			
		}
		Pt_value /= 25;
		sprintf(buffer_adc, "%d. \r\n", (int)Pt_value);		
		HAL_UART_Transmit(&huart2, (uint8_t *)buffer_adc, 7, HAL_MAX_DELAY);
		HAL_Delay(3);
		HAL_GPIO_WritePin(GPIOA, MTR_L_Pin, GPIO_PIN_RESET);
		HAL_Delay(300); */
		
/*		SDADC_Value = (SDADC_Value < 0) ? -SDADC_Value : SDADC_Value;
			Position_Dir = ((SDADC_Value - SDADC_Regulation) * 100) / SDADC_Regulation;
			if(Position_Dir > 99)
				Position_Dir = 99;
			Avg_degree = (Degree_tbl[(Position_Dir * 5)] + Degree_tbl[(Position_Dir * 5)+ 1] + Degree_tbl[(Position_Dir * 5)+ 2] + Degree_tbl[(Position_Dir * 5)+ 3] + Degree_tbl[(Position_Dir * 5)+ 4]) / 5;
			if((Avg_degree < 3200) && (Avg_degree > 150)){
				Rotation_degree(Avg_degree);
			}*/

			SDADC_Value = (SDADC_Value < 0) ? -SDADC_Value : SDADC_Value;
			sprintf(buffer_adc, "SDADC value is: %d \r\n", (int)SDADC_Value);
			HAL_UART_Transmit(&huart2, (uint8_t *)buffer_adc, 23, HAL_MAX_DELAY);
			HAL_Delay(250);
//		sprintf(buffer_adc, "SDADC = %d \r\n", (int)Position_Dir);
//		HAL_UART_Transmit(&huart2, (uint8_t *)buffer_adc, 15, HAL_MAX_DELAY);
//		HAL_Delay(500);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /**Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /**Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2|RCC_PERIPHCLK_ADC1
                              |RCC_PERIPHCLK_SDADC;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  PeriphClkInit.SdadcClockSelection = RCC_SDADCSYSCLK_DIV12;
  PeriphClkInit.Adc1ClockSelection = RCC_ADC1PCLK2_DIV2;

  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
  HAL_PWREx_EnableSDADC(PWR_SDADC_ANALOG2);
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};
  ADC_InjectionConfTypeDef sConfigInjected = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */
  /**Common config 
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /**Configure Regular Channel 
  */
  sConfig.Channel = ADC_CHANNEL_3;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /**Configure Inj ected Channel 
  */
  sConfigInjected.InjectedChannel = ADC_CHANNEL_5;
  sConfigInjected.InjectedRank = ADC_INJECTED_RANK_1;
  sConfigInjected.InjectedNbrOfConversion = 0;
  sConfigInjected.InjectedSamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  sConfigInjected.AutoInjectedConv = DISABLE;
  sConfigInjected.InjectedDiscontinuousConvMode = DISABLE;
  sConfigInjected.InjectedOffset = 0;
  if (HAL_ADCEx_InjectedConfigChannel(&hadc1, &sConfigInjected) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief SDADC2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SDADC2_Init(void)
{

  /* USER CODE BEGIN SDADC2_Init 0 */

  /* USER CODE END SDADC2_Init 0 */

  SDADC_ConfParamTypeDef ConfParamStruct = {0};

  /* USER CODE BEGIN SDADC2_Init 1 */

  /* USER CODE END SDADC2_Init 1 */
  /**Configure the SDADC low power mode, fast conversion mode,
  slow clock mode and SDADC1 reference voltage 
  */
  hsdadc2.Instance = SDADC2;
  hsdadc2.Init.IdleLowPowerMode = SDADC_LOWPOWER_NONE;
  hsdadc2.Init.FastConversionMode = SDADC_FAST_CONV_DISABLE;
  hsdadc2.Init.SlowClockMode = SDADC_SLOW_CLOCK_DISABLE;
  hsdadc2.Init.ReferenceVoltage = SDADC_VREF_VDDA;
  hsdadc2.InjectedTrigger = SDADC_SOFTWARE_TRIGGER;
  if (HAL_SDADC_Init(&hsdadc2) != HAL_OK)
  {
    Error_Handler();
  }
  /**Configure the Injected Mode 
  */
  if (HAL_SDADC_SelectInjectedDelay(&hsdadc2, SDADC_INJECTED_DELAY_NONE) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_SDADC_SelectInjectedTrigger(&hsdadc2, SDADC_SOFTWARE_TRIGGER) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_SDADC_InjectedConfigChannel(&hsdadc2, SDADC_CHANNEL_7, SDADC_CONTINUOUS_CONV_ON) != HAL_OK)
  {
    Error_Handler();
  }
  /**Set parameters for SDADC configuration 0 Register 
  */
  ConfParamStruct.InputMode = SDADC_INPUT_MODE_SE_ZERO_REFERENCE;
  ConfParamStruct.Gain = SDADC_GAIN_1;
  ConfParamStruct.CommonMode = SDADC_COMMON_MODE_VSSA;
  ConfParamStruct.Offset = 0;
  if (HAL_SDADC_PrepareChannelConfig(&hsdadc2, SDADC_CONF_INDEX_0, &ConfParamStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /**Configure the Injected Channel 
  */
  if (HAL_SDADC_AssociateChannelConfig(&hsdadc2, SDADC_CHANNEL_7, SDADC_CONF_INDEX_0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SDADC2_Init 2 */

  /* USER CODE END SDADC2_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/** 
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void) 
{
  /* DMA controller clock enable */
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA2_Channel3_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Channel3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Channel3_IRQn);
  /* DMA2_Channel4_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Channel4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Channel4_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, MTR_L_Pin|MTR_R_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : MTR_L_Pin MTR_R_Pin */
  GPIO_InitStruct.Pin = MTR_L_Pin|MTR_R_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void DMA2_Channel4_IRQHandler(void)
{
	int16_t tmpCnv = 0, tmpVal = 0;
	HAL_DMA_IRQHandler(&hdma_sdadc2);
	HAL_SDADC_InjectedStop_DMA(&hsdadc2);
	tmpCnv = (int16_t)InjectedConvData_SDADC1[0];
	tmpVal = ((((tmpCnv) * SDADC_VREF)) / (SDADC_GAIN * 32767));
	SDADC_Value = tmpVal;
	for(int i = 0; i < 512; i++){
		tmpCnv = (int16_t)InjectedConvData_SDADC1[i];
		tmpVal = ((((tmpCnv) * SDADC_VREF)) / (SDADC_GAIN * 32767));
		if(tmpVal > SDADC_Value)
			SDADC_Value = tmpVal;
	}
	//sprintf(buffer_adc, "SDADC value is: %d \r\n", (int)SDADC_Value);
	//HAL_UART_Transmit(&huart2, (uint8_t *)buffer_adc, 25, HAL_MAX_DELAY);
	//HAL_Delay(250);
	if(HAL_SDADC_InjectedStart_DMA(&hsdadc2, (uint32_t *)InjectedConvData_SDADC1, 1024) != HAL_OK){
		Error_Handler();
	}
}

static void Calibration_process(void){
		for(int i = 0; i < 25; i++){
			HAL_ADC_Start(&hadc1);
			HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
			Pt_value += HAL_ADC_GetValue(&hadc1);
		}
		Pt_value /= 25;
		while(Pt_value > 215 ){			
				HAL_ADC_Start(&hadc1);					
				HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
				Pt_value = HAL_ADC_GetValue(&hadc1);
				HAL_GPIO_WritePin(GPIOA, MTR_R_Pin, GPIO_PIN_SET);
		}				
		HAL_GPIO_WritePin(GPIOA, MTR_R_Pin, GPIO_PIN_RESET);
		//sprintf(buffer_adc, "Calibration fixed by: %d \r\n", Pt_value);
		//HAL_UART_Transmit(&huart2, (uint8_t *)buffer_adc, 27, HAL_MAX_DELAY);			
}

static void Rotation_degree(uint16_t rotate){
	static int Pt_value = 0;
	if(rotate > Pt_value){
		while(Pt_value < rotate ){
			HAL_ADC_Start(&hadc1);					
			HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
			Pt_value = HAL_ADC_GetValue(&hadc1);			
			HAL_GPIO_WritePin(GPIOA, MTR_L_Pin, GPIO_PIN_SET);
		}
		HAL_GPIO_WritePin(GPIOA, MTR_L_Pin, GPIO_PIN_RESET);
		return;
	}
	if(rotate < Pt_value){
		while(Pt_value > rotate ){	
			HAL_ADC_Start(&hadc1);					
			HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
			Pt_value = HAL_ADC_GetValue(&hadc1);			
			HAL_GPIO_WritePin(GPIOA, MTR_R_Pin, GPIO_PIN_SET);
		}
		HAL_GPIO_WritePin(GPIOA, MTR_R_Pin, GPIO_PIN_RESET);
		return;
	}
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
	HAL_GPIO_WritePin(GPIOA, MTR_R_Pin, GPIO_PIN_SET);
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
void assert_failed(char *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
