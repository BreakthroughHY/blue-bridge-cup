#include "jump_game.h"

int jumpingGames()
{
	// 创建对象
	SolutionJumpGame s;
	int nums[] = { 3,2,1,0,4 };

	vector<int> v;

	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); ++i)
	{
		v.push_back(nums[i]);
	}

	DWORD start_time = GetTickCount();

	cout << s.canJump(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间


	return 0;
}

bool SolutionJumpGame::canJump(vector<int>& nums)
{
	int len = nums.size();

	vector<bool> dp(len, false);

	dp[len - 1] = true; // 动态规划初始化

	for (int i = len - 2; i >= 0; --i)
	{
		for (int j = 1; j <= nums[i]; ++j)
		{
			if (dp[i + j])
			{
				dp[i] = true;
				break;
			}
		}
	}

	return dp[0];
}