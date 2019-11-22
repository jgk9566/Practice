#include "pch.h"
#include "InsertionSort.h"

CInsertionSort::CInsertionSort()
{
}

CInsertionSort::CInsertionSort(int* iArr, int iNumOfElements)
{
	std::cout << "Original Numbers(array) : ";

	for (int i = 0; i < iNumOfElements; ++i)
	{
		if (i == iNumOfElements - 1)
			std::cout << iArr[i] << std::endl;
		else
			std::cout << iArr[i] << ", ";
	}
}

CInsertionSort::CInsertionSort(std::vector<int> vecData)
{
	std::cout << "Original Numbers(vector) : ";

	for (int i = 0; i < vecData.size(); ++i)
	{
		if (i == vecData.size() - 1)
			std::cout << vecData[i] << std::endl;
		else
			std::cout << vecData[i] << ", ";
	}
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

	for (int iCompareIdx = 1; iCompareIdx < iSize; ++iCompareIdx)
	{
		iKey = iArr[iCompareIdx];

		for (int iLeftIdx = iCompareIdx - 1; iLeftIdx >= 0; --iLeftIdx)
		{
			if (iArr[iLeftIdx] > iKey)
			{
				iArr[iLeftIdx + 1] = iArr[iLeftIdx];

				if (iLeftIdx == 0)
					iArr[iLeftIdx] = iKey;
			}
			else
			{
				iArr[iLeftIdx + 1] = iKey;
				break;
			}
		}
	}
}

void CInsertionSort::InsertionSort1(int* pArr, int iSize)
{
	int iKey = 0;

	for (int iCompareIdx = 1; iCompareIdx < iSize; ++iCompareIdx)
	{
		iKey = pArr[iCompareIdx];

		for (int iLeftIdx = iCompareIdx - 1; iLeftIdx >= 0; --iLeftIdx)
		{
			if (pArr[iLeftIdx] > iKey)
			{
				pArr[iLeftIdx + 1] = pArr[iLeftIdx];

				if (iLeftIdx == 0)
					pArr[iLeftIdx] = iKey;
			}
			else
			{
				pArr[iLeftIdx + 1] = iKey;
				break;
			}
		}
	}
}

void CInsertionSort::InsertionSort1(std::vector<int>& vecData)
{
	int iKey = 0;

	for (int iCompare = 1; iCompare < vecData.size(); ++iCompare)
	{
		iKey = vecData[iCompare];

		for (int iLeft = iCompare - 1; iLeft >= 0; --iLeft)
		{
			if (vecData[iLeft] >= iKey)
			{
				vecData[iLeft + 1] = vecData[iLeft];

				if (iLeft == 0)
					vecData[iLeft] = iKey;
			}
			else
			{
				vecData[iLeft + 1] = iKey;
				break;
			}
		}
	}
}

void CInsertionSort::InsertionSort2(int* pArr, int iSize)
{
	int iKey = 0;

	for (int i = 1; i < iSize; ++i)
	{
		iKey = pArr[i];

		for (int iCompare = i - 1; iCompare >= 0; --iCompare)
		{
			if (pArr[iCompare] >= iKey)
			{
				pArr[iCompare + 1] = pArr[iCompare];

				if (iCompare == 0)
					pArr[iCompare] = iKey;
			}
			else
			{
				pArr[iCompare + 1] = iKey;
				break;
			}
		}
	}
}

void CInsertionSort::InsertionSort2(std::vector<int>& vecData)
{
	int iKeyValue = 0;

	for (int iKeyIdx = 1; iKeyIdx < vecData.size(); ++iKeyIdx)
	{
		iKeyValue = vecData[iKeyIdx];

		for (int iCompare = iKeyIdx - 1; iCompare >= 0; --iCompare)
		{
			if (vecData[iCompare] >= iKeyValue)
			{
				vecData[iCompare + 1] = vecData[iCompare];

				if (iCompare == 0)
					vecData[iCompare] = iKeyValue;
			}
			else
			{
				vecData[iCompare + 1] = iKeyValue;
				break;
			}
		}
	}
}

void CInsertionSort::InsertionSort3(int* pArr, int iSize)
{
	int iKeyValue = 0;

	for (int iKey = 1; iKey < iSize; ++iKey)
	{
		iKeyValue = pArr[iKey];

		for (int iLeft = iKey - 1; iLeft >= 0; --iLeft)
		{
			if (pArr[iLeft] >= iKeyValue)
			{
				pArr[iLeft + 1] = pArr[iLeft];

				if (iLeft == 0)
					pArr[iLeft] = iKeyValue;
			}
			else
			{
				pArr[iLeft + 1] = iKeyValue;
				break;
			}
		}
	}
}

void CInsertionSort::InsertionSort3(std::vector<int>& vecData)
{
	int iKey = 0;

	for (int iKeyIdx = 1; iKeyIdx < static_cast<int>(vecData.size()); ++iKeyIdx)
	{
		iKey = vecData[iKeyIdx];

		for (int iCompareIdx = iKeyIdx - 1; iCompareIdx >= 0; --iCompareIdx)
		{
			if (vecData[iCompareIdx] >= iKey)
			{
				vecData[iCompareIdx + 1] = vecData[iCompareIdx];

				if (iCompareIdx == 0)
					vecData[iCompareIdx] = iKey;
			}
			else
			{
				vecData[iCompareIdx + 1] = iKey;
				break;
			}
		}
	}
}

void CInsertionSort::InsertionSort4(int* pArr, int iSize)
{
	int iKey = 0;

	for (int iKeyIdx = 0; iKeyIdx < iSize; ++iKeyIdx)
	{
		iKey = pArr[iKeyIdx];

		for (int iCompare = iKeyIdx - 1; iCompare >= 0; --iCompare)
		{
			if (pArr[iCompare] >= iKey)
			{
				pArr[iCompare + 1] = pArr[iCompare];

				if (iCompare == 0)
					pArr[iCompare] = iKey;
			}
			else
			{
				pArr[iCompare + 1] = iKey;
				break;
			}
		}
	}
}
