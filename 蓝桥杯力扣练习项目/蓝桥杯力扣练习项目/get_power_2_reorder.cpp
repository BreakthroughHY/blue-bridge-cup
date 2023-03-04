#include "get_power_2_reorder.h"

int getPower2Reorder()
{
	// ���������
	SolutionPower2Reorder s;

	DWORD start_time = GetTickCount();

	//cout << s.reorderedPowerOf2(3) << endl;
	for (int i = 1; i < 10e5; ++i)
	{
		if (s.reorderedPowerOf2(i))
			cout << i << endl;
	}

	DWORD end_time = GetTickCount();

	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;//�������ʱ��


	return 0;
}

// ����Ŀ�꣺д����д�������Ч�ĳ��򣬲����Ǵ������Ϳ���ʱ�䡣     ������룺ѹե����Ա
bool SolutionPower2Reorder::reorderedPowerOf2(int n)
{
	int numQuantity[10] = { 0 }; // ��¼����ʮ������ֵ�ɸ�λ����������
	int numQuantityCompare[10] = { 0 }; // �Ӵ��������ȡ���ݣ����бȽ�
	int numquantity = getNumQuantity_(n);

	while (n) // ��ʼ����������ͱȽ�����
	{
		++numQuantity[n % 10];
		++numQuantityCompare[n % 10];
		n /= 10;
	}

	for (int i = 1; i <= 10e9; i = i << 1) // ��ȡ�о����÷��������ֵ�������������Ч��
	{
		if (getNumQuantity_(i) != numquantity) // �����Ŀ��ֵ���ַ��Ÿ�����ͬ��ֵ������ȴ�������ֱ�ӽ�����һ��ѭ���Ӷ����Ч��
		{
			if (getNumQuantity_(i) > numquantity) // ��Ŀ��ֵ���ַ��ϸ�����ͬ��ֵ�Ѿ��Ƚ���ɣ��˳�ѭ��
			{
				break;
			}
			continue;
		}

		int num = i; // ��ֹѭ�������ڴ�������ʱ�ı�
		while (num) // �����αȽ�ֵ�����������ʹ���ֵ������ɺϲ����õ������ַ��õ�ȱ�࣬��ȱ��ȫΪ��ʱ�ж�����
		{
			--numQuantityCompare[num % 10];
			num /= 10;
		}

		int flag = true; // ���μ��������Ƿ���ϣ���ʼ��Ϊ����
		for (int j = 0; j < sizeof(numQuantityCompare) / sizeof(numQuantityCompare[0]); ++j) // ���ȱ�������Ƿ�ȫΪ0
		{
			if (numQuantityCompare[j] != 0) // ��ȫΪ0ʱ���ñȽ�����
			{
				for (int ii = 0; ii < 10; ++ii)
				{
					numQuantityCompare[ii] = numQuantity[ii]; // ���ñȽ�����
				}
				flag = false; // ��ʼ����������������
				break; // ���αȽϲ���������ʼѰ����һ�����ܷ��ϵ�
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
