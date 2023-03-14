#include "remove_duplicate_letters.h"

int removeDuplicateLetters()
{
	// ��������
	SolutionRemoveDuplicateLetters s;
	string ss = "cbacdcbc";

	DWORD start_time = GetTickCount();

	cout << s.removeDuplicateLetters(ss) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

	return 0;
}

string SolutionRemoveDuplicateLetters::removeDuplicateLetters(string s)
{
	vector<int> num(26), vis(26);

	for (auto ch : s) // ͳ����ĸ����
		num[ch - 'a']++;

	string str; // �ַ����䵱ջ��ͬʱ�Ƿ���ֵ
	for (auto ch : s)
	{
		if (!vis[ch - 'a'])
		{
			while (!str.empty() && str.back() > ch) // �жϱ���Ԫ���Ƿ���Ҫ�������
			{
				if (num[str.back() - 'a'] > 0) // ��������ֱ���Ԫ�ؿ��Դ����
				{
					vis[str.back() - 'a'] = 0;
					str.pop_back();
				}
				else // �����ַ����в�����ֱ���Ԫ�أ����ܴ����
				{
					break;
				}
			}
			vis[ch - 'a'] = 1;
			str.push_back(ch);
		}
		num[ch - 'a'] -= 1;
	}

	return str;
}