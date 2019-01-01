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
215, 215, 215, 215, 215, 172, 210, 193, 237, 222, 246, 242, 250, 249, 266, 266, 266, 291, 298, 330, 333, 334, 325, 337, 334, 353, 357, 366, 392, 389, 396, 396, 
435, 446, 456, 447, 442, 468, 476, 473, 498, 512, 506, 517, 530, 530, 533, 569, 554, 576, 583, 592, 589, 602, 611, 612, 618, 616, 624, 641, 647, 653, 648, 675, 
675, 667, 677, 685, 693, 693, 704, 712, 727, 729, 736, 736, 746, 753, 756, 753, 757, 766, 776, 777, 791, 794, 803, 809, 808, 821, 828, 822, 825, 830, 847, 840, 
853, 861, 862, 853, 884, 896, 901, 898, 908, 911, 917, 921, 932, 936, 942, 962, 954, 969, 973, 967, 974, 987, 988, 990, 1000, 1000, 1020, 1021, 1021, 1022, 1040, 
1038, 1055, 1053, 1065, 1067, 1069, 1067, 1077, 1096, 1092, 1099, 1116, 1126, 1133, 1134, 1141, 1146, 1151, 1165, 1175, 1181, 1187, 1189, 1191, 1198, 1202, 1216, 
1223, 1229, 1232, 1238, 1248, 1252, 1257, 1264, 1280, 1278, 1291, 1297, 1309, 1311, 1322, 1328, 1333, 1335, 1333, 1346, 1366, 1369, 1378, 1385, 1390, 1398, 1400, 
1419, 1431, 1425, 1434, 1437, 1447, 1455, 1462, 1466, 1480, 1483, 1485, 1495, 1504, 1506, 1516, 1525, 1529, 1534, 1542, 1549, 1556, 1562, 1564, 1569, 1575, 1588, 
1589, 1596, 1599, 1608, 608, 1618, 1625, 1627, 1630, 1639, 1641, 1656, 1657, 671, 1671, 1676, 1685, 1691, 1697, 1698, 1709, 1713, 1716, 1725, 1730, 1734, 1737, 
1750, 1759, 1763, 1769, 1780, 1784, 1793, 1797, 1798, 1803, 1809, 1817, 1819, 1829, 1836, 1840, 1846, 1858, 1861, 1864, 1873, 1877, 1883, 1889, 1896, 1900, 1908, 
1911, 1918, 1930, 1933, 1935, 1943, 1946, 1955, 1962, 1968, 1972, 1973, 1985, 1991, 1997, 1997, 2006, 2012, 2019, 2024, 2032, 2035, 2040, 2049, 2058, 2060, 2069, 
2071, 2075, 2082, 2096, 2104, 2109, 2112, 2117, 2124, 2117, 2103, 2106, 2102, 2100, 2101, 2111, 2115, 122, 2124, 2136, 2138, 2148, 2148, 2156, 2159, 2167, 2159, 
2163, 2159, 2145, 2145, 2147, 2151, 2164, 2167, 2171, 2178, 2190, 2191, 2193, 2199, 2206, 2208, 2213, 2220, 2227, 2232, 2237, 2241, 2249, 2257, 2261, 2267, 2271, 
2278, 2287, 2294, 2298, 2302, 2310, 2310, 2326, 2332, 2336, 2340, 2345, 2354, 2361, 2367, 2371, 2376, 2382, 2388, 2391, 2399, 2401, 2412, 2414, 2422, 2426, 2433, 
2437, 2441, 2447, 2457, 2459, 2466, 2469, 2476, 2482, 2489, 2494, 2501, 2505, 2514, 2520, 2526, 2531, 2534, 2537, 2548, 2551, 2556, 2566, 2568, 2573, 2581, 2588, 
2592, 2598, 2602, 2607, 2614, 2625, 2626, 2636, 2640, 2644, 2653, 2662, 2665, 2669, 2675, 2678, 2686, 2692, 2700, 2708, 2709, 2714, 2727, 2729, 2734, 2740, 2748, 
2757, 2764, 2774, 2775, 2784, 2787, 2794, 2801, 2803, 2809, 2814, 2823, 2828, 2835, 2840, 2848, 2855, 2864, 2867, 2875, 2879, 2889, 2890, 2899, 2906, 2910, 2913, 
2924, 2932, 2942, 2944, 2954, 2958, 2967, 2974, 2985, 2989, 2991, 2998, 3005, 3021, 3025, 3031, 3037, 3045, 3055, 3059, 3067, 3074, 3080, 3081, 3090, 3097, 3111, 
3113, 3122, 3123, 3126, 3137, 3144, 3155, 3162, 3165, 3169, 3172, 3176, 3180, 3183, 3187, 3190, 3192, 3194, 3197, 3198, 3200, 2800 };
const uint16_t Degree_bar_tbl[256] = {
220, 232, 244, 256, 268, 280, 292, 304, 316, 328, 340, 352, 364, 376, 388, 400, 412, 424, 436, 448, 460, 472, 484, 496, 508, 520,
532, 544, 556, 568, 580, 592, 604, 616, 628, 640, 652,
664,
676,
688,
700,
712,
724,
736,
748,
760,
772,
784,
796,
808,
820,
832,
844,
856,
868,
880,
892,
904,
916,
928,
940,
952,
964,
976,
988,
1000,
1012,
1024,
1036,
1048,
1060,
1072,
1084,
1096,
1108,
1120,
1132,
1144,
1156,
1168,
1180,
1192,
1204,
1216,
1228,
1240,
1252,
1264,
1276,
1288,
1300,
1312,
1324,
1336,
1348,
1360,
1372,
1384,
1396,
1408,
1420,
1432,
1444,
1456,
1468,
1480,
1492,
1504,
1516,
1528,
1540,
1552,
1564,
1576,
1588,
1600,
1612,
1624,
1636,
1648,
1660,
1672,
1684,
1696,
1708,
1720,
1732,
1744,
1756,
1768,
1780,
1792,
1804,
1816,
1828,
1840,
1852,
1864,
1876,
1888,
1900,
1912,
1924,
1936,
1948,
1960,
1972,
1984,
1996,
2008,
2020,
2032,
2044,
2056,
2068,
2080,
2092,
2104,
2116,
2128,
2140,
2152,
2164,
2176,
2188,
2200,
2212,
2224,
2236,
2248,
2260,
2272,
2284,
2296,
2308,
2320,
2332,
2344,
2356,
2368,
2380,
2392,
2404,
2416,
2428,
2440,
2452,
2464,
2476,
2488,
2500,
2512,
2524,
2536,
2548,
2560,
2572,
2584,
2596,
2608,
2620,
2632,
2644,
2656,
2668,
2680,
2692,
2704,
2716,
2728,
2740,
2752,
2764,
2776,
2788,
2800,
2812,
2824,
2836,
2848,
2860,
2872,
2884,
2896,
2908,
2920,
2932,
2944,
2956,
2968,
2980,
2992,
3004,
3016,
3028,
3040,
3052,
3064,
3076,
3088,
3100,
3112,
3124,
3136,
3148,
3160,
3172,
3184,
3196,
3208,
3220,
3232,
3244,
3256,
3268,
3280 };
const uint32_t SDADC_val_deg[256] = {
432549824,
432549828,
432549832,
432549836,
432549840,
432549844,
432549848,
432549852,
432549856,
432549860,
432549864,
432549868,
432549872,
432549876,
432549880,
432549884,
432549888,
432549892,
432549896,
432549900,
432549904,
432549908,
432549912,
432549916,
432549920,
432549924,
432549928,
432549932,
432549936,
432549940,
432549944,
432549948,
432549952,
432549956,
432549960,
432549964,
432549968,
432549972,
432549976,
432549980,
432549984,
432549988,
432549992,
432549996,
432550000,
432550004,
432550008,
432550012,
432550016,
432550020,
432550024,
432550028,
432550032,
432550036,
432550040,
432550044,
432550048,
432550052,
432550056,
432550060,
432550064,
432550068,
432550072,
432550076,
432550080,
432550084,
432550088,
432550092,
432550096,
432550100,
432550104,
432550108,
432550112,
432550116,
432550120,
432550124,
432550128,
432550132,
432550136,
432550140,
432550144,
432550148,
432550152,
432550156,
432550160,
432550164,
432550168,
432550172,
432550176,
432550180,
432550184,
432550188,
432550192,
432550196,
432550200,
432550204,
432550208,
432550212,
432550216,
432550220,
432550224,
432550228,
432550232,
432550236,
432550240,
432550244,
432550248,
432550252,
432550256,
432550260,
432550264,
432550268,
432550272,
432550276,
432550280,
432550284,
432550288,
432550292,
432550296,
432550300,
432550304,
432550308,
432550312,
432550316,
432550320,
432550324,
432550328,
432550332,
432550336,
432550340,
432550344,
432550348,
432550352,
432550356,
432550360,
432550364,
432550368,
432550372,
432550376,
432550380,
432550384,
432550388,
432550392,
432550396,
432550400,
432550404,
432550408,
432550412,
432550416,
432550420,
432550424,
432550428,
432550432,
432550436,
432550440,
432550444,
432550448,
432550452,
432550456,
432550460,
432550464,
432550468,
432550472,
432550476,
432550480,
432550484,
432550488,
432550492,
432550496,
432550500,
432550504,
432550508,
432550512,
432550516,
432550520,
432550524,
432550528,
432550532,
432550536,
432550540,
432550544,
432550548,
432550552,
432550556,
432550560,
432550564,
432550568,
432550572,
432550576,
432550580,
432550584,
432550588,
432550592,
432550596,
432550600,
432550604,
432550608,
432550612,
432550616,
432550620,
432550624,
432550628,
432550632,
432550636,
432550640,
432550644,
432550648,
432550652,
432550656,
432550660,
432550664,
432550668,
432550672,
432550676,
432550680,
432550684,
432550688,
432550692,
432550696,
432550700,
432550704,
432550708,
432550712,
432550716,
432550720,
432550724,
432550728,
432550732,
432550736,
432550740,
432550744,
432550748,
432550752,
432550756,
432550760,
432550764,
432550768,
432550772,
432550776,
432550780,
432550784,
432550788,
432550792,
432550796,
432550800,
432550804,
432550808,
432550812,
432550816,
432550820,
432550824,
432550828,
432550832,
432550836,
432550840,
432550844 };
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

