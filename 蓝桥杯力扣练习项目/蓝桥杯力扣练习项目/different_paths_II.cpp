#include "different_paths_II.h"

int differentPathsII()
{
	// ��������
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

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

	return 0;
}

// ��̬�滮�ռ临�Ӷ�O(m+n)  ʱ�临�Ӷ�m*n
int SolutionDifferentPathII::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
	int m = obstacleGrid.size(); // ��¼�ж�����
	int n = obstacleGrid[0].size(); // ��¼�ж�����

	vector<int> dpL(n, 0); // ��dp����
	vector<int> dpC(m, 0); // ��dp����

	if (n == 1) // ����������
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
	dpL[0] = dpC[0] = 1; // ��̬�滮��ʼ��

	for (int i = 1; i < n; ++i) // ��ʼ����dp����
	{
		if (obstacleGrid[0][i])
			break; // ���������ϰ��˳�ѭ��
		dpL[i] = 1; // û�����ϰ�����λ�õ�·����һ
	}

	for (int i = 1; i < m; ++i) // ��ʼ����dp����
	{
		if (obstacleGrid[i][0])
			break; // ���������ϰ��˳�ѭ��
		dpC[i] = 1; // û�����ϰ�����λ�õ�·����һ
	}

	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < m; ++j)
		{
			if (obstacleGrid[i][j]) // ��λ�ô����ϰ�
			{
				dpL[j] = 0; // �ϰ��㲻���ܵ���·������Ϊ0
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