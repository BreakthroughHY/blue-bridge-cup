#include "gas_station.h"

int gasStation()
{
	// 创建对象
	SolutionGasStation s;
	vector<int> gas = { 2,3,4 };
	vector<int> cost = { 3,4,3 };

	DWORD start_time = GetTickCount();

	cout << s.canCompleteCircuit(gas, cost) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

int SolutionGasStation::canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
	int totalAmountOil = 0, oilTank = 0;

	int gasStationNumber = gas.size();

	int ans = -1;

	for (int i = 0; i < gasStationNumber; ++i)
	{
		if (ans == -1 && gas[i] - cost[i] >= 0)
		{
			ans = i;
			oilTank += gas[i] - cost[i];
		}
		else if (ans != -1)
		{
			oilTank += gas[i] - cost[i];
		}
		totalAmountOil += gas[i] - cost[i];
		if (oilTank < 0)
		{
			ans = -1;
			oilTank = 0;
		}
	}

	if (totalAmountOil >= 0 && ans != -1)
		return ans;
	else
		return -1;
}