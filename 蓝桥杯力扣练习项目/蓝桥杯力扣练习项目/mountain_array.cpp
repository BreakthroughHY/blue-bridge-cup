#include "mountain_array.h"

int mountainArray()
{
	// ������
	SolutionMountainArray s;
	//int nums[] = { 0,1,2,3,4,5,4,3,2,1,0 }; // 11
	//int nums[] = { 2, 1, 4, 7, 3, 2, 5 }; // 5
	//int nums[1] = { 0 }; // 0
	int nums[] = { 40,51,29,19,50,25 }; // 4
	// ��������
	vector<int> v;
	for (int i = 0; i < sizeof(nums) / sizeof(int); i++)
	{
		v.push_back(nums[i]);
	}

	DWORD start_time = GetTickCount();

	cout << "�Ϊ��" << s.longestMountain(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��


	return 0;
}

int SolutionMountainArray::longestMountain(vector<int>& arr)
{
	int max = 0;
	int leftFootMountain = -1;
	bool YFootMountain = false; // �Ƿ�����ɽ��
	// ����ɽ��
	for (int i = 0; i < arr.size(); ++i)
	{
		if ((!YFootMountain && i != (arr.size() - 1)) && arr[i] < arr[i + 1])
		{
			leftFootMountain = i; // ���ܵ���ɽ�ŷ��ϱ�־
			YFootMountain = true; // �Ѿ����ɽ��
		}
		else if ((YFootMountain && i != (arr.size() - 1)) && arr[i] == arr[i + 1])
		{
			YFootMountain = false; // ɾ��ɽ�ű��
		}
		else if ((YFootMountain && i != (arr.size() - 1)) && arr[i] > arr[i + 1])
		{
			if (i + 2 == arr.size() || arr[i + 1] <= arr[i + 2])
			{
				max = i + 1 - leftFootMountain + 1 > max ? i + 1 - leftFootMountain + 1 : max; // �ж���ɽ�Ƿ����
				YFootMountain = false; // ɾ��ɽ�ű��
			}
		}
	}

	return max;
}