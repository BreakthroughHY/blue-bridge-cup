#pragma once

#ifndef __MAXIMUM_SUBARRAY_AND_H__
#define __MAXIMUM_SUBARRAY_AND_H__

#include "main.h"

// ������
class SolutionMaximumSubarrayAnd {
public:
    int maxSubArray(vector<int>& nums);
};

int architecturalTheArray();

// ����ݹ�
int positiveNegativeIntervalLessThanZero(vector<int>& nums, int front, int back);

// �������
int positiveNegativeToRangeIsNotNegative(vector<int>& nums, int front, int back, int value);

// ��̬�滮������
int dynamicProgrammingMethodViolence(vector<int>& nums);

#endif // !__MAXIMUM_SUBARRAY_AND_H__
