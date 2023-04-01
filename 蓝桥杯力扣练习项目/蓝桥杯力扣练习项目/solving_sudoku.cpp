#include "solving_sudoku.h"

int theirIndependence()
{
	// ��������
	SolutionSolvingSudoku s;
	vector<vector<char>> v;

	v = { {'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'} };

	printV(v);

	DWORD start_time = GetTickCount();

	s.solveSudoku(v);

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

	printV(v);

	return 0;
}

void SolutionSolvingSudoku::solveSudoku(vector<vector<char>>& board)
{
	memset(row, false, sizeof(row));
	memset(columns, false, sizeof(columns));
	memset(check, false, sizeof(check));
	flag = true; // ���Ƽ�¼�Ƿ�δ�ҵ��𰸣��ҵ��𰸺��ʹ���򾡿���������ٲ���Ҫ��ִ������

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			char ch = board[i][j];
			if (ch != '.')
			{
				int index = ch - '1';
				row[i][index] = columns[j][index] = check[i / 3][j / 3][index] = true;
			}
			else
			{
				spaces.emplace_back(i, j);
			}
		}
	}

	dfs(board, 0);
}

void SolutionSolvingSudoku::dfs(vector<vector<char>>& board, int pos)
{
	if (pos == spaces.size())
	{
		flag = false; // �Ѿ��ҵ���
		return;
	}

	int i = spaces.at(pos).first, j = spaces.at(pos).second;

	for (int possible = 0; flag && possible < 9; ++possible)
	{
		if (!row[i][possible] && !columns[j][possible] && !check[i / 3][j / 3][possible])
		{
			row[i][possible] = columns[j][possible] = check[i / 3][j / 3][possible] = true;
			board[i][j] = possible + '1';
			dfs(board, pos + 1);
			row[i][possible] = columns[j][possible] = check[i / 3][j / 3][possible] = false;
		}
	}
}
