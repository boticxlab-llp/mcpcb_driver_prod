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
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
// #define led 11

enum pgm
{
  _inten,
  _clr,
  _lmp,
  _end,
  _dep,
  _foc
};

enum polar
{
  _minus,
  _plus,
  _zero
};

enum port
{
  inner_white,
  inner_warm,
  outer_white,
  outer_warm,
  test_led,
  buzzer
};
enum levels
{
  all_off = 100 - 0,
  all_on = 100 - 100,
  full = 100 - 100,

  // one = 100 - 30, // 18K 70 PWM
  // two = 100 - 37, // 27K --37
  // three = 100 - 44,
  // four = 100 - 51,
  // five = 100 - 58,
  // six = 100 - 65,
  // seven = 100 - 72,
  // eight = 100 - 79,
  // nine = 100 - 86,
  // ten = 100 - 100,

  // one = 100 - 30, // 18K 70 PWM
  // two = 100 - 38, // 27K --37
  // three = 100 - 46,
  // four = 100 - 54,
  // five = 100 - 62,
  // six = 100 - 70,
  // seven = 100 - 78,
  // eight = 100 - 86,
  // nine = 100 - 94,
  // ten = 100 - 100,

  //  one = 100 - 30, // 18K 70 PWM
  //  two = 100 - 44, // 27K --37
  //  three = 100 - 54,
  //  four = 100 - 66,
  //  five = 100 - 75,
  //  six = 100 - 84, // 87
  //  seven = 100 - 88,
  //  eight = 100 - 94,
  //  nine = 100 - 98,
  //  ten = 100 - 100,

  one = 100 - 30, // 18K 70 PWM
  two = 100 - 44, // 27K --37
  three = 100 - 54,
  four = 100 - 66,
  five = 100 - 72,
  six = 100 - 76, // 87
  seven = 100 - 80,
  eight = 100 - 84,
  nine = 100 - 88,
  ten = 100 - 90,
  // one_m = 100-60

};

enum levels_led
{
  // c_one = 100 - 20,
  // c_two = 100 - 40,
  // c_three = 100 - 60,
  // c_four = 100 - 80,
  // c_five = 100 - 100,

  /****   intensity 1 paramaters for color range ********/
  cp1_one = 100 - 33, // 19k
  cp1_two = 100 - 35,
  cp1_three = 100 - 37,
  cp1_four = 100 - 39,
  cp1_five = 100 - 41, // 29k

  cn1_one = 100 - 45, // 16k
  cn1_two = 100 - 45,
  cn1_three = 100 - 45,
  cn1_four = 100 - 45,
  cn1_five = 100 - 45,

  /****   intensity 2 paramaters for color range ********/
  cp2_one = 100 - 47, // 37k
  cp2_two = 100 - 49,
  cp2_three = 100 - 51,
  cp2_four = 100 - 53,
  cp2_five = 100 - 55, // 49k

  cn2_one = 100 - 68, // 33k
  cn2_two = 100 - 65, // 31k
  cn2_three = 100 - 62,
  cn2_four = 100 - 59,
  cn2_five = 100 - 57, // 25k
  /****   intensity 3 paramaters for color range ********/
  cp3_one = 100 - 59, // 53k
  cp3_two = 100 - 61,
  cp3_three = 100 - 63,
  cp3_four = 100 - 65,
  cp3_five = 100 - 67, // 66k

  cn3_one = 100 - 87, // 49k
  cn3_two = 100 - 83,
  cn3_three = 100 - 81,
  cn3_four = 100 - 79,
  cn3_five = 100 - 77, // 40k

  /****   intensity 4 paramaters for color range ********/
  cp4_one = 100 - 72, // 74k
  cp4_two = 100 - 74,
  cp4_three = 100 - 76,
  cp4_four = 100 - 78,
  cp4_five = 100 - 80, // 87k

  cn4_one = 100 - 97, // 60k
  cn4_two = 100 - 95,
  cn4_three = 100 - 93,
  cn4_four = 100 - 92,
  cn4_five = 100 - 90, // 53k

  /****   intensity 5 paramaters for color range ********/
  cp5_one = 100 - 82, // 92k
  cp5_two = 100 - 83,
  cp5_three = 100 - 85,
  cp5_four = 100 - 87,
  cp5_five = 100 - 88, // 106k

  cn5_one = 100 - 98, // 85k
  cn5_two = 100 - 97,
  cn5_three = 100 - 96,
  cn5_four = 100 - 95,
  cn5_five = 100 - 93, // 59k

  /****   intensity 6 paramaters for color range ********/
  cp6_one = 100 - 88, // 106k
  cp6_two = 100 - 88,
  cp6_three = 100 - 89,
  cp6_four = 100 - 89,
  cp6_five = 100 - 90, // 118k

  cn6_one = 100 - 99, //*72k
  cn6_two = 100 - 98,
  cn6_three = 100 - 97,
  cn6_four = 100 - 96,
  cn6_five = 100 - 95, // 59k

  /****   intensity 7 paramaters for color range ********/
  cp7_one = 100 - 91, // 121k
  cp7_two = 100 - 92,
  cp7_three = 100 - 93,
  cp7_four = 100 - 94,
  cp7_five = 100 - 95, // 128k

  cn7_one = 100 - 99, // 117k
  cn7_two = 100 - 98,
  cn7_three = 100 - 97,
  cn7_four = 100 - 96,
  cn7_five = 100 - 95,

  /****   intensity 8 paramaters for color range ********/
  cp8_one = 100 - 98,
  cp8_two = 100 - 99,
  cp8_three = 100 - 99,
  cp8_four = 100 - 100,
  cp8_five = 100 - 100,

  cn8_one = 100 - 99,
  cn8_two = 100 - 98,
  cn8_three = 100 - 97,
  cn8_four = 100 - 96,
  cn8_five = 100 - 95,

  /****   intensity 9 paramaters for color range ********/
  cp9_one = 100 - 99,
  cp9_two = 100 - 100,
  cp9_three = 100 - 100,
  cp9_four = 100 - 100,
  cp9_five = 100 - 100,

  cn9_one = 100 - 99,
  cn9_two = 100 - 98,
  cn9_three = 100 - 97,
  cn9_four = 100 - 96,
  cn9_five = 100 - 95,

  /****   intensity 10 paramaters for color range ********/
  cp10_one = 100 - 100,
  cp10_two = 100 - 100,
  cp10_three = 100 - 100,
  cp10_four = 100 - 100,
  cp10_five = 100 - 100,

  cn10_one = 100 - 100,
  cn10_two = 100 - 100,
  cn10_three = 100 - 100,
  cn10_four = 100 - 100,
  cn10_five = 100 - 100,

};
enum levels_led_focus
{
  f_one = 100 - 20,
  f_two = 100 - 65,
  f_three = 100 - 100,

};
int yl, wh;

int8_t last_status = 0; // intensity
int8_t last_clr_status = 0;
int prgm_status = 0;
uint8_t lamp_status = 1;
int8_t color_status = 0;
uint8_t color_polarity = 0;
uint8_t depth_status = 0;
uint8_t endo_status = 0;
uint8_t fous_status = 0;

int curr_pwm = 0;
int last_inten_pos = 0;

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
uint32_t pwm_value = 0;
uint32_t step = 0;

uint8_t Rx_data[5]; //  creating a buffer of 10 bytes
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM1_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_TIM3_Init(void);
/* USER CODE BEGIN PFP */

void led_pwm_setvalue(int _channel, int32_t value);

#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)

volatile uint8_t int_flag = 0;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  //	printf(Rx_data);
  HAL_UART_Receive_IT(&huart1, Rx_data, 5);
  //  memset(Rx_data,0,10);

  int_flag = 1;
}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/**
 * @brief  Retargets the C library printf function to the USART.
 * @param  None
 * @retval None
 */
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART1 and Loop until the end of transmission */
  // HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}