SDADC_HandleTypeDef hsdadc2;
DMA_HandleTypeDef hdma_sdadc2;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
__IO uint32_t InjectedConvData_SDADC1[512];
__IO uint32_t SDADC_Value = 0;
uint16_t Avg_degree;
int Position_Dir = 0;
int Pt_value = 0;
char buffer_adc[128];
	float ii;
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
	Calibration_process();
  /* USER CODE END 2 */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */	
		for(int i = 0; i < 256; i++){				
			if((SDADC_val_deg[i] == SDADC_Value) || (SDADC_val_deg[i] == SDADC_Value + 1) || (SDADC_val_deg[i] == SDADC_Value + 2) || (SDADC_val_deg[i] == SDADC_Value + 3))
				Position_Dir = i;
		}			
		Rotation_degree(Degree_bar_tbl[Position_Dir]);
		sprintf(buffer_adc, "SDADC value is: %d, Pos: %d, Avg: %d \r\n", (uint32_t)SDADC_Value, (uint8_t)Position_Dir, (uint16_t)Degree_bar_tbl[Position_Dir]);
		HAL_UART_Transmit(&huart2, (uint8_t *)buffer_adc, 48, HAL_MAX_DELAY);
		HAL_Delay(50);
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
	uint32_t tmpCnv = 0, tmpVal = 0;
	HAL_DMA_IRQHandler(&hdma_sdadc2);
	HAL_SDADC_InjectedStop_DMA(&hsdadc2);
	tmpCnv = (uint32_t)InjectedConvData_SDADC1[0];
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
			HAL_GPIO_WritePin(GPIOA, MTR_L_Pin, GPIO_PIN_SET);
			HAL_Delay(3);
			HAL_GPIO_WritePin(GPIOA, MTR_L_Pin, GPIO_PIN_RESET);
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
				HAL_Delay(3);
				HAL_GPIO_WritePin(GPIOA, MTR_R_Pin, GPIO_PIN_RESET);
				HAL_Delay(3);
		}				
		//sprintf(buffer_adc, "Calibration fixed by: %d \r\n", Pt_value);
		//HAL_UART_Transmit(&huart2, (uint8_t *)buffer_adc, 27, HAL_MAX_DELAY);			
}

