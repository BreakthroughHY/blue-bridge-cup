#include "split_palindrome_string_II.h"

int segmentationPalindromeSeriesII()
{
	// 创建对象
	SolutionSplitPalindromeStrinII s;

	DWORD start_time = GetTickCount();

	cout << s.minCut("abbab") << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

int SolutionSplitPalindromeStrinII::minCut(string s)
{
	int n = s.size();

	int left, right;

	for (int i = 0; i < n; ++i)
	{
		left = right = i;
		uMap[left].emplace_back(right); // 单个字符是回文数，直接写入哈希表
		while (--left >= 0 && ++right < n && s[left] == s[right])
		{
			uMap[left].emplace_back(right);
		}

		if (i == n - 1)
			break;

		left = i;
		right = i + 1;

		while (left >= 0 && right < n && s[left] == s[right])
		{
			uMap[left].emplace_back(right);
			--left;
			++right;
		}
	}
	
	return 0;
}

//void dfs()
//{
//	if 
//}