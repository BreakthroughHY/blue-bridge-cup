#pragma once

#ifndef __ALPHABETIC_HETEROTOPIC_WORD_GROUPING_H__
#define __ALPHABETIC_HETEROTOPIC_WORD_GROUPING_H__

#include <unordered_map>
#include "main.h"

// ������
class SolutionAlphabeticHeterotopicWordGrouping {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs);

    vector<vector<string>> groupAnagramsLeetcode(vector<string>& strs);

    vector<vector<string>> groupAnagramsLeetCode(vector<string>& strs);
};

int lettersEctopicWordGroups();

// �ж������Ƿ���ͬ
bool comp(unordered_map<int, int>& m1, unordered_map<int, int> m2);

void printV_(vector<vector<string>> v);

#endif // !__ALPHABETIC_HETEROTOPIC_WORD_GROUPING_H__
