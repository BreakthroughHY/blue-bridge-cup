#include "mountain_array.h"

int mountainArray()
{
	// 创建类
	SolutionMountainArray s;
	//int nums[] = { 0,1,2,3,4,5,4,3,2,1,0 }; // 11
	//int nums[] = { 2, 1, 4, 7, 3, 2, 5 }; // 5
	//int nums[1] = { 0 }; // 0
	int nums[] = { 40,51,29,19,50,25 }; // 4
	// 创建数组
	vector<int> v;
	for (int i = 0; i < sizeof(nums) / sizeof(int); i++)
	{
		v.push_back(nums[i]);
	}

	DWORD start_time = GetTickCount();

	cout << "最长为：" << s.longestMountain(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间


	return 0;
}

int SolutionMountainArray::longestMountain(vector<int>& arr)
{
	int max = 0;
	int leftFootMountain = -1;
	bool YFootMountain = false; // 是否标记左山脚
	// 找左山脚
	for (int i = 0; i < arr.size(); ++i)
	{
		if ((!YFootMountain && i != (arr.size() - 1)) && arr[i] < arr[i + 1])
		{
			leftFootMountain = i; // 可能的左山脚放上标志
			YFootMountain = true; // 已经标记山脚
		}
		else if ((YFootMountain && i != (arr.size() - 1)) && arr[i] == arr[i + 1])
		{
			YFootMountain = false; // 删除山脚标记
		}
		else if ((YFootMountain && i != (arr.size() - 1)) && arr[i] > arr[i + 1])
		{
			if (i + 2 == arr.size() || arr[i + 1] <= arr[i + 2])
			{
				max = i + 1 - leftFootMountain + 1 > max ? i + 1 - leftFootMountain + 1 : max; // 判断新山是否更大
				YFootMountain = false; // 删除山脚标记
			}
		}
	}

	return max;
}