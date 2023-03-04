#pragma once

#ifndef __COUNT_PRIME_H__
#define __COUNT_PRIME_H__

#include "main.h"

// 声明类
class Solution {
public:
    Solution() // 构造函数，目前写不写都行，没有影响
    {
        
    }

    int countPrimes(int n); // 类方法类内声明，类外实现

    int countPrimesLeetCode(int n); // 类方法类内声明，类外实现
};

int countPrime();

bool isPrime(int x);

#endif // !__COUNT_PRIME_H__
