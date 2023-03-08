#include "maximum_subarray_and.h"

int architecturalTheArray()
{
	// ��������
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

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��
	return 0;
}

// �ݹ�ⷨ �ж����ֺ�С��0�����Ҫ�����Ĳ���
int SolutionMaximumSubarrayAnd::maxSubArray(vector<int>& nums)
{
	int front = 0, back = 0; // ��¼

	for (int i = 0; i < nums.size(); ++i) // ʹfrontָ���һ������0������f
	{
		if (nums[i] > 0)
		{
			front = i;
			break;
		}
	}

	for (int i = nums.size() - 1; i >= 0; --i) // ʹbackָ�����һ������0������
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

// ���������С����
int positiveNegativeIntervalLessThanZero(vector<int>& nums, int front, int back)
{
	int plusSignAnd = 0;
	int minusSignAnd = 0;

	for (; front <= back; ++front) // ���ֲ������
	{
		if (nums[front] < 0) // ������������������������
			break;
		else
			plusSignAnd += nums[front];
	}
	
	for (; front <= back; ++front) // �������
	{
		if (nums[front] >= 0) // ���ηǸ������������Ǹ�������
			break;
		else
			minusSignAnd += nums[front];
	}

	if (front == back + 1)
		return plusSignAnd;

	if (minusSignAnd + plusSignAnd < 0) // ʹ����Ա������������еĸ��������
	{
		return max(positiveNegativeIntervalLessThanZero(nums, front, back), plusSignAnd);
	}
	else // ��������
	{
		return positiveNegativeToRangeIsNotNegative(nums, front, back, plusSignAnd + minusSignAnd);
	}
}

// �������
int positiveNegativeToRangeIsNotNegative(vector<int>& nums, int front, int back, int value)
{
	int plusSignAnd = 0;
	int minusSignAnd = 0;

	for (; front <= back; ++front) // ���ֲ������
	{
		if (nums[front] < 0) // ������������������������
			break;
		else
			plusSignAnd += nums[front];
	}

	for (; front <= back; ++front) // �������
	{
		if (nums[front] >= 0) // ���ηǸ������������Ǹ�������
			break;
		else
			minusSignAnd += nums[front];
	}

	if (front == back + 1)
		return plusSignAnd + value;

	if (minusSignAnd + plusSignAnd < 0) // ʹ����Ա������������еĸ��������
	{
		return max(positiveNegativeIntervalLessThanZero(nums, front, back), value + plusSignAnd);
	}
	else // ��������
	{
		return positiveNegativeToRangeIsNotNegative(nums, front, back, value + plusSignAnd + minusSignAnd);
	}
}

// ��̬�滮������
int dynamicProgrammingMethodViolence(vector<int>& nums)
{
	int len = nums.size();
	vector<int> dp(len);

	dp[0] = nums[0]; // ��̬�滮��ʼ��

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