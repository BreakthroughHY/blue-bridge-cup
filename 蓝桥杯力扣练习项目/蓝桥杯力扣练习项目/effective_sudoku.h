#pragma once

#ifndef __EFFECTIVE_SUDOKU_H__
#define __EFFECTIVE_SUDOKU_H__

#include "main.h"

// ÀàÉùÃ÷
class SolutionEffectiveSudoku {
public:
    bool isValidSudoku(vector<vector<char>>& board);
};

int validSudoku();

void printV(vector<vector<char>>& board);

#endif // !__EFFECTIVE_SUDOKU_H__
