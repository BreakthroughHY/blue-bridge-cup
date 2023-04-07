#include "the_best_time_to_buy_and_sell_stocks.h"

int bestTimeToBuySellStocks()
{
	// 创建对象
	SolutionTheBestTimeToBuyandSellStocks s;
	vector<int> v{ 7,1,5,3,6,4 };

	DWORD start_time = GetTickCount();

	cout << s.maxProfit(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;
}

int SolutionTheBestTimeToBuyandSellStocks::maxProfit(vector<int>& prices)
{
	
	return 0;
}