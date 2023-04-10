#include "split_palindrome_string_II.h"

int segmentationPalindromeSeriesII()
{
	// 创建对象
	SolutionSplitPalindromeStrinII s;

	DWORD start_time = GetTickCount();

	cout << s.minCut("abbab") << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

int SolutionSplitPalindromeStrinII::minCut(string s)
{

	return 0;
}