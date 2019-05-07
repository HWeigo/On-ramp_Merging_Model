#include "includes.h"

#define MIN(A,B) ((A)<(B)? (A):(B)) 
#define MAX(A,B) ((A)>(B)? (A):(B))


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

void Master_CarNode::calc_vRange(Other_CarNode other)
{
	switch (other.label)
	{
	case ArriveBeforeMaster:
	{
		float x_tmp;   //�Գ�����MergePointʱ��������ȫλ��
		float delta_x; //������MergePoint����

		delta_x = x_mergePoint - x_current;
		x_tmp = delta_x - calc_SafeDistance(*this, other);
		v_max = x_tmp / other.calc_TimeToMergePoint();
		v_max = MIN(v_max, v_MAX); 
	}break;
	case ArriveAfterMaster:
	{
		float t_tmp; //t_tmp������С�ٶȵ���MergePoint��ʱ��
		float delta_x; //������MergePoint����

		delta_x = x_mergePoint - x_current;
		t_tmp = other.calc_TimeToMergePoint() - calc_SafeDistance(*this, other) / other.v_current;
		v_min = delta_x / t_tmp;
		v_min = MAX(v_min, 0);
	}break;
	default:
		break;
	}
}


