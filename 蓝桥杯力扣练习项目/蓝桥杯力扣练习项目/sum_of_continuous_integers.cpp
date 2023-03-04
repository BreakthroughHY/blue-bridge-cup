#include "sum_of_continuous_integers.h"

int sumContinuousInteger()
{
	// ���������
	SolutionSumInt s;

	DWORD start_time = GetTickCount();

	//cout << "�����������У�" << s.consecutiveNumbersSum(66704037) << "����" << endl;

	cout << "�����������У�" << s.consecutiveNumbersSumOptimize(15) << "����" << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��



	return 0;
}

int SolutionSumInt::consecutiveNumbersSum(int n)
{
	int count = 0;
	int continuousNumSum = 0;
	int front = 0, back = 0;

	while (front <= n)
	{
		if (continuousNumSum == n)
		{
			++count;
			continuousNumSum += ++front;
		}
		else if (continuousNumSum < n)
		{
			continuousNumSum += ++front;
		}
		else
		{
			continuousNumSum -= back++;
		}
	}

	return count;
}

int SolutionSumInt::consecutiveNumbersSumOptimize(int n)
{
	int count = 0;
	int continuousNumSum = 0;
	int front = 0, back = 0;
	int maxNum = 0;

	while (front <= n)
	{
		if (continuousNumSum == n)
		{
			++count;
			maxNum = front - back;
			if (back != 0)
				++maxNum;
			break;
		}
		else if (continuousNumSum < n)
		{
			continuousNumSum += ++front;
		}
		else
		{
			continuousNumSum -= back++;
		}
	}

	for (int i = 1; i < maxNum; i++)
	{
		if (isOdd(i))
		{
			if (n % i == 0)
				++count;
		}
		else
		{
			if (n % i == (i / 2))
				++count;
		}
	}

	return count;
}

// �ж��Ƿ�Ϊ����
bool isOdd(int x)
{
	if (x % 2)
		return true;
	return false;
}