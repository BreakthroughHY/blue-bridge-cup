#include "the_best_time_to_buy_and_sell_stocks.h"

int bestTimeToBuySellStocks()
{
	// 创建对象
	SolutionTheBestTimeToBuyandSellStocks s;
	vector<int> v{ 7,1,5,3,6,4 };

	DWORD start_time = GetTickCount();

	//cout << s.maxProfit(v) << endl;
	cout << s.maxProfitNew(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

// 动态规划二维数组
int SolutionTheBestTimeToBuyandSellStocks::maxProfit(vector<int>& prices)
{
	int n = prices.size();

	vector<vector<int>> dp(n, vector<int>(2));

	dp[0][0] = -prices[0];

	for (int i = 1; i < n; ++i)
	{
		dp[i][0] = max(-prices[i], dp[i - 1][0]);
		dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
	}

	return dp.back().back();
}

// 动态规划一维数组
int SolutionTheBestTimeToBuyandSellStocks::maxProfitNew(vector<int>& prices)
{
	int n = prices.size();

	vector<int> dp{ {-prices[0], 0} };
	vector<int> temp{ {-prices[0], 0} };

	for (int i = 1; i < n; ++i)
	{
		dp[0] = max(-prices[i], temp[0]);
		dp[1] = max(temp[0] + prices[i], temp[1]);
		temp = dp;
	}

	return dp.back();
}