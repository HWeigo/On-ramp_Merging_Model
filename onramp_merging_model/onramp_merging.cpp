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

void Other_CarNode::calc_vRangeForMaster(Master_CarNode master)
{
	labeling(master);

	switch (label)
	{
	case ArriveBeforeMaster:
	{
		float x_tmp;   //旁车到达MergePoint时，主车安全位置
		float delta_x; //主车与MergePoint距离
		float v_lastmax;

		delta_x = x_mergePoint - master.x_current;
		x_tmp = delta_x - calc_SafeDistance(master, *this);
		v_MasterMax = x_tmp / calc_TimeToMergePoint();
	}break;
	case ArriveAfterMaster:
	{
		float t_tmp; //t_tmp：主车以最小速度到达MergePoint的时间
		float delta_x; //主车与MergePoint距离
		float v_lastmin;

		delta_x = x_mergePoint - master.x_current;
		t_tmp = calc_TimeToMergePoint() - calc_SafeDistance(master, *this) / v_current;
		v_MasterMin = delta_x / t_tmp;
	}break;
	default:
		break;
	}
}

float Master_CarNode::calc_TimeToMergePoint()
{
	return (x_mergePoint - x_current)/v_current;
}

float Master_CarNode::calc_BrakeDistance()
{
	return v_current * v_current / (a_safe * 2);
}

void Master_CarNode::calc_vRange(Other_CarNode *other)
{
	int i = 0;
	while (other[i].v_current != -1)
	{
		other[i].calc_vRangeForMaster(*this);
		switch (other[i].label)
		{
		case ArriveBeforeMaster:
		{
			v_max = MIN(v_max, other[i].v_MasterMax, v_MAX);
		}break;
		case ArriveAfterMaster:
		{
			v_min = MAX(v_min, other[i].v_MasterMin, 0.0f);
		}break;
		default:
			break;
		}
		++i;
	}
}


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

