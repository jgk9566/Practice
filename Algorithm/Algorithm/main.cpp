#include <iostream>

#include "QuickSort.h"

// 출력을 위한 함수
void Print(const int* data, int iCount)
{
	for (int i = 0; i < iCount; ++i)
	{
		std::cout << data[i] << ", ";
	}

	std::cout << std::endl;
}

int main()
{
	int Num[10] = { 1, 4, 5, 6, 2, 3, 8, 9, 10, 7 };

	CQuickSort pSort;

	// 정렬 전
	Print(Num, 10);

	//pSort.QuickSort(0, 9, Num);
	pSort.QuickSort(Num, 0, 9);

	// 정렬 이후
	Print(Num, 10);

	int iNum;
	std::cin >> iNum;

	return 0;
}