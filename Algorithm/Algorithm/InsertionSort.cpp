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
			if (iArr[iCompareIdx] > iKey) // 현재 키값보다 크면 오른쪽 배열로 이동.
			{
				iArr[iCompareIdx + 1] = iArr[iCompareIdx];

				// 비교 대상이 첫 인덱스인 경우엔 Key 값을 첫 배열에 삽입.
				if (iCompareIdx == 0)
					iArr[iCompareIdx] = iKey;
			}
			else // 현재 키값보다 작거나 같으면 j 위치에 삽입하고 루프 빠져나오기.
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
