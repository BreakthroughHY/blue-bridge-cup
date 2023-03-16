#pragma once

#ifndef __DISTURB_STRING_H__
#define __DISTURB_STRING_H__

#include <algorithm>
#include <unordered_map> // 无序映射
#include "main.h"
// 类声明
class SolutionDisturbString {
private:
    string s1, s2;

    int memo[30][30][31];
public:
    bool isScramble(string s1, string s2);

    // 深度优先遍历
    bool dfs(int front, int back, int dividingSubscript);

    // 检测字符串内的数字字符是否相同
    bool checkIfSimilar(int i1, int i2, int length);
};

int disturbString();

#endif // !__DISTURB_STRING_H__
