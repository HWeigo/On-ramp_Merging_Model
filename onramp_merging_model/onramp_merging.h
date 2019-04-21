#ifndef __ONRAMP_MERGING_H
#define __ONRAMP_MERGING_H

#include "includes.h"

#define RISK_MODE

using namespace std;

struct Master_CarNode
{
	float v;
	float x;
	float last_v;
	float amax;
	float amin;
	uint8_t line;
	float length;
};

struct Other_CarNode
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
	PREPMERGE = 3, 

}MergeState_e;

typedef enum
{
	STOP = 0,
	UNIFORMSPEED = 1,
	SPEEDUP = 2,
	SLOWDOWN = 3,
}SpeedMode_e;


void MergeStateFSM(void);
void checkMergingCondition(Master_CarNode master, Other_CarNode other);

void adjustSpeed_KL();
void adjustSpeed_PREP();

#endif 