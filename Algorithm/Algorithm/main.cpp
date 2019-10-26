#include <iostream>

#include "QuickSort.h"
#include "Calculator.h"

using namespace std;

// 출력을 위한 함수
void Print(const int* data, int iCount)
{
	for (int i = 0; i < iCount; ++i)
	{
		std::cout << data[i] << ", ";
	}

	std::cout << std::endl;
}

void Print(std::vector<int> data, int iCount)
{
	for (int i = 0; i < iCount; ++i)
	{
		std::cout << data[i] << ", ";
	}

	std::cout << std::endl;
}

float Calculate(int iNum1, int iNum2, char cSign)
{
	float fResult = 0;

	switch (cSign)
	{
	case '+':
		fResult = iNum1 + iNum2;
		break;
	case '-':
		fResult = iNum1 - iNum2;
		break;
	case '*':
		fResult = iNum1 * iNum2;
		break;
	case '/':
		fResult = iNum1 / iNum2;
		break;
	default:		
		break;
	}

	return fResult;
}

void DontQuitConsole()
{
	// 중단 걸기 위해서
	int iNum;
	std::cin >> iNum;
}

class A
{
};

class B
{

	virtual void print()
	{
	}
	virtual void print2()
	{
	}

	char ctest1;
	char ctest2;
	int iInt;
	char ctest3;
};

int main()
{
	int Num[10] = { 1, 4, 5, 6, 2, 3, 8, 9, 10, 7 };
	std::vector<int> vecNum;

	int iSize = sizeof(Num) / sizeof(int);

	for (int i = 0; i < iSize; ++i)
	{
		vecNum.push_back(Num[i]);
	}

	CQuickSort pSort;

	// 정렬 전
	Print(vecNum, vecNum.size());

	//pSort.QuickSort(0, 9, Num);
	//pSort.QuickSort(Num, 0, 9);
	pSort.QuickSort(vecNum, 0, 9);

	// 정렬 이후
	Print(vecNum, vecNum.size());
	

	/*char cTest = 0;

	for (int i = 0; i < 128; ++i)
	{
		cTest = i;
		
		std::cout << i << ": " << cTest << std::endl;
	}

	B b;

	size_t count = sizeof(b);

	cout << count << endl;*/

	/*A a;
	count = sizeof(a);
	cout << count << endl;*/

	// const
	/*const int** foo = 0;
	foo = 0x000;
	*foo = 0x000;
	**foo = 10; (x)

	int* const* iPoint = 0;

	iPoint = 0x000; (x)
	*iPoint = 0x000;
	**iPoint = 0x000;

	int** const foo2 = 0;
	foo2 = 0x000; (x)
	*foo2 = 0x000;
	**foo2 = 10;

	int const ** foo1 = 0;
	foo1 = 0x000;
	*foo1 = 0x000;
	**foo1 = 10; (x)

	const int * aabb = 0x000;

	aabb = 0x000;
	*aabb = 10; (x)


	int const * aabb3 = 0x000;
	aabb3 = 0x000;
	*aabb3 = 10; (x)

	const int aaa = 10;
	int const aab = 10;

	aaa = 90; (x)
	aab = 80; (x)*/

	// Simple Calculator
	/*int* iFirstNumber = new int;
	int* iSecondNumber = new int;
	char cSign = NULL;

	cout << "Insert First Number : ";
	cin >> *iFirstNumber;
	
	while (true)
	{
		if (cSign == '+' || cSign == '-' || cSign == '*' || cSign == '/')
			break;

		cout << "Insert Operation Sign (+, -, *, /) : ";
		cin >> cSign;
	}

	cout << "Insert Second Number : ";
	cin >> *iSecondNumber;


	float Result = 0;
	Result = Calculate(*iFirstNumber, *iSecondNumber, cSign);

	cout << "Result : " << Result << endl;

	delete iFirstNumber;
	delete iSecondNumber;*/

	CCalculator Calculator;

	//char cTesting[] = "(9-1/3)*4"; // 34.6667
	//char cTesting[] = "6-1*3"; // 3
	//char cTesting[] = "4*(7+2)"; // 36
	char cTesting[] = "52*(58/9+3-1)/2"; // 219.555556

	std::vector<std::string> vecTesting;
	vecTesting.push_back("52");
	vecTesting.push_back("*");
	vecTesting.push_back("(");
	vecTesting.push_back("58");
	vecTesting.push_back("/");
	vecTesting.push_back("9");
	vecTesting.push_back("+");
	vecTesting.push_back("3");
	vecTesting.push_back("-");
	vecTesting.push_back("1");
	vecTesting.push_back(")");
	vecTesting.push_back("/");
	vecTesting.push_back("2");
	
	double fResult = Calculator.Calculate(vecTesting);

	cout << fixed;
	cout.precision(6);
	cout << fResult << endl;

	DontQuitConsole();

	return 0;
}