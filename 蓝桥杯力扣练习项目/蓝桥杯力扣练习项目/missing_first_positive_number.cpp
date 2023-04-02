#include "missing_first_positive_number.h"

int lackTheFirstPositiveNumber()
{
	// 创建对象
	SolutionMissingFirstPositiveNumber s;
	vector<int> v;

	v = { 3, 4, -1, 1 };

	DWORD start_time = GetTickCount();

	//cout << s.firstMissingPositive(v) << endl;
		cout << s.firstMissingPositiveNew(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

// 传入的容器通过下标对应的数据是否为负数表示下标加一数据是否存在于容器内 （传入的容器同时充当哈希表）
int SolutionMissingFirstPositiveNumber::firstMissingPositive(vector<int>& nums)
{
	int n = nums.size();

	for (int i = 0; i < n; ++i)
		if (nums[i] <= 0)
			nums[i] = n + 1;

	for (int i = 0; i < n; ++i)
	{
		int temp = abs(nums[i]);
		if (temp <= n)
			nums[temp - 1] = -abs(nums[temp - 1]);
	}

	for (int i = 0; i < n; ++i)
		if (nums[i] > 0)
			return i + 1;

	return n + 1;
}

int SolutionMissingFirstPositiveNumber::firstMissingPositiveNew(vector<int>& nums)
{
	int n = nums.size();

	// 新的高效算法
	for (int i = 0; i < n; ++i) {
		while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
			swap(nums[nums[i] - 1], nums[i]);
		}
	}


	// 算法没有考虑重复元素的情况，题目也没有说但测试案例有重复元素
	//for (int i = 0; i < n; ++i)
	//{
	//	if (nums[i] > 0 && nums[i] <= n)
	//		continue;
	//	return i + 1;
	//}

	for (int i = 0; i < n; ++i)
	{
		if (nums[i] != i + 1)
			return i + 1;
	}

	return n + 1;
}