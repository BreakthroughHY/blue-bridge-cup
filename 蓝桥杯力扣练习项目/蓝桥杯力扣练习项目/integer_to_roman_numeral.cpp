#include "integer_to_roman_numeral.h"
//#include <unordered_map>
#include <algorithm>

int integerRomaNum()
{
	// 创建对象
	SolutionIntRomanNum s;

	DWORD start_time = GetTickCount();

	cout << s.intToRoman(911) << endl;
	/*for (int i = 1; i < 4000; ++i)
		cout << s.intToRoman(i) << endl;*/

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

string SolutionIntRomanNum::intToRoman(int num)
{
	map<int, string> m; // 创建队组容器

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

	for (auto a : m)
		cout << a.first << "		" << a.second << endl;
	/*for (map<int, string>::iterator it = --m.end(); it != m.begin(); --it)
	{
		while (num >= (*it).first)
		{
			num -= (*it).first;
			ret += (*it).second;
		}

		if (num == 0)
			return ret;
	}*/

	for (map<int, string>::reverse_iterator it = m.rbegin(); it != m.rend(); ++it)
	{
		while (num >= it->first)
		{
			num -= it->first;
			ret += it->second;
		}

		if (num == 0)
			return ret;
	}

	return "";
}