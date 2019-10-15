#pragma once

#include <vector>

class CQuickSort
{
public:
	CQuickSort();
	~CQuickSort();

public:
	void QuickSort(int* NumList, int iStartIdx, int iEndIdx);
	void QuickSort(int start, int end, int* data);

private:
	void Swap(int* iData, int iNum1, int iNum2);
};

