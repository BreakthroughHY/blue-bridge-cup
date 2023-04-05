#pragma once

#ifndef __WORD_CHAIN_H__
#define __WORD_CHAIN_H__

#include <unordered_set>
#include "main.h"

// ÀàÉùÃ÷
class SolutionWordChain {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList);
};

int wordChain();

#endif // !__WORD_CHAIN_H__
