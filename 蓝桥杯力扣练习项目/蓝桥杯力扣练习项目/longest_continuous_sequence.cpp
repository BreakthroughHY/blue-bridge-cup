#include "longest_continuous_sequence.h"

int longestContinuousSequence()
{
	// 创建对象
	SolutionLongestContinuousSequence s;
	vector<int> v;

	v = { 1,2,0,1 };

	DWORD start_time = GetTickCount();

	//cout << s.longestConsecutive(v) << endl;
	cout << s.longestConsecutiveNew(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

int SolutionLongestContinuousSequence::longestConsecutive(vector<int>& nums)
{
	// 去除重复元素，题目好像没说会重复，不过作为开发人员要对可能的错误进行预防
	unordered_set<int> uSet;
	for (auto& a : nums)
		uSet.insert(a);

	int maxConsecutiveDigits = 0;

	for (auto& a : uSet)
	{
		if (!uSet.count(a - 1))
		{
			int currNum = a + 1;
			int currLen = 1;
			while (uSet.count(currNum))
			{
				++currLen;
				++currNum;
			}
			maxConsecutiveDigits = max(maxConsecutiveDigits, currLen);
		}
	}

	return maxConsecutiveDigits;
}

int SolutionLongestContinuousSequence::longestConsecutiveNew(vector<int>& nums)
{
	if (nums.empty())
		return 0;

	sort(nums.begin(), nums.end());

	int maxConsecutiveDigits = 1;
	int maxConsecutiveDigitsTemp = 1;
	int temp = nums.front();

	for (vector<int>::iterator it = ++nums.begin(); it != nums.end(); ++it)
	{
		if (*it == temp)
			continue;
		if (*it == temp + 1)
		{
			++maxConsecutiveDigitsTemp;
			temp = *it;
		}
		else
		{
			maxConsecutiveDigits = max(maxConsecutiveDigits, maxConsecutiveDigitsTemp);
			maxConsecutiveDigitsTemp = 1;
			temp = *it;
		}
	}

	return max(maxConsecutiveDigits, maxConsecutiveDigitsTemp);
}