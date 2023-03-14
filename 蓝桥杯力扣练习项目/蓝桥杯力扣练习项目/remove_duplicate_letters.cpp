#include "remove_duplicate_letters.h"

int removeDuplicateLetters()
{
	// 创建对象
	SolutionRemoveDuplicateLetters s;
	string ss = "cbacdcbc";

	DWORD start_time = GetTickCount();

	cout << s.removeDuplicateLetters(ss) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

string SolutionRemoveDuplicateLetters::removeDuplicateLetters(string s)
{
	vector<int> num(26), vis(26);

	for (auto ch : s) // 统计字母数量
		num[ch - 'a']++;

	string str; // 字符串充当栈，同时是返回值
	for (auto ch : s)
	{
		if (!vis[ch - 'a'])
		{
			while (!str.empty() && str.back() > ch) // 判断本次元素是否需要被处理掉
			{
				if (num[str.back() - 'a'] > 0) // 后续会出现本次元素可以处理掉
				{
					vis[str.back() - 'a'] = 0;
					str.pop_back();
				}
				else // 后续字符串中不会出现本次元素，不能处理掉
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