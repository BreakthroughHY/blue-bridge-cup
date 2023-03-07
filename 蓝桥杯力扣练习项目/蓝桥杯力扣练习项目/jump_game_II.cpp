#include "jump_game_II.h"

int jumpingGamesII()
{
	// 创建对象
	SolutionJumpGameII s;
	//int nums[] = { 2,3,1,1,4 };
	int nums[2] = {2, 5};

	vector<int> v;

	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); ++i)
	{
		v.push_back(nums[i]);
	}

	DWORD start_time = GetTickCount();

	cout << s.jump(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

// 贪心算法简化问题，从后方以此判断是否每一个位置到最后点的跳跃次数，为减少不必要的二次计算，
// 将每一个点的跳跃次数保存到数组中(动态规划)
int SolutionJumpGameII::jump(vector<int>& nums)
{
	int len = nums.size();
	if (len == 1)
		return 0;
	vector<int> dp(len, INT_MAX); // 默认每个带你到达目标点的跳动次数为无穷大，不可能到达


	for (int i = len - 2; i >= 0; --i)
	{
		if (nums[i] >= len - 1 - i) // 本点的大小支持一次性到大目标位置， 所有所有已经到达本点的都可以只用跳一次到达目标
		{
			dp[i] = 1;
		}
		else // 本点无法一次性到达目标点
		{
			int minLen = INT_MAX; // 记录本点能到达的步数最少点
			for (int j = 0; j < nums[i]; ++j)
			{
				if (dp[i + j + 1] != INT_MAX)
				{
					minLen = min(minLen, dp[i + j + 1]);
				}
			}
			if (minLen != INT_MAX)
			{
				dp[i] = minLen + 1;
			}
		}
	}

	return dp[0];
}
