#include "longest_valid_bracket.h"

int maximumEffectiveBrackets()
{
	// ���������
	SolutionLongestValidBracket s;

	DWORD start_time = GetTickCount();

	cout << s.longestValidParentheses("()(()(()))") << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

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

// �ж���ָ��������Ϊͷ�ַ�����Ч�����ַ�������
void specifiesLengthTheLeftParenthesis(string& s, int i, int& ans)
{
	int maxLen = 0; // ��¼��Ч����
	int numRParenthesis = 1; // ����������

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