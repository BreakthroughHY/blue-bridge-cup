#pragma once

#ifndef __MAXIMUM_SUBARRAY_AND_H__
#define __MAXIMUM_SUBARRAY_AND_H__

#include "main.h"

// 类声明
class SolutionMaximumSubarrayAnd {
public:
    int maxSubArray(vector<int>& nums);
};

int architecturalTheArray();

// 正向递归
int positiveNegativeIntervalLessThanZero(vector<int>& nums, int front, int back);

// 不厌恶函数
int positiveNegativeToRangeIsNotNegative(vector<int>& nums, int front, int back, int value);

#endif // !__MAXIMUM_SUBARRAY_AND_H__
