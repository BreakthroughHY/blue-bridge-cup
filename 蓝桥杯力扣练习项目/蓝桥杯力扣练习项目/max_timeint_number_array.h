#pragma once

#ifndef __MAX_TIMEINT_NUMBER_ARRAY_H__
#define __MAX_TIMEINT_NUMBER_ARRAY_H__

#include "vector"
#include "main.h"

// ������
class SolutionMaxTime {
public:
    string largestTimeFromDigits(vector<int>& arr);
};

int maximumTimeWithinAnArray();

// ����Ƿ���ڷ���С�ڻ����ָ��ָ�������ַ�
bool testLessThanSpecifiedNumberExistence(int numQuantity[], int x);

// ���ʣ���������ַ����Ƿ�ȫ�����ڵ���6
bool checkWhetherResidualIsAllGreaterThanEqualTo6(int numQuantity[]);

#endif // !__MAX_TIMEINT_NUMBER_ARRAY_H__
