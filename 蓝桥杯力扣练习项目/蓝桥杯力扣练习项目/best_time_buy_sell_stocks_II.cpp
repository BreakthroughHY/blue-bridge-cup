#include "best_time_buy_sell_stocks_II.h"

int bestTimeToBuyStocksII()
{
	// ��������
	SolutionTimeBuySellStocks s;
	vector<int> v{ 1,8,6,2,5,4,8,3,7 };

	DWORD start_time = GetTickCount();

	cout << s.maxProfitBes(v) << endl;

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��

	return 0;

}

// ��Ʊ׬Ǯ�ķ�ʽ�ǹ���
int SolutionTimeBuySellStocks::maxProfitBes(vector<int>& prices)
{


	return 0;
}