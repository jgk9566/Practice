#include "pch.h"
#include "Macro.h"

#include "QuickSort.h"
#include "Calculator.h"
#include "List.h"
#include "InsertionSort.h"
#include "SmilegateAlgorithm.h"
#include "Timer.h"
#include "SelectionSort.h"
#include "LineDemoTest.h"
#include "Programmers.h"


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
void TestingSelectionSort();
void TestingLineDemoAlgorithm();

// Random Number Generator
void RandomNumberGenerator(int* array, int iArrSize);
void RandomNumberGenerator(std::vector<int>* vecOutput, int iCount);


// Set console size
void SetColsoleSize(int iWidth, int iHieght);

// Classes and Structures
struct _tagVector2;

// *remember that only pointer class types can be forward declared.
template<typename T, int a> class CTesting;
class ABCD;
class CEntity;
class CPlayer;
class CEnemy;


int main()
{
	SetColsoleSize(1200, 540);

	// functions for testing
	TestingQuickSort();
	TestingInsertionSort();
	TestingSelectionSort();

	TestingLineDemoAlgorithm();


	CProgrammers test;
	std::vector<int> progresses = {93, 30, 55, 90, 10};
	std::vector<int> speeds = {1, 30, 5, 5, 10};
	std::vector<int> answers = { 1, 3, 2, 4, 2 };

	test.Exam(answers);
	

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

class ABCD
{
public:
	ABCD() = default;
	ABCD(const int& aa) :
		iNumber(aa),
		strName("Unknown")
	{
	}
	ABCD(const std::string& Name) :
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
	void PrintMyself()
	{
		std::cout << "Number : " << iNumber << std::endl;
		std::cout << "Name : " << strName << std::endl;
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

// Creates random numbers
// *vecOutput : stl vector<int> type that you want to store data.
// iCount : number of elements that you want to generate.
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

// Creates random numbers
// array : array that you want to store data.
// iArrSize : size of array.
void RandomNumberGenerator(int* array, int iArrSize)
{
	for (int i = 0; i < iArrSize; ++i)
	{
		array[i] = i;
	}

	// std::begin() and std::end() can be used, but pointers do not work

	std::random_shuffle(&array[0], &array[iArrSize - 1]);
}

void SetColsoleSize(int iWidth, int iHeight)
{
	HWND hConsole = GetConsoleWindow();

	RECT ConsoleRect;
	GetWindowRect(hConsole, &ConsoleRect);

	MoveWindow(hConsole, ConsoleRect.left, ConsoleRect.top, iWidth, iHeight, TRUE);
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
	QuickSort.QuickSort4(Array, 0, 29);
	QuickSort.QuickSort4(vecData, 0, static_cast<int>(vecData.size() - 1));

	// Print sorted numbers
	std::cout << "After Sorting(array) : ";
	Print(Array, 30);
	std::cout << "After Sorting(vector) : ";
	Print(vecData);
}

void TestingInsertionSort()
{
	std::cout << "==================== Insertion Sort Testing ====================" << std::endl;

	int Array[30];
	std::vector<int> vecData;

	RandomNumberGenerator(Array, 30);
	RandomNumberGenerator(&vecData, 30);

	CInsertionSort InsertionSortArray(Array, 30);
	CInsertionSort InsertionSortVector(vecData);

	InsertionSortArray.InsertionSort4(Array, 30);
	InsertionSortVector.InsertionSort4(vecData);

	std::cout << "After Sorting(array) : ";
	Print(Array, 30);
	std::cout << "After Sorting(vector) : ";
	Print(vecData);
}

void TestingSelectionSort()
{
	std::cout << "==================== Selection Sort Testing ====================" << std::endl;

	int iArray[30];
	std::vector<int> vecData;

	RandomNumberGenerator(iArray, 30);
	RandomNumberGenerator(&vecData, 30);

	std::cout << "Before Sorting (array) : ";
	Print(iArray, 30);
	std::cout << "Before Sorting (vector) : ";
	Print(vecData);

	CSelectionSort pSelectionSort;
	pSelectionSort.SelectionSort2(iArray, 30);
	pSelectionSort.SelectionSort2(vecData);

	std::cout << "After Sorting (array) : ";
	Print(iArray, 30);
	std::cout << "After Sorting (vector) : ";
	Print(vecData);
}

void TestingLineDemoAlgorithm()
{
	std::cout << "============ Line Studio Demo Test ============" << std::endl;

	CLineDemoTest RectTest = CLineDemoTest();
	
	//"CBD"
	//["BACDE", "CBADF", "AECB", "BDA"]
	std::string inputA = "CBD";
	std::vector<std::string> vecInput;
	vecInput.push_back("BACDE");
	vecInput.push_back("CBADF"); // true
	vecInput.push_back("AECB"); // true
	vecInput.push_back("BDA");
	vecInput.push_back("AEF"); // true
	vecInput.push_back("C"); // true

	RectTest.SkillTree(inputA, vecInput);
	
	// Largest Number [3, 30, 34, 5, 9]
	std::vector<int> vecInput2;
	vecInput2.push_back(3);
	vecInput2.push_back(30);
	vecInput2.push_back(34);
	vecInput2.push_back(5);
	vecInput2.push_back(9);

	RectTest.TheLargestNumber(vecInput2);

	//RectTest.PrintInputPositions();

	//RectTest.FindFinalRectPosition(RectTest.GetRandomRectVector());

	//std::vector<int> vector;

}