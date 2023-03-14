#include "distribute_candy.h"

int pointsCandy()
{
	// ��������
	SolutionDistributeCandy s;
	vector<int> v = { 1,0,2 };

	DWORD start_time = GetTickCount();

	cout << s.candy(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

	return 0;
}

//// ��������Ҫ��������̫��˼·Խ��Խ��
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
//			// ��ʹ�ù���ռ䣬�������ƹ��ڸ��ӣ�Ӱ�����ع��࣬������ʹ�ÿ������ִ��Ч�ʺ��ڴ�ʹ��
//			// ������ʱ�䳤�����׳�bug���ۺ������ʺϴ�ţʹ�ã�
//			// Ŀǰ�����������ʣ����δ���
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

// �ٷ��������α���
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