#ifndef __ONRAMP_MERGING_H
#define __ONRAMP_MERGING_H

#include "includes.h"

#define RISK_MODE     //ע�͹ر�ð��ģʽ


/*
* �����������
* \param v ����
* \param x x����������
* \param a_max ����������ٶ�
* \param a_safe ��ȫ���ٶ�
* \param lane ����
* \param length ����
* \param x_mergePoint Ԥ�ƻ�����
*/
struct Master_CarNode
{
	float v;
	float x;
	float a_max;
	float a_safe;
	uint8_t lane = 0;
	float length;
	float x_mergePoint;
};

/*
* �����Գ����
* \param v ����
* \param x x����������
* \param 
* \param lane ����
* \param length ����
*/
struct Other_CarNode
{
	float v;
	float x;
	float previous_v;
	uint8_t lane = 1;
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
void checkMergingCondition_KL(const Master_CarNode master, const Other_CarNode other);

void adjustSpeed_KL(Master_CarNode master, Other_CarNode other);
void adjustSpeed_PREP(Master_CarNode master, Other_CarNode other);

#endif 