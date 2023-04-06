#pragma once

#ifndef __YANG_HUI_TRIANGLE_H__
#define __YANG_HUI_TRIANGLE_H__

#include "main.h"

// ÀàÉùÃ÷
class SolutionYangHuiTriangle {
public:
    vector<vector<int>> generate(int numRows);

    void printV(vector<vector<int>>& v);
};

int yangHuiTriangle();

#endif // !__YANG_HUI_TRIANGLE_H__
