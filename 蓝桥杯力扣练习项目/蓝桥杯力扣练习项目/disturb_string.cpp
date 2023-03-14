#include "disturb_string.h"

int disturbString()
{
	// 创建对象
	SolutionDisturbString s;
	string ss = "cbacdcbc";
	string as = "asdf";

	DWORD start_time = GetTickCount();

	cout << s.isScramble(ss, as) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

// 深度优先遍历，应该算是暴力算法
bool SolutionDisturbString::isScramble(string s1, string s2)
{
	this->s1 = s1; // 将字符串赋值给类成员减少资源消耗
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

// 深度优先遍历
bool dfs(int front, int back, int dividingSubscript)
{
	if (front == back)
	{

	}
}