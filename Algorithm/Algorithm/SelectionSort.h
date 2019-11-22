#pragma once

class CSelectionSort
{

public:
	CSelectionSort();
	~CSelectionSort();

public:
	void SelectionSort(int* pData, int iSize);
	void SelectionSort(std::vector<int>& vecData);
	void SelectionSort2(int* pData, int iSize);

};

