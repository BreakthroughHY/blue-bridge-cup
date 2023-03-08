#include "climb_stairs.h"

int climbStairs()
{
	// ��������
	SolutionClimbStairs s;

	DWORD start_time = GetTickCount();

	//cout << s.climbStairs(1) << endl;
	cout << s.climbStairsNew(4) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

	return 0;
}

// ��̬�滮�ռ临�Ӷȿ���ѹ��С��n,��Ӧ�û�Ӱ��Ч��
int SolutionClimbStairs::climbStairs(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;

	vector<int> dp(n);

	dp[n - 1] = 1;
	dp[n - 2] = 2;

	for (int i = n - 3; i >= 0; --i)
	{
		dp[i] = dp[i + 1] + dp[i + 2];
	}
	
	return dp[0];
}

// �Ż��ռ�ռ��
int SolutionClimbStairs::climbStairsNew(int n)
{
	if (n == 1)
		return 1;

	vector<int> dp(3);

	dp[2] = 1;
	dp[1] = 2;

	for (int i = n - 3; i >= 0; --i)
	{
		dp[0] = dp[1] + dp[2];
		dp[2] = dp[1];
		dp[1] = dp[0];
	}

	return dp[0];
}