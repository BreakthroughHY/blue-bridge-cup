#include "best_time_buy_sell_stocks_II.h"

int bestTimeToBuyStocksII()
{
	// 创建对象
	SolutionTimeBuySellStocks s;
	vector<int> v{ 7,1,5,3,6,4 };

	DWORD start_time = GetTickCount();

	//cout << s.maxProfitBes(v) << endl;
	cout << s.maxProfitBes_Greedy(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;

}

// 股票赚钱的方式是过程
// 动态规划解法
int SolutionTimeBuySellStocks::maxProfitBes(vector<int>& prices)
{
	int numDays = prices.size(); // 天数

	vector<vector<int>> dp(numDays, vector<int>(2));

	//dp[0][0] = 0; // dp数组初始化
	//dp[0][1] = -prices[0];
	// 内存占用优化
	int dp0 = 0, dp1 = -prices[0];
	int dp0N, dp1N;

	for (int i = 1; i < numDays; ++i)
	{
		/*dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
		dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);*/
		// 内存占用优化
		dp0N = max(dp0, dp1 + prices[i]);
		dp1N = max(dp0 - prices[i], dp1);
		dp0 = dp0N;
		dp1 = dp1N;
	}

	return dp0;
}

// 贪心算法
int SolutionTimeBuySellStocks::maxProfitBes_Greedy(vector<int>& prices)
{
	int ans = 0, n = prices.size();

	for (int i = 1; i < n; ++i)
		ans += max(0, prices[i] - prices[i - 1]);

	return ans;
}
