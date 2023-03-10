#include "maximum_rectangle.h"

int biggestRectangle()
{
	// 创建对象
	SolutionMaximumRectangle s;

	DWORD start_time = GetTickCount();
	vector<vector<char>> v{ {'1','0','1','0','0'},
											{'1','0','1','1','1'},
											{'1','1','1','1','1'},
											{'1','0','0','1','0'} };

	cout << s.maximalRectangle(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

// 没啥说的，基本上是暴力枚举上优化时间。
int SolutionMaximumRectangle::maximalRectangle(vector<vector<char>>& matrix)
{
	int m = matrix[0].size(); // 表格宽度
	int n = matrix.size(); // 表格高度

	vector<vector<int>> d(n, vector<int>(m, 0));

	for (int i = 0; i < n; ++i)
	{
		if (matrix[i][0] == '1')
			d[i][0] = 1;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j < m; ++j)
		{
			if (matrix[i][j] == '1')
			{
				d[i][j] = d[i][j - 1] + 1;
			}
			cout << d[i][j] << "	";
		}
		cout << endl;
	}

	int mostWidespread = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (d[i][j] != 0)
			{
				int height = 1; // 矩形高
				int heightTemp = i; // 检测阶段上边所在行
				while (heightTemp >= 0 && d[heightTemp][j] != 0)
				{
					int minimumWidth = m;
					for (int k = 0; k < height; ++k)
					{
						minimumWidth = min(minimumWidth, d[i - k][j]);
					}
					mostWidespread = max(mostWidespread, height * minimumWidth);
					++height;
					--heightTemp;
				}
			}
		}
	}

	return mostWidespread;
}