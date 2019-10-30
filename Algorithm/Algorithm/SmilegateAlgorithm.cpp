#include "SmilegateAlgorithm.h"
#include <iostream>
#include <stack>

CSmilegateAlgorithm::CSmilegateAlgorithm()
{
}


CSmilegateAlgorithm::~CSmilegateAlgorithm()
{
}

bool CSmilegateAlgorithm::Brackets()
{
	char input[100];
	std::cin >> input;

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

void CSmilegateAlgorithm::CellExpansion()
{
	char input[100];
	std::cin.getline(input, 100, '\n');

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

	std::cout << Output << std::endl;
}

void CSmilegateAlgorithm::Triangle()
{
	char input[100];
	std::cin.getline(input, 100, '\n');

	int a, b, c;
	a = atoi(&input[0]);
	b = atoi(&input[2]);
	c = atoi(&input[4]);

	if (a + b <= c)
	{
		std::cout << "No Triangle" << std::endl;
		return;
	}

	int iResult = c * c - (a * a + b * b);

	if (iResult)
	{
		if (iResult < 0)
		{
			std::cout << "Acute Triangle" << std::endl;
		}
		else
		{
			std::cout << "Abtuse Triangle" << std::endl;
		}
	}
	else
	{
		std::cout << "Right Triangle" << std::endl;
	}
}

void CSmilegateAlgorithm::UIEvent()
{
	char cInputNM[100] = {};
	gets_s(cInputNM);
	
	int iIdx = 0;
	char cN[3];
	char cM[5];

	while (cInputNM[iIdx] != ' ')
	{
		cN[iIdx] = cInputNM[iIdx];
		++iIdx;
	}
	cN[iIdx] = '\0';

	int i = 0;
	while (cInputNM[iIdx + 1] != '\0')
	{
		cM[i] = cInputNM[iIdx + 1];
		++iIdx;
		++i;
	}
	cM[i] = '\0';

	int iN = atoi(cN);
	int iM = atoi(cM);

	

	for (int i = 0; i < iN; ++i)
	{
		// 버튼 위치 입력 받기
		char RectLRBT[20] = {};
		gets_s(RectLRBT);
		
		int iIndex = 0;
		

	}




	return;
}

char * CSmilegateAlgorithm::StrTok(char * string, const char * change, char ** context)
{
	const char* text;
	static char* c = NULL;



	return nullptr;
}

