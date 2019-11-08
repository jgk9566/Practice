#include <iostream>
#include <stack>

#include "QuickSort.h"
#include "Calculator.h"
#include "List.h"
#include "InsertionSort.h"
#include "SmilegateAlgorithm.h"
#include "Timer.h"

#include <string>
#include <string.h>
#include <vector>
#include <list>
#include <memory> // for the smart pointers
#include <functional> // for std::function


// Function for preventing closing the consol winow rightaway
void DontQuitConsole();

// Functions for printing something
void Print(const int* data, int iCount);
void Print(std::vector<int> data);
template<typename T, int b> void Print2(T data);

template <typename T, typename TT> void Push(T& container, int iCount);

// Function for Testing Quick Sort
void TestingQuickSort();
void TestingInsertionSort();


// Classes and Structures
struct _tagVector2;

template<typename T, int a> class CTesting;
class ABC;
class CEntity;
class CPlayer;
class CEnemy;



int main()
{
	//TestingQuickSort();
	TestingInsertionSort();

	DontQuitConsole();

	return 0;
}




void Print(const int* data, int iCount)
{
	for (int i = 0; i < iCount; ++i)
	{
		if (i == iCount - 1)
			std::cout << data[i] << std::endl;
		else
			std::cout << data[i] << ", ";
	}
}

void Print(std::vector<int> data)
{
	int iCount = static_cast<int>(data.size());

	for (int i = 0; i < iCount; ++i)
	{
		if (i == iCount - 1)
			std::cout << data[i] << std::endl;
		else
			std::cout << data[i] << ", ";
	}
}

void DontQuitConsole()
{
	// 콘솔창이 자동 종료되지 않게하기 위함
	std::cin.get();
}

typedef struct _tagVector2
{
	unsigned int x = 15;
	unsigned int y;

	_tagVector2() :
		x(10),
		y(0)
	{
		x = 8;
	}
}Vector2, *PVector2;

template <typename T, int a = 0>
class CTesting
{
public:
	CTesting()	:
		a(0)
	{
		std::cout << "Change worked" << std::endl;
		std::cout << "Change did not work" << std::endl;
		std::cout << a << std::endl;
	}
	~CTesting()
	{
	}
};

template <typename T, int b = 0>
void Print2(T data)
{
	std::cout << data << " " << b << std::endl;;
}

template <typename T, typename TT>
void Push(T& container, int iCount)
{
	TT test;
	//CTimer Time2;
	for (int i = 0; i < iCount; ++i)
	{
		container.push_back(test);

	}

	CTimer Time;
	for (int i = 0; i < iCount; ++i)
	{
		container.pop_back();
	}
}

class ABC
{
public:
	ABC() = default;
	ABC(const int& aa) :
		iNumber(aa),
		strName("Unknown")
	{
	}
	ABC(const std::string& Name) :
		iNumber(0),
		strName(Name)
	{
	}

private:
	int iNumber;
	std::string strName;

public:
	void Print(int a)
	{
		std::cout << "Integer : " << a << std::endl;
	}
};

class CEntity
{
public:
	CEntity()	:
		x(0.f),
		y(0.f)
	{
		std::cout << "Constructor" << std::endl;
	}
	~CEntity()
	{
		std::cout << "Destructor" << std::endl;
	}

public:
	float x;
	float y;

public:
	virtual void PrintFunc()
	{
	}
};

class CPlayer : public CEntity
{
public:
	void Print()
	{
		std::cout << "Successfully Printed" << std::endl;
	}
};

class CEnemy : public CEntity
{
	static std::function<void(CEntity, int)>	m_Function;

	void Add(int x, int y)
	{
		std::cout << "X +" << "Y" << " =" << x + y << std::endl;
	}
};

void TestingQuickSort()
{
	int Array[] = { 5, 6, 3, 2, 10, 8, 9, 7, 1, 4 };
	std::vector<int> vecData = { 5, 6, 3, 2, 10, 8, 9, 7, 1, 4 };

	CQuickSort QuickSortArray(Array, 10);
	CQuickSort QuickSortVector(vecData);

	QuickSortArray.QuickSort(Array, 0, 9);
	QuickSortVector.QuickSortVector(vecData, 0, 9);

	std::cout << "After Sorting(array) : ";
	Print(Array, 10);
	std::cout << "After Sorting(vector) : ";
	Print(vecData);
}

void TestingInsertionSort()
{
	int Array[] = { 5, 6, 3, 2, 10, 8, 9, 7, 1, 4, 15, 13, 17, 19, 20, 11, 12, 18, 14, 16 };
	std::vector<int> vecData = { 5, 6, 3, 2, 10, 8, 9, 7, 1, 4 };

	CInsertionSort InsertionSort;

	InsertionSort.InsertionSort(Array, 20);
	InsertionSort.InsertionSort(vecData, vecData.size());

	std::cout << "After Sorting(array) : ";
	Print(Array, 20);
	std::cout << "After Sorting(vector) : ";
	Print(vecData);
}