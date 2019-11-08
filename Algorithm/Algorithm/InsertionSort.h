#pragma once

#include "Macro.h"

class CInsertionSort
{
public:
	CInsertionSort();
	~CInsertionSort();

public:
	void InsertionSortRef(int * iArr, int iSize);
	void InsertionSort(std::vector<int>& vecData, int iSize);
	void InsertionSort(int* iArr, int iSize);
};

