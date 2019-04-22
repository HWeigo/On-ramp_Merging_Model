#include "includes.h"

MergeState_e MergeState = KEEPLANE;
MergeState_e last_MergeState = KEEPLANE;
SpeedMode_e SpeedMode = UNIFORMSPEED;

Master_CarNode g_master;
Other_CarNode g_other;


//汇流状态机
void MergeStateFSM(void)
{
	switch (MergeState)
	{
	case KEEPLANE:
	{
		checkMergingCondition_KL(g_master, g_other);
	}break;
	case PREPMERGE:
	{
		adjustSpeed_PREP(g_master,g_other);
	}break;
	case MERGE:
	{

	}break;
	default:
		break;
	}
	last_MergeState = MergeState;   //暂未使用
}

//KEEPLANE状态下监测是否可以汇流
void checkMergingCondition_KL(const Master_CarNode master, const Other_CarNode other) 
{
	float delta_x = 0;
	float MMS = 0;

	delta_x = master.x - other.x;
	MMS = calc_MMS(master, other);

	if (delta_x > MMS) MergeState = PREPMERGE;    //满足汇流条件切换至PREPMERGE
	else adjustSpeed_KL(master,other);            //否则调整速度

	return;
}

void adjustSpeed_PREP(Master_CarNode master, Other_CarNode other)
{
	float delta_master2mergePoint;
	float delta_other2mergePoint;

	delta_master2mergePoint = master.x_mergePoint - master.x;
	delta_other2mergePoint = master.x_mergePoint - other.x;

	if (delta_master2mergePoint / master.v < delta_other2mergePoint / other.v)
	{
		SpeedMode = UNIFORMSPEED;
	}
	else
	{
		SpeedMode = SLOWDOWN;
	}
}

void adjustSpeed_KL(Master_CarNode master, Other_CarNode other)
{

}


