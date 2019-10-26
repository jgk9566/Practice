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
		while (NumList[iLeft] <= NumList[iPivot] && iLeft <= iEndIdx)
		{
			++iLeft;

			// 상위 while 루프를 빠져나오기 위해 iLeft를 먼저 올려준다.
			if (iLeft == iEndIdx)
				break;
		}
		while (NumList[iRight] >= NumList[iPivot] && iRight > iStartIdx)
		{
			--iRight;
		}

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

void CQuickSort::QuickSort(std::vector<int> &vecData, int iStartIdx, int iEndIdx)
{
	if (iStartIdx >= iEndIdx)
		return;

	int iPivotIdx = iStartIdx;
	int iLeftIdx = iPivotIdx + 1;
	int iRightIdx = iEndIdx;

	while (iLeftIdx <= iRightIdx)
	{
		while (vecData[iLeftIdx] <= vecData[iPivotIdx] && iLeftIdx < iEndIdx)
		{
			++iLeftIdx;			
		}
		while (vecData[iRightIdx] >= vecData[iPivotIdx] && iRightIdx > iStartIdx)
		{
			--iRightIdx;
		}

		if (iRightIdx < iLeftIdx) // 엊갈린 상태
		{
			Swap(vecData, iRightIdx, iPivotIdx);
		}
		else
		{
			Swap(vecData, iRightIdx, iLeftIdx);
		}

		if (iLeftIdx == iRightIdx)
			break;
	}

	QuickSort(vecData, iStartIdx, iRightIdx - 1);
	QuickSort(vecData, iRightIdx + 1, iEndIdx);
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

