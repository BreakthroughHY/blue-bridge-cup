#include "best_time_buy_sell_stocks_II.h"

int bestTimeToBuyStocksII()
{
	// 创建对象
	SolutionTimeBuySellStocks s;
	vector<int> v{ 1,8,6,2,5,4,8,3,7 };

	DWORD start_time = GetTickCount();

	cout << s.maxProfitBes(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间

	return 0;

}

// 股票赚钱的方式是过程
int SolutionTimeBuySellStocks::maxProfitBes(vector<int>& prices)
{


	return 0;
}