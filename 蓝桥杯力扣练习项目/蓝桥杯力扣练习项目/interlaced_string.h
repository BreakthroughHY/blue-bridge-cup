#pragma once

#ifndef __INTERLACED_STRING_H__
#define __INTERLACED_STRING_H__

#include "main.h"

// ÀàÉùÃ÷
class SolutionInterlacedString {
private:
    string s1, s2, s3;
    vector<bool> dp;
    int n, m;

public:
    bool isInterleave(string s1, string s2, string s3);

    bool dfs(int s1, int s2, int s3);

    bool fine(int i1, int i2, int i3);
};

int staggeredStr();

#endif // !__INTERLACED_STRING_H__
