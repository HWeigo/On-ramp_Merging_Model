#include "onramp_merging.h"
#include "calculation.h"

MergeState_e MergeState = KEEPLANE;
MergeState_e last_MergeState = KEEPLANE;

void MergeStateFSM(Master_CarNode master, Other_CarNode other)
{
	switch (MergeState)
	{
	case KEEPLANE:
	{
		checkMergingCondition(master, other);
	}break;
	case PREPMERGE:
	{
		adjustSpeed_PREPMERGE();
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
	else adjustSpeed_KEEPLANE();

	return;
}

void adjustSpeed_PREPMERGE()
{

}

void adjustSpeed_KEEPLANE()
{

}


