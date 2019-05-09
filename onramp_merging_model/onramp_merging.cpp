#include "includes.h"

//#define MIN(A,B,C) ( (A)<(B)? ( (A)<(C)?(A):(C)) : ((B)<(C)?(B):(C)) )
//#define MAX(A,B,C) ( (A)>(B)? ( (A)>(C)?(A):(C)) : ((B)>(C)?(B):(C)) )


void Other_CarNode::labeling(Master_CarNode master)
{
	if (master.calc_TimeToMergePoint() < calc_TimeToMergePoint())
	{
		label = ArriveAfterMaster;
	}
	else
	{
		label = ArriveBeforeMaster;
	}
}

//注，未添加异常处理
float Other_CarNode::calc_TimeToMergePoint()
{
	return (x_mergePoint - x_current) / v_current;
}

int labeled = 0; 
void Other_CarNode::calc_vRangeForMaster(Master_CarNode master)
{
	if (labeled == 0)
	{
		labeling(master);
	}

	switch (label)
	{
	case ArriveBeforeMaster:
	{
		float x_tmp;   //旁车到达MergePoint时，主车安全位置
		float delta_x; //主车与MergePoint距离
		float v_lastmax;

		delta_x = x_mergePoint - master.x_current;
		x_tmp = delta_x - calc_SafeDistance(master, *this);
		v_MasterMax = x_tmp / calc_TimeToMergePoint();
	}break;
	case ArriveAfterMaster:
	{
		float t_tmp; //t_tmp：主车以最小速度到达MergePoint的时间
		float delta_x; //主车与MergePoint距离
		float v_lastmin;

		delta_x = x_mergePoint - master.x_current;
		t_tmp = calc_TimeToMergePoint() - calc_SafeDistance(master, *this) / v_current;
		v_MasterMin = delta_x / t_tmp;
	}break;
	default:
		break;
	}
}

float Master_CarNode::calc_TimeToMergePoint()
{
	return (x_mergePoint - x_current)/v_current;
}

float Master_CarNode::calc_BrakeDistance()
{
	return v_current * v_current / (a_safe * 2);
}

void Master_CarNode::calc_vRange(Other_CarNode *other)
{
	int i = 0;
	v_max = v_speedLimit;
	v_min = 0.0f;
	while (other[i].v_current != -1)
	{
		other[i].calc_vRangeForMaster(*this);
		switch (other[i].label)
		{
		case ArriveBeforeMaster:
		{
			v_max = MIN(v_max, other[i].v_MasterMax, v_MAX);
		}break;
		case ArriveAfterMaster:
		{
			//if (labeled == 0)
			//{
				v_min = MAX(v_min, other[i].v_MasterMin, 0.0f);
			//}
			//else
			//{
			//	v_min = other[i].v_MasterMin;
			//}
		}break;
		default:
			break;
		}
		++i;
	}
}

void Master_CarNode::adjustSpeed(Other_CarNode *other)
{
	if (v_max > v_min)
	{
		v_target = v_max;
	}
	else
	{
		//找出other.label == ArriveAfterMaster中v_MasterMin的最大值
		//将该other标记为ArriveBeforeMaster，计算v_MasterMax
		//导入calc_vRange重新得到新的v_max,v_min
		//v_max>v_min跳出 否则循环
		while (v_max < v_min)
		{
			int i = 0;
			float maxMinSpeed = 0;
			int maxElement = 0;
			while (other[i].label != None)
			{

				if (other[i].label == ArriveAfterMaster)
				{
#ifdef DEBUG
					cout << "Other " << i << " arrive after master" << '\n';
					cout << "v_MasterMin: " << other[i].v_MasterMin << '\n' << endl;
#endif // DEBUG
					maxElement = other[i].v_MasterMin > maxMinSpeed ? i : maxElement;
					maxMinSpeed = other[i].v_MasterMin > maxMinSpeed ? other[i].v_MasterMin : maxMinSpeed;
				}
				++i;
			}
#ifdef DEBUG
			cout << "Most dangerous car's index: " << maxElement << endl;
			cout << "Max v_MasterMin: " << other[maxElement].v_MasterMin << '\n' << endl;
#endif // DEBUG

			other[maxElement].label = ArriveBeforeMaster; 
			other[maxElement].v_MasterMin = -1;

			labeled = 1; //关闭函数中打标签
			calc_vRange(other);
			labeled = 0; //重新开启打标签
			//v_current = v_max;

#ifdef DEBUG
			cout << "After adjust v_max: " << (*this).v_max << '\n';
			cout << "After adjust v_min: " << (*this).v_min << '\n';
			cout << "--------------------" << endl;
#endif // DEBUG

		}
		v_target = v_max;
	}
}


template<class T>
T MIN(T n1, T n2)
{
	return n1 < n2 ? n1 : n2;
}
template<class T>
T MIN(T n1, T n2, T n3)
{
	return n1 < n2 ? (n1 < n3 ? n1 : n3) : (n2 < n3 ? n2 : n3);
}

template<class T>
T MAX(T n1, T n2)
{
	return n1 > n2 ? n1 : n2;
}
template<class T>
T MAX(T n1, T n2, T n3)
{
	return n1 > n2 ? (n1 > n3 ? n1 : n3) : (n2 > n3 ? n2 : n3);
}

