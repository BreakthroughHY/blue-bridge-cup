#pragma once

#ifndef __DISTURB_STRING_H__
#define __DISTURB_STRING_H__

#include "main.h"
// ������
class SolutionDisturbString {
private:
    string s1, s2;
public:
    bool isScramble(string s1, string s2);
};

int disturbString();

// ������ȱ���
bool dfs(int front, int back, int dividingSubscript);

#endif // !__DISTURB_STRING_H__
