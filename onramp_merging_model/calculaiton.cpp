#include "includes.h"

float calc_LineSafeDistance(Master_CarNode master, Other_CarNode other)
{
	if (other.v > master.v)
	{
		float tc, master_a;
#ifdef RISK_MODE
		master_a = master.a_max;
#else
		master_a = master.a_safe;
#endif 
		tc = (other.v - master.v) / master_a;

		return master.length + master_a * tc * tc / 2;
	}
	else
	{
		return master.length;
	}
}

float calc_BrakeDistance(Master_CarNode master)
{
	return master.v * master.v / (master.a_safe * 2);
}

float calc_MMS(Master_CarNode master, Other_CarNode other)
{
	return calc_BrakeDistance(master) + calc_LineSafeDistance(master, other);
}

