#include "maximum_subarray_and.h"

int architecturalTheArray()
{
	// ��������
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

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��
	return 0;
}

// �ݹ�ⷨ �ж����ֺ�С��0�����Ҫ�����Ĳ���
int SolutionMaximumSubarrayAnd::maxSubArray(vector<int>& nums)
{
	int front, back; // ��¼
	
	for (int i = 0; i < nums.size(); ++i) // ʹfrontָ���һ������0������
	{
		if (nums[i] > 0)
		{
			break;
			front = i;
		}
	}

	for (int i = nums.size() - 1; i >= 0; --i) // ʹbackָ�����һ������0������
	{
		if (nums[i] > 0)
		{
			break;
			back = i;
		}
	}




	return 0;
}