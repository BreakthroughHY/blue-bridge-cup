#pragma once

#ifndef __MINIMUM_COVER_SUBSTRING_H__
#define __MINIMUM_COVER_SUBSTRING_H__

#include <unordered_map>
#include <string>
#include "main.h"

// ������
class SolutionMinimumCoverSubstring {
public:
    string minWindow(string s, string t);
};

int minimumCoverSubstring();

// �������map�������Ƿ�ȫ��Ϊ�Ǹ���
bool isAllNonnegative(unordered_map<char, int>& freq);

#endif // !__MINIMUM_COVER_SUBSTRING_H__
