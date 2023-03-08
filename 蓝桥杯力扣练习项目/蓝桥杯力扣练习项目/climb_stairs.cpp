#include "climb_stairs.h"

int climbStairs()
{
	// 创建对象
	SolutionClimbStairs s;

	DWORD start_time = GetTickCount();

	//cout << s.climbStairs(1) << endl;
	cout << s.climbStairsNew(4) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

// 动态规划空间复杂度可以压到小于n,但应该会影响效率
int SolutionClimbStairs::climbStairs(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;

	vector<int> dp(n);

	dp[n - 1] = 1;
	dp[n - 2] = 2;

	for (int i = n - 3; i >= 0; --i)
	{
		dp[i] = dp[i + 1] + dp[i + 2];
	}
	
	return dp[0];
}

// 优化空间占用
int SolutionClimbStairs::climbStairsNew(int n)
{
	if (n == 1)
		return 1;

	vector<int> dp(3);

	dp[2] = 1;
	dp[1] = 2;

	for (int i = n - 3; i >= 0; --i)
	{
		dp[0] = dp[1] + dp[2];
		dp[2] = dp[1];
		dp[1] = dp[0];
	}

	return dp[0];
}