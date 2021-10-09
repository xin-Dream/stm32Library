# STM32Library

# 一、 框架结构
## 1. algorithm
  > 一些算法函数
  + uint32_t my_32abs(uint32_t number)
    + 函数功能：对unsigned int32的数据取绝对值
    + 输入参数：需要取绝对值的数据
    + 输出参数：取绝对值后的数据
    + 注意事项：无
  + int my_abs(int number)
    + 函数功能：对unsigned int32的数据取绝对值
    + 输入参数：需要取绝对值的数据
    + 输出参数：取绝对值后的数据
    + 注意事项：无
  + float filter(float alpha, float adc_now, float adc_pre)
    + 函数功能：一阶低通滤波器
    + 输入参数：
    + 输出参数：
    + 注意事项：
  + void quick_sort(int a[], int length)
    + 函数功能：
    + 输入参数：
    + 输出参数：
    + 注意事项：
  + void my_qsort(int a[], int low, int high)
    + 函数功能：
    + 输入参数：
    + 输出参数：
    + 注意事项：
  + int partition(int a[], int low, int high)
    + 函数功能：
    + 输入参数：
    + 输出参数：
    + 注意事项：
  + int direction_judge(int a[])
    + 函数功能：
    + 输入参数：
    + 输出参数：
    + 注意事项：
  + int varweight_mean(int a[])
    + 函数功能：
    + 输入参数：
    + 输出参数：
    + 注意事项：
  + int angle_position(int TargetAngle)
    + 函数功能：
    + 输入参数：
    + 输出参数：
    + 注意事项：
  + int angle_incremental(int deviation)
    + 函数功能：
    + 输入参数：
    + 输出参数：
    + 注意事项：
  + int Get_Target(int start, int bias)
    + 函数功能：
    + 输入参数：
    + 输出参数：
    + 注意事项：
  + int Get_Bias(int start, int target)
    + 函数功能：
    + 输入参数：
    + 输出参数：
    + 注意事项：
  + int PID_Control(int SetPoint, int CurrentPoint, PID_TypeDef pid_params)
    + 函数功能：
    + 输入参数：
    + 输出参数：
    + 注意事项：
## 2. communication
  > stm32中通讯相关的函数，如蓝牙、WiFi、CAN等
  + void myuart_DMA(UART_HandleTypeDef *huart)
    + 函数功能：
    + 输入参数：
    + 输出参数：
    + 注意事项：
  + void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
  + void myuartDMA_callback(UART_HandleTypeDef *huart)
  + void JY60_Callback(UART_HandleTypeDef *huart)
  + PUTCHAR_PROTOTYPE
## 3. macro
  > 宏文件，综合性函数
  + void ParamsInit()
  + void structParams()
  + void OLED_Show(void)
  + int limit_range(int speed, int limit_num)
  + void ADCpartition()
  + void judge(void)
## 4. motorControl
  > 控制电机相关的底层函数，如直流减速电机、步进电机、舵机、伺服电机等
  + void encode_read(TIM_HandleTypeDef L_tim, TIM_HandleTypeDef R_tim)
  + void remoteControl()
  + void motor_control(int L_speed, int R_speed)
## 5. oled
  > OLED屏幕显示的函数
  + void OLED_Refresh_Gram(void)
  + void OLED_WR_Byte(uint8_t dat, uint8_t cmd)
  + void OLED_Display_On(void)
  + void OLED_Display_Off(void)
  + void OLED_Clear(void)
  + void OLED_DrawPoint(uint8_t x, uint8_t y, uint8_t t)
  + void OLED_Fill(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t dot)
  + void OLED_ShowChar(uint8_t x, uint8_t y, uint8_t chr, uint8_t size, uint8_t mode)
  + uint32_t mypow(uint8_t m, uint8_t n)
  + void OLED_ShowNum(uint8_t x, uint8_t y, uint32_t num, uint8_t len, uint8_t size)
  + void OLED_ShowString(uint8_t x, uint8_t y, const uint8_t *p, uint8_t size)
  + void OLED_Init(void)
  + 
## 6. tft
  > TFT屏幕显示的函数