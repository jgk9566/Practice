#include "pch.h"
#include "SelectionSort.h"

CSelectionSort::CSelectionSort()
{
}

CSelectionSort::~CSelectionSort()
{
}

void CSelectionSort::SelectionSort(int* pData, int iSize)
{
	for (int iKeyIdx = 0; iKeyIdx < iSize; ++iKeyIdx)
	{
		int iSmallestIdx = iKeyIdx;
		
		for (int iCompareIdx = iKeyIdx + 1; iCompareIdx < iSize; ++iCompareIdx)
		{
			if (pData[iSmallestIdx] > pData[iCompareIdx])
				iSmallestIdx = iCompareIdx;
		}

		// Switch the data between key index and small index
		int iTemp = pData[iKeyIdx];
		pData[iKeyIdx] = pData[iSmallestIdx];
		pData[iSmallestIdx] = iTemp;
	}
}

