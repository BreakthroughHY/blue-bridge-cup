#include "connected_to_rainwater.h"

int afterRain()
{
	// 创建对象
	SolutionConnectedRainwater s;

	//int nums[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	//int nums[] = { 4, 2, 3};
	int nums[] = { 5, 4, 1, 2 };
	vector<int> v;
	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); ++i)
	{
		v.push_back(nums[i]);
	}

	DWORD start_time = GetTickCount();

	cout << "存水：" << s.trap(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

int SolutionConnectedRainwater::trap(vector<int>& height)
{
	int waterStorage = 0;
	int front = 0, back;

	for (int i = 1; i < height.size(); ++i)
	{
		if (height[i] >= height[front])
		{
			if (front + 1 != i)
			{
				back = i; // 记录本次可能右边界
				waterStorage += (min(height[front], height[i]) * (i - front - 1) - arraySumSpecifiedInterval(height, front + 1, i));
				front = i;
			}
			else
			{
				front = i;
			}
		}

		if (i == height.size() - 1 && front != i)
		{
			i = front;
			--height[front];
		}
			
	}
	return waterStorage;
}

// 对数组指定区间求和 (前闭区间，后开区间)
int arraySumSpecifiedInterval(vector<int>& v, int front, int back)
{
	int sum = 0;
	for (; front < back; ++front)
		sum += v[front];
	return sum;
}