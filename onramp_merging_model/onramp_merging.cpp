#include "includes.h"

MergeState_e MergeState = KEEPLANE;
MergeState_e last_MergeState = KEEPLANE;

Master_CarNode g_master;
Other_CarNode g_other;

void MergeStateFSM(void)
{
	switch (MergeState)
	{
	case KEEPLANE:
	{
		checkMergingCondition(g_master, g_other);
	}break;
	case PREPMERGE:
	{
		adjustSpeed_PREP();
	}break;
	case MERGE:
	{

	}break;
	default:
		break;
	}
	last_MergeState = MergeState;
}

void checkMergingCondition(Master_CarNode master, Other_CarNode other)
{
	float delta_x = 0;
	float MMS = 0;

	delta_x = master.x - other.x;
	MMS = calc_MMS(master, other);

	if (delta_x > MMS) MergeState = MERGE;
	else adjustSpeed_KL();

	return;
}

void adjustSpeed_PREP()
{

}

void adjustSpeed_KL()
{

}


