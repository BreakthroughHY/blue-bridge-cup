#include "jump_game_II.h"

int jumpingGamesII()
{
	// ��������
	SolutionJumpGameII s;
	int nums[] = { 2,3,1,1,4 };
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

int SolutionJumpGameII::jump(vector<int>& nums)
{




}