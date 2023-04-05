#include "word_relay_II.h"

int randomlyII()
{
	// ��������
	SolutionWordRelayII s;
	vector<string> v;
	vector<vector<string>> vv;

	v = { "hot","dot","dog","lot","log","cog" };

	DWORD start_time = GetTickCount();

	vv = s.findLadders("hit", "cog", v);

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

	s.printVector(vv);

	return 0;
}

vector<vector<string>> SolutionWordRelayII::findLadders(string beginWord, string endWord, vector<string>& wordList)
{
	vector<vector<string>> ans;

	unordered_set<string> dict = { wordList.begin(), wordList.end() };

	if (dict.find(endWord) == dict.end()) // ������ֵ��в�����Ŀ���ַ��������Բ����ܴ���ת��·��
	{
		return ans;
	}

	dict.erase(beginWord);

	unordered_map<string, int> steps{ {beginWord, 0} };
	unordered_map<string, set<string>> from{ {beginWord, {}} };
	queue<string> q{ {beginWord} };

	int step = 0;
	int wordLen = beginWord.size();
	bool flag = false;
	while (!q.empty())
	{
		++step;
		int size = q.size();
		for (int i = 0; i < size; ++i)
		{
			const string currWord = move(q.front());
			string nextWord = currWord;
			q.pop();
			for (int j = 0; j < wordLen; ++j)
			{
				const char origin = nextWord[j];
				for (int c = 'a'; c <= 'z'; ++c)
				{
					nextWord[j] = c;
					if (steps[nextWord] == step)
					{
						from[nextWord].insert(currWord);
					}
					if (dict.find(nextWord) == dict.end()) // �ֵ��в������µ���ֱ�ӽ���ѭ����ִ��
					{
						continue;
					}

					dict.erase(nextWord);

					q.push(nextWord);

					from[nextWord].insert(currWord);

					steps[nextWord] = step;

					if (nextWord == endWord)
					{
						flag = true;
					}
				}
				nextWord[j] = origin;
			}
		}
		if (flag)
		{
			break;
		}
	}

	if (flag)
	{
		vector<string> vTemp{ {endWord} };

		backtrack(ans, from, vTemp, endWord);
	}

	return ans;
}

void backtrack(vector<vector<string>>& ans, unordered_map<string, set<string>>& from, vector<string> vTemp, string str)
{
	if (from[str].empty())
	{
		ans.push_back({ vTemp.rbegin(), vTemp.rend() });
		return;
	}
	for (const string& s : from[str])
	{
		vTemp.push_back(s);
		backtrack(ans, from, vTemp, s);
		vTemp.pop_back();
	}
}

// ��ӡ��άvector����
void SolutionWordRelayII::printVector(vector<vector<string>>& v)
{
	for (auto fa : v)
	{
		for (auto so : fa)
		{
			cout << so << "	 ";
		}
		cout << endl;
	}
	cout << "��άvector������ӡ��ɣ�" << endl;
}