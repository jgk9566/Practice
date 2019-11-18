#pragma once

#include "Macro.h"

class CInsertionSort
{
public:
	CInsertionSort();
	CInsertionSort(int* iArr, int iNumOfElements);
	CInsertionSort(std::vector<int> vecData);
	~CInsertionSort();

public:
	void InsertionSortRef(int * iArr, int iSize);
	void InsertionSort(std::vector<int>& vecData, int iSize);
	void InsertionSort(int* iArr, int iSize);
	void InsertionSort1(int* pArr, int iSize);
	void InsertionSort1(std::vector<int>& vecData);
	void InsertionSort2(int* pArr, int iSize);
	void InsertionSort2(std::vector<int>& vecData);
};

