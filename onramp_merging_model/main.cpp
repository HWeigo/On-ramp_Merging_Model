#include "includes.h"

int main()
{
	Master_CarNode g_master;
	Other_CarNode g_other;

	g_master.v_current = 60;
	g_master.x_current = 0;
	g_master.length = 2;

	g_other.v_current = 70;
	g_other.x_current = -200;
	g_other.length = 2;

	g_other.labeling(g_master);

	g_master.calc_vRange(g_other);
#ifdef DEBUG
	cout << "Merge Point's coordinate: " << x_mergePoint << '\n';

	cout << "Master's velocity: " << g_master.v_current << '\n';
	cout << "Master's coordinate: " << g_master.x_current << '\n';
	cout << "Other's velocity: " << g_other.v_current << '\n';
	cout << "Other's coordinate: " << g_other.x_current << '\n';

	cout << "Other' label: "<< g_other.label << '\n';

	cout << "v_max: " << g_master.v_max << '\n';
	cout << "v_min: " << g_master.v_min;

	cout << endl;
#endif // DEBUG


	system("pause");

	return 0;
}