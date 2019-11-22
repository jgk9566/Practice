#include "pch.h"
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

void CQuickSort::QuickSort1(int* pData, int iStart, int iEnd)
{
	if (iStart >= iEnd)
		return;

	int iPivot = iStart;
	int iLeft = iPivot + 1;
	int iRight = iEnd;

	while (iLeft <= iRight)
	{
		while (iLeft <= iEnd && pData[iLeft] <= pData[iPivot])
			++iLeft;
		while (iRight > iStart&& pData[iRight] >= pData[iPivot])
			--iRight;

		if (iLeft > iRight)
		{
			int iTemp = pData[iRight];
			pData[iRight] = pData[iPivot];
			pData[iPivot] = iTemp;
		}
		else
		{
			int iTemp = pData[iRight];
			pData[iRight] = pData[iLeft];
			pData[iLeft] = iTemp;
		}
	}

	QuickSort1(pData, iStart, iRight - 1);
	QuickSort1(pData, iRight + 1, iEnd);
}

void CQuickSort::QuickSort(int* pData, int iStartIdx, int iEndIdx)
{
	if (iStartIdx >= iEndIdx)
		return;

	int iPivotIdx = iStartIdx;
	int iLeftIdx = iPivotIdx + 1;
	int iRightIdx = iEndIdx;

	while (iLeftIdx <= iRightIdx)
	{
		while (iLeftIdx <= iEndIdx && pData[iLeftIdx] <= pData[iPivotIdx])
			++iLeftIdx;
		while (iRightIdx > iStartIdx && pData[iRightIdx] >= pData[iPivotIdx])
			--iRightIdx;

		if (iLeftIdx > iRightIdx)
		{
			int iTemp = pData[iPivotIdx];
			pData[iPivotIdx] = pData[iRightIdx];
			pData[iRightIdx] = iTemp;
		}
		else
		{
			int iTemp = pData[iLeftIdx];
			pData[iLeftIdx] = pData[iRightIdx];
			pData[iRightIdx] = iTemp;
		}
	}

	QuickSort(pData, iStartIdx, iRightIdx - 1);
	QuickSort(pData, iRightIdx + 1, iEndIdx);
}


void CQuickSort::QuickSort1(std::vector<int>& vecData, int iStart, int iEnd)
{
	if (iStart >= iEnd)
		return;

	int iPivot = iStart;
	int iLeft = iPivot + 1;
	int iRight = iEnd;

	while (iLeft <= iRight)
	{
		while (iLeft <= iEnd && vecData[iLeft] <= vecData[iPivot])
			++iLeft;
		while (iRight > iStart&& vecData[iRight] >= vecData[iPivot])
			--iRight;

		if (iLeft > iRight)
		{
			// 스왑
			int iTemp = vecData[iRight];
			vecData[iRight] = vecData[iPivot];
			vecData[iPivot] = iTemp;
		}
		else
		{
			int iTemp = vecData[iRight];
			vecData[iRight] = vecData[iLeft];
			vecData[iLeft] = iTemp;
		}
	}

	// 재귀
	QuickSort1(vecData, iStart, iRight - 1);
	QuickSort1(vecData, iRight + 1, iEnd);
}

void CQuickSort::QuickSort2(int* pData, int iStartIdx, int iEndIdx)
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
		while (iRight > iStartIdx && pData[iRight] >= pData[iPivot])
			--iRight;

		if (iLeft > iRight)
		{
			int iTemp = pData[iRight];
			pData[iRight] = pData[iPivot];
			pData[iPivot] = iTemp;
		}
		else
		{
			int iTemp = pData[iRight];
			pData[iRight] = pData[iLeft];
			pData[iLeft] = iTemp;
		}
	}

	QuickSort2(pData, iStartIdx, iRight - 1);
	QuickSort2(pData, iRight + 1, iEndIdx);
}

void CQuickSort::QuickSort2(std::vector<int>& vecData, int iStart, int iEnd)
{
	if (iStart >= iEnd)
		return;

	int iPivot = iStart;
	int iLeft = iPivot + 1;
	int iRight = iEnd;

	while (iLeft <= iRight)
	{
		while (iLeft <= iEnd && vecData[iLeft] <= vecData[iPivot])
			++iLeft;
		while (iRight > iStart&& vecData[iRight] >= vecData[iPivot])
			--iRight;

		if (iLeft > iRight)
		{
			int iTemp = vecData[iRight];
			vecData[iRight] = vecData[iPivot];
			vecData[iPivot] = iTemp;
		}
		else
		{
			int iTemp = vecData[iRight];
			vecData[iRight] = vecData[iPivot];
			vecData[iPivot] = iTemp;
		}
	}

	QuickSort2(vecData, iStart, iRight - 1);
	QuickSort2(vecData, iRight + 1, iEnd);
}

void CQuickSort::QuickSort3(int* pData, int iStart, int iEnd)
{
	if (iStart >= iEnd)
		return;

	int iPivot = iStart;
	int iLeft = iPivot + 1;
	int iRight = iEnd;

	while (iLeft <= iRight)
	{
		while (iLeft <= iEnd && pData[iLeft] <= pData[iPivot])
			++iLeft;
		while (iRight > iStart&& pData[iRight] >= pData[iPivot])
			--iRight;

		if (iLeft > iRight)
		{
			int iTemp = pData[iRight];
			pData[iRight] = pData[iPivot];
			pData[iPivot] = iTemp;
		}
		else
		{
			int iTemp = pData[iRight];
			pData[iRight] = pData[iLeft];
			pData[iLeft] = iTemp;
		}
	}

	QuickSort3(pData, iStart, iRight - 1);
	QuickSort3(pData, iRight + 1, iEnd);
}

void CQuickSort::QuickSort3(std::vector<int>& vecData, int iStartIdx, int iEndIdx)
{
	if (iStartIdx >= iEndIdx)
		return;

	int iPivot = iStartIdx;
	int iLeft = iPivot + 1;
	int iRight = iEndIdx;

	while (iLeft <= iRight)
	{
		while (iLeft <= iEndIdx && vecData[iLeft] <= vecData[iPivot])
			++iLeft;
		while (iRight > iStartIdx&& vecData[iRight] >= vecData[iPivot])
			--iRight;

		if (iLeft > iRight)
		{
			int iTemp = vecData[iRight];
			vecData[iRight] = vecData[iPivot];
			vecData[iPivot] = iTemp;
		}
		else
		{
			int iTemp = vecData[iRight];
			vecData[iRight] = vecData[iLeft];
			vecData[iLeft] = iTemp;
		}
	}

	QuickSort3(vecData, iStartIdx, iRight - 1);
	QuickSort3(vecData, iRight + 1, iEndIdx);
}

void CQuickSort::QuickSort4(int* pData, int iStart, int iEnd)
{
	if (iStart >= iEnd)
		return;

	int iPivot = iStart;
	int iLeft = iPivot + 1;
	int iRight = iEnd;

	while (iLeft <= iRight)
	{
		while (iLeft <= iEnd && pData[iLeft] <= pData[iPivot])
			++iLeft;
		while (iRight > iStart&& pData[iRight] >= pData[iPivot])
			--iRight;

		if (iLeft > iRight)
		{
			int iTemp = pData[iRight];
			pData[iRight] = pData[iPivot];
			pData[iPivot] = iTemp;
		}
		else
		{
			int iTemp = pData[iRight];
			pData[iRight] = pData[iLeft];
			pData[iLeft] = iTemp;
		}
	}

	QuickSort4(pData, iStart, iRight - 1);
	QuickSort4(pData, iRight + 1, iEnd);
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

