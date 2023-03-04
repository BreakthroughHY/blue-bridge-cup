#pragma once

#ifndef __MAX_TIMEINT_NUMBER_ARRAY_H__
#define __MAX_TIMEINT_NUMBER_ARRAY_H__

#include "vector"
#include "main.h"

// 类声明
class SolutionMaxTime {
public:
    string largestTimeFromDigits(vector<int>& arr);
};

int maximumTimeWithinAnArray();

// 检测是否存在符合小于或等于指定指的数字字符
bool testLessThanSpecifiedNumberExistence(int numQuantity[], int x);

// 检查剩余两个数字符合是否全部大于等于6
bool checkWhetherResidualIsAllGreaterThanEqualTo6(int numQuantity[]);

#endif // !__MAX_TIMEINT_NUMBER_ARRAY_H__
