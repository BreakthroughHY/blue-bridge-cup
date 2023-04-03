#include "minimum_cover_substring.h"

int minimumCoverSubstring()
{
	// ��������
	SolutionMinimumCoverSubstring s;

	DWORD start_time = GetTickCount();

	cout << s.minWindow("AADOBECODEBANC", "ABC") << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

	return 0;
}

string SolutionMinimumCoverSubstring::minWindow(string s, string t)
{
	int n = s.size();
	unordered_map<char, int> freq; // ��¼Ŀ���ַ����е���ĸƵ��
	int left = 0, right = 0;
	int strMin = INT_MAX;
	int l, r;

	for (int i = 0; i < t.size(); ++i)
		--freq[t[i]];

	while (right <= n)
	{
		if (isAllNonnegative(freq))
		{
			if (strMin > (right - left))
			{
				l = left;
				r = right;
				strMin = r - l;
			}
			--freq[s[left]];
			++left;
		}
		else
		{
			++freq[s[right]];
			++right;
		}
	}

	//for (auto a : freq)
	//	cout << a.first << "		" << a.second << endl;
	cout << l << "		" << r << endl;

	return "";
}

// �������map�������Ƿ�ȫ��Ϊ�Ǹ���
bool isAllNonnegative(unordered_map<char, int>& freq)
{
	for (auto a : freq)
		if (a.second < 0)
			return false;

	return true;
}