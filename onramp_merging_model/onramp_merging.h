#ifndef __ONRAMP_MERGING_H
#define __ONRAMP_MERGING_H

#include "includes.h"

#define RISK_MODE     //注释关闭冒险模式


/*
* 定义主车结点
* \param v 车速
* \param x x方向上坐标
* \param a_max 可输出最大加速度
* \param a_safe 安全加速度
* \param lane 车道
* \param length 车长
* \param x_mergePoint 预计汇流点
*/
struct Master_CarNode
{
	float v;
	float x;
	float a_max;
	float a_safe;
	uint8_t lane = 0;
	float length;
	float x_mergePoint;
};

/*
* 定义旁车结点
* \param v 车速
* \param x x方向上坐标
* \param 
* \param lane 车道
* \param length 车长
*/
struct Other_CarNode
{
	float v;
	float x;
	float previous_v;
	uint8_t lane = 1;
	float length;
};

typedef enum
{
	MERGE = 1,
	KEEPLANE = 2,
	PREPMERGE = 3, 

}MergeState_e;

typedef enum
{
	STOP = 0,
	UNIFORMSPEED = 1,
	SPEEDUP = 2,
	SLOWDOWN = 3,
}SpeedMode_e;


void MergeStateFSM(void);
void checkMergingCondition_KL(const Master_CarNode master, const Other_CarNode other);

void adjustSpeed_KL(Master_CarNode master, Other_CarNode other);
void adjustSpeed_PREP(Master_CarNode master, Other_CarNode other);

#endif 