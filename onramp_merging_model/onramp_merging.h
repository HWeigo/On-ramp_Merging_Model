#ifndef __ONRAMP_MERGING_H
#define __ONRAMP_MERGING_H

#include "includes.h"

#define RISK_MODE     //注释关闭冒险模式
#define DEBUG
const float d_Follow = 10; //安全跟车距离

//声明类
class Master_CarNode; 
class Other_CarNode;

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
const float x_mergePoint = 1000;
class Master_CarNode
{
public:
	float v_current;
	float x_current = 0;
	float a_safe;
	float v_max = 0;
	float v_min = 0;
	uint8_t lane = 0;
	float length;
	float calc_TimeToMergePoint();
	float calc_BrakeDistance();
	void calc_vRange(Other_CarNode other);

private:
	float a_MAX; //车辆牵引力能提供的最大加速度
	float v_MAX =10000; //车辆理论最大速度
};

/*
* 定义旁车结点
* \param v 车速
* \param x x方向上坐标
* \param 
* \param lane 车道
* \param length 车长
*/
typedef enum
{
	None = 0,
	ArriveBeforeMaster =1,
	ArriveAfterMaster =2,
}Label_e;

class Other_CarNode
{
public:
	float v_current;
	float x_current;
	float v_previous;
	uint8_t lane = 1;
	float length;
	Label_e label = None;
	void labeling(Master_CarNode master);
	float calc_TimeToMergePoint();

private:
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



#endif 