#include "longest_valid_bracket.h"

int maximumEffectiveBrackets()
{
	// 创建类对象
	SolutionLongestValidBracket s;

	DWORD start_time = GetTickCount();

	cout << s.longestValidParentheses("()(()(()))") << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

int SolutionLongestValidBracket::longestValidParentheses(string s)
{
	int ans = 0;
	int len = s.length();

	for (int i = 0; i < len; ++i)
	{
		if (s[i] == '(')
		{
			if (len - i + 1 <= ans) // 剩余长度没有现在最大长度长，没有检测的必要，直接退出节约执行时间
				break;
			specifiesLengthTheLeftParenthesis(s, i, ans, len);
		}
			
	}
	return ans << 1;
}

// 判定已指定左括号为头字符的有效括号字符串长度
void specifiesLengthTheLeftParenthesis(string& s, int i, int& ans, int& len)
{
	int maxLen = 0; // 记录有效长度
	int numRParenthesis = 1; // 右括号数量

	int counting = 0;
	for (++i; i < len; ++i)
	{
		if (s[i] == '(')
		{
			++numRParenthesis;
		}
		else
		{
			++counting;
			--numRParenthesis;
			if (!numRParenthesis)
			{
				maxLen = max(maxLen, counting);
			}

			if (numRParenthesis < 0)
			{
				ans = max(maxLen, ans);
				return;
			}
		}
		
		ans = max(ans, maxLen);
	}
}