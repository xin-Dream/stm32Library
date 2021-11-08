//
// Created by dream on 2021/11/8.
//

// 武术擂台机器人专有函数

#include "Arena.h"

extern Sensor_TypeDef sensors;

extern Motor_TypeDef motor;


void OLED_Show(void) {
	//	len1=1000;len2=2000;len3=3000;len4=4000;
	//	len5=5000;len6=6000;len7=7000;len8=8000;
	//=============第一行显示len1—len4=======================//
	// 第一行数据显示前面四个传感器
	// 依次为：前左，下左，下右，前右
//    OLED_ShowNum(00, 0, sensors.ADC_Buff[3], 4, 12);
//    OLED_ShowNum(32, 0, sensors.ADC_Buff[4], 4, 12);
//    OLED_ShowNum(64, 0, sensors.ADC_Buff[5], 4, 12);
//    OLED_ShowNum(96, 0, sensors.ADC_Buff[6], 4, 12);
	OLED_ShowNum(00, 0, sensors.ADC_Buff[5], 4, 12);
	OLED_ShowNum(32, 0, sensors.ADC_Buff[7], 4, 12);
	OLED_ShowNum(64, 0, sensors.ADC_Buff[4], 4, 12);
	OLED_ShowNum(96, 0, sensors.ADC_Buff[9], 4, 12);
	//=============第二行显示len5—len7=======================//
	// 第二行数据显示另外三个测距传感器
	// 依次为：左，后，右
//    OLED_ShowNum(00, 10, sensors.ADC_Buff[7], 4, 12);
//    OLED_ShowNum(32, 10, sensors.ADC_Buff[8], 4, 12);
//    OLED_ShowNum(64, 10, sensors.ADC_Buff[9], 4, 12);
	OLED_ShowNum(00, 10, sensors.ADC_Buff[6], 4, 12);
	OLED_ShowNum(32, 10, sensors.ADC_Buff[8], 4, 12);
	OLED_ShowNum(64, 10, sensors.ADC_Buff[3], 4, 12);
	OLED_ShowNum(96, 10, sensors.motion_flag, 4, 12);
//	OLED_ShowNum(96, 10, motion_flag, 4, 12);
	//=============第三行显示编码器1=======================//
	OLED_ShowString(00, 20, "L", 12);
	if (motor.L_encode_Dir)
		OLED_ShowString(12, 20, "+", 12), OLED_ShowNum(24, 20,
													   motor.L_encode, 5, 12);
	else
		OLED_ShowString(12, 20, "-", 12), OLED_ShowNum(24, 20, motor.L_encode,
													   5, 12);
	//=============第三行显示编码器2=======================//
	OLED_ShowString(62 + 00, 20, "R", 12);
	if (motor.R_encode_Dir)
		OLED_ShowString(62 + 12, 20, "+", 12), OLED_ShowNum(62 + 24, 20,
															motor.R_encode, 5, 12);
	else
		OLED_ShowString(62 + 12, 20, "-", 12), OLED_ShowNum(62 + 24, 20,
															motor.R_encode, 5, 12);

	//=============第四行显示PWM左=======================//
	OLED_ShowString(00, 30, "L", 12);
	if (motor.speed < 0)
		OLED_ShowString(13, 30, "-", 12), OLED_ShowNum(31, 30,
													   -motor.speed, 4, 12);
	else
		OLED_ShowString(13, 30, "+", 12), OLED_ShowNum(31, 30, motor.speed,
													   4, 12);
	//=============第四行显示PWM右=======================//
//	OLED_ShowString(64 + 00, 30, "R",12);
//	if (L_motor.speed < 0)
//		OLED_ShowString(64 + 13, 30, "-",12), OLED_ShowNum(64 + 31, 30, -L_motor.speed,
//				4, 12);
//	else
//		OLED_ShowString(64 + 13, 30, "+",12), OLED_ShowNum(64 + 31, 30, L_motor.speed, 4,
//				12);
	//=============第五行显示角度=======================//
	OLED_ShowString(0, 40, "P", 12);
	OLED_ShowNum(0 + 14, 40, sensors.PITCH, 5, 12);
	OLED_ShowString(42, 40, "R", 4);
	OLED_ShowNum(42 + 14, 40, sensors.ROLL, 5, 12);
	OLED_ShowString(85, 40, "Y", 4);
	OLED_ShowNum(85 + 14, 40, sensors.YAW, 5, 12);
	//=============第六行显示灰度=======================//
	//  第六行数据显示三个灰度传感器
	// 依次为：前左，后中，前右
	OLED_ShowNum(00, 50, sensors.ADC_Buff[0], 4, 12);
	OLED_ShowNum(40, 50, sensors.ADC_Buff[1], 4, 12);
	OLED_ShowNum(80, 50, sensors.ADC_Buff[2], 4, 12);

	//=============刷新=======================//
	OLED_Refresh_Gram();
}

