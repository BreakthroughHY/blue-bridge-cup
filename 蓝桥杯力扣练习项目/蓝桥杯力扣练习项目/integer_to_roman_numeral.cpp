#include "integer_to_roman_numeral.h"
#include <algorithm>

int integerRomaNum()
{
	// 创建对象
	SolutionIntRomanNum s;

	DWORD start_time = GetTickCount();

	cout << s.intToRoman(911) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

string SolutionIntRomanNum::intToRoman(int num)
{
	map<int, string> m; // 创建队组容器

	m[0] = "";
	m[1] = "I";
	m[4] = "IV";
	m[5] = "V";
	m[9] = "IX";
	m[10] = "X";
	m[40] = "XL";
	m[50] = "L";
	m[90] = "XC";
	m[100] = "C";
	m[400] = "CD";
	m[500] = "D";
	m[900] = "CM";
	m[1000] = "M";
	
	string ret = "";

	for (map<int, string>::iterator it = --m.end(); it != m.begin(); --it)
	{
		//cout << (*it).first << "	" << (*it).second << endl;
		while (num >= (*it).first)
		{
			num -= num;
			ret += (*it).second;
		}

		if (num == 0)
			return ret;
	}

	return "";
}