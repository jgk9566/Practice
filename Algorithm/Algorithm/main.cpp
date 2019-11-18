
#include "pch.h"
#include "Macro.h"

#include "QuickSort.h"
#include "Calculator.h"
#include "List.h"
#include "InsertionSort.h"
#include "SmilegateAlgorithm.h"
#include "Timer.h"


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

// Random Number Generator
void RandomNumberGenerator(int* array, int iArrSize);
void RandomNumberGenerator(std::vector<int>* vecOutput, int iCount);


// Classes and Structures
struct _tagVector2;

template<typename T, int a> class CTesting;
class ABC;
class CEntity;
class CPlayer;
class CEnemy;



int main()
{
	TestingQuickSort();
	TestingInsertionSort();

	DontQuitConsole();
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

void RandomNumberGenerator(std::vector<int>* vecOutput, int iCount)
{
	for (int i = 0; i < iCount; ++i)
	{
		vecOutput->push_back(i);
	}

	std::vector<int>::iterator	iterStart = vecOutput->begin();
	std::vector<int>::iterator	iterEnd = vecOutput->end();

	std::random_shuffle(iterStart, iterEnd);
}

void RandomNumberGenerator(int* array, int iArrSize)
{
	for (int i = 0; i < iArrSize; ++i)
	{
		array[i] = i;
	}

	// std::begin() and std::end() can be used, but pointers do not work

	std::random_shuffle(&array[0], &array[iArrSize - 1]);
}


void TestingQuickSort()
{
	std::cout << "==================== Quick Sort Testing ====================" << std::endl;

	int Array[30];
	std::vector<int> vecData;

	// Generate random numbers and print
	RandomNumberGenerator(&vecData, 30);
	RandomNumberGenerator(Array, 30);
	Print(vecData);
	Print(Array, 30);

	// Sort those random numbers
	CQuickSort QuickSort;
	QuickSort.QuickSort2(Array, 0, 29);
	QuickSort.QuickSort2(vecData, 0, static_cast<int>(vecData.size() - 1));

	// Print sorted numbers
	std::cout << "After Sorting(array) : ";
	Print(Array, 30);
	std::cout << "After Sorting(vector) : ";
	Print(vecData);
}

void TestingInsertionSort()
{
	std::cout << "==================== Insertion Sort Testing ====================" << std::endl;

	int Array[] = { 5, 6, 3, 2, 10, 8, 9, 7, 1, 4, 15, 13, 17, 19, 20, 11, 12, 18, 14, 16 };
	std::vector<int> vecData = { 5, 6, 3, 2, 10, 8, 9, 7, 1, 4 };
	
	CInsertionSort InsertionSortArray(Array, 20);
	CInsertionSort InsertionSortVector(vecData);

	InsertionSortArray.InsertionSort2(Array, 20);
	InsertionSortVector.InsertionSort2(vecData);

	std::cout << "After Sorting(array) : ";
	Print(Array, 20);
	std::cout << "After Sorting(vector) : ";
	Print(vecData);
}