#include "wildcard_matching.h"

int wildcardMatch()
{
	// ��������
	SolutionWildcardMatching s;

	DWORD start_time = GetTickCount();

	cout << s.isMatch("adceb", "*a*b") << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

	return 0;
}

bool SolutionWildcardMatching::isMatch(string s, string p)
{
	int m = s.size();
	int n = p.size();

	vector<vector<int>> dp(m + 1, vector<int>(n + 1));

	dp[0][0] = true; // ������ȫΪ�� ƥ�����Ϊƥ��ɹ�

	for (int i = 1; i <= n; ++i) // ����sΪ�� ��p��Ϊ�յ������ֻ��pȫΪ*��ƥ��
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