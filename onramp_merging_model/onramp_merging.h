#ifndef __ONRAMP_MERGING_H
#define __ONRAMP_MERGING_H

#include "onramp_merging.h"
#include <stdint.h>

#define RISK_MODE


struct carNode
{
	float v;
	float x;
	float last_v;
	float amax;
	float amin;
	uint8_t line;
	float length;
};

typedef enum
{
	MERGE = 1,
	KEEPLANE = 2,

}MergeState_e;

typedef enum
{
	STOP = 0,
	UNIFORMSPEED = 1,
	SPEEDUP = 2,
	SLOWDOWN = 3,
}SpeedMode_e;

void MergeStateFSM(void);
float calc_LineSafeDistance(carNode master, carNode other);
float calc_BrakeDistance(carNode master);
float calc_MMS(carNode master, carNode other);


#endif