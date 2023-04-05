#pragma once

#ifndef __LONGEST_CONTINUOUS_SEQUENCE_H__
#define __LONGEST_CONTINUOUS_SEQUENCE_H__

#include <unordered_set>
#include "main.h"

// ÀàÉùÃ÷
class SolutionLongestContinuousSequence {
public:
    int longestConsecutive(vector<int>& nums);

    int longestConsecutiveNew(vector<int>& nums);
};

int longestContinuousSequence();

#endif // !__LONGEST_CONTINUOUS_SEQUENCE_H__
