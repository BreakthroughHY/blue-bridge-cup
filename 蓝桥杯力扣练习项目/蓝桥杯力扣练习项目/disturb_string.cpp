#include "disturb_string.h"

int disturbString()
{
	// ��������
	SolutionDisturbString s;
	string ss = "cbacdcbc";
	string as = "asdf";

	DWORD start_time = GetTickCount();

	cout << s.isScramble(ss, as) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

	return 0;
}

// ������ȱ�����Ӧ�����Ǳ����㷨
bool SolutionDisturbString::isScramble(string s1, string s2)
{
	this->s1 = s1; // ���ַ�����ֵ�����Ա������Դ����
	this->s2 = s2;

	int n = s1.length();
	bool ret = false;

	for (int i = 1; i < n - 1; ++i)
	{
		ret = dfs(0, n - 1, i);
		if (ret)
			return ret;
	}

	return ret;
}

// ������ȱ���
bool dfs(int front, int back, int dividingSubscript)
{
	if (front == back)
	{

	}
}