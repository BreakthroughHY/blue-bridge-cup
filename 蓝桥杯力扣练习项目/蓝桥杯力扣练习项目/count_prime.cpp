#include "count_prime.h"

int countPrime()
{
	// ʵ��������
	Solution s;

	//cout << "���У�" << s.countPrimes(499979) << "���������������֡�" << endl;

	cout << "���У�" << s.countPrimesLeetCode(499979) << "���������������֡�" << endl;

	return 0;
}

int Solution::countPrimes(int n)
{
	int count = 0; // ��¼��������������
	for (int i = 2; i < n; i++)
	{
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				break; // ����1��������Ա�����
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
	int count = 0; // ��¼��������������

	for (int i = 2; i < n; ++i)
	{
		count += isPrime(i);
	}
	return count;
}

// �жϴ���������Ƿ�Ϊ����
bool isPrime(int x)
{
	for (int i = 2; i * i <= x; ++i)
	{
		if (x % i == 0)
			return false;
	}

	return true;
}