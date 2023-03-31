#include "roman_numeral_to_integer.h"

int romanNumeralToInteger()
{
	// ��������
	SolutionRomanNumeralToInteger s;

	DWORD start_time = GetTickCount();

	//cout << s.romanToInt("CMXI") << endl;
	cout << s.romanToIntNew("CMXI") << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

	return 0;
}

int SolutionRomanNumeralToInteger::romanToInt(string s)
{
	map<int, string> m; // ������������

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

	int strLen = s.size();
	int ret = 0;
	int l = 0; // �ַ�����ǰ���λ��

	for (map<int, string>::reverse_iterator rit = m.rbegin(); rit != m.rend(); ++rit)
	{
		if (rit->second.size() >= 2 && strLen - l < 2)
			continue;
		bool flag = true;
		while (flag)
		{
			for (int i = 0; i < rit->second.size(); ++i)
			{
				if (s[l + i] != rit->second[i])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				ret += rit->first;
				l += rit->second.size();
			}
		}
	}

	return ret;
}

// ��������ṩ����˼·Java����ʵ�ֶ�Ӧ��C++����
int SolutionRomanNumeralToInteger::romanToIntNew(string s)
{
	unordered_map<char, int> uMap;

	uMap['I'] = 1;
	uMap['V'] = 5;
	uMap['X'] = 10;
	uMap['L'] = 50;
	uMap['C'] = 100;
	uMap['D'] = 500;
	uMap['M'] = 1000;

	int ret = 0;

	int lastCharValue = INT_MAX; // ��¼�ϸ��ַ�
	for (int i = 0; i < s.size(); ++i)
	{
		ret += uMap[s[i]];
		if (uMap[s[i]] > lastCharValue)
			ret -= (2 * lastCharValue);
		lastCharValue = uMap[s[i]];
	}

	return ret;
}