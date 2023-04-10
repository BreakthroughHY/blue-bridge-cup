#include "split_palindrome_string.h"

int splitPalindromeString()
{
	// 创建对象
	SolutionSplitPalindromeString s;

	DWORD start_time = GetTickCount();

	vector<vector<string>> v = s.partition("abbab");

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	s.printV(v);

	return 0;
}

// 自写方法   和官方第二种方法思路相同
vector<vector<string>> SolutionSplitPalindromeString::partition(string s)
{
	int n = s.size();
	vector<string> temp;
	int left, right;

	for (int i = 0; i < n; ++i)
	{
		left = right = i;
		dict[left].emplace_back(right);
		while (--left >= 0 && ++right < n && s[left] == s[right])
		{
			dict[left].emplace_back(right);
		}
		if (i == n - 1)
			break;

		left = i;
		right = i + 1;

		while (left >= 0 && right < n && s[left] == s[right])
		{
			dict[left].emplace_back(right);
			++right;
			--left;
		}
	}

	dfs(temp, 0, s);

	return ret;
}

void SolutionSplitPalindromeString::dfs(vector<string>& temp, int left, string& s)
{
	if (dict.find(left) == dict.end())
	{
		ret.emplace_back(temp.begin(), temp.end());
		return;
	}
	for (auto right : dict[left])
	{
		temp.emplace_back(s.substr(left, right - left + 1));
		dfs(temp, right + 1, s);
		temp.pop_back();
	}
}

void SolutionSplitPalindromeString::printV(vector<vector<string>>& v)
{
	for (auto& fa : v)
	{
		for (auto& so : fa)
			cout << so << "	";
		cout << endl;
	}
}