/**
 * @简 介： ADC数据分类
 * @参 数：  无
 * @返回值：  无
 * @备 注：  无
 */
void ADCpartition() {
	uint32_t range_forward;

	//将前两测距传感器数据存入Range_forward并处理，将处理后的数据用做前侧数据
	sensors.Range_forward[0] = sensors.ADC_Buff[5];
	sensors.Range_forward[1] = sensors.ADC_Buff[9];
	//数据进行变权重处理
	range_forward = varweight_mean(sensors.Range_forward);

	//将周围测距传感器按，前后左右顺序分别存入Range_around
	sensors.Range_around[0] = range_forward;
	sensors.Range_around[1] = sensors.ADC_Buff[8];
	sensors.Range_around[2] = sensors.ADC_Buff[6];
	sensors.Range_around[3] = sensors.ADC_Buff[3];

	//按先左后右的顺序将传感器数据存入，以待后续处理
	sensors.Range_below[0] = sensors.ADC_Buff[7];
	sensors.Range_below[1] = sensors.ADC_Buff[4];

	//由于灰度传感器按三角放置，故按前左，前右，后中的顺序存入Gray
	sensors.Gray[0] = sensors.ADC_Buff[0];
	sensors.Gray[1] = sensors.ADC_Buff[1];
	sensors.Gray[2] = sensors.ADC_Buff[2];
}
/*
 * 角度控制算法-------------------------------------------------------------------------------------
 */
/**
 * @简 介： 角度绝对值控制函数
 * @参 数： 目标角度值，顺时针为正，逆时针为负
 * @返回值： 是否已到达目标角度
 * @备 注：无
 */
int angle_position(int TargetAngle) {
	//将角度值映射到0-65535
	//其实这个映射为0-65535或0-360是一样的，只是较大的数值会提高一点控制精度
	int TargetValue = TargetAngle * 182;    //182=(1/360)*65535
	int bias;
	int sum = 0;
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);

	while (1) {
		bias = Get_Bias(sensors.YAW, TargetValue);
		sum += bias;

		motor_control(-bias * motor.turn_coff, bias * motor.turn_coff);
		HAL_Delay(1);
		if (my_abs(bias) < 600) {
			break;
		}
	}

	motor_control(0, 0);
}

/**
 * @简 介： 角度增量式控制函数
 * @参 数： 增量式目标角度值，顺时针为正，逆时针为负
 * @返回值： 是否已到达目标角度
 * @备 注： 无
 */
int angle_incremental(int deviation) {
	int target;
	int bias;
	int sum = 0;
	int deviationValue = deviation * 182;//182=(1/360)*65535
	int local_angle = sensors.YAW;

	target = Get_Target(local_angle, deviationValue);
	//    motor.target = 32000;

	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);

	while (1) {
		bias = Get_Bias(sensors.YAW, target);
		sum += bias;
		motor_control(-bias * motor.turn_coff, bias * motor.turn_coff);
		HAL_Delay(1);
		if (my_abs(bias) < 600) {
			break;
		}
	}
	motor_control(0, 0);
}


int Get_Target(int start, int bias) {

	int sum = start + bias;

	if (sum < 0) {
		sum += 65535;
	} else if (sum > 65535) {
		sum -= 65535;
	} else {
		return sum;
	}
}

int Get_Bias(int start, int target) {
	int bias;
	bias = target - start;
	if (bias < -32000) {
		bias = bias + 65535;
	} else if (bias > 32000) {
		bias = bias - 65535;
	}
	return bias;
}

void judge(void) {

	if (sensors.motion_flag == left) {
		angle_incremental(90);
	} else if (sensors.motion_flag == right) {
		angle_incremental(-90);
	} else if (sensors.motion_flag == backward) {
		//        angle_incremental(180);
		return;
	} else {
		return;
	}
}