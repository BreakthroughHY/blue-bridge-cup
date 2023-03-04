#include "get_power_2_reorder.h"

int getPower2Reorder()
{
	// 创建类对象
	SolutionPower2Reorder s;

	DWORD start_time = GetTickCount();

	//cout << s.reorderedPowerOf2(3) << endl;
	for (int i = 1; i < 10e5; ++i)
	{
		if (s.reorderedPowerOf2(i))
			cout << i << endl;
	}

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//输出运行时间


	return 0;
}

// 程序目标：写出能写出的最高效的程序，不考虑代码量和开发时间。     任务代码：压榨程序员
bool SolutionPower2Reorder::reorderedPowerOf2(int n)
{
	int numQuantity[10] = { 0 }; // 记录传入十进制数值由个位数字组成情况
	int numQuantityCompare[10] = { 0 }; // 从储存数组获取数据，进行比较
	int numquantity = getNumQuantity_(n);

	while (n) // 初始化储存数组和比较数组
	{
		++numQuantity[n % 10];
		++numQuantityCompare[n % 10];
		n /= 10;
	}

	for (int i = 1; i <= 10e9; i = i << 1) // 获取列举作用符合题意的值，作用运算提高效率
	{
		if (getNumQuantity_(i) != numquantity) // 允许和目标值数字符号个数相同的值进行深度处理，否则直接进行下一次循环从而提高效率
		{
			if (getNumQuantity_(i) > numquantity) // 和目标值数字符合个数相同的值已经比较完成，退出循环
			{
				break;
			}
			continue;
		}

		int num = i; // 防止循环变量在处理数据时改变
		while (num) // 将本次比较值数字组成需求和传入值数字组成合并，得到个数字符好的缺余，当缺余全为零时判定符合
		{
			--numQuantityCompare[num % 10];
			num /= 10;
		}

		int flag = true; // 本次检测的数组是否符合，初始化为符合
		for (int j = 0; j < sizeof(numQuantityCompare) / sizeof(numQuantityCompare[0]); ++j) // 检测缺余数字是否全为0
		{
			if (numQuantityCompare[j] != 0) // 不全为0时重置比较数组
			{
				for (int ii = 0; ii < 10; ++ii)
				{
					numQuantityCompare[ii] = numQuantity[ii]; // 重置比较数组
				}
				flag = false; // 初始化不成立重新设置
				break; // 本次比较不成立，开始寻找下一个可能符合的
			}
		}
		if (flag)
			return true;
	}
	return false;
}

int getNumQuantity_(int x)
{
	return to_string(x).size();
}
