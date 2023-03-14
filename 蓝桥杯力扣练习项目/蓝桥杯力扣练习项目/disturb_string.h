#pragma once

#ifndef __DISTURB_STRING_H__
#define __DISTURB_STRING_H__

#include "main.h"
// 类声明
class SolutionDisturbString {
private:
    string s1, s2;
public:
    bool isScramble(string s1, string s2);
};

int disturbString();

// 深度优先遍历
bool dfs(int front, int back, int dividingSubscript);

#endif // !__DISTURB_STRING_H__
