#include "InsertionSort.h"



CInsertionSort::CInsertionSort()
{
}


CInsertionSort::~CInsertionSort()
{
}

void CInsertionSort::InsertionSortRef(int * iArr, int iSize)
{
	int iKey = 0;

	for (int iKeyIdx = 1; iKeyIdx < iSize; ++iKeyIdx)
	{
		iKey = iArr[iKeyIdx];

		for (int iCompareIdx = iKeyIdx - 1; iCompareIdx >= 0; --iCompareIdx)
		{			
			if (iArr[iCompareIdx] > iKey) // ���� Ű������ ũ�� ������ �迭�� �̵�.
			{
				iArr[iCompareIdx + 1] = iArr[iCompareIdx];

				// �� ����� ù �ε����� ��쿣 Key ���� ù �迭�� ����.
				if (iCompareIdx == 0)
					iArr[iCompareIdx] = iKey;
			}
			else // ���� Ű������ �۰ų� ������ j ��ġ�� �����ϰ� ���� ����������.
			{
				iArr[iCompareIdx + 1] = iKey;
				break;
			}
		}
	}
}

void CInsertionSort::InsertionSort(std::vector<int>& vecData, int iSize)
{
	int iKey = 0;

	for (int iKeyIdx = 1; iKeyIdx < iSize; ++iKeyIdx)
	{
		iKey = vecData[iKeyIdx];

		for (int iComapreIdx = iKeyIdx - 1; iComapreIdx >= 0; --iComapreIdx)
		{
			if (vecData[iComapreIdx] > iKey)
			{
				vecData[iComapreIdx + 1] = vecData[iComapreIdx];

				if (iComapreIdx == 0)
					vecData[iComapreIdx] = iKey;
			}
			else
			{
				vecData[iComapreIdx + 1] = iKey;
				break;
			}
		}
	}
}

void CInsertionSort::InsertionSort(int* iArr, int iSize)
{
	int iKey = 0;

	for (int iKeyIdx = 1; iKeyIdx < iSize; ++iKeyIdx)
	{
		iKey = iArr[iKeyIdx];

		for (int iCompareIdx = iKeyIdx - 1; iCompareIdx >= 0; --iCompareIdx)
		{
			if (iArr[iCompareIdx] > iKey)
			{
				iArr[iCompareIdx + 1] = iArr[iCompareIdx];

				if (iCompareIdx == 0)
				{
					iArr[iCompareIdx] = iKey;
				}
			}
			else
			{
				iArr[iCompareIdx + 1] = iKey;
				break;
			}
		}
	}
}
