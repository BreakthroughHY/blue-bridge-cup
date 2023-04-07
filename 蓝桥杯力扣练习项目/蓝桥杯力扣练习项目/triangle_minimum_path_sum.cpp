#include "triangle_minimum_path_sum.h"

int triangleMinimumPath()
{
	// 创建对象
	SolutionTriangleMinimumPathSum s;
	//vector<vector<int>> v{ {2},{3, 4},{6, 5, 7}, {4,1,8,3} };
	vector<vector<int>> v{ {-10 } };

	DWORD start_time = GetTickCount();

	//cout << s.minimumTotal(v) << endl;
	cout << s.minimumTotalNew(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

// 动态规划未优化空间情况  二维数组
int SolutionTriangleMinimumPathSum::minimumTotal(vector<vector<int>>& triangle)
{
	int n = triangle.size();
	int m = triangle.front().front();
	vector<vector<int>> dp{ {m} };
	vector<int> temp{ {m} };

	for (int i = 1; i < n; ++i)
	{
		temp.clear();
		temp.emplace_back(dp[i - 1].front() + triangle[i].front());
		for (int j = 1; j < i; ++j)
			temp.emplace_back((min(dp[i - 1][j - 1], dp[i - 1][j])) + triangle[i][j]);
		temp.emplace_back(dp[i - 1].back() + triangle[i].back());
		dp.emplace_back(temp.begin(), temp.end());
	}

	return *min_element(temp.begin(), temp.end());
}

// 动态规划一维数组
int SolutionTriangleMinimumPathSum::minimumTotalNew(vector<vector<int>>& triangle)
{
	int n = triangle.size();
	int m = triangle.front().front();
	vector<int> dp{ {m} };
	vector<int> temp{ {m} };

	for (int i = 1; i < n; ++i)
	{
		temp.clear();
		temp.emplace_back(dp.front() + triangle[i].front());
		for (int j = 1; j < i; ++j)
			temp.emplace_back((min(dp[j - 1], dp[j])) + triangle[i][j]);
		temp.emplace_back(dp.back() + triangle[i].back());
		dp = temp;
	}

	return *min_element(dp.begin(), dp.end());
}