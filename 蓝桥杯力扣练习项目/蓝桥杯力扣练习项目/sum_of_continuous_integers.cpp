#include "sum_of_continuous_integers.h"

int sumContinuousInteger()
{
	// 创建类对象
	SolutionSumInt s;

	DWORD start_time = GetTickCount();

	//cout << "符合条件的有：" << s.consecutiveNumbersSum(66704037) << "个。" << endl;

	cout << "符合条件的有：" << s.consecutiveNumbersSumOptimize(15) << "个。" << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间



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

// 判断是否为奇数
bool isOdd(int x)
{
	if (x % 2)
		return true;
	return false;
}