#include "includes.h"

float calc_SafeDistance(Master_CarNode master, Other_CarNode other)
{
	switch (other.label)
	{
	case ArriveBeforeMaster:
	{
		if (other.v_current > master.v_current)
		{
			return master.calc_BrakeDistance() + other.length;
		}
		else
		{
			return master.calc_BrakeDistance() + other.length +
				(master.v_current * master.v_current - other.v_current * other.v_current) / 2 / master.a_safe;
		}
	}
	case ArriveAfterMaster:
	{
		if (master.v_current > other.v_current)
		{
			return master.calc_BrakeDistance() + master.length;
		}
		else
		{
			return master.calc_BrakeDistance() + master.length +
				(other.v_current * other.v_current - master.v_current * master.v_current) / 2 / master.a_safe;
		}
	}
	default:
		break;
	}
}


