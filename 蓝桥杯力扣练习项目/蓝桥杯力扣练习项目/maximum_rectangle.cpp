#include "maximum_rectangle.h"

int biggestRectangle()
{
	// ��������
	SolutionMaximumRectangle s;

	DWORD start_time = GetTickCount();
	vector<vector<char>> v{ {'1','0','1','0','0'},
											{'1','0','1','1','1'},
											{'1','1','1','1','1'},
											{'1','0','0','1','0'} };

	cout << s.maximalRectangle(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

	return 0;
}

int SolutionMaximumRectangle::maximalRectangle(vector<vector<char>>& matrix)
{
	int m = matrix[0].size(); // �����
	int n = matrix.size(); // ���߶�

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
				d[i][j] = d[i][j] + 1;
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
			int height = 1; // ���θ�
			int heightTemp = i; // ���׶��ϱ�������
			while (d[heightTemp][j] != 0 && heightTemp <= 0)
			{
				int maximumWidth = 0;
				for (int k = 0; k < height; ++k)
				{
					maximumWidth = max(maximumWidth, d[heightTemp][j]);
				}
				mostWidespread = max(mostWidespread, height * maximumWidth);
				++height;
			}
		}
	}


	return mostWidespread;
}