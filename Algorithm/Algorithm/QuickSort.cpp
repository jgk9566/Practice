#include "QuickSort.h"



CQuickSort::CQuickSort()
{
}


CQuickSort::~CQuickSort()
{
}

void CQuickSort::QuickSort(int * NumList, int iStartIdx, int iEndIdx)
{
	// ���Ұ� 1���� ��� (�ε����� 1���� ��) �״�� �д�.
	if (iStartIdx >= iEndIdx)
		return;

	int iPivot = iStartIdx;
	int iLeft = iPivot + 1; // �Ǻ� ���� ū ���ڸ� ã�´�.
	int iRight = iEndIdx; // �Ǻ� ���� ���� ���ڸ� ã�´�.
	int iTemp = 0;

	while (iLeft <= iRight) // ���� ������ �� ����.
	{
		while (NumList[iLeft] <= NumList[iPivot] && iLeft <= iEndIdx)
		{
			++iLeft;

			// ���� while ������ ���������� ���� iLeft�� ���� �÷��ش�.
			if (iLeft == iEndIdx)
				break;
		}
		while (NumList[iRight] >= NumList[iPivot] && iRight > iStartIdx)
		{
			--iRight;
		}

		// ���� ���ڿ� ������ ���ڰ� ������ ���¶�� Ű ���� ��ü
		if (iLeft > iRight)
		{
			Swap(NumList, iRight, iPivot);
		}
		// �ƴ϶�� ���� ���ڿ� ������ ���ڸ� ��ü���ش�.
		else
		{
			Swap(NumList, iLeft, iRight);
		}
	}

	// ��͸� �����鼭 ���� �׷� ����
	QuickSort(NumList, iStartIdx, iRight - 1);
	// ��͸� �����鼭 ������ �׷� ����
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

		if (iRightIdx < iLeftIdx) // ������ ����
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

