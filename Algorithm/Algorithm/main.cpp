#include <iostream>

#include "QuickSort.h"

// ����� ���� �Լ�
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

	// ���� ��
	Print(Num, 10);

	//pSort.QuickSort(0, 9, Num);
	pSort.QuickSort(Num, 0, 9);

	// ���� ����
	Print(Num, 10);

	int iNum;
	std::cin >> iNum;

	return 0;
}