int res_max;
int res_min;
int step_size_color = 2;

void color_steps(int y)
{

  res_max = (y + 14) + 5 * step_size_color;

  if (res_max > 90)
  {
    res_max = 90;
  }

  res_min = (y - 14) - 5 * step_size_color;
  if (res_min < 10)
  {
    res_min = 10;
  }
}

void glow_prv()
{
  switch (prgm_status)
  {
  case _inten:
    led_pwm_setvalue(inner_white, last_status);
    led_pwm_setvalue(inner_warm, last_status);
    led_pwm_setvalue(outer_warm, last_status);
    led_pwm_setvalue(outer_white, last_status);
    // HAL_UART_Transmit(&huart1, "1", 10, 100);

    break;
  case _clr:
    if (color_polarity == _minus)
    {
      // led_pwm_setvalue(inner_white, 50);
      // led_pwm_setvalue(outer_white, 50); //last_clr_status

      led_pwm_setvalue(inner_white, last_clr_status);
      led_pwm_setvalue(outer_white, last_clr_status);

      // led_pwm_setvalue(inner_white, color_status);
      // led_pwm_setvalue(outer_white, color_status);
      led_pwm_setvalue(inner_warm, all_off);
      led_pwm_setvalue(outer_warm, all_off);
      // HAL_UART_Transmit(&huart1, "2+", 10, 100);
    }
    else if (color_polarity == _plus)
    {
      led_pwm_setvalue(inner_warm, last_clr_status);
      led_pwm_setvalue(outer_warm, last_clr_status);

      led_pwm_setvalue(inner_white, all_off);
      led_pwm_setvalue(outer_white, all_off);
      // HAL_UART_Transmit(&huart1, "2-", 10, 100);
    }
    else
    {
      led_pwm_setvalue(inner_white, last_status);
      led_pwm_setvalue(inner_warm, last_status);
      led_pwm_setvalue(outer_warm, last_status);
      led_pwm_setvalue(outer_white, last_status);
    }
    break;
  case _end:
    if (color_polarity == _zero)
    {
      if (endo_status == 0)
      {
        led_pwm_setvalue(inner_white, last_clr_status);
        led_pwm_setvalue(inner_warm, last_clr_status);
        led_pwm_setvalue(outer_warm, last_clr_status);
        led_pwm_setvalue(outer_white, last_clr_status);
        // HAL_UART_Transmit(&huart1, "3", 10, 100);
      }
      else
      {
        led_pwm_setvalue(inner_warm, last_clr_status);
        led_pwm_setvalue(inner_white, last_clr_status);
        led_pwm_setvalue(outer_warm, all_off);
        led_pwm_setvalue(outer_white, all_off);
        // HAL_UART_Transmit(&huart1, "3", 10, 100);
      }
    }
    else
    {
      if (color_polarity == _plus)
      {
      }

      else if (color_polarity == _minus)
      {
        led_pwm_setvalue(inner_white, last_clr_status);
        led_pwm_setvalue(outer_white, last_clr_status);
      }
    }

    break;
  case _dep:
    if (depth_status == 0)
    {
      led_pwm_setvalue(inner_white, last_status);
      led_pwm_setvalue(inner_warm, last_status);
      led_pwm_setvalue(outer_warm, last_status);
      led_pwm_setvalue(outer_white, last_status);
      // HAL_UART_Transmit(&huart1, "4", 10, 100);
    }
    else
    {
      led_pwm_setvalue(inner_warm, all_on);
      led_pwm_setvalue(inner_white, all_on);
      led_pwm_setvalue(outer_warm, all_on);
      led_pwm_setvalue(outer_white, all_on);
      // HAL_UART_Transmit(&huart1, "5", 10, 100);
    }
    break;

  default:
    // HAL_UART_Transmit(&huart1, "dff", 10, 100);
    break;
  }
}

void glow_prv_inner()
{
  switch (prgm_status)
  {
  case _inten:
    led_pwm_setvalue(inner_white, last_status);
    led_pwm_setvalue(inner_warm, last_status);
    led_pwm_setvalue(outer_warm, all_off);
    led_pwm_setvalue(outer_white, all_off);
    // // HAL_UART_Transmit(&huart1, "1", 10, 100);

    break;
  case _clr:
    if (color_polarity == _minus)
    {
      led_pwm_setvalue(inner_white, last_clr_status);
      led_pwm_setvalue(outer_white, all_off);
      // led_pwm_setvalue(inner_white, color_status);
      // led_pwm_setvalue(outer_white, color_status);
      led_pwm_setvalue(inner_warm, all_off);
      led_pwm_setvalue(outer_warm, all_off);
      //      // HAL_UART_Transmit(&huart1, "2+", 10, 100);
    }
    else if (color_polarity == _plus)
    {
      led_pwm_setvalue(inner_warm, last_clr_status);
      // led_pwm_setvalue(inner_warm, color_status);
      led_pwm_setvalue(outer_warm, all_off);
      // led_pwm_setvalue(outer_warm, color_status);
      led_pwm_setvalue(inner_white, all_off);
      led_pwm_setvalue(outer_white, all_off);
      //      // HAL_UART_Transmit(&huart1, "2-", 10, 100);
    }
    else
    {
      led_pwm_setvalue(inner_white, last_status);
      led_pwm_setvalue(inner_warm, last_status);
      led_pwm_setvalue(outer_warm, all_off);
      led_pwm_setvalue(outer_white, all_off);
    }
    // if (color_polarity == _plus)
    // {
    //   led_pwm_setvalue(inner_white, color_status);
    //   led_pwm_setvalue(outer_white, color_status);
    //   led_pwm_setvalue(inner_warm, all_off);
    //   led_pwm_setvalue(outer_warm, all_off);
    //   // // HAL_UART_Transmit(&huart1, "2+", 10, 100);
    // }
    // if (color_polarity == _minus)
    // {
    //   led_pwm_setvalue(inner_warm, color_status);
    //   led_pwm_setvalue(inner_warm, color_status);
    //   led_pwm_setvalue(inner_white, all_off);
    //   led_pwm_setvalue(inner_white, all_off);
    //   // // HAL_UART_Transmit(&huart1, "2-", 10, 100);
    // }
    break;
  case _end:

    if (endo_status == 0)
    {
      if (color_polarity == _zero)
      {
        led_pwm_setvalue(inner_white, last_status);
        led_pwm_setvalue(inner_warm, last_status);
        led_pwm_setvalue(outer_warm, all_off);
        led_pwm_setvalue(outer_white, all_off);
      }
      else if (color_polarity == _minus)
      {
        led_pwm_setvalue(inner_white, all_off);
        led_pwm_setvalue(inner_warm, last_status);
        led_pwm_setvalue(outer_warm, last_status);
        led_pwm_setvalue(outer_white, all_off);
      }
      else if (color_polarity == _plus)
      {
        led_pwm_setvalue(inner_white, last_status);
        led_pwm_setvalue(inner_warm, all_off);
        led_pwm_setvalue(outer_warm, all_off);
        led_pwm_setvalue(outer_white, last_status);
      }

      // // HAL_UART_Transmit(&huart1, "3", 10, 100);
    }
    else
    {
      // led_pwm_setvalue(inner_warm, last_status);
      // led_pwm_setvalue(inner_white, last_status);
      // led_pwm_setvalue(outer_warm, all_off);
      // led_pwm_setvalue(outer_white, all_off);
      // // HAL_UART_Transmit(&huart1, "3", 10, 100);

      if (color_polarity == _zero)
      {
        led_pwm_setvalue(inner_white, last_status);
        led_pwm_setvalue(inner_warm, last_status);
        led_pwm_setvalue(outer_warm, all_off);
        led_pwm_setvalue(outer_white, all_off);
      }
      else if (color_polarity == _minus)
      {
        led_pwm_setvalue(inner_white, all_off);
        led_pwm_setvalue(inner_warm, last_status);
        led_pwm_setvalue(outer_warm, all_off);
        led_pwm_setvalue(outer_white, all_off);
      }
      else if (color_polarity == _plus)
      {
        led_pwm_setvalue(inner_white, last_status);
        led_pwm_setvalue(inner_warm, all_off);
        led_pwm_setvalue(outer_warm, all_off);
        led_pwm_setvalue(outer_white, all_off);
      }
    }
    break;
  case _dep:
    if (depth_status == 0)
    {
      led_pwm_setvalue(inner_white, last_status);
      led_pwm_setvalue(inner_warm, last_status);
      // led_pwm_setvalue(outer_warm, last_status);
      // led_pwm_setvalue(outer_white, last_status);
      // // HAL_UART_Transmit(&huart1, "4", 10, 100);
    }
    else
    {
      led_pwm_setvalue(inner_warm, all_on);
      led_pwm_setvalue(inner_white, all_on);
      led_pwm_setvalue(outer_warm, all_off);
      led_pwm_setvalue(outer_white, all_off);
      // // HAL_UART_Transmit(&huart1, "5", 10, 100);
    }
    break;

  default:
    // // HAL_UART_Transmit(&huart1, "dff", 10, 100);
    break;
  }
}
int myAtoi()
{

  int res = 0;
  if ((Rx_data[2] - '0') > 1)
  {
    return 0;
  }
  else
  {
    res = res * 10 + Rx_data[2] - '0';
    res = res * 10 + Rx_data[3] - '0';
    res = res * 10 + Rx_data[4] - '0';
  }

  return 100 - res;
}

