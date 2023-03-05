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

	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == '(')
			specifiesLengthTheLeftParenthesis(s, i, ans);
	}
	return ans << 1;
}

// 判定已指定左括号为头字符的有效括号字符串长度
void specifiesLengthTheLeftParenthesis(string& s, int i, int& ans)
{
	int maxLen = 0; // 记录有效长度
	int numRParenthesis = 1; // 右括号数量

	int counting = 0;
	for (++i; i < s.length(); ++i)
	{
		if (s[i] == '(')
		{
			++numRParenthesis;
		}
		else if (s[i] == ')')
		{
			++counting;
			--numRParenthesis;
			if (!numRParenthesis)
			{
				maxLen = max(maxLen, counting);
				//counting = 0;
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