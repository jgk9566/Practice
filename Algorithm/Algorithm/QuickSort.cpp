#include "QuickSort.h"


CQuickSort::CQuickSort()
{
}

CQuickSort::CQuickSort(int* NumList, int iNumElements)
{	
	std::cout << "Original Numbers(array) : ";
	
	for (int i = 0; i < iNumElements; ++i)
	{
		if (i == iNumElements - 1)
			std::cout << NumList[i] << std::endl;
		else
			std::cout << NumList[i] << ", ";
	}
}

CQuickSort::CQuickSort(std::vector<int> vecData)
{
	int iCount = vecData.size();
	std::cout << "Original Numbers(vector) : ";

	for (int i = 0; i < iCount; ++i)
	{
		if (i == iCount - 1)
			std::cout << vecData[i] << std::endl;
		else
			std::cout << vecData[i] << ", ";
	}
}

CQuickSort::~CQuickSort()
{
}

void CQuickSort::QuickSortRef(int * NumList, int iStartIdx, int iEndIdx)
{
	// 원소가 1개인 경우 (인덱스가 1개일 때) 그대로 둔다.
	if (iStartIdx >= iEndIdx)
		return;

	int iPivotIdx = iStartIdx;
	int iLeftIdx = iPivotIdx + 1; // 피봇 보다 큰 숫자를 찾는다.
	int iRightIdx = iEndIdx; // 피봇 보다 작은 숫자를 찾는다.

	while (iLeftIdx <= iRightIdx) // 서로 교차될 때 까지.
	{
		while (iLeftIdx <= iEndIdx && NumList[iLeftIdx] <= NumList[iPivotIdx])
		{
			++iLeftIdx;
		}
		while (iRightIdx > iStartIdx && NumList[iRightIdx] >= NumList[iPivotIdx])
		{
			--iRightIdx;
		}

		// 왼쪽 숫자와 오른쪽 숫자가 엇갈린 상태라면 키 값과 교체
		if (iLeftIdx > iRightIdx)
		{
			Swap(NumList, iRightIdx, iPivotIdx);
		}
		// 아니라면 왼쪽 숫자와 오른쪽 숫자를 교체해준다.
		else
		{
			Swap(NumList, iLeftIdx, iRightIdx);
		}
	}

	// 재귀를 돌리면서 왼쪽 그룹 정렬
	QuickSortRef(NumList, iStartIdx, iRightIdx - 1);
	// 재귀를 돌리면서 오른쪽 그룹 정렬
	QuickSortRef(NumList, iRightIdx + 1, iEndIdx);
}

void CQuickSort::QuickSortVector(std::vector<int> &vecData, int iStartIdx, int iEndIdx)
{
	if (iStartIdx >= iEndIdx)
		return;

	int iPivotIdx = iStartIdx;
	int iLeftIdx = iPivotIdx + 1;
	int iRightIdx = iEndIdx;

	while (iLeftIdx <= iRightIdx)
	{
		while (iLeftIdx <= iEndIdx && vecData[iLeftIdx] <= vecData[iPivotIdx])
			++iLeftIdx;
		while (iRightIdx > iStartIdx && vecData[iRightIdx] >= vecData[iPivotIdx])
			--iRightIdx;

		if (iLeftIdx > iRightIdx)
		{
			int iTemp = vecData[iPivotIdx];
			vecData[iPivotIdx] = vecData[iRightIdx];
			vecData[iRightIdx] = iTemp;
		}
		else
		{
			int iTemp = vecData[iLeftIdx];
			vecData[iLeftIdx] = vecData[iRightIdx];
			vecData[iRightIdx] = iTemp;
		}
	}

	QuickSortVector(vecData, iStartIdx, iRightIdx - 1);
	QuickSortVector(vecData, iRightIdx + 1, iEndIdx);
}

void CQuickSort::QuickSort(int* pData, int iStartIdx, int iEndIdx)
{
	if (iStartIdx >= iEndIdx)
		return;

	int iPivot = iStartIdx;
	int iLeft = iPivot + 1;
	int iRight = iEndIdx;

	while (iLeft <= iRight)
	{
		while (iLeft <= iEndIdx && pData[iLeft] <= pData[iPivot])
			++iLeft;
		while (iRight > iStartIdx&& pData[iRight] >= pData[iPivot])
			--iRight;

		if (iLeft > iRight)
		{
			int iTemp = pData[iPivot];
			pData[iPivot] = pData[iRight];
			pData[iRight] = iTemp;
		}
		else
		{
			int iTemp = pData[iLeft];
			pData[iLeft] = pData[iRight];
			pData[iRight] = iTemp;
		}
	}

	QuickSort(pData, iStartIdx, iRight - 1);
	QuickSort(pData, iRight + 1, iEndIdx);
}



void CQuickSort::Swap(int* iData, int iIdxNum1, int iIdxNum2)
{
	int iTemp = iData[iIdxNum1];
	iData[iIdxNum1] = iData[iIdxNum2];
	iData[iIdxNum2] = iTemp;
}

void CQuickSort::Swap(std::vector<int> &vecData, int iNum1, int iNum2)
{		
	int iTemp = vecData[iNum1];
	vecData[iNum1] = vecData[iNum2];
	vecData[iNum2] = iTemp;
}

