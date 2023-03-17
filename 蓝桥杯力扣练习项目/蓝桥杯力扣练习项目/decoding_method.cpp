#include "decoding_method.h"

int decodingMethod()
{
	// 创建对象
	SolutionDecodingMethod s;
	//string ss = "11106";
	//string ss = "1123";
	//string ss = "10011";
	string ss = "230";

	DWORD start_time = GetTickCount();

	cout << s.numDecodings(ss) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

int SolutionDecodingMethod::numDecodings(string s)
{
	if (s[0] == '0') // 题目翻译有问题，并不是只要头部不为0字符串就一定对，内部可能出现两个连续的0
		return 0;
	bool flag = false;
	for (auto ch : s)
	{
		if (ch == '0')
		{
			if (flag)
				return 0;
			flag = true;
			continue;
		}
		flag = false;
	}

	int n = s.length();
	vector<int> dp(n + 1, 0);
	dp[n] = 1;

	if (s.back() != '0')
	{
		dp[n - 1] = 1;
	}
	else
		dp[n - 1] = -1;

	for (int i = n - 2; i >= 0; --i)
	{
		if (s[i] == '0')
		{
			dp[i] = -dp[i + 1];
		}
		else if (s[i + 1] == '0')
		{
			if (s[i] > '2')
				return 0;
			dp[i] = -dp[i + 1];
		}
		else if (i + 2 == n || s[i + 2] != '0')
		{
			if (s.substr(i, 2) >= "1" && s.substr(i, 2) <= "26")
			{
				dp[i] = dp[i + 1] + dp[i + 2];
			}
			else
				dp[i] = dp[i + 1];
		}
		else
		{
			dp[i] = dp[i + 1];
		}
	}
	return dp[0];
}

int SolutionDecodingMethod::numDecodingsLeetcode(string s)
{
	int n = s.size();
	vector<int> f(n + 1);
	f[0] = 1;
	for (int i = 1; i <= n; ++i) {
		if (s[i - 1] != '0') {
			f[i] += f[i - 1];
		}
		if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)) {
			f[i] += f[i - 2];
		}
	}
	return f[n];
}