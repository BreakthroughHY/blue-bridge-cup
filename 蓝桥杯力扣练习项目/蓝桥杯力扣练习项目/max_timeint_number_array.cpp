#include "max_timeint_number_array.h"

int maximumTimeWithinAnArray()
{
	// ������
	SolutionMaxTime s;
	vector<int> v;
	/*int num[4] = { 7,7,0,6 };
	for (int i = 0; i < 4; ++i)
	{
		v.push_back(num[i]);
	}*/
	

	DWORD start_time = GetTickCount();

	//cout << s.largestTimeFromDigits(v) << endl;
	int count = 0;
	// �ϵ�ǿ��
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			for (int k = 0; k < 9; ++k)
			{
				for (int l = 0; l < 9; ++l)
				{
					v.push_back(i);
					v.push_back(j);
					v.push_back(k);
					v.push_back(l);
					string ss = s.largestTimeFromDigits(v);
					if (!ss.empty())
					{
						++count;
						cout << ss << endl;
					}
					

					for (int a = 0; a < 4; ++a)
						v.pop_back();
				}
			}
		}
	}

	cout << "�������" << count << "�ֽ����" << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

	return 0;
}

// ����Ŀ�꣺д����д�������Ч�ĳ��򣬲����Ǵ������Ϳ���ʱ�䡣     ������룺ѹե����Ա
string SolutionMaxTime::largestTimeFromDigits(vector<int>& arr)
{
	int numQuantity[10] = { 0 };
	string timeStr; // ʱ���ַ���

	// ��ȡͳ�������ַ�������
	for (int i = 0; i < 4; ++i) // Ϊɶѭ��4�Σ���Ϊ��Ŀ˵��
	{
		++numQuantity[arr[i]];
	}

	// Сʱ����
	// �ж�Сʱ�Ƿ���2��ʮλ
	if (numQuantity[2] >= 2 || numQuantity[2] == 1 && (numQuantity[3] != 0 || numQuantity[1] != 0 || numQuantity[0] != 0))
	{
		timeStr += 2 + 48; // ���Сʱʮλ
		--numQuantity[2];


		for (int i = 3;; --i)
		{
			if (numQuantity[i] != 0)
			{
				timeStr += i + 48; // ���Сʱ��λ
				--numQuantity[i];
				break;
			}
		}
	}
	else if (!numQuantity[0] && !numQuantity[1])
	{
		return "";
	}
	else
	{
		for (int i = 1;; --i)
		{
			if (numQuantity[i] != 0)
			{
				timeStr += i + 48; // ���Сʱʮλ
				--numQuantity[i];
				break;
			}
		}

		for (int i = 9;; --i)
		{
			if (numQuantity[i] != 0)
			{
				timeStr += i + 48; // ���Сʱ��λ
				--numQuantity[i];
				break;
			}
		}
	}

	// ��ӷ���
	//timeStr += ":";

	// ���Ӵ���
	// ʣ������������ȫ�����ڵ���6
	if (checkWhetherResidualIsAllGreaterThanEqualTo6(numQuantity))
	{
		if (timeStr == "21" || timeStr == "20")
		{
			for (int i = 9;; --i)
			{
				if (numQuantity[i] != 0)
				{
					timeStr += i + 48; // ��ӷ���ʮλ
					--numQuantity[i];
					break;
				}
			}
			for (int i = 9;; --i)
			{
				if (numQuantity[i] != 0)
				{
					timeStr += i + 48; // ��ӷ���ʮλ
					--numQuantity[i];
					break;
				}
			}
			char temp = timeStr[0];
			timeStr[0] = timeStr[1];
			timeStr[1] = timeStr[2];
			timeStr[2] = temp;
		}
		else
			return "";
	}
	else
	{
		for (int i = 5;; --i)
		{
			if (numQuantity[i] != 0)
			{
				timeStr += i + 48; // ��ӷ���ʮλ
				--numQuantity[i];
				break;
			}
		}

		for (int i = 9;; --i)
		{
			if (numQuantity[i] != 0)
			{
				timeStr += i + 48; // ��ӷ��Ӹ�λ
				--numQuantity[i];
				break;
			}
		}
	}

	timeStr.insert(2, ":");

	return timeStr;
}

// ����Ƿ���ڷ���С�ڻ����ָ��ָ�������ַ�  
bool testLessThanSpecifiedNumberExistence(int numQuantity[], int x)
{
	for (int i = 0; i <= x; ++i)
	{
		if (numQuantity[i] > 0)
			return true;
	}
	return false;
}

// ���ʣ���������ַ����Ƿ�ȫ�����ڵ���6
bool checkWhetherResidualIsAllGreaterThanEqualTo6(int numQuantity[])
{
	for (int i = 5; i >= 0; --i)
	{
		if (numQuantity[i])
			return false;
	}
	return true;
}