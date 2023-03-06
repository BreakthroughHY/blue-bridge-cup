#pragma once

#ifndef __CONNECTED_TO_RAINWATER_H__
#define __CONNECTED_TO_RAINWATER_H__

#include <vector>
#include "main.h"

// 类构建
class SolutionConnectedRainwater {
public:
    int trap(vector<int>& height);
};

int afterRain();

// 对数组指定区间求和 (前闭区间，后开区间)
int arraySumSpecifiedInterval(vector<int>& v, int front, int back);

#endif // !__CONNECTED_TO_RAINWATER_H__
