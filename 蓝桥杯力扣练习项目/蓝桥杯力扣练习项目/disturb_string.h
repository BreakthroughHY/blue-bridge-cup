#pragma once

#ifndef __DISTURB_STRING_H__
#define __DISTURB_STRING_H__

#include <algorithm>
#include <unordered_map> // ����ӳ��
#include "main.h"
// ������
class SolutionDisturbString {
private:
    string s1, s2;

    int memo[30][30][31];
public:
    bool isScramble(string s1, string s2);

    // ������ȱ���
    bool dfs(int front, int back, int dividingSubscript);

    // ����ַ����ڵ������ַ��Ƿ���ͬ
    bool checkIfSimilar(int i1, int i2, int length);
};

int disturbString();

#endif // !__DISTURB_STRING_H__