static void Rotation_degree(uint16_t rotate){
	static int Pt_value = 0;
	HAL_GPIO_WritePin(GPIOA, MTR_R_Pin, GPIO_PIN_SET);
	HAL_Delay(2);
	HAL_GPIO_WritePin(GPIOA, MTR_R_Pin, GPIO_PIN_RESET);
	if(rotate > Pt_value){
		while(Pt_value < rotate ){
			HAL_ADC_Start(&hadc1);					
			HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
			Pt_value = HAL_ADC_GetValue(&hadc1);			
			HAL_GPIO_WritePin(GPIOA, MTR_R_Pin, GPIO_PIN_SET);
			HAL_Delay(1);
			HAL_GPIO_WritePin(GPIOA, MTR_R_Pin, GPIO_PIN_RESET);
			HAL_Delay(1);
		}		
		return;
	}
	if(rotate < Pt_value){
		while(Pt_value > rotate ){	
			HAL_ADC_Start(&hadc1);					
			HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
			Pt_value = HAL_ADC_GetValue(&hadc1);			
			HAL_GPIO_WritePin(GPIOA, MTR_L_Pin, GPIO_PIN_SET);
			HAL_Delay(1);
			HAL_GPIO_WritePin(GPIOA, MTR_L_Pin, GPIO_PIN_RESET);
			HAL_Delay(1);
		}
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
