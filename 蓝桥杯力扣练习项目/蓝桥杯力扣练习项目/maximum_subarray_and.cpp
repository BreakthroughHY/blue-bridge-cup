#include "maximum_subarray_and.h"

int architecturalTheArray()
{
	// 创建对象
	SolutionMaximumSubarrayAnd s;
	int nums[] = { 2,3,1,1,4 };

	vector<int> v;

	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); ++i)
	{
		v.push_back(nums[i]);
	}

	DWORD start_time = GetTickCount();

	cout << s.maxSubArray(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间
	return 0;
}

// 递归解法 判定部分和小于0情况下要保留的部分
int SolutionMaximumSubarrayAnd::maxSubArray(vector<int>& nums)
{
	int front, back; // 记录
	
	for (int i = 0; i < nums.size(); ++i) // 使front指向第一个大于0的数字
	{
		if (nums[i] > 0)
		{
			break;
			front = i;
		}
	}

	for (int i = nums.size() - 1; i >= 0; --i) // 使back指向最后一个大于0的数字
	{
		if (nums[i] > 0)
		{
			break;
			back = i;
		}
	}




	return 0;
}