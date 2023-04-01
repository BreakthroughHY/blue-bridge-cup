#pragma once

#ifndef __SOLVING_SUDOKU_H__
#define __SOLVING_SUDOKU_H__

#include "main.h"
#include "effective_sudoku.h" // 有效的数独	Effective Sudoku  用一下里面的打印函数

// 类声明
class SolutionSolvingSudoku {
private:
    bool row[9][9];
    bool columns[9][9];
    bool check[3][3][9];
    vector<pair<int, int>> spaces;
    bool flag;

public:
    void solveSudoku(vector<vector<char>>& board);

    void dfs(vector<vector<char>>& board, int pos);
};

int theirIndependence();

#endif // !__SOLVING_SUDOKU_H__
