#include "the_best_time_to_buy_and_sell_stocksIII.h"

int bestTimeToBuyStocksIII()
{
	// 创建对象
	SolutionTheBestTimeToBuyandSellStocksIII s;
	vector<int> v{ 3,3,5,0,0,3,1,4 };

	DWORD start_time = GetTickCount();

	//cout << s.maxProfit(v) << endl;
	cout << s.maxProfitNew(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

// 这个方法实际上是下面那个方法优化掉dp数组的动态规划，优化的太狠特别难理解思路（证明思路成立）
int SolutionTheBestTimeToBuyandSellStocksIII::maxProfit(vector<int>& prices)
{
	int n = prices.size();
	int buy1 = -prices[0], sell1 = 0;
	int buy2 = -prices[0], sell2 = 0;
	for (int i = 1; i < n; ++i) {
		buy1 = max(buy1, -prices[i]);
		sell1 = max(sell1, buy1 + prices[i]);
		buy2 = max(buy2, sell1 - prices[i]);
		sell2 = max(sell2, buy2 + prices[i]);
	}
	return sell2;
}

int SolutionTheBestTimeToBuyandSellStocksIII::maxProfitNew(vector<int>& prices)
{
	int n = prices.size();

	vector<vector<int>> dp(n, vector<int>(4));

	dp[0][0] = dp[0][2] = -prices[0];

	for (int i = 1; i < n; ++i)
	{
		dp[i][0] = max(dp[i - 1][0], -prices[i]);
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
		dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
		dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
	}
	return max(dp.back()[1], dp.back()[3]);
}