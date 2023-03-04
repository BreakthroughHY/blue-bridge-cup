#include "super_number_palindromes.h"

int superNumberPalindromes()
{
	// 创建类
	SolutionSuperNumberPalindromes s;

	DWORD start_time = GetTickCount();

	cout << "符合条件的有" << s.superpalindromesInRange("40000000000000000", "50000000000000000") << "个。" << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

int SolutionSuperNumberPalindromes::superpalindromesInRange(string left, string right)
{
	int i = 0;
	int count = 0;
	long long front = stoll(left), back = stoll(right); // 将数字字符串转换为整型    // 有范围限制，参数超出范围报错，参数不达标报错
	cout << back << endl;
	for (int i = sqrt(front); i * i <= back; ++i)
	{
		cout << i << endl;
		if (i * i >= front)
		{
			if (isNumberPalindromes(i) && isNumberPalindromes(i * i))
				++count;
		}
	}

	return count;
}

// 传入数字判断是否为回文数
bool isNumberPalindromes(int x)
{
	string numStr = to_string(x);
	int front = 0, back = numStr.size() - 1; // 记录字符串的头尾
	for (; front < back; ++front, --back)
	{
		if (numStr[front] != numStr[back])
			return false;
	}

	return true;
 }