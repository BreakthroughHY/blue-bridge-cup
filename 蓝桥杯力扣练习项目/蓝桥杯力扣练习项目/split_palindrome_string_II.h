#pragma once

#ifndef __SPLIT_PALINDROME_STRING_II_H__
#define __SPLIT_PALINDROME_STRING_II_H__

#include <unordered_map> // 无序哈希表
#include "main.h"

// 类声明
class SolutionSplitPalindromeStrinII {
private:
    unordered_map<int, vector<int>> uMap;
public:
    int minCut(string s);
};

int segmentationPalindromeSeriesII();

#endif // !__SPLIT_PALINDROME_STRING_II_H__
