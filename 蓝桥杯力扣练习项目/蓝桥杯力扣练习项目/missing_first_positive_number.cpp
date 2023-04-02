#include "missing_first_positive_number.h"

int lackTheFirstPositiveNumber()
{
	// ��������
	SolutionMissingFirstPositiveNumber s;
	vector<int> v;

	v = { 3, 4, -1, 1 };

	DWORD start_time = GetTickCount();

	//cout << s.firstMissingPositive(v) << endl;
		cout << s.firstMissingPositiveNew(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

	return 0;
}

// ���������ͨ���±��Ӧ�������Ƿ�Ϊ������ʾ�±��һ�����Ƿ������������ �����������ͬʱ�䵱��ϣ��
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

	// �µĸ�Ч�㷨
	for (int i = 0; i < n; ++i) {
		while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
			swap(nums[nums[i] - 1], nums[i]);
		}
	}


	// �㷨û�п����ظ�Ԫ�ص��������ĿҲû��˵�����԰������ظ�Ԫ��
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