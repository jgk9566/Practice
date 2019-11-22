#pragma once

//#include "Macro.h"

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
	void QuickSort1(int* pData, int iStart, int iEnd);
	void QuickSort1(std::vector<int>& vecData, int iStart, int iEnd);
	void QuickSort2(int* pData, int iStartIdx, int iEndIdx);
	void QuickSort2(std::vector<int>& vecData, int iStart, int iEnd);
	void QuickSort3(int* pData, int iStart, int iEnd);
	void QuickSort3(std::vector<int>& vecData, int iStartIdx, int iEndIdx);
	void QuickSort4(int* pData, int iStart, int iEnd);

private:
	void Swap(int* iData, int iNum1, int iNum2);
	void Swap(std::vector<int> &vecData, int iNum1, int iNum2);
};

