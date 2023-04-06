#include "yang_hui_triangle.h"

int yangHuiTriangle()
{
	// 创建对象
	SolutionYangHuiTriangle s;
	vector<vector<int>> v;

	DWORD start_time = GetTickCount();

	v = s.generate(5);

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	s.printV(v);

	return 0;
}

vector<vector<int>> SolutionYangHuiTriangle::generate(int numRows)
{
	vector<vector<int>> ans{ {1} };
	vector<int> temp;

	for (int i = 1; i < numRows; ++i)
	{
		temp.emplace_back(1);
		for (int j = 1; j < i; ++j)
		{
			temp.emplace_back(ans[i - 1][j - 1] + ans[i - 1][j]);
		}
		temp.emplace_back(1);
		ans.emplace_back(temp.begin(), temp.end());
		temp.clear();
	}

	return ans;
}

void SolutionYangHuiTriangle::printV(vector<vector<int>>& v)
{
	for (auto& fa : v)
	{
		for (auto& so : fa)
		{
			cout << so << "	";
		}
		cout << endl;
	}
}