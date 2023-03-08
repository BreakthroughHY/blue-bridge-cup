#include "different_paths_II.h"

int differentPathsII()
{
	// 创建对象
	SolutionDifferentPathII s;
	//vector<vector<int>> v{ {0,0,0},
	//									   {0,1,0},
	//									   {0,0,0} };

	vector<vector<int>> v{ {0,0},
											{1,1},
									   {0,0} };

	//vector<vector<int>> v{ {1,0}};

	DWORD start_time = GetTickCount();

	cout << s.uniquePathsWithObstacles(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

// 动态规划空间复杂度O(m+n)  时间复杂度m*n
int SolutionDifferentPathII::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
	int m = obstacleGrid.size(); // 记录有多少行
	int n = obstacleGrid[0].size(); // 记录有多少列

	vector<int> dpL(n, 0); // 行dp数组
	vector<int> dpC(m, 0); // 列dp数组

	if (n == 1) // 处理刁钻情况
	{
		if (n == m && 1 == m)
		{
			if (obstacleGrid[0][0])
				return 0;
			return 1;
		}
		else
		{
			for (int i = 0; i < m; ++i)
			{
				if (obstacleGrid[i][0])
					return 0;
			}
			return 1;
		}
	}

	if (obstacleGrid[0][0])
		return 0;
	dpL[0] = dpC[0] = 1; // 动态规划初始化

	for (int i = 1; i < n; ++i) // 初始化行dp数组
	{
		if (obstacleGrid[0][i])
			break; // 首行遇到障碍退出循环
		dpL[i] = 1; // 没遇到障碍到本位置的路径加一
	}

	for (int i = 1; i < m; ++i) // 初始化列dp数组
	{
		if (obstacleGrid[i][0])
			break; // 首列遇到障碍退出循环
		dpC[i] = 1; // 没遇到障碍到本位置的路径加一
	}

	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < m; ++j)
		{
			if (obstacleGrid[i][j]) // 本位置存在障碍
			{
				dpL[j] = 0; // 障碍点不可能到达路径数量为0
			}
			else
			{
				if (!(j - 1))
				{
					dpL[j] = dpL[j] + dpC[i];
				}
				else
				{
					dpL[j] += dpL[j - 1];
				}
			}
		}
	}

	return dpL[n - 1];
}