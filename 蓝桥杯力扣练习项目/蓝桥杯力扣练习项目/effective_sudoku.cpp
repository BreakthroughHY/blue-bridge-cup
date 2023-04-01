#include "effective_sudoku.h"

int validSudoku()
{
	// 创建对象
	SolutionEffectiveSudoku s;

	vector<vector<char>> v;

	/*v = { {'5','3','.','.','7','.','.','.','.'}
	,{'6','.','.','1','9','5','.','.','.'}
	,{'.','9','8','.','.','.','.','6','.'}
	,{'8','.','.','.','6','.','.','.','3'}
	,{'4','.','.','8','.','3','.','.','1'}
	,{'7','.','.','.','2','.','.','.','6'}
	,{'.','6','.','.','.','.','2','8','.'}
	,{'.','.','.','4','1','9','.','.','5'}
	,{'.','.','.','.','8','.','.','7','9'} };*/

	v = { {'8','3','.','.','7','.','.','.','.'}
,{'6','.','.','1','9','5','.','.','.'}
,{'.','9','8','.','.','.','.','6','.'}
,{'8','.','.','.','6','.','.','.','3'}
,{'4','.','.','8','.','3','.','.','1'}
,{'7','.','.','.','2','.','.','.','6'}
,{'.','6','.','.','.','.','2','8','.'}
,{'.','.','.','4','1','9','.','.','5'}
,{'.','.','.','.','8','.','.','7','9'} };

	printV(v);

	DWORD start_time = GetTickCount();

	cout << s.isValidSudoku(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

bool SolutionEffectiveSudoku::isValidSudoku(vector<vector<char>>& board)
{
	int rowValueFreq[9][9];
	int columnsValueFreq[9][9];
	int checkValueFreq[3][3][9];

	memset(rowValueFreq, -1, sizeof(rowValueFreq));
	memset(columnsValueFreq, -1, sizeof(columnsValueFreq));
	memset(checkValueFreq, -1, sizeof(checkValueFreq));

	// 遍历每一个小方格内的数据，(只遍历一次，有点动态规划的那味了，牺牲空间换时间)
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			char ch = board[i][j];
			if (ch != '.')
			{
				int index = ch - '0' - 1;
				++rowValueFreq[i][index];
				++columnsValueFreq[j][index];
				++checkValueFreq[i / 3][j / 3][index];
				if (rowValueFreq[i][index] || columnsValueFreq[j][index] || checkValueFreq[i / 3][j / 3][index])
					return false;
			}
		}
	}

	return true;
}

void printV(vector<vector<char>>& board)
{
	for (auto& l : board)
	{
		for (auto& c : l)
		{
			cout << c << "	";
		}
		cout << endl;
	}
}