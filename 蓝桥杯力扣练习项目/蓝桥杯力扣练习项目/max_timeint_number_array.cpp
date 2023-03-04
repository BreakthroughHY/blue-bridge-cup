#include "max_timeint_number_array.h"

int maximumTimeWithinAnArray()
{
	// 创建类
	SolutionMaxTime s;
	vector<int> v;
	/*int num[4] = { 7,7,0,6 };
	for (int i = 0; i < 4; ++i)
	{
		v.push_back(num[i]);
	}*/
	

	DWORD start_time = GetTickCount();

	//cout << s.largestTimeFromDigits(v) << endl;
	int count = 0;
	// 上点强度
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			for (int k = 0; k < 9; ++k)
			{
				for (int l = 0; l < 9; ++l)
				{
					v.push_back(i);
					v.push_back(j);
					v.push_back(k);
					v.push_back(l);
					string ss = s.largestTimeFromDigits(v);
					if (!ss.empty())
					{
						++count;
						cout << ss << endl;
					}
					

					for (int a = 0; a < 4; ++a)
						v.pop_back();
				}
			}
		}
	}

	cout << "共演算出" << count << "种结果！" << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

// 程序目标：写出能写出的最高效的程序，不考虑代码量和开发时间。     任务代码：压榨程序员
string SolutionMaxTime::largestTimeFromDigits(vector<int>& arr)
{
	int numQuantity[10] = { 0 };
	string timeStr; // 时间字符串

	// 获取统计数字字符的数组
	for (int i = 0; i < 4; ++i) // 为啥循环4次，因为题目说的
	{
		++numQuantity[arr[i]];
	}

	// 小时处理
	// 判断小时是否能2做十位
	if (numQuantity[2] >= 2 || numQuantity[2] == 1 && (numQuantity[3] != 0 || numQuantity[1] != 0 || numQuantity[0] != 0))
	{
		timeStr += 2 + 48; // 添加小时十位
		--numQuantity[2];


		for (int i = 3;; --i)
		{
			if (numQuantity[i] != 0)
			{
				timeStr += i + 48; // 添加小时个位
				--numQuantity[i];
				break;
			}
		}
	}
	else if (!numQuantity[0] && !numQuantity[1])
	{
		return "";
	}
	else
	{
		for (int i = 1;; --i)
		{
			if (numQuantity[i] != 0)
			{
				timeStr += i + 48; // 添加小时十位
				--numQuantity[i];
				break;
			}
		}

		for (int i = 9;; --i)
		{
			if (numQuantity[i] != 0)
			{
				timeStr += i + 48; // 添加小时个位
				--numQuantity[i];
				break;
			}
		}
	}

	// 添加符号
	//timeStr += ":";

	// 分钟处理
	// 剩余两个数字是全部大于等于6
	if (checkWhetherResidualIsAllGreaterThanEqualTo6(numQuantity))
	{
		if (timeStr == "21" || timeStr == "20")
		{
			for (int i = 9;; --i)
			{
				if (numQuantity[i] != 0)
				{
					timeStr += i + 48; // 添加分钟十位
					--numQuantity[i];
					break;
				}
			}
			for (int i = 9;; --i)
			{
				if (numQuantity[i] != 0)
				{
					timeStr += i + 48; // 添加分钟十位
					--numQuantity[i];
					break;
				}
			}
			char temp = timeStr[0];
			timeStr[0] = timeStr[1];
			timeStr[1] = timeStr[2];
			timeStr[2] = temp;
		}
		else
			return "";
	}
	else
	{
		for (int i = 5;; --i)
		{
			if (numQuantity[i] != 0)
			{
				timeStr += i + 48; // 添加分钟十位
				--numQuantity[i];
				break;
			}
		}

		for (int i = 9;; --i)
		{
			if (numQuantity[i] != 0)
			{
				timeStr += i + 48; // 添加分钟个位
				--numQuantity[i];
				break;
			}
		}
	}

	timeStr.insert(2, ":");

	return timeStr;
}

// 检测是否存在符合小于或等于指定指的数字字符  
bool testLessThanSpecifiedNumberExistence(int numQuantity[], int x)
{
	for (int i = 0; i <= x; ++i)
	{
		if (numQuantity[i] > 0)
			return true;
	}
	return false;
}

// 检查剩余两个数字符合是否全部大于等于6
bool checkWhetherResidualIsAllGreaterThanEqualTo6(int numQuantity[])
{
	for (int i = 5; i >= 0; --i)
	{
		if (numQuantity[i])
			return false;
	}
	return true;
}