#pragma once

#ifndef __WORD_RELAY_II_H__
#define __WORD_RELAY_II_H__

#include <set>
#include <unordered_set>
#include "main.h"

// 类声明
class SolutionWordRelayII {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList);

    // 打印二维vector容器
    void printVector(vector<vector<string>>& v);
};

int randomlyII();

void backtrack(vector<vector<string>>& ans, unordered_map<string, set<string>>& from, vector<string> vTemp, string str);

#endif // !__WORD_RELAY_II_H__
