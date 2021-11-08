//
// Created by dream on 2021/11/8.
//

#ifndef _ARENA_H
#define _ARENA_H

#include "macro.h"

/*
 * 角度控制算法-------------------------------------------------------------------------------------
 */
int angle_position(int TargetAngle);

int angle_incremental(int deviation);

int Get_Target(int start, int bias);

int Get_Bias(int start, int target);
/*
 * -------------------------------------------------------------------------------------
 */
void OLED_Show();

void ADCpartition();

void judge(void);

#endif //_ARENA_H
