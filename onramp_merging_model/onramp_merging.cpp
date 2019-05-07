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

//ע��δ����쳣����
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
		float x_tmp;   //�Գ�����MergePointʱ��������ȫλ��
		float delta_x; //������MergePoint����
		float v_lastmax;

		v_lastmax = v_max;

		delta_x = x_mergePoint - x_current;
		x_tmp = delta_x - calc_SafeDistance(*this, other);
		v_max = x_tmp / other.calc_TimeToMergePoint();
		v_max = MIN(v_max, v_lastmax, v_MAX); //��ǰʱ������ٶ���ȡСֵ
	}break;
	case ArriveAfterMaster:
	{
		float t_tmp; //t_tmp������С�ٶȵ���MergePoint��ʱ��
		float delta_x; //������MergePoint����
		float v_lastmin;

		v_lastmin = v_min;

		delta_x = x_mergePoint - x_current;
		t_tmp = other.calc_TimeToMergePoint() - calc_SafeDistance(*this, other) / other.v_current;
		v_min = delta_x / t_tmp;
		v_min = MAX(v_min, v_lastmin, 0.0f); //��ǰʱ������ٶ���ȡ��ֵ
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

