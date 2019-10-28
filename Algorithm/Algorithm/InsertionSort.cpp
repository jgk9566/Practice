#include "InsertionSort.h"



CInsertionSort::CInsertionSort()
{
}


CInsertionSort::~CInsertionSort()
{
}

void CInsertionSort::InsertionSort(int * iArr, int iSize)
{
	int iKey = 0;

	for (int i = 1; i < iSize; ++i)
	{
		iKey = iArr[i];

		for (int j = i - 1; j >= 0; --j)
		{			
			if (iArr[j] > iKey)
			{
				iArr[j + 1] = iArr[j];
			}
			else
			{
				iArr[j + 1] = iKey;
				break;
			}
		}
	}
}
