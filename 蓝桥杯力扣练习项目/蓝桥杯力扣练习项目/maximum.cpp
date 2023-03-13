#include "maximum.h"

int maximumNumber()
{
	// 创建对象
	SolutionMaximum s;
	vector<int> v = { 3,30,34,5,9 };

	DWORD start_time = GetTickCount();

	cout << s.largestNumber(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

string SolutionMaximum::largestNumber(vector<int>& nums)
{



	return "";
}
