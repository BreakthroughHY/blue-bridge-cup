#pragma once

#ifndef  __ROMAN_NUMERAL_TO_INTEGER_H__
#define __ROMAN_NUMERAL_TO_INTEGER_H__

#include <unordered_map>
#include "main.h"

// 类声明
class SolutionRomanNumeralToInteger {
public:
    int romanToInt(string s);

    int romanToIntNew(string s); // 根据题解提供的新思路Java代码实现对应的C++代码
};

int romanNumeralToInteger();

#endif // ! __ROMAN_NUMERAL_TO_INTEGER_H__
