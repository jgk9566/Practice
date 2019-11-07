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
	// 콘솔창이 자동 종료되지 않게하기 위함
	std::cin.get();
}

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

template <typename T, int a>
class CTesting
{
public:
	CTesting()
	{
		std::cout << "Change worked" << std::endl;
		std::cout << "Change did not work" << std::endl;
		std::cout << a << std::endl;
	}
	~CTesting()
	{
	}
};

template <typename T, int b>
void Print2(T data)
{
	std::cout << data << " " << b << std::endl;;
}

class CCC
{
public:
	CCC()
	{
		std::cout << "생성자 호출 됨" << std::endl;
	}
	~CCC()
	{
		std::cout << "소멸자 호출 됨" << std::endl;
	}

private:
	int a;
	int b;
};

struct Test
{
	char t[1024];
};

struct Test2
{
	int ii[1024];
	
	Test2()
	{
		for (int i = 0; i < 1024; ++i)
		{
			ii[i] = i;
		}
	}	
};

struct Test3
{
	int a[1000];
};

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
	ABC(const int& aa) 	: 
		iNumber(aa),
		strName("Unknown")
	{
	}
	ABC(const std::string& Name)	:
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
	CEntity()
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

	int main()
	{
		CSmilegateAlgorithm	m_Smilegatealgo;

		m_Smilegatealgo.UIEvent();

	DontQuitConsole();
	
	return 0;
}