#include "maximum.h"

int maximumNumber()
{
	// ��������
	SolutionMaximum s;
	vector<int> v = { 3,30,34,5,9 };

	DWORD start_time = GetTickCount();

	cout << s.largestNumber(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

	return 0;
}

string SolutionMaximum::largestNumber(vector<int>& nums)
{



	return "";
}
