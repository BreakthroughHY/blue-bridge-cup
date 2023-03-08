#include "maximum_subarray_and.h"

int architecturalTheArray()
{
	// 创建对象
	SolutionMaximumSubarrayAnd s;
	//int nums[] = { -2,1,-3,4,-1,2,1,-5,4 };
	//int nums[] = { 5, 4, -1, 7, 8 };
	int nums[] = { 1,2,-1,-2,2,1,-2,1 };

	vector<int> v;

	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); ++i)
	{
		v.push_back(nums[i]);
	}

	DWORD start_time = GetTickCount();

	//cout << s.maxSubArray(v) << endl;
	cout << dynamicProgrammingMethodViolence(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间
	return 0;
}

// 递归解法 判定部分和小于0情况下要保留的部分
int SolutionMaximumSubarrayAnd::maxSubArray(vector<int>& nums)
{
	int front = 0, back = 0; // 记录

	for (int i = 0; i < nums.size(); ++i) // 使front指向第一个大于0的数字f
	{
		if (nums[i] > 0)
		{
			front = i;
			break;
		}
	}

	for (int i = nums.size() - 1; i >= 0; --i) // 使back指向最后一个大于0的数字
	{
		if (nums[i] > 0)
		{
			back = i;
			break;
		}
	}

	if (front == back)
	{
		if (nums[front] < 0)
		{
			int num = INT_MIN;
			for (int i = 0; i < nums.size(); ++i)
			{
				if (nums[i] > num)
					num = nums[i];
			}
			return num;
		}
		return nums[front];
	}


	return 	positiveNegativeIntervalLessThanZero(nums, front, back);
}

// 正负区间和小于零
int positiveNegativeIntervalLessThanZero(vector<int>& nums, int front, int back)
{
	int plusSignAnd = 0;
	int minusSignAnd = 0;

	for (; front <= back; ++front) // 正局部区间和
	{
		if (nums[front] < 0) // 本次正数区间碰到负数结束
			break;
		else
			plusSignAnd += nums[front];
	}
	
	for (; front <= back; ++front) // 负区间和
	{
		if (nums[front] >= 0) // 本次非负数区间碰到非负数结束
			break;
		else
			minusSignAnd += nums[front];
	}

	if (front == back + 1)
		return plusSignAnd;

	if (minusSignAnd + plusSignAnd < 0) // 使程序对本次正负区间中的负区间厌恶
	{
		return max(positiveNegativeIntervalLessThanZero(nums, front, back), plusSignAnd);
	}
	else // 不厌恶情况
	{
		return positiveNegativeToRangeIsNotNegative(nums, front, back, plusSignAnd + minusSignAnd);
	}
}

// 不厌恶函数
int positiveNegativeToRangeIsNotNegative(vector<int>& nums, int front, int back, int value)
{
	int plusSignAnd = 0;
	int minusSignAnd = 0;

	for (; front <= back; ++front) // 正局部区间和
	{
		if (nums[front] < 0) // 本次正数区间碰到负数结束
			break;
		else
			plusSignAnd += nums[front];
	}

	for (; front <= back; ++front) // 负区间和
	{
		if (nums[front] >= 0) // 本次非负数区间碰到非负数结束
			break;
		else
			minusSignAnd += nums[front];
	}

	if (front == back + 1)
		return plusSignAnd + value;

	if (minusSignAnd + plusSignAnd < 0) // 使程序对本次正负区间中的负区间厌恶
	{
		return max(positiveNegativeIntervalLessThanZero(nums, front, back), value + plusSignAnd);
	}
	else // 不厌恶情况
	{
		return positiveNegativeToRangeIsNotNegative(nums, front, back, value + plusSignAnd + minusSignAnd);
	}
}

// 动态规划暴力法
int dynamicProgrammingMethodViolence(vector<int>& nums)
{
	int len = nums.size();
	vector<int> dp(len);

	dp[0] = nums[0]; // 动态规划初始化

	for (int i = 1; i < len; ++i)
	{
		if (dp[i - 1] <= 0)
		{
			dp[i] = nums[i];
		}
		else
		{
			dp[i] = dp[i - 1] + nums[i];
		}
	}

	int max_ = INT_MIN;
	for (int i = 0; i < len; ++i)
	{
		max_ = max(max_, dp[i]);
	}

	return max_;
}