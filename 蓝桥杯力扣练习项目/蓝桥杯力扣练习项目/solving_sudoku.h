#pragma once

#ifndef __SOLVING_SUDOKU_H__
#define __SOLVING_SUDOKU_H__

#include "main.h"
#include "effective_sudoku.h" // ��Ч������	Effective Sudoku  ��һ������Ĵ�ӡ����

// ������
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
