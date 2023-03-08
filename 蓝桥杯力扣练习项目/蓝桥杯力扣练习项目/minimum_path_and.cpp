#include "minimum_path_and.h"

int minimumPathAnd()
{
	// ��������
	SolutionMinimumPathandAnd s;

	vector<vector<int>> v{ {1, 3, 1},
										   {1, 5, 1},
									       {4, 2, 1} };


	DWORD start_time = GetTickCount();

	cout << s.minPathSum(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

	return 0;
}

// �ƶ����������Ƶ�ֻ�����º����ң��������ⷴ������
// ��̬�滮���ռ临�Ӷ�n,ʱ�临�Ӷ�n*m
int SolutionMinimumPathandAnd::minPathSum(vector<vector<int>>& grid)
{
	int m = grid.size(); // ��¼����
	int n = grid[0].size(); // ��¼����

	vector<int> dp(n, 0);

	for (int i = 0; i < n; ++i) // ��ʼ��dp����
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