#pragma once

#ifndef __CONCATENATE_SUBSTRINGS_OF_ALL_WORDS_H__
#define __CONCATENATE_SUBSTRINGS_OF_ALL_WORDS_H__

#include <unordered_map>
#include <string>
#include "main.h"

// ÀàÉùÃ÷
class SolutionConcatenateSubstringsWords {
public:
    vector<int> findSubstring(string s, vector<string>& words);
};

int allWordsInSeriesSequenceNumbers();

void printVector(vector<int> v);

#endif // !__CONCATENATE_SUBSTRINGS_OF_ALL_WORDS_H__