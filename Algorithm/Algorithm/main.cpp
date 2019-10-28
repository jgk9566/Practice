#include <iostream>
#include <stack>

#include "QuickSort.h"
#include "Calculator.h"
#include "List.h"
#include "InsertionSort.h"

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

// 스마일게이트 알고리즘
bool Brackets()
{
	char input[100];
	cin >> input;

	std::stack<char>	stackInput;
	int					iSize = 0;

	iSize = (int)strlen(input);

	// 갯수가 홀수면 무조건 False
	if (iSize % 2 != 0)
		return false;

	for (int i = 0; i < iSize; ++i)
	{
		if (input[i] == '(' || input[i] == '{' || input[i] == '[')
		{
			stackInput.push(input[i]);
		}
		else
		{
			if (stackInput.empty())
				return false;
			else
			{
				// 스택 Top과 괄호형 비교
				char cCompare = NULL;

				switch (input[i])
				{
				case ')':
					cCompare = '(';
					break;
				case '}':
					cCompare = '{';
					break;
				case ']':
					cCompare = '[';
					break;
				default:
					break;
				}
				
				if (cCompare == stackInput.top())
				{
					stackInput.pop();
					continue;
				}
				else
				{
					return false;
				}
			}
		}
	}

	return true;
}

void CellExpansion()
{
	char input[100];
	cin.getline(input, 100, '\n');
	//cin >> input;

	char Output[100] = {};
	char cChange = '0' + '1';

	int iIdx = 0;
	while (input[iIdx] != ' ')
	{
		Output[iIdx] = input[iIdx];
		++iIdx;
	}

	int iCount = atoi(&input[iIdx + 1]);

	for (int i = 0; i < iCount; ++i)
	{
		// 제일 앞, 뒤 먼저 예외로 처리
		if (input[0] + input[iIdx - 2] == cChange)
		{
			if (input[iIdx - 1] == '1')
				Output[iIdx - 1] = '0';
			else
				Output[iIdx - 1] = '1';
		}
		if (input[1] + input[iIdx - 1] == cChange)
		{
			if (input[0] == '1')
				Output[0] = '0';
			else
				Output[0] = '1';
		}

		// 중간 번호들 처리
		for (int j = 1; j < iIdx - 1; ++j)
		{
			if (input[j - 1] + input[j + 1] == cChange)
			{
				if (input[j] == '1')
					Output[j] = '0';
				else
					Output[j] = '1';
			}
		}

		for (int k = 0; k < iIdx; ++k)
		{
			input[k] = Output[k];
		}
	}

	cout << Output << endl;
}

void Triangle()
{
	char input[100];
	cin.getline(input, 100, '\n');

	int a, b, c;
	a = atoi(&input[0]);
	b = atoi(&input[2]);
	c = atoi(&input[4]);

	if (a + b <= c)
	{
		cout << "No Triangle" << endl;
		return;
	}

	int iResult = c * c - (a * a + b * b);

	if (iResult)
	{
		if (iResult < 0)
		{
			cout << "Acute Triangle" << endl;
		}
		else
		{
			cout << "Abtuse Triangle" << endl;
		}
	}
	else
	{
		cout << "Right Triangle" << endl;
	}
}

typedef struct _tagRectangle
{
	unsigned int L;
	unsigned int R;
	unsigned int B;
	unsigned int T;
}Rectangle, *PRectangle;

typedef struct _tagVector2
{
	unsigned int x = 15;
	unsigned int y;

	_tagVector2()	:
		x(10)
	{
		x = 8;
	}
}Vector2, *PVector2;

void UIEvent()
{
	
	//PVector2 vect2 = static_cast<PVector2>(operator new(sizeof(Vector2)));
	//PVector2 vect2 = (PVector2)malloc(sizeof(Vector2));
	//PVector2 add = new (vect2) Vector2();

	PVector2 vec = new Vector2;
	new (vec) Vector2();

	char inputNM[8];
	cin.getline(inputNM, 8, '\n');
	
	char inputN[2];
	inputN[0] = inputNM[0];
	inputN[1] = inputNM[1];
	
	char inputM[4];
	inputM[0] = inputNM[3];
	inputM[1] = inputNM[4];
	inputM[2] = inputNM[5];
	inputM[3] = inputNM[6];
	
	std::string strN(inputN);
	std::string strM(inputM);

	int iN = atoi(strN.c_str());
	int iM = atoi(strM.c_str());

	vector<string> vecStrRect;
	vector<Rectangle> vecRectInfo;
	
	for (int i = 0; i < iN; ++i)
	{
		char inputLRBT[256] = {};
		cin.getline(inputLRBT, 256, '\n');	
		
		string strLRBT = inputLRBT;

		vecStrRect.push_back(strLRBT);
	}
	
	for (int i = 0; i < vecStrRect.size(); ++i)
	{
		Rectangle Rect;

		string strTemp = vecStrRect[i].substr(0, vecStrRect[i].find(" "));
		Rect.L = atoi(strTemp.c_str());
		
		vecStrRect[i].erase(vecStrRect[i].find(" ") + strlen(" "));
		strTemp = vecStrRect[i].substr(0, vecStrRect[i].find(" "));
		Rect.R = atoi(strTemp.c_str());

		vecStrRect[i].erase(vecStrRect[i].find(" ") + strlen(" "));
		strTemp = vecStrRect[i].substr(0, vecStrRect[i].find(" "));
		Rect.B = atoi(strTemp.c_str());

		vecStrRect[i].erase(vecStrRect[i].find(" ") + strlen(" "));
		strTemp = vecStrRect[i].substr(0, vecStrRect[i].find(" "));
		Rect.T = atoi(strTemp.c_str());

		vecRectInfo.push_back(Rect);
	}

	// check
	vector<string> vecStrClick;
	vector<Vector2> vecClickPos;

	for (int i = 0; i < iM; ++i)
	{
		char cClick[256] = {};
		cin.getline(cClick, 256, '\n');

		string strClick = cClick;

		vecStrClick.push_back(strClick);
	}

	for (int i = 0; i < vecStrClick.size(); ++i)
	{
		Vector2 Position;
		
		string strTemp = vecStrClick[i].substr(0, vecStrClick[i].find(" "));
		Position.x = atoi(strTemp.c_str());

		vecStrClick[i].erase(vecStrClick[i].find(" ") + strlen(" "));
		strTemp = vecStrClick[i].substr(0, vecStrClick[i].find(" "));
		Position.y = atoi(strTemp.c_str());

		vecClickPos.push_back(Position);
	}

	return;

}

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


	CList<int> m_pList;

	m_pList.Push_Back(10);
	m_pList.Push_Back(9);
	m_pList.Push_Back(4);
	m_pList.Push_Back(2);

	/*char input[100];
	scanf_s("%s", input);
	printf("Hello Goorm! Your input is %s", input);
	
	int iNum = atoi(input);

	for (int i = 1; i <= iNum; ++i)
	{
		if (iNum % i == 0)
		{
			printf("%d ", i);
		}
	}*/


	/*CInsertionSort m_InsertionSort;

	m_InsertionSort.InsertionSort(Num, 10);

	Print(Num, 10);*/
	
	UIEvent();


	/*if (Brackets())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;*/

	DontQuitConsole();

	return 0;
}