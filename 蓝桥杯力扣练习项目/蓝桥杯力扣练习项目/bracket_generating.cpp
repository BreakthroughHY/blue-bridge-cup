#include "bracket_generating.h"

int parenthesesGenerates()
{
	// ���������
	SolutionBracketGenerating s;

	DWORD start_time = GetTickCount();

	//cout << s.generateParenthesis(2).at(0) << endl;
	vector<string> ss = s.generateParenthesis(10);
	//throughVector(ss);

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

	return 0;
}

vector<string> SolutionBracketGenerating::generateParenthesis(int n)
{
	stack<char> stack_;

	vector<string> v;

	string intermediateStr("("); // ��ӵ�һ��������
	--n; // ������������һ
	stack_.push(')'); // �����ŵ���һ������ջ��

	recursiveBrackets(v, stack_, intermediateStr, n);

	return v;
}

// ����vector����
void throughVector(vector<string>& v)
{
	cout << "�����������!" << endl;
	int i = 0;
	for (vector<string>::iterator itBegin = v.begin(); itBegin != v.end(); ++itBegin)
	{
		cout << ++i << *itBegin << endl;
	}
}

// ���ŵݹ� ��������10 ִ��ʱ��500ms
void recursiveBrackets(vector<string>& v, stack<char> stack_, string s, int n)
{
	stack<char> stack_n(stack_); // ������������if�������޸����ݵ��������ֹ�����޸ĺ��޷�ʹ��
	string ss(s); // ��������
	if (!stack_.empty())
	{
		s += ')';
		stack_.pop();
		if (!n && stack_.empty()) // ���ۺ���������һ������һ��Ϊ ��)�� ����һ����֧�������ж�Ҫ����ӡ�)�����ж�
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