#include "alphabetical_combination_of_phone_numbers.h"

int numberLetterCombinations()
{
	// 创建对象
	SolutionNumberLetterCombinations s;
	vector<string> v;

	DWORD start_time = GetTickCount();

	v = s.letterCombinations("2379");

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	printVector(v);

	return 0;
}

vector<string> SolutionNumberLetterCombinations::letterCombinations(string digits)
{
	vector<string> retV;
	unordered_map<int, string> uMap;
	int index = 0;
	string strTemp = "";

	if (digits.empty())
		return retV;

	uMap = { {'2' , "abc"},
		{'3' , "def"},
		{'4' , "ghi"},
		{'5' , "jkl"},
		{'6' , "mno"},
		{'7' , "pqrs"},
		{'8' , "tuv"},
		{'9' , "wxyz"}
	};

	dfs(retV, uMap, index, digits, strTemp);

	return retV;
}

void dfs(vector<string>& retV, unordered_map<int, string>& uMap, int index, string& digits, string strTemp)
{
	if (index == digits.size())
	{
		retV.push_back(strTemp);
		return;
	}
	else
	{
		string temp;
		for (int i = 0; i < uMap[digits[index]].size(); ++i)
		{
			temp = strTemp;
			dfs(retV, uMap, (index + 1), digits, temp += uMap[digits[index]][i]);
		}
	}
}

void printVector(vector<string>& v)
{
	for (auto it = v.begin(); it != v.end(); ++it)
		cout << *it << endl;
}