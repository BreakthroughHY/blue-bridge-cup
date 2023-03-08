#include "minimum_path_and.h"

int minimumPathAnd()
{
	// 创建对象
	SolutionMinimumPathandAnd s;

	vector<vector<int>> v{ {1, 3, 1},
										   {1, 5, 1},
									       {4, 2, 1} };


	DWORD start_time = GetTickCount();

	cout << s.minPathSum(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

// 移动方向有限制的只能向下和向右，这样问题反倒简单了
// 动态规划，空间复杂度n,时间复杂度n*m
int SolutionMinimumPathandAnd::minPathSum(vector<vector<int>>& grid)
{
	int m = grid.size(); // 记录行数
	int n = grid[0].size(); // 记录列数

	vector<int> dp(n, 0);

	for (int i = 0; i < n; ++i) // 初始化dp数组
	{
		if (!i)
			dp[i] = grid[0][i];
		else
			dp[i] = dp[i - 1] + grid[0][i];
	}

	for (int i = 1; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!j)
				dp[j] = dp[j] + grid[i][j];
			else
				dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
		}
	}

	return dp[n - 1];
}