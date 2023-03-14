#include "distribute_candy.h"

int pointsCandy()
{
	// 创建对象
	SolutionDistributeCandy s;
	vector<int> v = { 1,0,2 };

	DWORD start_time = GetTickCount();

	cout << s.candy(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

//// 放弃，需要考虑因素太多思路越走越深
//int SolutionDistributeCandy::candy(vector<int>& ratings)
//{
//	int numChildren = ratings.size();
//
//	int leastNumberCandy = 1;
//
//	if (numChildren < 2)
//		return numChildren == 0 ? 0 : 1;
//
//	int onNumberCandy = 1;
//	int dissatisfactionWithAdd = 0;
//	int n = 0, f = 0, m = 0;
//
//	for (int i = 1; i < numChildren; ++i)
//	{
//		if (ratings[i] > ratings[i - 1])
//		{
//			leastNumberCandy += ++onNumberCandy;
//			n = onNumberCandy;
//			m = 0;
//		}
//		else
//		{
//			if (ratings[i - 1] > ratings[i] && onNumberCandy == 1)
//			{
//				++m;
//				leastNumberCandy += ++dissatisfactionWithAdd;
//				f = dissatisfactionWithAdd + 1;
//			}
//			else
//			{
//				dissatisfactionWithAdd = 0;
//			}
//			leastNumberCandy += 1;
//			onNumberCandy = 1; 
//
//			// 不使用过多空间，条件控制过于复杂，影响因素过多，工程中使用可以提高执行效率和内存使用
//			// 但开发时间长和容易出bug，综合评价适合大牛使用，
//			// 目前开发情况，仅剩条件未完成
//			if (n <= f && ratings[i - f + 1] != ratings[i - f] && m >=2)
//			{
//				n += f - n + 1;
//				leastNumberCandy += f - n + 1;
//			}
//		}
//	}
//
//	return leastNumberCandy;
//}

// 官方方法两次遍历
int SolutionDistributeCandy::candy(vector<int>& ratings)
{
	int n = ratings.size();

	vector<int> left(n, 1);
	
	for (int i = 1; i < n; ++i)
	{
		if (ratings[i - 1] < ratings[i])
			left[i] = left[i - 1] + 1;
	}

	int totalNumberSweets = max(1, left[n - 1]);
	int temp = 1;
	for (int i = n - 2; i >= 0; --i)
	{
		if (ratings[i] > ratings[i + 1])
		{
			++temp;
			totalNumberSweets += max(temp, left[i]);
		}
		else
		{
			totalNumberSweets += max(1, left[i]);
			temp = 1;
		}
	}
	return totalNumberSweets;
}