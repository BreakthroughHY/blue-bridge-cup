#include "super_number_palindromes.h"

int superNumberPalindromes()
{
	// ������
	SolutionSuperNumberPalindromes s;

	DWORD start_time = GetTickCount();

	cout << "������������" << s.superpalindromesInRange("40000000000000000", "50000000000000000") << "����" << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

	return 0;
}

int SolutionSuperNumberPalindromes::superpalindromesInRange(string left, string right)
{
	int i = 0;
	int count = 0;
	long long front = stoll(left), back = stoll(right); // �������ַ���ת��Ϊ����    // �з�Χ���ƣ�����������Χ������������걨��
	cout << back << endl;
	for (int i = sqrt(front); i * i <= back; ++i)
	{
		cout << i << endl;
		if (i * i >= front)
		{
			if (isNumberPalindromes(i) && isNumberPalindromes(i * i))
				++count;
		}
	}

	return count;
}

// ���������ж��Ƿ�Ϊ������
bool isNumberPalindromes(int x)
{
	string numStr = to_string(x);
	int front = 0, back = numStr.size() - 1; // ��¼�ַ�����ͷβ
	for (; front < back; ++front, --back)
	{
		if (numStr[front] != numStr[back])
			return false;
	}

	return true;
 }