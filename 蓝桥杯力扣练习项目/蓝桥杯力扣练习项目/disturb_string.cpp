#include "disturb_string.h"

int disturbString()
{
	// 创建对象
	SolutionDisturbString s;
	string ss = "abcdbdacbdac";
	string as = "bdacabcdbdac";

	DWORD start_time = GetTickCount();

	cout << s.isScramble(ss, as) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

// 深度优先遍历，应该算是暴力算法
bool SolutionDisturbString::isScramble(string s1, string s2)
{
	memset(memo, 0, sizeof(memo)); // 将数组全部填充为0
	this->s1 = s1; // 将字符串赋值给类成员减少资源消耗
	this->s2 = s2;

	return dfs(0, 0, s1.size());
}

// 深度优先遍历
bool SolutionDisturbString::dfs(int i1, int i2, int dividingSubscript)
{
	if (memo[i1][i2][dividingSubscript]) // 查表 已经处理过的数据直接使用减少计算
		return memo[i1][i2][dividingSubscript] == 1;

	// 检测两个字串是否相同
	if (s1.substr(i1, dividingSubscript) == s2.substr(i2, dividingSubscript))
	{
		memo[i1][i2][dividingSubscript] = 1;
		return true;
	}

	// 检测两个字串内的数字字符数量是否正确
	if (!checkIfSimilar(i1, i2, dividingSubscript))
	{
		memo[i1][i2][dividingSubscript] = -1;
		return false;
	}

	// 枚举分割点
	for (int i = 1; i < dividingSubscript; ++i)
	{
		// 不交换
		if (dfs(i1, i2, i) && dfs(i1 + i, i2 + i, dividingSubscript - i))
		{
			memo[i1][i2][dividingSubscript] = 1;
			return true;
		}

		// 交换
		if (dfs(i1, i2 + dividingSubscript - i,i) && dfs(i1 + i, i2, dividingSubscript - i))
		{
			memo[i1][i2][dividingSubscript] = 1;
			return true;
		}
	}
	memo[i1][i2][dividingSubscript] = -1;
	return false;
}

// 检测字符串内的数字字符是否相同
bool SolutionDisturbString::checkIfSimilar(int i1, int i2, int length)
{
	unordered_map<int, int> freq; // 数子字符出现频率

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