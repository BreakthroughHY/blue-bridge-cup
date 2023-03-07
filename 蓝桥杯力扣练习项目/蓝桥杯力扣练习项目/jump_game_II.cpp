#include "jump_game_II.h"

int jumpingGamesII()
{
	// ��������
	SolutionJumpGameII s;
	//int nums[] = { 2,3,1,1,4 };
	int nums[2] = {2, 5};

	vector<int> v;

	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); ++i)
	{
		v.push_back(nums[i]);
	}

	DWORD start_time = GetTickCount();

	cout << s.jump(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

	return 0;
}

// ̰���㷨�����⣬�Ӻ��Դ��ж��Ƿ�ÿһ��λ�õ��������Ծ������Ϊ���ٲ���Ҫ�Ķ��μ��㣬
// ��ÿһ�������Ծ�������浽������(��̬�滮)
int SolutionJumpGameII::jump(vector<int>& nums)
{
	int len = nums.size();
	if (len == 1)
		return 0;
	vector<int> dp(len, INT_MAX); // Ĭ��ÿ�����㵽��Ŀ������������Ϊ����󣬲����ܵ���


	for (int i = len - 2; i >= 0; --i)
	{
		if (nums[i] >= len - 1 - i) // ����Ĵ�С֧��һ���Ե���Ŀ��λ�ã� ���������Ѿ����ﱾ��Ķ�����ֻ����һ�ε���Ŀ��
		{
			dp[i] = 1;
		}
		else // �����޷�һ���Ե���Ŀ���
		{
			int minLen = INT_MAX; // ��¼�����ܵ���Ĳ������ٵ�
			for (int j = 0; j < nums[i]; ++j)
			{
				if (dp[i + j + 1] != INT_MAX)
				{
					minLen = min(minLen, dp[i + j + 1]);
				}
			}
			if (minLen != INT_MAX)
			{
				dp[i] = minLen + 1;
			}
		}
	}

	return dp[0];
}
