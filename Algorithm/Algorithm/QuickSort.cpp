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
		while (NumList[iLeft] <= NumList[iPivot])
			++iLeft;
		while (NumList[iRight] >= NumList[iPivot] && iRight > iStartIdx)
			--iRight;

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

