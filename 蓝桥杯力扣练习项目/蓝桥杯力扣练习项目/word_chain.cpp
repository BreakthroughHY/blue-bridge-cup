#include "word_chain.h"

int wordChain()
{
	// 创建对象
	SolutionWordChain s;
	vector<string> v;

	v = { "hot","dot","dog","lot","log","cog" };

	DWORD start_time = GetTickCount();

	cout << s.ladderLength("hit", "cog", v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

int SolutionWordChain::ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	unordered_set<string> dict = { wordList.begin(), wordList.end() };

	queue<string> q{ {beginWord} };

	int wordLen = beginWord.size();
	int setp = 1;

	while (!q.empty())
	{
		++setp;
		int size = q.size();
		for (int i = 0; i < size; ++i)
		{
			string nextWord = move(q.front());
			q.pop();
			for (int j = 0; j < wordLen; ++j)
			{
				const char origin = nextWord[j];
				for (int c = 'a'; c <= 'z'; ++c)
				{
					nextWord[j] = c;
					if (dict.find(nextWord) == dict.end())
					{
						continue;
					}
					dict.erase(nextWord);
					q.push(nextWord);
					if (nextWord == endWord)
						return setp;
				}
				nextWord[j] = origin;
			}
		}
	}

	return 0;
}