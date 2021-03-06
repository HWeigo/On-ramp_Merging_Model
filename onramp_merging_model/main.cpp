#include "includes.h"

int main()
{
	Master_CarNode g_master;
	Other_CarNode g_other[10];

	g_master.v_current = 60;
	g_master.x_current = 0;
	g_master.length = 2;

	g_other[0].v_current = 70;
	g_other[0].x_current = -200;
	g_other[0].length = 2;

	g_other[1].v_current = 80;
	g_other[1].x_current = 00;
	g_other[1].length = 2.5;

	g_other[2].v_current = 75;
	g_other[2].x_current = -300;
	g_other[2].length = 2;

	g_other[3].v_current = 60;
	g_other[3].x_current = -300;
	g_other[3].length = 2;

	g_master.calc_vRange(g_other);

#ifdef DEBUG

	cout << "Merge Point's coordinate: " << x_mergePoint << '\n' << endl;

	cout << "Master's current velocity: " << g_master.v_current << '\n';
	cout << "Master's current coordinate: " << g_master.x_current << '\n' << endl;

	for (int i = 0; g_other[i].label != None; ++i)
	{
		cout << "Other[" << i << "] \n";
		cout << "Other's velocity: " << g_other[i].v_current << '\n';
		cout << "Other's coordinate: " << g_other[i].x_current << '\n' ;
		cout << "Other' label: " << g_other[i].label  << endl;	
		if (g_other[i].label == ArriveAfterMaster)
		{
			cout << "Other' label: ArriveAfterMaster \n";
			cout << "v_MasterMin: " << g_other[i].v_MasterMin << '\n' << endl;
		}
		else
		{
			cout << "Other' label: ArriveBeforeMaster \n";
			cout << "v_MasterMax: " << g_other[i].v_MasterMax << '\n' << endl;
		}
	}

	cout << "v_max: " << g_master.v_max << '\n';
	cout << "v_min: " << g_master.v_min << '\n';

	cout << "---------Adjusting Speed---------" << '\n';
	cout << endl;

#endif // DEBUG

	g_master.adjustSpeed(g_other);

#ifdef DEBUG
	cout << "v_target: " << g_master.v_target << endl;

#endif // DEBUG


	system("pause");

	return 0;
}

void adjustSpeed(Master_CarNode master, Other_CarNode other)
{
	if (master.v_max > master.v_min)
	{
		master.v_target = master.v_max;
	}
	else
	{

	}
}