#include "wildcard_matching.h"

int wildcardMatch()
{
	// 创建对象
	SolutionWildcardMatching s;

	DWORD start_time = GetTickCount();

	cout << s.isMatch("", "") << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

bool SolutionWildcardMatching::isMatch(string s, string p)
{



	return true;
}