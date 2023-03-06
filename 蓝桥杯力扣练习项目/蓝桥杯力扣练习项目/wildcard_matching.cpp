#include "wildcard_matching.h"

int wildcardMatch()
{
	// 创建对象
	SolutionWildcardMatching s;

	DWORD start_time = GetTickCount();

	cout << s.isMatch("adceb", "*a*b") << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

bool SolutionWildcardMatching::isMatch(string s, string p)
{
	int m = s.size();
	int n = p.size();

	vector<vector<int>> dp(m + 1, vector<int>(n + 1));

	dp[0][0] = true; // 两个串全为空 匹配情况为匹配成功

	for (int i = 1; i <= n; ++i) // 处理s为空 ，p不为空的情况，只有p全为*才匹配
	{
		if (p[i - 1] == '*')
		{
			dp[0][i] = true;
		}
		else
		{
			break;
		}
	}

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (p[j - 1] == '*')
			{
				dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
			}
			else if (p[j - 1] == '?' || p[j - 1] == s[i - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
		}
	}

	return dp[m][n];
}