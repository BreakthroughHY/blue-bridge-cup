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
	int len = s.length();

	for (int i = 0; i < len; ++i)
	{
		if (s[i] == '(')
		{
			if (len - i + 1 <= ans) // ʣ�೤��û��������󳤶ȳ���û�м��ı�Ҫ��ֱ���˳���Լִ��ʱ��
				break;
			specifiesLengthTheLeftParenthesis(s, i, ans, len);
		}
			
	}
	return ans << 1;
}

// �ж���ָ��������Ϊͷ�ַ�����Ч�����ַ�������
void specifiesLengthTheLeftParenthesis(string& s, int i, int& ans, int& len)
{
	int maxLen = 0; // ��¼��Ч����
	int numRParenthesis = 1; // ����������

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