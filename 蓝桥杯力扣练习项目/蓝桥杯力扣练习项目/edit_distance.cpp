#include "edit_distance.h"

int editDistance()
{
	// ��������
	SolutionEditDistance s;

	DWORD start_time = GetTickCount();

	cout << s.minDistance("", "") << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

	return 0;
}

int SolutionEditDistance::minDistance(string word1, string word2)
{

	return 0;
}