#include "connected_to_rainwater.h"

int afterRain()
{
	// ��������
	SolutionConnectedRainwater s;

	int nums[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	vector<int> v;
	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); ++i)
	{
		v.push_back(nums[i]);
	}

	DWORD start_time = GetTickCount();

	cout << "��ˮ��" << s.trap(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

	return 0;
}

int trap(vector<int>& height)
{
	int waterStorage = 0;
	int front = 0, back;

	for (int i = 1; i < height.size(); ++i)
	{
		if (height[i] >= height[front])
		{


		}

	}




}