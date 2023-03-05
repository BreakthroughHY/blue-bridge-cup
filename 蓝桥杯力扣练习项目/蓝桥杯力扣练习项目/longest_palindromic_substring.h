#pragma once

#ifndef __LONGEST_PALINDROMIC_SUBSTRING_H__
#define __LONGEST_PALINDROMIC_SUBSTRING_H__

#include "main.h"

// ÀàÉùÃ÷
class SolutionLongestPalindromicSubstring {
public:
    string longestPalindrome(string s);
};

int backToLongestTextStr();

int launchCenter(string& s, int left, int right);

#endif // !__LONGEST_PALINDROMIC_SUBSTRING_H__
