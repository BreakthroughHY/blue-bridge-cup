#include "container_most_water.h"

int containersWaterAreMost()
{
	// 创建对象
	SolutionContainerMostWater s;
	vector<int> v{ 1,8,6,2,5,4,8,3,7 };

	DWORD start_time = GetTickCount();

	cout << s.maxArea(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

int SolutionContainerMostWater::maxArea(vector<int>& height)
{
	int l = 0;
	int r = height.size() - 1;
	int largestVolume = 0; // 容积

	while (l != r)
	{
		largestVolume = max(largestVolume, min(height[l], height[r]) * (r - l));
		if (height[l] < height[r])
			++l;
		else
			--r;
	}

	return largestVolume;
}