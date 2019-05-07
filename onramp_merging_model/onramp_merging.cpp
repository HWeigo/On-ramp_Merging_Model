#include "includes.h"

//#define MIN(A,B,C) ( (A)<(B)? ( (A)<(C)?(A):(C)) : ((B)<(C)?(B):(C)) )
//#define MAX(A,B,C) ( (A)>(B)? ( (A)>(C)?(A):(C)) : ((B)>(C)?(B):(C)) )


void Other_CarNode::labeling(Master_CarNode master)
{
	if (master.calc_TimeToMergePoint() < calc_TimeToMergePoint())
	{
		label = ArriveAfterMaster;
	}
	else
	{
		label = ArriveBeforeMaster;
	}
}

//注，未添加异常处理
float Other_CarNode::calc_TimeToMergePoint()
{
	return (x_mergePoint - x_current) / v_current;
}

float Master_CarNode::calc_TimeToMergePoint()
{
	return (x_mergePoint - x_current)/v_current;
}

float Master_CarNode::calc_BrakeDistance()
{
	return v_current * v_current / (a_safe * 2);
}

void Master_CarNode::calc_vRange(Other_CarNode &other)
{
	other.labeling(*this);
	switch (other.label)
	{
	case ArriveBeforeMaster:
	{
		float x_tmp;   //旁车到达MergePoint时，主车安全位置
		float delta_x; //主车与MergePoint距离
		float v_lastmax;

		v_lastmax = v_max;

		delta_x = x_mergePoint - x_current;
		x_tmp = delta_x - calc_SafeDistance(*this, other);
		v_max = x_tmp / other.calc_TimeToMergePoint();
		v_max = MIN(v_max, v_lastmax, v_MAX); //当前时刻最大速度中取小值
	}break;
	case ArriveAfterMaster:
	{
		float t_tmp; //t_tmp：以最小速度到达MergePoint的时间
		float delta_x; //主车与MergePoint距离
		float v_lastmin;

		v_lastmin = v_min;

		delta_x = x_mergePoint - x_current;
		t_tmp = other.calc_TimeToMergePoint() - calc_SafeDistance(*this, other) / other.v_current;
		v_min = delta_x / t_tmp;
		v_min = MAX(v_min, v_lastmin, 0.0f); //当前时刻最大速度中取大值
	}break;
	default:
		break;
	}
}

//void Master_CarNode::adjustSpeed(Other_CarNode other)
//{
//
//}

template<class T>
T MIN(T n1, T n2)
{
	return n1 < n2 ? n1 : n2;
}
template<class T>
T MIN(T n1, T n2, T n3)
{
	return n1 < n2 ? (n1 < n3 ? n1 : n3) : (n2 < n3 ? n2 : n3);
}

template<class T>
T MAX(T n1, T n2)
{
	return n1 > n2 ? n1 : n2;
}
template<class T>
T MAX(T n1, T n2, T n3)
{
	return n1 > n2 ? (n1 > n3 ? n1 : n3) : (n2 > n3 ? n2 : n3);
}

