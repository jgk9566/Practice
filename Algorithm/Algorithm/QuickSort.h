#pragma once

#include <vector>

class CQuickSort
{
public:
	CQuickSort();
	~CQuickSort();

public:
	void QuickSort(int* NumList, int iStartIdx, int iEndIdx);
	void QuickSort(std::vector<int> &vecData, int iStartIdx, int iEndIdx);

private:
	void Swap(int* iData, int iNum1, int iNum2);
	void Swap(std::vector<int> &vecData, int iNum1, int iNum2);
};

