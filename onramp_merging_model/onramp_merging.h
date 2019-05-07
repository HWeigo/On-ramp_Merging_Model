#ifndef __ONRAMP_MERGING_H
#define __ONRAMP_MERGING_H

#include "includes.h"

#define RISK_MODE     //ע�͹ر�ð��ģʽ
#define DEBUG

/*********************************/

const float d_Follow = 10; //��ȫ��������
const float v_speedLimit = 90; //��·����
const float x_mergePoint = 1000; //����������

/*********************************/


//������
class Master_CarNode; 
class Other_CarNode;

/*
* �����������
* \param v_current ��ǰ����
* \param v_target Ŀ�공��
* \param x_current x����������
* \param a_safe ��ȫ���ٶ�
* \param v_max �����ٶ���������ٶ�
* \param v_min �����ٶ�������С�ٶ�
* \param lane ���� 
* \param length ����
* \param a_MAX ����ǣ�������ṩ�������ٶ�
* \param v_MAX ������������ٶ�

* \func calc_TimeToMergePoint ���ص�������ʱ��
* \func calc_BrakeDistance ����ɲ������
* \func calc_vRange ��������ٶ���
*/

class Master_CarNode
{
public:
	float v_current = 0;
	float v_target = 0;
	float x_current = 0;
	float a_safe = 7; //���궨 ɲ�����ٶ�
	float v_max = v_speedLimit;
	float v_min = 0;
	uint8_t lane = 0;  //δʹ��
	float length;
	float calc_TimeToMergePoint();
	float calc_BrakeDistance();
	void calc_vRange(Other_CarNode &other);
	//void adjustSpeed(Other_CarNode other);

private:
	float a_MAX; //����ǣ�������ṩ�������ٶ�
	float v_MAX = v_speedLimit; //������������ٶ�
};

typedef enum
{
	None = 0,
	ArriveBeforeMaster =1,
	ArriveAfterMaster =2,
}Label_e;

/*
* �����Գ����
* \param v_current ����
* \param v_previous ��һʱ�̳���
* \param x_current x����������
* \param lane ����
* \param length ����
* \param label �Գ���ǩ
* ��None���ޣ�ArriveBeforeMaster���������ȵ������㣬ArriveAfterMaster���������󵽻����㡿
*
* \func labeling ���ǩ
* \func calc_TimeToMergePoint() ���ص��������ʱ��
*/
class Other_CarNode
{
public:
	float v_current = -1;
	float v_previous = 0; //δʹ��
	float x_current;
	uint8_t lane = 1; //δʹ��
	float length = 2;
	Label_e label = None;
	void labeling(Master_CarNode master);
	float calc_TimeToMergePoint();
};

//������Сֵ
template <class T>
T MIN(T n1, T n2);
template <class T>
T MIN(T n1, T n2, T n3);

//�������ֵ
template <class T>
T MAX(T n1, T n2);
template <class T>
T MAX(T n1, T n2, T n3);

//״̬��ö�ٶ���
//typedef enum
//{
//	MERGE = 1,
//	KEEPLANE = 2,
//	PREPMERGE = 3, 
//
//}MergeState_e;
//
//typedef enum
//{
//	STOP = 0,
//	UNIFORMSPEED = 1,
//	SPEEDUP = 2,
//	SLOWDOWN = 3,
//}SpeedMode_e;

#endif 

