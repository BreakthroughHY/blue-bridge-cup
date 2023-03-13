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

// c++���6�����ǿ
string SolutionMaximum::largestNumber(vector<int>& nums)
{
	sort(nums.begin(), nums.end(), [](const int& x, const int& y) {
		long sx = 10, sy = 10;
		while (sx <= x)
			sx *= 10;
		while (sy <= y)
			sy *= 10;
		return sy * x + y > sx * y + x;
		});

	if (nums[0] == 0)
		return "0";

	string ret;
	for (int x : nums)
		ret += to_string(x);

	return ret;
}
