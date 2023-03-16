#include "disturb_string.h"

int disturbString()
{
	// ��������
	SolutionDisturbString s;
	string ss = "abcdbdacbdac";
	string as = "bdacabcdbdac";

	DWORD start_time = GetTickCount();

	cout << s.isScramble(ss, as) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

	return 0;
}

// ������ȱ�����Ӧ�����Ǳ����㷨
bool SolutionDisturbString::isScramble(string s1, string s2)
{
	memset(memo, 0, sizeof(memo)); // ������ȫ�����Ϊ0
	this->s1 = s1; // ���ַ�����ֵ�����Ա������Դ����
	this->s2 = s2;

	return dfs(0, 0, s1.size());
}

// ������ȱ���
bool SolutionDisturbString::dfs(int i1, int i2, int dividingSubscript)
{
	if (memo[i1][i2][dividingSubscript]) // ��� �Ѿ������������ֱ��ʹ�ü��ټ���
		return memo[i1][i2][dividingSubscript] == 1;

	// ��������ִ��Ƿ���ͬ
	if (s1.substr(i1, dividingSubscript) == s2.substr(i2, dividingSubscript))
	{
		memo[i1][i2][dividingSubscript] = 1;
		return true;
	}

	// ��������ִ��ڵ������ַ������Ƿ���ȷ
	if (!checkIfSimilar(i1, i2, dividingSubscript))
	{
		memo[i1][i2][dividingSubscript] = -1;
		return false;
	}

	// ö�ٷָ��
	for (int i = 1; i < dividingSubscript; ++i)
	{
		// ������
		if (dfs(i1, i2, i) && dfs(i1 + i, i2 + i, dividingSubscript - i))
		{
			memo[i1][i2][dividingSubscript] = 1;
			return true;
		}

		// ����
		if (dfs(i1, i2 + dividingSubscript - i,i) && dfs(i1 + i, i2, dividingSubscript - i))
		{
			memo[i1][i2][dividingSubscript] = 1;
			return true;
		}
	}
	memo[i1][i2][dividingSubscript] = -1;
	return false;
}

// ����ַ����ڵ������ַ��Ƿ���ͬ
bool SolutionDisturbString::checkIfSimilar(int i1, int i2, int length)
{
	unordered_map<int, int> freq; // �����ַ�����Ƶ��

	for (int i = i1; i < i1 + length; ++i)
		++freq[s1[i]];

	for (int i = i2; i < i2 + length; ++i)
		--freq[s2[i]];

	if (any_of(freq.begin(), freq.end(), [](const auto& entry) {return entry.second != 0; }))
	{
		return false;
	}
	return true;
}