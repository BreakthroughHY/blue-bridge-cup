#include "concatenate_substrings_of_all_words.h"

int allWordsInSeriesSequenceNumbers()
{
	// 创建对象
	SolutionConcatenateSubstringsWords s;
	vector<string> v;
	v.push_back("good");
	v.push_back("good");
	v.push_back("word");
	v.push_back("best");

	DWORD start_time = GetTickCount();

	printVector(s.findSubstring("wordgoodgoodgoodbestword", v));

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

vector<int> SolutionConcatenateSubstringsWords::findSubstring(string s, vector<string>& words)
{
	const int m = words.size(), n = words[0].size(), ls = s.length();
	vector<int> ret;

	for (int i = 0; i < n && i + n * m - 1 < ls; ++i)
	{
		unordered_map<string, int> diff;
		for (int j = 0; j < m; ++j)
		{
			++diff[s.substr(i + j * n, n)];
		}

		for (auto& str : words)
		{
			if (--diff[str] == 0)
			{
				diff.erase(str);
			}
		}

		for (int start = i; start + m * n <= ls; start += n)
		{
			if (start != i)
			{
				string word = s.substr(start + n * (m - 1), n);
				if (++diff[word] == 0)
					diff.erase(word);

				word = s.substr(start - n, n);
				if (--diff[word] == 0)
					diff.erase(word);
			}
			if (diff.empty())
				ret.push_back(start);
		}
	}
	return ret;
}

void printVector(vector<int> v)
{
	for (auto& i : v)
		cout << i << endl;
}