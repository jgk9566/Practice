#include "QuickSort.h"



CQuickSort::CQuickSort()
{
}


CQuickSort::~CQuickSort()
{
}

void CQuickSort::QuickSort(int * NumList, int iStartIdx, int iEndIdx)
{
	// 원소가 1개인 경우 (인덱스가 1개일 때) 그대로 둔다.
	if (iStartIdx >= iEndIdx)
		return;

	int iPivot = iStartIdx;
	int iLeft = iPivot + 1; // 피봇 보다 큰 숫자를 찾는다.
	int iRight = iEndIdx; // 피봇 보다 작은 숫자를 찾는다.
	int iTemp = 0;

	while (iLeft <= iRight) // 서로 교차될 때 까지.
	{
		while (NumList[iLeft] <= NumList[iPivot])
			++iLeft;
		while (NumList[iRight] >= NumList[iPivot] && iRight > iStartIdx)
			--iRight;

		// 왼쪽 숫자와 오른쪽 숫자가 엇갈린 상태라면 키 값과 교체
		if (iLeft > iRight)
		{
			Swap(NumList, iRight, iPivot);
		}
		// 아니라면 왼쪽 숫자와 오른쪽 숫자를 교체해준다.
		else
		{
			Swap(NumList, iLeft, iRight);
		}
	}

	// 재귀를 돌리면서 왼쪽 그룹 정렬
	QuickSort(NumList, iStartIdx, iRight - 1);
	// 재귀를 돌리면서 오른쪽 그룹 정렬
	QuickSort(NumList, iRight + 1, iEndIdx);
}

void CQuickSort::QuickSort(int start, int end, int * data)
{
	if (start >= end)
		return;

	int key = start;
	int i = start + 1;
	int j = end;
	int temp = 0;

	while (i <= j)
	{
		while (i <= end && data[i] <= data[key])
		{
			++i;
		}
		while (j > start && data[j] >= data[key])
		{
			--j;
		}

		if (i > j)
		{
			Swap(data, j, key);
			//temp = data[j];
			//data[j] = data[key];
			//data[key] = temp;
		}
		else
		{
			Swap(data, i, j);
			//temp = data[i];
			//data[i] = data[j];
			//data[j] = temp;
		}		
	}

	QuickSort(start, j - 1, data);
	QuickSort(j + 1, end, data);
}

void CQuickSort::Swap(int* iData, int iIdxNum1, int iIdxNum2)
{
	int iTemp = iData[iIdxNum1];
	iData[iIdxNum1] = iData[iIdxNum2];
	iData[iIdxNum2] = iTemp;
}

