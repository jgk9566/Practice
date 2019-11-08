#pragma once

#include <vector>
#include "Macro.h"

class CQuickSort
{
public:
	CQuickSort();
	CQuickSort(int* NumList, int iNumElements);
	CQuickSort(class std::vector<int> vecData);
	~CQuickSort();

public:
	void QuickSortRef(int* NumList, int iStartIdx, int iEndIdx);
	void QuickSortVector(std::vector<int> &vecData, int iStartIdx, int iEndIdx);
	void QuickSort(int* pData, int iStartIdx, int iEndIdx);

private:
	void Swap(int* iData, int iNum1, int iNum2);
	void Swap(std::vector<int> &vecData, int iNum1, int iNum2);
};

