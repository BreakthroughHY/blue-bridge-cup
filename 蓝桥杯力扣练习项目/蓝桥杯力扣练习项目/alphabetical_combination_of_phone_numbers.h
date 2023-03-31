#pragma once

#ifndef __ALPHABETICAL_COMBINATION_OF_PHONE_NUMBERS_H__
#define __ALPHABETICAL_COMBINATION_OF_PHONE_NUMBERS_H__

#include <unordered_map>
#include "main.h"

// ÀàÉùÃ÷
class SolutionNumberLetterCombinations {
public:
    vector<string> letterCombinations(string digits);
};

int numberLetterCombinations();

void printVector(vector<string>& v);

void dfs(vector<string>& retV, unordered_map<int, string>& uMap, int index, string& digits, string strTemp);

#endif // !__ALPHABETICAL_COMBINATION_OF_PHONE_NUMBERS_H__