void led_pwm_setvalue(int _channel, int32_t value)
{
  switch (_channel)
  {
  case inner_white:
    TIM1->CCR3 = value;
    break;
  case inner_warm:
    TIM1->CCR4 = value;
    break;
  case outer_white:
    //    TIM1->CCR2 = value;
    TIM3->CCR4 = value;
    break;
  case outer_warm:
    //    TIM1->CCR1 = value;
    TIM3->CCR1 = value;
    break;
    //  case test_led:
    //    TIM3->CCR4 = value;
    //    break;
  default:
    //	    printf("no channel select");
    break;
  }
  //	HAL_Delay(2);
}
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
  MX_TIM1_Init();
  MX_USART1_UART_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */

  //  TIM3->CCR4 = 999;
  //  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
  //    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);

  //    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  //    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);

  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
  /* PWM CONTROL FUNCTION
   * ARG 1 : led channel
   * ARG 2 : set level (zero to nine)
   * */
  //  led_pwm_setvalue(test_led,five);

  HAL_UART_Receive_IT(&huart1, Rx_data, 5); // Receive 4 Bytes of data
                                            //  TIM3->CCR3 = 60000;

  yl = 0;
  wh = 0;

  // int_flag = 1;
  // Rx_data[0] = '@';
  // Rx_data[1] = 'I';
  // Rx_data[2] = '_';
  // Rx_data[3] = '1';
  // Rx_data[4] = '#';

  //  Rx_data[0] = '$';
  //   Rx_data[1] = 'Y';
  //   Rx_data[2] = '0';
  //   Rx_data[3] = '2';
  //   Rx_data[4] = '0';

  //
  prgm_status = _inten;
  lamp_status = 1;
  color_status = 0;
  uint8_t color_polarity = _minus;
  depth_status = 0;
  endo_status = 0;
  fous_status = 0;
  last_status = one;
  color_polarity = _zero;

  HAL_Delay(4000);
