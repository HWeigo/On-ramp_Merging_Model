#ifndef __ONRAMP_MERGING_H
#define __ONRAMP_MERGING_H

#include "includes.h"

#define RISK_MODE     //ע�͹ر�ð��ģʽ
#define DEBUG
const float d_Follow = 10; //��ȫ��������

//������
class Master_CarNode; 
class Other_CarNode;

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
const float x_mergePoint = 1000;
class Master_CarNode
{
public:
	float v_current;
	float x_current = 0;
	float a_safe;
	float v_max = 0;
	float v_min = 0;
	uint8_t lane = 0;
	float length;
	float calc_TimeToMergePoint();
	float calc_BrakeDistance();
	void calc_vRange(Other_CarNode other);

private:
	float a_MAX; //����ǣ�������ṩ�������ٶ�
	float v_MAX =10000; //������������ٶ�
};

/*
* �����Գ����
* \param v ����
* \param x x����������
* \param 
* \param lane ����
* \param length ����
*/
typedef enum
{
	None = 0,
	ArriveBeforeMaster =1,
	ArriveAfterMaster =2,
}Label_e;

class Other_CarNode
{
public:
	float v_current;
	float x_current;
	float v_previous;
	uint8_t lane = 1;
	float length;
	Label_e label = None;
	void labeling(Master_CarNode master);
	float calc_TimeToMergePoint();

private:
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



#endif 