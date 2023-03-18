#include "interlaced_string.h"

int staggeredStr()
{
	// ��������
	SolutionInterlacedString s;

	string s1 = "aabcc";
	string s2 = "dbbca";

	string s3 = "aadbbcbcac";


	DWORD start_time = GetTickCount();

	cout << s.isInterleave(s1, s2, s3) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

	return 0;
}

bool SolutionInterlacedString::isInterleave(string s1, string s2, string s3)
{
	int n = s1.size(), m = s2.size(), k = s3.size();

	if (n + m != k)
		return false;

	vector<vector<int>> f(n + 1, vector<int>(m + 1, false));

	f[0][0] = true;

	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			int p = i + j - 1;
			if (i > 0)
				f[i][j] = (f[i - 1][j] && s1[i - 1] == s3[p]);
			if (j > 0)
				f[i][j] |= (f[i][j - 1] && s2[j - 1] == s3[p]);
		}
	}
	return f[n][m];
}


//// Ϊʲô���ٷ���������Ϊ˼ά���ԣ��������˫ָ���˼��Ǩ�Ƶ���̬�滮
//bool SolutionInterlacedString::isInterleave(string s1, string s2, string s3) {
//    auto f = vector < vector <int> >(s1.size() + 1, vector <int>(s2.size() + 1, false));
//
//    int n = s1.size(), m = s2.size(), t = s3.size();
//
//    if (n + m != t) {
//        return false;
//    }
//
//    f[0][0] = true;
//    for (int i = 0; i <= n; ++i) {
//        for (int j = 0; j <= m; ++j) {
//            int p = i + j - 1;
//            if (i > 0) {
//                f[i][j] = (f[i - 1][j] && s1[i - 1] == s3[p]);
//            }
//            if (j > 0) {
//                f[i][j] |= (f[i][j - 1] && s2[j - 1] == s3[p]);
//            }
//        }
//    }
//
//    return f[n][m];
//}
