#include "matrix_zeroing.h"

int matrixZero()
{
	// 创建对象
	SolutionMatrixZeroing s;
	vector<vector<int>> v;

	v = { {1,1,1},{1,0,1},{1,1,1} };
	
	DWORD start_time = GetTickCount();

	s.setZeroes(v);

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	for (auto fa : v)
	{
		for (auto so : fa)
		{
			cout << so << "	";
		}
		cout << endl;
	}

	return 0;
}

void SolutionMatrixZeroing::setZeroes(vector<vector<int>>& matrix)
{
	int m = matrix.size();
	int n = matrix[0].size();
	vector<bool> row(m, false), col(n, false);

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (!matrix[i][j])
				row[i] = col[j] = true;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (row[i] || col[j])
			{
				matrix[i][j] = 0;
			}
		}
	}
}