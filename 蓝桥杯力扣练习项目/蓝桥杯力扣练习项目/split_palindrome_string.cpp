#include "split_palindrome_string.h"

int splitPalindromeString()
{
	// 创建对象
	SolutionSplitPalindromeString s;

	DWORD start_time = GetTickCount();

	vector<vector<string>> v = s.partition("aab");

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

vector<vector<string>> SolutionSplitPalindromeString::partition(string s)
{
	int n = s.size();
	vector<vector<string>> ret;
	vector<string> temp;
	int left, right;

	for (int i = 0; i < n; ++i)
	{
		temp.clear();
		left = right = i;
		temp.emplace_back(s.substr());
		while ()
		{

		}
		ret.emplace_back(temp.begin(), temp.end());
	}

	return ret;
}