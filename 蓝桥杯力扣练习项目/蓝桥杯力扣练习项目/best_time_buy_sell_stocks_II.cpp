#include "best_time_buy_sell_stocks_II.h"

int bestTimeToBuyStocksII()
{
	// ��������
	SolutionTimeBuySellStocks s;
	vector<int> v{ 7,1,5,3,6,4 };

	DWORD start_time = GetTickCount();

	//cout << s.maxProfitBes(v) << endl;
	cout << s.maxProfitBes_Greedy(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

	return 0;

}

// ��Ʊ׬Ǯ�ķ�ʽ�ǹ���
// ��̬�滮�ⷨ
int SolutionTimeBuySellStocks::maxProfitBes(vector<int>& prices)
{
	int numDays = prices.size(); // ����

	vector<vector<int>> dp(numDays, vector<int>(2));

	//dp[0][0] = 0; // dp�����ʼ��
	//dp[0][1] = -prices[0];
	// �ڴ�ռ���Ż�
	int dp0 = 0, dp1 = -prices[0];
	int dp0N, dp1N;

	for (int i = 1; i < numDays; ++i)
	{
		/*dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
		dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);*/
		// �ڴ�ռ���Ż�
		dp0N = max(dp0, dp1 + prices[i]);
		dp1N = max(dp0 - prices[i], dp1);
		dp0 = dp0N;
		dp1 = dp1N;
	}

	return dp0;
}

// ̰���㷨
int SolutionTimeBuySellStocks::maxProfitBes_Greedy(vector<int>& prices)
{
	int ans = 0, n = prices.size();

	for (int i = 1; i < n; ++i)
		ans += max(0, prices[i] - prices[i - 1]);

	return ans;
}
