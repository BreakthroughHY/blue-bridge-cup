#include "count_prime.h"

int countPrime()
{
	// 实例化对象
	Solution s;

	//cout << "共有：" << s.countPrimes(499979) << "个符合条件的数字。" << endl;

	cout << "共有：" << s.countPrimesLeetCode(499979) << "个符合条件的数字。" << endl;

	return 0;
}

int Solution::countPrimes(int n)
{
	int count = 0; // 记录符合条件的数字
	for (int i = 2; i < n; i++)
	{
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				break; // 除了1和自身可以被整除
			}
			else if (j == (i - 1))
			{
				count++;
				cout << i << endl;
			}
		}
	}
	if (n > 2)
	{
		count++;
	}

	return count;
}


int Solution::countPrimesLeetCode(int n)
{
	int count = 0; // 记录符合条件的数字

	for (int i = 2; i < n; ++i)
	{
		count += isPrime(i);
	}
	return count;
}

// 判断传入的数字是否为质数
bool isPrime(int x)
{
	for (int i = 2; i * i <= x; ++i)
	{
		if (x % i == 0)
			return false;
	}

	return true;
}