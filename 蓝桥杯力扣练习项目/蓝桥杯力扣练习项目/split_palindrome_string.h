#pragma once

#ifndef __SPLIT_PALINDROME_STRING_H__
#define __SPLIT_PALINDROME_STRING_H__

#include <unordered_map>
#include "main.h"

// ÀàÉùÃ÷
class SolutionSplitPalindromeString {
private:
    vector<vector<string>> ret;
    unordered_map<int, vector<int>> dict;
public:
    vector<vector<string>> partition(string s);

    void printV(vector<vector<string>>& v);

    void dfs(vector<string>& temp, int left, string& s);
};

int splitPalindromeString();

#endif // !__SPLIT_PALINDROME_STRING_H__
