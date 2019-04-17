#ifndef __ONRAMP_MERGING_H
#define __ONRAMP_MERGING_H

#include "onramp_merging.h"
#include <stdint.h>

#define RISK_MODE

#define min(A,B) ((A)<(B) ? (A):(B))

struct carNode
{
	float v;
	float x;
	float amax;
	float amin;
	uint8_t line;
	float length;
};

typedef enum
{
	MERGE = 1,
	NOTMERGE = 2,

}MergeOption_e;

typedef enum
{
	STOP = 0,
	UNIFORMSPEED = 1,
	SPEEDUP = 2,
	SLOWDOWN = 3,
}SpeedMode_e;

float calc_LineSafeDistance(carNode master, carNode other);

#endif