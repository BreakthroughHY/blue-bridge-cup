#include "longest_palindromic_substring.h"

int backToLongestTextStr()
{
	// 创建类对象
	SolutionLongestPalindromicSubstring s;

	DWORD start_time = GetTickCount();

	cout << "最长为：" << s.longestPalindrome("babad") << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

string SolutionLongestPalindromicSubstring::longestPalindrome(string s)
{
	int len = s.length();
	if (len < 2)
		return s;

	int maxLen = 0; // 记录符合条件的最长字串的长度
	int evenLong, oddLong;
	int substringHead;

	for (int i = 0; i < s.length() - 1; ++i)
	{
		evenLong = launchCenter(s, i, i);
		oddLong = launchCenter(s, i, i + 1);

		int longest = max(evenLong, oddLong);
		
		if (maxLen < longest)
		{
			maxLen = longest;
			substringHead = i - (longest - 1) / 2;
		}
	}

	return s.substr(substringHead, maxLen);
}

int launchCenter(string& s, int left, int right)
{
	while (left >= 0 && right <= s.length() - 1)
	{
		if (s[left] == s[right])
		{
			--left;
			++right;
		}
		else
			break;
	}
	return right - left - 1; // 返回符合条件的子串长度
}