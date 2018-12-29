/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
const int Degree_tbl[500] = {
	130, 131, 147, 164, 172, 171, 200, 208, 201, 222, 257, 238, 245, 250, 266, 265, 264, 294, 295, 313, 329, 333, 330, 333, 352, 
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
	3141, 3146, 3151, 3161, 3166, 3171, 3172, 3173, 3175, 3176, 3177, 3179, 3183, 3185, 3190, 3193, 3199, 3200 }
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
#define SDADC_VREF            (float) 3300  /* SDADC external reference is set to 3.3V */
#define SDADC_GAIN            (uint32_t) 1  /* SDADC internal gain is set to 4: update this define according to POT_SDADC_GAIN */
#define SDADC_Regulation			(uint16_t) 800
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MTR_L_Pin GPIO_PIN_0
#define MTR_L_GPIO_Port GPIOA
#define MTR_R_Pin GPIO_PIN_1
#define MTR_R_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
