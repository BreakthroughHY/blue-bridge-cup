#include "bracket_generating.h"

int parenthesesGenerates()
{
	// 创建类对象
	SolutionBracketGenerating s;

	DWORD start_time = GetTickCount();

	//cout << s.generateParenthesis(2).at(0) << endl;
	vector<string> ss = s.generateParenthesis(10);
	//throughVector(ss);

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

vector<string> SolutionBracketGenerating::generateParenthesis(int n)
{
	stack<char> stack_;

	vector<string> v;

	string intermediateStr("("); // 添加第一个左括号
	--n; // 左括号数量减一
	stack_.push(')'); // 将括号的另一半推入栈内

	recursiveBrackets(v, stack_, intermediateStr, n);

	return v;
}

// 遍历vector容器
void throughVector(vector<string>& v)
{
	cout << "容器遍历结果!" << endl;
	int i = 0;
	for (vector<string>::iterator itBegin = v.begin(); itBegin != v.end(); ++itBegin)
	{
		cout << ++i << *itBegin << endl;
	}
}

// 括号递归 输入数据10 执行时间500ms
void recursiveBrackets(vector<string>& v, stack<char> stack_, string s, int n)
{
	stack<char> stack_n(stack_); // 备份数据两个if都都有修改数据的情况，防止数据修改后无法使用
	string ss(s); // 备份数据
	if (!stack_.empty())
	{
		s += ')';
		stack_.pop();
		if (!n && stack_.empty()) // 无论和中情况最后一个符号一定为 ‘)’ 所有一条分支结束的判定要在添加‘)’后判定
		{
			v.push_back(s);
			return;
		}
		recursiveBrackets(v, stack_, s, n);
	}

	if (n)
	{
		--n;
		ss += '(';
		stack_n.push(')');
		recursiveBrackets(v, stack_n, ss, n);
	}
}