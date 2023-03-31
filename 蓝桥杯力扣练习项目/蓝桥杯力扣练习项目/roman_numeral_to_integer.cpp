#include "roman_numeral_to_integer.h"

int romanNumeralToInteger()
{
	// 创建对象
	SolutionRomanNumeralToInteger s;

	DWORD start_time = GetTickCount();

	cout << s.romanToInt("CMXI") << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

int SolutionRomanNumeralToInteger::romanToInt(string s)
{
	map<int, string> m; // 创建队组容器

	/*m["I"] = 1;
	m["IV"] = 4;
	m["V"] = 5;
	m["IX"] = 9;
	m["X"] = 10;
	m["XL"] = 40;
	m["L"] = 50;
	m["XC"] = 90;
	m["C"] = 100;
	m["CD"] = 400;
	m["D"] = 500;
	m["CM"] = 900;
	m["M"] = 1000;*/

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

	int ret = 0;
	int l = 0; // 字符串当前检测位置
	bool flag = true;

	for (map<int, string>::reverse_iterator rit = m.rbegin(); rit != m.rend(); ++rit)
	{
		while (flag)
		{
			
		}
	}

	return 1;
}