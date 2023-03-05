#pragma once

#ifndef __BRACKET_GENERATING_H__
#define __BRACKET_GENERATING_H__

#include <vector>
#include <stack>
#include "main.h"

class SolutionBracketGenerating {
public:
    vector<string> generateParenthesis(int n);
};

int parenthesesGenerates();

void throughVector(vector<string>& v); // ±éÀúÈÝÆ÷

void recursiveBrackets(vector<string>& v, stack<char> stack_, string s, int n);

#endif // !__BRACKET_GENERATING_H__
