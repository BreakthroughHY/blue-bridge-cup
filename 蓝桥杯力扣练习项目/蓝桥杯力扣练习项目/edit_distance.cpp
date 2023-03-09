#include "edit_distance.h"

int editDistance()
{
	// 创建对象
	SolutionEditDistance s;

	DWORD start_time = GetTickCount();

	cout << s.minDistance("asdfssqwes", "ass") << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

int SolutionEditDistance::minDistance(string word1, string word2)
{
	int n = word1.size(); // 原字符串长度
	int m = word2.size(); // 目标字符串长度
	vector<vector<int>> dp(n, vector<int>(m, 1));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (word1[i] == word2[j])
				dp[i][j] = 0; // 出现相同字符将对应dp数组值设为0
			cout << dp[i][j] << "	";
		}
		cout << endl;
		cout << endl;
	}
	cout << "-------------------------------------" << endl;
	// 寻找dp数组内的最优路径
	// 同样通过动态规划寻找最优路径   空间复杂度n，时间复杂度n*m

	vector<int> dp_(m);

	// 初始化dp_数组
	for (int i = 0; i < m; ++i)
	{
		if (!i) // i等于0特殊处理
			dp_[i] = dp[0][i];
		else
			dp_[i] = dp_[i - 1] + 1;
		cout << dp_[i] << "	";
	}
	cout << endl;
	int temp, temp1;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!j) // j 等于0特殊处理
			{
				temp1 = dp_[j];
				dp_[j] = dp_[j] + 1;
				cout << dp_[j] << "	";
			}
			else
			{
				temp = temp1;
				temp1 = dp_[j];
				if (temp <= min(dp_[j - 1], dp_[j]))
				{
					dp_[j] = dp[i][j] + temp;
					cout << dp_[j] << "	";
				}
				else
				{
					if (dp_[j - 1] > dp_[j])
					{
						dp_[j] = dp_[j] + 1;
						cout << dp_[j] << "	";
					}
					else
					{
						dp_[j] = dp_[j - 1] + 1;
						cout << dp_[j] << "	";
					}
				}
			}
		}
		cout << endl;
	}

	return dp_[m - 1];
}