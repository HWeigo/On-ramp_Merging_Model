#include "onramp_merging.h"


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