// last_status = one;
//   color_polarity = _zero;
  led_pwm_setvalue(inner_warm, last_status);
  led_pwm_setvalue(inner_white, last_status);
  led_pwm_setvalue(outer_warm, last_status);
  led_pwm_setvalue(outer_white, last_status);

  //  HAL_Delay(5000);
  //
  //  led_pwm_setvalue(inner_warm, all_on);
  //  led_pwm_setvalue(inner_white, all_on);
  //  led_pwm_setvalue(outer_warm, all_on);
  //  led_pwm_setvalue(outer_white, all_on);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    // // HAL_UART_Transmit(&huart1,"123456" , 5, 1000);
    // // HAL_UART_Transmit(&huart1,"99887" , 5, 100);
    // HAL_Delay(250);
    int avg = 0;
    if (int_flag)
    {
      // // HAL_UART_Transmit(&huart1, &Rx_data[0], 1, 1000);
      // // HAL_UART_Transmit(&huart1, &Rx_data[1], 1, 1000);
      // // HAL_UART_Transmit(&huart1, &Rx_data[2], 1, 1000);
      // // HAL_UART_Transmit(&huart1, &Rx_data[3], 1, 1000);
      // // HAL_UART_Transmit(&huart1, &Rx_data[4], 1, 1000);
      //      // HAL_UART_Transmit(&huart1, &Rx_data[0], 5, 1000);
      //      Rx_data[0] = last_status;
      // HAL_UART_Transmit(&huart1, &Rx_data[0], 5, 1000);
      //  // HAL_UART_Transmit(&huart1,"." , 1, 100);
      int_flag = 0;

      if (Rx_data[0] == '@') //@I_1#,@I_5#
      {
        if (Rx_data[1] == 'I')
        {
          prgm_status = _inten;
          last_inten_pos = Rx_data[3];
          if (lamp_status == 1)
          {
            switch (Rx_data[3])
            {
            case '1':
              last_inten_pos = 1;

              if (depth_status == 1)
              {
                if (endo_status == 1)
                {
                  led_pwm_setvalue(inner_warm, all_on);
                  led_pwm_setvalue(inner_white, all_on);
                  led_pwm_setvalue(outer_warm, all_off);
                  led_pwm_setvalue(outer_white, all_off);
                }
                else
                {
                  led_pwm_setvalue(inner_warm, all_on);
                  led_pwm_setvalue(inner_white, all_on);
                  led_pwm_setvalue(outer_warm, all_on);
                  led_pwm_setvalue(outer_white, all_on);
                }
              }

              else
              {
                if (color_polarity == _zero)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, one);
                    led_pwm_setvalue(inner_white, one);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, one);
                    led_pwm_setvalue(inner_white, one);
                    led_pwm_setvalue(outer_warm, one);
                    led_pwm_setvalue(outer_white, one);
                  }
                }
                else if (color_polarity == _minus)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, one);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, one);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_warm, one);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                }

                else if (color_polarity == _plus)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(inner_white, one);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(inner_white, one);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, one);
                  }
                }
              }

              last_status = one;
              break;
            case '2':
              last_inten_pos = 2;
              if (depth_status == 1)
              {
                if (endo_status == 1)
                {
                  led_pwm_setvalue(inner_warm, all_on);
                  led_pwm_setvalue(inner_white, all_on);
                  led_pwm_setvalue(outer_warm, all_off);
                  led_pwm_setvalue(outer_white, all_off);
                }
                else
                {
                  led_pwm_setvalue(inner_warm, all_on);
                  led_pwm_setvalue(inner_white, all_on);
                  led_pwm_setvalue(outer_warm, all_on);
                  led_pwm_setvalue(outer_white, all_on);
                }
              }

              else
              {
                if (color_polarity == _zero)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, two);
                    led_pwm_setvalue(inner_white, two);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, two);
                    led_pwm_setvalue(inner_white, two);
                    led_pwm_setvalue(outer_warm, two);
                    led_pwm_setvalue(outer_white, two);
                  }
                }
                else if (color_polarity == _minus)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, two);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, two);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_warm, two);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                }

                else if (color_polarity == _plus)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(inner_white, two);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(inner_white, two);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, two);
                  }
                }
              }

              last_status = two;
              break;
            case '3':
              last_inten_pos = 3;
              if (depth_status == 1)
              {
                if (endo_status == 1)
                {
                  led_pwm_setvalue(inner_warm, all_on);
                  led_pwm_setvalue(inner_white, all_on);
                  led_pwm_setvalue(outer_warm, all_off);
                  led_pwm_setvalue(outer_white, all_off);
                }
                else
                {
                  led_pwm_setvalue(inner_warm, all_on);
                  led_pwm_setvalue(inner_white, all_on);
                  led_pwm_setvalue(outer_warm, all_on);
                  led_pwm_setvalue(outer_white, all_on);
                }
              }

              else
              {
                if (color_polarity == _zero)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, three);
                    led_pwm_setvalue(inner_white, three);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, three);
                    led_pwm_setvalue(inner_white, three);
                    led_pwm_setvalue(outer_warm, three);
                    led_pwm_setvalue(outer_white, three);
                  }
                }
                else if (color_polarity == _minus)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, three);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, three);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_warm, three);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                }

                else if (color_polarity == _plus)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(inner_white, three);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(inner_white, three);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, three);
                  }
                }
              }

              last_status = three;
              break;
            case '4':
              last_inten_pos = 4;
              if (depth_status == 1)
              {
                if (endo_status == 1)
                {
                  led_pwm_setvalue(inner_warm, all_on);
                  led_pwm_setvalue(inner_white, all_on);
                  led_pwm_setvalue(outer_warm, all_off);
                  led_pwm_setvalue(outer_white, all_off);
                }
                else
                {
                  led_pwm_setvalue(inner_warm, all_on);
                  led_pwm_setvalue(inner_white, all_on);
                  led_pwm_setvalue(outer_warm, all_on);
                  led_pwm_setvalue(outer_white, all_on);
                }
              }

              else
              {
                if (color_polarity == _zero)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, four);
                    led_pwm_setvalue(inner_white, four);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, four);
                    led_pwm_setvalue(inner_white, four);
                    led_pwm_setvalue(outer_warm, four);
                    led_pwm_setvalue(outer_white, four);
                  }
                }
                else if (color_polarity == _minus)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, four);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, four);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_warm, four);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                }

                else if (color_polarity == _plus)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(inner_white, four);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(inner_white, four);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, four);
                  }
                }
              }

              last_status = four;
              break;
            case '5':
              last_inten_pos = 5;
              if (depth_status == 1)
              {
                if (endo_status == 1)
                {
                  led_pwm_setvalue(inner_warm, all_on);
                  led_pwm_setvalue(inner_white, all_on);
                  led_pwm_setvalue(outer_warm, all_off);
                  led_pwm_setvalue(outer_white, all_off);
                }
                else
                {
                  led_pwm_setvalue(inner_warm, all_on);
                  led_pwm_setvalue(inner_white, all_on);
                  led_pwm_setvalue(outer_warm, all_on);
                  led_pwm_setvalue(outer_white, all_on);
                }
              }

              else
              {
                if (color_polarity == _zero)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, five);
                    led_pwm_setvalue(inner_white, five);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, five);
                    led_pwm_setvalue(inner_white, five);
                    led_pwm_setvalue(outer_warm, five);
                    led_pwm_setvalue(outer_white, five);
                  }
                }
                else if (color_polarity == _minus)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, five);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, five);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_warm, five);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                }

                else if (color_polarity == _plus)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(inner_white, five);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(inner_white, five);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, one);
                  }
                }
              }

              last_status = five;
              break;
            case '6':
              last_inten_pos = 6;
              if (depth_status == 1)
              {
                if (endo_status == 1)
                {
                  led_pwm_setvalue(inner_warm, all_on);
                  led_pwm_setvalue(inner_white, all_on);
                  led_pwm_setvalue(outer_warm, all_off);
                  led_pwm_setvalue(outer_white, all_off);
                }
                else
                {
                  led_pwm_setvalue(inner_warm, all_on);
                  led_pwm_setvalue(inner_white, all_on);
                  led_pwm_setvalue(outer_warm, all_on);
                  led_pwm_setvalue(outer_white, all_on);
                }
              }

              else
              {
                if (color_polarity == _zero)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, six);
                    led_pwm_setvalue(inner_white, six);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, six);
                    led_pwm_setvalue(inner_white, six);
                    led_pwm_setvalue(outer_warm, six);
                    led_pwm_setvalue(outer_white, six);
                  }
                }
                else if (color_polarity == _minus)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, six);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, six);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_warm, six);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                }

                else if (color_polarity == _plus)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(inner_white, six);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(inner_white, six);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, six);
                  }
                }
              }

              last_status = six;
              break;
            case '7':
              last_inten_pos = 7;
              if (depth_status == 1)
              {
                if (endo_status == 1)
                {
                  led_pwm_setvalue(inner_warm, all_on);
                  led_pwm_setvalue(inner_white, all_on);
                  led_pwm_setvalue(outer_warm, all_off);
                  led_pwm_setvalue(outer_white, all_off);
                }
                else
                {
                  led_pwm_setvalue(inner_warm, all_on);
                  led_pwm_setvalue(inner_white, all_on);
                  led_pwm_setvalue(outer_warm, all_on);
                  led_pwm_setvalue(outer_white, all_on);
                }
              }

              else
              {
                if (color_polarity == _zero)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, seven);
                    led_pwm_setvalue(inner_white, seven);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, seven);
                    led_pwm_setvalue(inner_white, seven);
                    led_pwm_setvalue(outer_warm, seven);
                    led_pwm_setvalue(outer_white, seven);
                  }
                }
                else if (color_polarity == _minus)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, seven);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, seven);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_warm, seven);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                }

                else if (color_polarity == _plus)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(inner_white, seven);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(inner_white, seven);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, seven);
                  }
                }
              }

              last_status = seven;
              break;
            case '8':
              last_inten_pos = 8;
              if (depth_status == 1)
              {
                if (endo_status == 1)
                {
                  led_pwm_setvalue(inner_warm, all_on);
                  led_pwm_setvalue(inner_white, all_on);
                  led_pwm_setvalue(outer_warm, all_off);
                  led_pwm_setvalue(outer_white, all_off);
                }
                else
                {
                  led_pwm_setvalue(inner_warm, all_on);
                  led_pwm_setvalue(inner_white, all_on);
                  led_pwm_setvalue(outer_warm, all_on);
                  led_pwm_setvalue(outer_white, all_on);
                }
              }

              else
              {
                if (color_polarity == _zero)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, eight);
                    led_pwm_setvalue(inner_white, eight);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, eight);
                    led_pwm_setvalue(inner_white, eight);
                    led_pwm_setvalue(outer_warm, eight);
                    led_pwm_setvalue(outer_white, eight);
                  }
                }
                else if (color_polarity == _minus)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, eight);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, eight);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_warm, eight);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                }

                else if (color_polarity == _plus)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(inner_white, eight);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(inner_white, eight);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, eight);
                  }
                }
              }

              last_status = eight;
              break;
            case '9':
              last_inten_pos = 9;
              if (depth_status == 1)
              {
                if (endo_status == 1)
                {
                  led_pwm_setvalue(inner_warm, all_on);
                  led_pwm_setvalue(inner_white, all_on);
                  led_pwm_setvalue(outer_warm, all_off);
                  led_pwm_setvalue(outer_white, all_off);
                }
                else
                {
                  led_pwm_setvalue(inner_warm, all_on);
                  led_pwm_setvalue(inner_white, all_on);
                  led_pwm_setvalue(outer_warm, all_on);
                  led_pwm_setvalue(outer_white, all_on);
                }
              }

              else
              {
                if (color_polarity == _zero)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, nine);
                    led_pwm_setvalue(inner_white, nine);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, nine);
                    led_pwm_setvalue(inner_white, nine);
                    led_pwm_setvalue(outer_warm, nine);
                    led_pwm_setvalue(outer_white, nine);
                  }
                }
                else if (color_polarity == _minus)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, nine);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, nine);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_warm, nine);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                }

                else if (color_polarity == _plus)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(inner_white, nine);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(inner_white, nine);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, nine);
                  }
                }
              }

              last_status = nine;
              break;
            case ':':
              last_inten_pos = 10;
              if (lamp_status == 1)
              {
                if (endo_status == 1)
                {
                  if (depth_status == 0)
                  {
                    led_pwm_setvalue(inner_warm, ten);
                    led_pwm_setvalue(inner_white, ten);
                  }

                  else
                  {
                    led_pwm_setvalue(inner_warm, all_on);
                    led_pwm_setvalue(inner_white, all_on);
                  }

                  led_pwm_setvalue(outer_warm, all_off);
                  led_pwm_setvalue(outer_white, all_off);
                }
                else
                {
                  if (depth_status == 0)
                  {
                    led_pwm_setvalue(inner_warm, ten);
                    led_pwm_setvalue(inner_white, ten);
                    led_pwm_setvalue(outer_warm, ten);
                    led_pwm_setvalue(outer_white, ten);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, all_on);
                    led_pwm_setvalue(inner_white, all_on);
                    led_pwm_setvalue(outer_warm, all_on);
                    led_pwm_setvalue(outer_white, all_on);
                  }
                }
              }
              last_status = ten;
              break;

            default:
              break;
            }
          }
          else
          {
            led_pwm_setvalue(inner_white, all_off);
            led_pwm_setvalue(inner_warm, all_off);
            led_pwm_setvalue(outer_warm, all_off);
            led_pwm_setvalue(outer_white, all_off);
          }
        }
        else if (Rx_data[1] == 'C') //@c-5#
        {

          prgm_status = _clr;
          color_steps(last_status);
          //  avg = (res_min + res_max) / 2;
          // avg = last_status;

          if (lamp_status == 1)
          {
            if (Rx_data[2] == '-')
            {
              // avg =  res_max - 5*step_size_color;
              avg = last_status - 15;
              color_polarity = _minus;
              // if (lamp_status == 1)
              // {
              //   led_pwm_setvalue(inner_white, all_off);
              //   led_pwm_setvalue(inner_white, all_off);
              // }

              if (Rx_data[3] == '5' && depth_status != 1)
              {
                color_polarity = _minus;
                // color_status = res_min - step_size_color * 1;

                switch (last_inten_pos)
                {

                case 1:
                  curr_pwm = cn1_five;
                  break;
                case 2:
                  curr_pwm = cn2_five;
                  break;
                case 3:
                  curr_pwm = cn3_five;
                  break;
                case 4:
                  curr_pwm = cn4_five;
                  break;
                case 5:
                  curr_pwm = cn5_five;
                  break;
                case 6:
                  curr_pwm = cn6_five;
                  break;
                case 7:
                  curr_pwm = cn7_five;
                  break;
                case 8:
                  curr_pwm = cn8_five;
                  break;
                case 9:
                  curr_pwm = cn9_five;
                  break;
                case 10:
                  curr_pwm = cn10_five;
                  break;

                default:
                  break;
                }
                last_clr_status = curr_pwm;

                if (depth_status == 1)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, ten);
                    led_pwm_setvalue(inner_white, ten);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, ten);
                    led_pwm_setvalue(inner_white, ten);
                    led_pwm_setvalue(outer_warm, ten);
                    led_pwm_setvalue(outer_white, ten);
                  }
                }

                else
                {

                  // color_status = res_min - step_size_color * 1;

                  if (endo_status == 1)
                  {

                    led_pwm_setvalue(inner_warm, curr_pwm);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                    led_pwm_setvalue(outer_warm, all_off);
                  }
                  else
                  {

                    // led_pwm_setvalue(inner_warm, avg - step_size_color * 1);
                    led_pwm_setvalue(inner_warm, curr_pwm);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                    led_pwm_setvalue(outer_warm, curr_pwm);
                  }
                }
              }
              else if (Rx_data[3] == '4')
              {
                color_polarity = _minus;
                // color_status = res_min - step_size_color * 1;
                switch (last_inten_pos)
                {
                case 1:
                  curr_pwm = cn1_four;
                  break;
                case 2:
                  curr_pwm = cn2_four;
                  break;
                case 3:
                  curr_pwm = cn3_four;
                  break;
                case 4:
                  curr_pwm = cn4_four;
                  break;
                case 5:
                  curr_pwm = cn5_four;
                  break;
                case 6:
                  curr_pwm = cn6_four;
                  break;
                case 7:
                  curr_pwm = cn7_four;
                  break;
                case 8:
                  curr_pwm = cn8_four;
                  break;
                case 9:
                  curr_pwm = cn9_four;
                  break;
                case 10:
                  curr_pwm = cn10_four;
                  break;

                default:
                  break;
                }
                if (depth_status == 1)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, ten);
                    led_pwm_setvalue(inner_white, ten);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, ten);
                    led_pwm_setvalue(inner_white, ten);
                    led_pwm_setvalue(outer_warm, ten);
                    led_pwm_setvalue(outer_white, ten);
                  }
                }

                else
                {

                  // color_status = res_min - step_size_color * 2;
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, curr_pwm);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                    led_pwm_setvalue(outer_warm, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, curr_pwm);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                    led_pwm_setvalue(outer_warm, curr_pwm);
                  }
                }
              }
              else if (Rx_data[3] == '3')
              {
                color_polarity = _minus;
                color_status = res_min - step_size_color * 1;
                switch (last_inten_pos)
                {
                case 1:
                  curr_pwm = cn1_three;
                  break;
                case 2:
                  curr_pwm = cn2_three;
                  break;
                case 3:
                  curr_pwm = cn3_three;
                  break;
                case 4:
                  curr_pwm = cn4_three;
                  break;
                case 5:
                  curr_pwm = cn5_three;
                  break;
                case 6:
                  curr_pwm = cn6_three;
                  break;
                case 7:
                  curr_pwm = cn7_three;
                  break;
                case 8:
                  curr_pwm = cn8_three;
                  break;
                case 9:
                  curr_pwm = cn9_three;
                  break;
                case 10:
                  curr_pwm = cn10_three;
                  break;

                default:
                  break;
                }
                if (depth_status == 1)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, ten);
                    led_pwm_setvalue(inner_white, ten);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, ten);
                    led_pwm_setvalue(inner_white, ten);
                    led_pwm_setvalue(outer_warm, ten);
                    led_pwm_setvalue(outer_white, ten);
                  }
                }

                else
                {

                  // color_status = res_min - step_size_color * 3;
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, curr_pwm);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                    led_pwm_setvalue(outer_warm, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, curr_pwm);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                    led_pwm_setvalue(outer_warm, curr_pwm);
                  }
                }
              }
              else if (Rx_data[3] == '2')
              {
                color_polarity = _minus;
                // color_status = res_min - step_size_color * 1;
                switch (last_inten_pos)
                {
                case 1:
                  curr_pwm = cn1_two;
                  break;
                case 2:
                  curr_pwm = cn2_two;
                  break;
                case 3:
                  curr_pwm = cn3_two;
                  break;
                case 4:
                  curr_pwm = cn4_two;
                  break;
                case 5:
                  curr_pwm = cn5_two;
                  break;
                case 6:
                  curr_pwm = cn6_two;
                  break;
                case 7:
                  curr_pwm = cn7_two;
                  break;
                case 8:
                  curr_pwm = cn8_two;
                  break;
                case 9:
                  curr_pwm = cn9_two;
                  break;
                case 10:
                  curr_pwm = cn10_two;
                  break;

                default:
                  break;
                }

                if (depth_status == 1)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, ten);
                    led_pwm_setvalue(inner_white, ten);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, ten);
                    led_pwm_setvalue(inner_white, ten);
                    led_pwm_setvalue(outer_warm, ten);
                    led_pwm_setvalue(outer_white, ten);
                  }
                }

                else
                {

                  // color_status = avg  + step_size_color * 4;
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, curr_pwm);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                    led_pwm_setvalue(outer_warm, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, curr_pwm);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                    led_pwm_setvalue(outer_warm, curr_pwm);
                  }
                }
              }
              else if (Rx_data[3] == '1')
              {
                color_polarity = _minus;
                // color_status = res_min - step_size_color * 1;
                switch (last_inten_pos)
                {
                case 1:
                  curr_pwm = cn1_one;
                  break;
                case 2:
                  curr_pwm = cn2_one;
                  break;
                case 3:
                  curr_pwm = cn3_one;
                  break;
                case 4:
                  curr_pwm = cn4_one;
                  break;
                case 5:
                  curr_pwm = cn5_one;
                  break;
                case 6:
                  curr_pwm = cn6_one;
                  break;
                case 7:
                  curr_pwm = cn7_one;
                  break;
                case 8:
                  curr_pwm = cn8_one;
                  break;
                case 9:
                  curr_pwm = cn9_one;
                  break;
                case 10:
                  curr_pwm = cn10_one;
                  break;

                default:
                  break;
                }

                if (depth_status == 1)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, ten);
                    led_pwm_setvalue(inner_white, ten);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, ten);
                    led_pwm_setvalue(inner_white, ten);
                    led_pwm_setvalue(outer_warm, ten);
                    led_pwm_setvalue(outer_white, ten);
                  }
                }

                else
                {

                  // color_status = res_min - step_size_color * 5;
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, curr_pwm);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                    led_pwm_setvalue(outer_warm, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, curr_pwm);
                    led_pwm_setvalue(inner_white, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                    led_pwm_setvalue(outer_warm, curr_pwm);
                  }
                }
              }
              else if (Rx_data[3] == '0')
              {
                color_polarity = _zero;
                color_status = res_min - step_size_color * 1;
                if (depth_status == 1)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, all_on);
                    led_pwm_setvalue(inner_white, all_on);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, all_on);
                    led_pwm_setvalue(inner_white, all_on);
                    led_pwm_setvalue(outer_warm, all_on);
                    led_pwm_setvalue(outer_white, all_on);
                  }
                }

                else
                {
                  color_status = last_status;

                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, last_status);
                    led_pwm_setvalue(inner_white, last_status);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, last_status);
                    led_pwm_setvalue(inner_white, last_status);
                    led_pwm_setvalue(outer_warm, last_status);
                    led_pwm_setvalue(outer_white, last_status);
                  }
                }
              }
            }

            else if (Rx_data[2] == '+') //@c+5#
            {

              // in  t_avg = (res_min + res_max) / 2;
              // int avg = (res_max - last_status)/5;
              avg = last_status - 15; // res_max - 5*step_size_color;
              color_polarity = _plus;
              // color_status = res_min - step_size_color * 1;
              if (Rx_data[3] == '5' && depth_status != 1)
              {
                color_polarity = _plus;
                // color_status = res_min - step_size_color * 1;

                switch (last_inten_pos)
                {
                case 1:
                  curr_pwm = cp1_five;
                  break;
                case 2:
                  curr_pwm = cp2_five;
                  break;
                case 3:
                  curr_pwm = cp3_five;
                  break;
                case 4:
                  curr_pwm = cp4_five;
                  break;
                case 5:
                  curr_pwm = cp5_five;
                  break;
                case 6:
                  curr_pwm = cp6_five;
                  break;
                case 7:
                  curr_pwm = cp7_five;
                  break;
                case 8:
                  curr_pwm = cp8_five;
                  break;
                case 9:
                  curr_pwm = cp9_five;
                  break;
                case 10:
                  curr_pwm = cp10_five;
                  break;

                default:
                  break;
                }
                last_clr_status = curr_pwm;

                if (depth_status == 1)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(inner_white, ten);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, ten);
                    led_pwm_setvalue(inner_white, ten);
                    led_pwm_setvalue(outer_warm, ten);
                    led_pwm_setvalue(outer_white, ten);
                  }
                }

                else
                {
                  // color_status = avg + step_size_color * 1;
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_white, curr_pwm);
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                    led_pwm_setvalue(outer_warm, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_white, curr_pwm);
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(outer_white, curr_pwm);
                    led_pwm_setvalue(outer_warm, all_off);
                  }
                }
              }
              else if (Rx_data[3] == '4')
              {
                color_polarity = _plus;
                // color_status = res_min - step_size_color * 1;
                switch (last_inten_pos)
                {
                case 1:
                  curr_pwm = cp1_four;
                  break;
                case 2:
                  curr_pwm = cp2_four;
                  break;
                case 3:
                  curr_pwm = cp3_four;
                  break;
                case 4:
                  curr_pwm = cp4_four;
                  break;
                case 5:
                  curr_pwm = cp5_four;
                  break;
                case 6:
                  curr_pwm = cp6_four;
                  break;
                case 7:
                  curr_pwm = cp7_four;
                  break;
                case 8:
                  curr_pwm = cp8_four;
                  break;
                case 9:
                  curr_pwm = cp9_four;
                  break;
                case 10:
                  curr_pwm = cp10_four;
                  break;

                default:
                  break;
                }

                if (depth_status == 1)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(inner_white, ten);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, ten);
                    led_pwm_setvalue(inner_white, ten);
                    led_pwm_setvalue(outer_warm, ten);
                    led_pwm_setvalue(outer_white, ten);
                  }
                }

                else
                {
                  // color_status = avg + step_size_color * 1;
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_white, curr_pwm);
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                    led_pwm_setvalue(outer_warm, all_off);
                  }

                  else
                  {
                    led_pwm_setvalue(inner_white, curr_pwm);
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(outer_white, curr_pwm);
                    led_pwm_setvalue(outer_warm, all_off);
                  }
                }
              }
              else if (Rx_data[3] == '3') //@c+5#
              {
                color_polarity = _plus;
                color_status = res_min - step_size_color * 1;
                switch (last_inten_pos)
                {
                case 1:
                  curr_pwm = cp1_three;
                  break;
                case 2:
                  curr_pwm = cp2_three;
                  break;
                case 3:
                  curr_pwm = cp3_three;
                  break;
                case 4:
                  curr_pwm = cp4_three;
                  break;
                case 5:
                  curr_pwm = cp5_three;
                  break;
                case 6:
                  curr_pwm = cp6_three;
                  break;
                case 7:
                  curr_pwm = cp7_three;
                  break;
                case 8:
                  curr_pwm = cp8_three;
                  break;
                case 9:
                  curr_pwm = cp9_three;
                  break;
                case 10:
                  curr_pwm = cp10_three;
                  break;

                default:
                  break;
                }
                if (depth_status == 1)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(inner_white, ten);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, ten);
                    led_pwm_setvalue(inner_white, ten);
                    led_pwm_setvalue(outer_warm, ten);
                    led_pwm_setvalue(outer_white, ten);
                  }
                }

                else
                {
                  // color_status = res_max + step_size_color * 3;
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_white, curr_pwm);
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                    led_pwm_setvalue(outer_warm, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_white, curr_pwm);
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(outer_white, curr_pwm);
                    led_pwm_setvalue(outer_warm, all_off);
                  }
                }
              }
              else if (Rx_data[3] == '2')
              {
                color_polarity = _plus;
                color_status = res_min - step_size_color * 1;
                switch (last_inten_pos)
                {
                case 1:
                  curr_pwm = cp1_two;
                  break;
                case 2:
                  curr_pwm = cp2_two;
                  break;
                case 3:
                  curr_pwm = cp3_two;
                  break;
                case 4:
                  curr_pwm = cp4_two;
                  break;
                case 5:
                  curr_pwm = cp5_two;
                  break;
                case 6:
                  curr_pwm = cp6_two;
                  break;
                case 7:
                  curr_pwm = cp7_two;
                  break;
                case 8:
                  curr_pwm = cp8_two;
                  break;
                case 9:
                  curr_pwm = cp9_two;
                  break;
                case 10:
                  curr_pwm = cp10_two;
                  break;

                default:
                  break;
                }
                if (depth_status == 1)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(inner_white, ten);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, ten);
                    led_pwm_setvalue(inner_white, ten);
                    led_pwm_setvalue(outer_warm, ten);
                    led_pwm_setvalue(outer_white, ten);
                  }
                }

                else
                {
                  // color_status = res_max + step_size_color * 2;
                  if (endo_status == 1)
                  {
                    // led_pwm_setvalue(inner_white, avg + step_size_color * 4);
                    led_pwm_setvalue(inner_white, curr_pwm);
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                    led_pwm_setvalue(outer_warm, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_white, curr_pwm);
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(outer_white, curr_pwm);
                    led_pwm_setvalue(outer_warm, all_off);
                  }
                }
              }
              else if (Rx_data[3] == '1')
              {
                color_polarity = _plus;
                // color_status = res_min - step_size_color * 1;
                if (depth_status == 1)
                {
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(inner_white, ten);
                    led_pwm_setvalue(outer_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_warm, ten);
                    led_pwm_setvalue(inner_white, ten);
                    led_pwm_setvalue(outer_warm, ten);
                    led_pwm_setvalue(outer_white, ten);
                  }
                }

                else
                {
                  // color_status = res_max + step_size_color * 5;
                  switch (last_inten_pos)
                  {
                  case 1:
                    curr_pwm = cp1_one;
                    break;
                  case 2:
                    curr_pwm = cp2_one;
                    break;
                  case 3:
                    curr_pwm = cp3_one;
                    break;
                  case 4:
                    curr_pwm = cp4_one;
                    break;
                  case 5:
                    curr_pwm = cp5_one;
                    break;
                  case 6:
                    curr_pwm = cp6_one;
                    break;
                  case 7:
                    curr_pwm = cp7_one;
                    break;
                  case 8:
                    curr_pwm = cp8_one;
                    break;
                  case 9:
                    curr_pwm = cp9_one;
                    break;
                  case 10:
                    curr_pwm = cp10_one;
                    break;

                  default:
                    break;
                  }
                  if (endo_status == 1)
                  {
                    led_pwm_setvalue(inner_white, curr_pwm);
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(outer_white, all_off);
                    led_pwm_setvalue(outer_warm, all_off);
                  }
                  else
                  {
                    led_pwm_setvalue(inner_white, curr_pwm);
                    led_pwm_setvalue(inner_warm, all_off);
                    led_pwm_setvalue(outer_white, curr_pwm);
                    led_pwm_setvalue(outer_warm, all_off);
                  }
                }
              }
            }
          }
          else
          {
            color_polarity = _plus;
            led_pwm_setvalue(inner_white, all_off);
            led_pwm_setvalue(inner_warm, all_off);
            led_pwm_setvalue(outer_warm, all_off);
            led_pwm_setvalue(outer_white, all_off);
          }
        }

        else if (Rx_data[1] == 'L') //@L_1#
        {
          // prgm_status = _lmp;
          if (Rx_data[3] == '0')
          {
            lamp_status = 0;
            led_pwm_setvalue(inner_warm, all_off);
            led_pwm_setvalue(inner_white, all_off);
            led_pwm_setvalue(outer_warm, all_off);
            led_pwm_setvalue(outer_white, all_off);
            // HAL_UART_Transmit(&huart1, "l on", 10, 100);
          }
          else
          {
            lamp_status = 1;
            // HAL_UART_Transmit(&huart1, "ps", 10, 100);

            if (depth_status == 0)
            {
              if (endo_status == 0)
              {
                // all prv
                glow_prv();
              }
              else
              {
                // inner prv
                glow_prv_inner();
              }
            }
            else
            {
              if (endo_status == 0)
              {
                // all on max
                led_pwm_setvalue(inner_warm, all_on);
                led_pwm_setvalue(inner_white, all_on);
                led_pwm_setvalue(outer_warm, all_on);
                led_pwm_setvalue(outer_white, all_on);
              }
              else
              {
                // inner on max
                led_pwm_setvalue(inner_warm, all_on);
                led_pwm_setvalue(inner_white, all_on);
                led_pwm_setvalue(outer_warm, all_off);
                led_pwm_setvalue(outer_white, all_off);
              }
            }

            // switch (prgm_status)
            // {
            // case _inten:
            //   led_pwm_setvalue(inner_white, last_status);
            //   led_pwm_setvalue(inner_warm, last_status);
            //   led_pwm_setvalue(outer_warm, last_status);
            //   led_pwm_setvalue(outer_white, last_status);
            //   // HAL_UART_Transmit(&huart1, "1", 10, 100);

            //   break;
            // case _clr:
            //   if (color_polarity == _plus)
            //   {
            //     led_pwm_setvalue(inner_white, color_status);
            //     led_pwm_setvalue(outer_white, color_status);
            //     led_pwm_setvalue(inner_warm, all_off);
            //     led_pwm_setvalue(outer_warm, all_off);
            //     // HAL_UART_Transmit(&huart1, "2+", 10, 100);
            //   }
            //   if (color_polarity == _minus)
            //   {
            //     led_pwm_setvalue(inner_warm, color_status);
            //     led_pwm_setvalue(inner_warm, color_status);
            //     led_pwm_setvalue(inner_white, all_off);
            //     led_pwm_setvalue(inner_white, all_off);
            //     // HAL_UART_Transmit(&huart1, "2-", 10, 100);
            //   }
            //   break;
            // case _end:

            //   if (endo_status == 0)
            //   {
            //     led_pwm_setvalue(inner_white, last_status);
            //     led_pwm_setvalue(inner_warm, last_status);
            //     led_pwm_setvalue(outer_warm, last_status);
            //     led_pwm_setvalue(outer_white, last_status);
            //     // HAL_UART_Transmit(&huart1, "3", 10, 100);
            //   }
            //   else
            //   {
            //     led_pwm_setvalue(inner_warm, last_status);
            //     led_pwm_setvalue(inner_white, last_status);
            //     led_pwm_setvalue(outer_warm, all_off);
            //     led_pwm_setvalue(outer_white, all_off);
            //     // HAL_UART_Transmit(&huart1, "3", 10, 100);
            //   }
            //   break;
            // case _dep:
            //   if (depth_status == 0)
            //   {
            //     led_pwm_setvalue(inner_white, last_status);
            //     led_pwm_setvalue(inner_warm, last_status);
            //     led_pwm_setvalue(outer_warm, last_status);
            //     led_pwm_setvalue(outer_white, last_status);
            //     // HAL_UART_Transmit(&huart1, "4", 10, 100);
            //   }
            //   else
            //   {
            //     led_pwm_setvalue(inner_warm, all_on);
            //     led_pwm_setvalue(inner_white, all_on);
            //     led_pwm_setvalue(outer_warm, all_on);
            //     led_pwm_setvalue(outer_white, all_on);
            //     // HAL_UART_Transmit(&huart1, "5", 10, 100);
            //   }
            //   break;

            // default:
            //   // HAL_UART_Transmit(&huart1, "dff", 10, 100);
            //   break;
            // }
          }
        }

        else if (Rx_data[1] == 'E') // && (lamp_status == 1)
        {
          prgm_status = _end;

          if (Rx_data[3] == '0')
          {
            // endo_status = 1;
            endo_status = 0;
            // // HAL_UART_Transmit(&huart1, "e0", 10, 100);
            if (depth_status == 0)
            {
              if (lamp_status == 1)
              {
                // glow_prv();

                if (color_polarity == _zero)
                {
                  // prgm_status = _clr; alll prv based on intensity
                  led_pwm_setvalue(inner_warm, last_status);
                  led_pwm_setvalue(inner_white, last_status);
                  led_pwm_setvalue(outer_warm, last_status);
                  led_pwm_setvalue(outer_white, last_status);
                }
                else if (color_polarity == _plus)
                {
                  // prgm_status = _inten; only white
                  led_pwm_setvalue(inner_warm, all_off);
                  led_pwm_setvalue(inner_white, last_clr_status);
                  led_pwm_setvalue(outer_warm, all_off);
                  led_pwm_setvalue(outer_white, last_clr_status);
                }
                else if (color_polarity == _minus)
                {
                  led_pwm_setvalue(inner_warm, last_clr_status);
                  led_pwm_setvalue(inner_white, all_off);
                  led_pwm_setvalue(outer_warm, last_clr_status);
                  led_pwm_setvalue(outer_white, all_off);
                }
              }

              else
              {
                // HAL_UART_Transmit(&huart1, "e1", 10, 100);
                led_pwm_setvalue(inner_warm, all_off);
                led_pwm_setvalue(inner_white, all_off);
                led_pwm_setvalue(outer_warm, all_off);
                led_pwm_setvalue(outer_white, all_off);
              }
            }

            else
            {
              led_pwm_setvalue(inner_warm, all_on);
              led_pwm_setvalue(inner_white, all_on);
              led_pwm_setvalue(outer_warm, all_on);
              led_pwm_setvalue(outer_white, all_on);
            }
          }
          else // inner only
          {
            endo_status = 1;
            if (depth_status == 0)
            {
              if (lamp_status == 1)
              {
                // glow_prv_inner();
                if (color_polarity == _zero)
                {
                  // prgm_status = _clr; alll prv based on intensity
                  led_pwm_setvalue(inner_warm, last_status);
                  led_pwm_setvalue(inner_white, last_status);
                  led_pwm_setvalue(outer_warm, all_off);
                  led_pwm_setvalue(outer_white, all_off);
                }
                else if (color_polarity == _plus)
                {
                  // prgm_status = _inten; only white
                  led_pwm_setvalue(inner_warm, all_off);
                  led_pwm_setvalue(inner_white, last_clr_status);
                  led_pwm_setvalue(outer_warm, all_off);
                  led_pwm_setvalue(outer_white, all_off);
                }
                else if (color_polarity == _minus)
                {
                  led_pwm_setvalue(inner_warm, last_clr_status);
                  led_pwm_setvalue(inner_white, all_off);
                  led_pwm_setvalue(outer_warm, all_off);
                  led_pwm_setvalue(outer_white, all_off);
                }
              }
              else
              {
                led_pwm_setvalue(inner_warm, all_off);
                led_pwm_setvalue(inner_white, all_off);
                led_pwm_setvalue(outer_warm, all_off);
                led_pwm_setvalue(outer_white, all_off);
              }
            }

            else
            {
              // HAL_UART_Transmit(&huart1, "e1", 10, 100);
              // endo_status = 0;
              if (lamp_status == 1)
              {
                led_pwm_setvalue(inner_warm, all_on);
                led_pwm_setvalue(inner_white, all_on);
                led_pwm_setvalue(outer_warm, all_off);
                led_pwm_setvalue(outer_white, all_off);
              }
              else
              {
                led_pwm_setvalue(inner_warm, all_off);
                led_pwm_setvalue(inner_white, all_off);
                led_pwm_setvalue(outer_warm, all_off);
                led_pwm_setvalue(outer_white, all_off);
              }
            }
          }
        }

        else if (Rx_data[1] == 'D') //  && (lamp_status == 1)
        {

          prgm_status = _dep;
          if (Rx_data[3] == '0')
          {

            depth_status = 0;
            if (lamp_status == 1)
            {
              if (endo_status == 1)
              {
                led_pwm_setvalue(inner_warm, last_status);
                led_pwm_setvalue(inner_white, last_status);
                led_pwm_setvalue(outer_warm, all_off);
                led_pwm_setvalue(outer_white, all_off);
              }
              else
              {
                led_pwm_setvalue(inner_warm, last_status);
                led_pwm_setvalue(inner_white, last_status);
                led_pwm_setvalue(outer_warm, last_status);
                led_pwm_setvalue(outer_white, last_status);
              }
            }
            else
            {
              led_pwm_setvalue(inner_warm, all_off);
              led_pwm_setvalue(inner_white, all_off);
              led_pwm_setvalue(outer_warm, all_off);
              led_pwm_setvalue(outer_white, all_off);
            }
          }
          else // if (Rx_data[3] == '1' && (lamp_status == 1))
          {
            depth_status = 1;
            if (lamp_status == 1)
            {
              if (endo_status == 1)
              {
                led_pwm_setvalue(inner_warm, all_on);
                led_pwm_setvalue(inner_white, all_on);
                led_pwm_setvalue(outer_warm, all_off);
                led_pwm_setvalue(outer_white, all_off);
              }
              else
              {
                led_pwm_setvalue(inner_warm, all_on);
                led_pwm_setvalue(inner_white, all_on);
                led_pwm_setvalue(outer_warm, all_on);
                led_pwm_setvalue(outer_white, all_on);
              }
            }
            else
            {
              led_pwm_setvalue(inner_warm, all_off);
              led_pwm_setvalue(inner_white, all_off);
              led_pwm_setvalue(outer_warm, all_off);
              led_pwm_setvalue(outer_white, all_off);
            }
          }
        }

        else if (Rx_data[1] == 'F')
        {
          if (Rx_data[3] == '1')
          {
            if (lamp_status == 1)
            {
              led_pwm_setvalue(inner_warm, 100 - 15);
              led_pwm_setvalue(inner_white, 100 - 15);
              led_pwm_setvalue(outer_warm, 100 - 15);
              led_pwm_setvalue(outer_white, 100 - 15);
            }
            else
            {
              led_pwm_setvalue(inner_warm, all_off);
              led_pwm_setvalue(inner_white, all_off);
              led_pwm_setvalue(outer_warm, all_off);
              led_pwm_setvalue(outer_white, all_off);
            }
          }
          if (Rx_data[3] == '2')
          {
            if (lamp_status == 1)
            {
              led_pwm_setvalue(inner_warm, 100 - 50);
              led_pwm_setvalue(inner_white, 100 - 50);
              led_pwm_setvalue(outer_warm, 100 - 50);
              led_pwm_setvalue(outer_white, 100 - 50);
            }
            else
            {
              led_pwm_setvalue(inner_warm, all_off);
              led_pwm_setvalue(inner_white, all_off);
              led_pwm_setvalue(outer_warm, all_off);
              led_pwm_setvalue(outer_white, all_off);
            }
          }
          if (Rx_data[3] == '3')
          {
            if (lamp_status == 1)
            {
              led_pwm_setvalue(inner_warm, all_on);
              led_pwm_setvalue(inner_white, all_on);
              led_pwm_setvalue(outer_warm, all_on);
              led_pwm_setvalue(outer_white, all_on);
            }
            else
            {
              led_pwm_setvalue(inner_warm, all_off);
              led_pwm_setvalue(inner_white, all_off);
              led_pwm_setvalue(outer_warm, all_off);
              led_pwm_setvalue(outer_white, all_off);
            }
          }
        }
      }
    }
    //	      HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
    HAL_Delay(100);
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

  /** Initializes the RCC Oscillators according to the specified parameters
   * in the RCC_OscInitTypeDef structure.
   */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL12;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
   */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
 * @brief TIM1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 48 - 1;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 100 - 1;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */
  HAL_TIM_MspPostInit(&htim1);
}

/**
 * @brief TIM3 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 48 - 1;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 100 - 1;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */
  HAL_TIM_MspPostInit(&htim3);
}

/**
 * @brief USART1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */
}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void)
{
  /* USER CODE BEGIN MX_GPIO_Init_1 */
  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /* USER CODE BEGIN MX_GPIO_Init_2 */
  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

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

#ifdef USE_FULL_ASSERT
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
