#include "onramp_merging.h"


MergeState_e MergeState = KEEPLANE;
MergeState_e last_MergeState = KEEPLANE;
void MergeStateFSM(void)
{
	switch (MergeState)
	{
	case KEEPLANE:
	{
		
	}break;
	case MERGE:
	{

	}break;
	default:
		break;
	}
	last_MergeState = MergeState;
}

void checkCondition(carNode master, carNode other)
{
	float delta_x = 0;
	float MMS = 0;

	delta_x = master.x - other.x;
	MMS = calc_MMS(master, other);

	if (delta_x > MMS) MergeState = MERGE;
	
	return;
}



float calc_LineSafeDistance(carNode master, carNode other)
{
	if (other.v > master.v)
	{
		float tc, master_a;
		#ifdef RISK_MODE
		master_a = master.amax;
		#else
		master_a = master.amin;
		#endif 
		tc = (other.v - master.v) / master_a;

		return master.length + master_a * tc * tc / 2;
	}
	else
	{
		return master.length;
	}
}

float calc_BrakeDistance(carNode master)
{
	return master.v * master.v / (master.amin * 2);
}

float calc_MMS(carNode master, carNode other)
{
	return calc_BrakeDistance(master) + calc_LineSafeDistance(master, other);
}

