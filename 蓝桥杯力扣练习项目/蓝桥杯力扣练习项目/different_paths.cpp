#include "different_paths.h"

int differentPaths()
{
	// 创建对象
	SolutionDifferentPaths s;

	DWORD start_time = GetTickCount();

	cout << s.uniquePaths(3,7) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

// 动态规划空间复杂度0(n)
int SolutionDifferentPaths::uniquePaths(int m, int n)
{
	vector<int> dp(m, 1);

	for (int i = 1; i < n; ++i)
	{
		//dp[0] = 1;
		for (int j = 1; j < m; ++j)
		{
			dp[j] = dp[j - 1] + dp[j];
		}
	}
	return dp[m - 1];
}