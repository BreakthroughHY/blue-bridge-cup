#include "yang_hui_triangle_II.h"

int yangHuiTriangleII()
{
	// 创建对象
	SolutionYangHuiTriangleII s;
	vector<int> v;

	DWORD start_time = GetTickCount();

	v = s.getRow(5);

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	s.printV(v);

	return 0;
}

// 还可以再优化只使用一个数组
vector<int> SolutionYangHuiTriangleII::getRow(int rowIndex)
{
	vector<int> ret{ {1} }, temp;

	for (int i = 1;; ++i)
	{
		if (i - 1 == rowIndex)
			return ret;
		temp.clear();
		temp.swap(ret);

		ret.emplace_back(1);
		for (int j = 1; j < i; ++j)
		{
			ret.emplace_back(temp[j - 1] + temp[j]);
		}
		ret.emplace_back(1);
	}

	return ret;
}

void SolutionYangHuiTriangleII::printV(vector<int>& v)
{
	for (auto a : v)
		cout << a << "	";
	cout << endl;
}