#include "edit_distance.h"

int editDistance()
{
	// ��������
	SolutionEditDistance s;

	DWORD start_time = GetTickCount();

	cout << s.minDistance("asdfssqwes", "ass") << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

	return 0;
}

int SolutionEditDistance::minDistance(string word1, string word2)
{
	int n = word1.size(); // ԭ�ַ�������
	int m = word2.size(); // Ŀ���ַ�������
	vector<vector<int>> dp(n, vector<int>(m, 1));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (word1[i] == word2[j])
				dp[i][j] = 0; // ������ͬ�ַ�����Ӧdp����ֵ��Ϊ0
			cout << dp[i][j] << "	";
		}
		cout << endl;
		cout << endl;
	}
	cout << "-------------------------------------" << endl;
	// Ѱ��dp�����ڵ�����·��
	// ͬ��ͨ����̬�滮Ѱ������·��   �ռ临�Ӷ�n��ʱ�临�Ӷ�n*m

	vector<int> dp_(m);

	// ��ʼ��dp_����
	for (int i = 0; i < m; ++i)
	{
		if (!i) // i����0���⴦��
			dp_[i] = dp[0][i];
		else
			dp_[i] = dp_[i - 1] + 1;
		cout << dp_[i] << "	";
	}
	cout << endl;
	int temp, temp1;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!j) // j ����0���⴦��
			{
				temp1 = dp_[j];
				dp_[j] = dp_[j] + 1;
				cout << dp_[j] << "	";
			}
			else
			{
				temp = temp1;
				temp1 = dp_[j];
				if (temp <= min(dp_[j - 1], dp_[j]))
				{
					dp_[j] = dp[i][j] + temp;
					cout << dp_[j] << "	";
				}
				else
				{
					if (dp_[j - 1] > dp_[j])
					{
						dp_[j] = dp_[j] + 1;
						cout << dp_[j] << "	";
					}
					else
					{
						dp_[j] = dp_[j - 1] + 1;
						cout << dp_[j] << "	";
					}
				}
			}
		}
		cout << endl;
	}

	return dp_[m - 1];
}