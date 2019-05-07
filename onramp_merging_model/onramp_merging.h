#ifndef __ONRAMP_MERGING_H
#define __ONRAMP_MERGING_H

#include "includes.h"

#define RISK_MODE     //注释关闭冒险模式
#define DEBUG

/*********************************/

const float d_Follow = 10; //安全跟车距离
const float v_speedLimit = 90; //道路限速
const float x_mergePoint = 1000; //汇流点坐标

/*********************************/


//声明类
class Master_CarNode; 
class Other_CarNode;

/*
* 定义主车结点
* \param v_current 当前车速
* \param v_target 目标车速
* \param x_current x方向上坐标
* \param a_safe 安全加速度
* \param v_max 可行速度域中最大速度
* \param v_min 可行速度域中最小速度
* \param lane 车道 
* \param length 车长
* \param a_MAX 车辆牵引力能提供的最大加速度
* \param v_MAX 车辆理论最大速度

* \func calc_TimeToMergePoint 返回到汇流点时间
* \func calc_BrakeDistance 返回刹车距离
* \func calc_vRange 计算可行速度域
*/

class Master_CarNode
{
public:
	float v_current = 0;
	float v_target = 0;
	float x_current = 0;
	float a_safe = 7; //待标定 刹车加速度
	float v_max = v_speedLimit;
	float v_min = 0;
	uint8_t lane = 0;  //未使用
	float length;
	float calc_TimeToMergePoint();
	float calc_BrakeDistance();
	void calc_vRange(Other_CarNode &other);
	//void adjustSpeed(Other_CarNode other);

private:
	float a_MAX; //车辆牵引力能提供的最大加速度
	float v_MAX = v_speedLimit; //车辆理论最大速度
};

typedef enum
{
	None = 0,
	ArriveBeforeMaster =1,
	ArriveAfterMaster =2,
}Label_e;

/*
* 定义旁车结点
* \param v_current 车速
* \param v_previous 上一时刻车速
* \param x_current x方向上坐标
* \param lane 车道
* \param length 车长
* \param label 旁车标签
* 【None：无，ArriveBeforeMaster：比主车先到汇流点，ArriveAfterMaster：比主车后到汇流点】
*
* \func labeling 打标签
* \func calc_TimeToMergePoint() 返回到达汇流点时间
*/
class Other_CarNode
{
public:
	float v_current = -1;
	float v_previous = 0; //未使用
	float x_current;
	uint8_t lane = 1; //未使用
	float length = 2;
	Label_e label = None;
	void labeling(Master_CarNode master);
	float calc_TimeToMergePoint();
};

//返回最小值
template <class T>
T MIN(T n1, T n2);
template <class T>
T MIN(T n1, T n2, T n3);

//返回最大值
template <class T>
T MAX(T n1, T n2);
template <class T>
T MAX(T n1, T n2, T n3);

//状态机枚举定义
//typedef enum
//{
//	MERGE = 1,
//	KEEPLANE = 2,
//	PREPMERGE = 3, 
//
//}MergeState_e;
//
//typedef enum
//{
//	STOP = 0,
//	UNIFORMSPEED = 1,
//	SPEEDUP = 2,
//	SLOWDOWN = 3,
//}SpeedMode_e;

#endif 

