#include "distribute_candy.h"

int pointsCandy()
{
	// 创建对象
	SolutionDistributeCandy s;
	vector<int> v = { 1,2,3,5,4,3,2,1,4,3,2,1 };

	DWORD start_time = GetTickCount();

	cout << s.candy(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

// 放弃，需要考虑因素太多思路越走越深
int SolutionDistributeCandy::candy(vector<int>& ratings)
{
	int numChildren = ratings.size();

	int leastNumberCandy = 1;

	if (numChildren < 2)
		return numChildren == 0 ? 0 : 1;

	int onNumberCandy = 1;
	int dissatisfactionWithAdd = 0;
	int n = 0, f = 0, m = 0;

	for (int i = 1; i < numChildren; ++i)
	{
		if (ratings[i] > ratings[i - 1])
		{
			leastNumberCandy += ++onNumberCandy;
			n = onNumberCandy;
			m = 0;
		}
		else
		{
			if (ratings[i - 1] > ratings[i] && onNumberCandy == 1)
			{
				++m;
				leastNumberCandy += ++dissatisfactionWithAdd;
				f = dissatisfactionWithAdd + 1;
			}
			else
			{
				dissatisfactionWithAdd = 0;
			}
			leastNumberCandy += 1;
			onNumberCandy = 1;

			if (n == f && ratings[i - f + 1] != ratings[i - f] && m >=2)
			{
				++n;
				++leastNumberCandy;
			}
		}
	}

	return leastNumberCandy;
}