#pragma once

#ifndef __MINIMUM_COVER_SUBSTRING_H__
#define __MINIMUM_COVER_SUBSTRING_H__

#include <unordered_map>
#include <string>
#include "main.h"

// 类声明
class SolutionMinimumCoverSubstring {
public:
    string minWindow(string s, string t);
};

int minimumCoverSubstring();

// 检查无序map容器内是否全部为非负数
bool isAllNonnegative(unordered_map<char, int>& freq);

#endif // !__MINIMUM_COVER_SUBSTRING_H__
