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

	// ������ Ȧ���� ������ False
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
				// ���� Top�� ��ȣ�� ��
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
		// ���� ��, �� ���� ���ܷ� ó��
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

		// �߰� ��ȣ�� ó��
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
	
	char* cM;
	char* cN = strtok_s(cInputNM, " ", &cM);

	int iM, iN;
	iM = atoi(cM);
	iN = atoi(cN);

	std::vector<UIButton>	vecButtonInfo;

	for (int i = 0; i < iN; ++i)
	{
		char cInputLRBT[100] = {};
		gets_s(cInputLRBT);

		char* cRectInfo;
		char* cRectNext;
		cRectInfo = strtok_s(cInputLRBT, " ", &cRectNext);
		
		UIButton Button;

		Button.L = atoi(cRectInfo);

		cRectInfo = strtok_s(cRectNext, " ", &cRectNext);
		Button.R = atoi(cRectInfo);

		cRectInfo = strtok_s(cRectNext, " ", &cRectNext);
		Button.B = atoi(cRectInfo);

		Button.T = atoi(cRectNext);

		Button.iButtonNumber = i + 1;

		vecButtonInfo.push_back(Button);
	}

	std::vector<ClickPos>	vecClickPos;

	for (int i = 0; i < iM; ++i)
	{
		char cInputXY[100] = {};
		gets_s(cInputXY);

		char* cRectInfo;
		char* cRectNext;
		cRectInfo = strtok_s(cInputXY, " ", &cRectNext);

		ClickPos	Pos;
		Pos.X = atoi(cRectInfo);
		Pos.Y = atoi(cRectNext);

		vecClickPos.push_back(Pos);
	}
	
	// ��ư ��ŭ ���鼭 Ŭ���� ������ ��ǥ�� �������� �˻�
	for (int i = 0; i < iM; ++i)
	{
		for (int j = iN - 1; j >= 0; --j)
		{
			// Ŭ����ǥ x�� �簢�� L, R / Ŭ����ǥ y�� �簢�� B, T �˻�
			if (vecButtonInfo[j].L <= vecClickPos[i].X && vecButtonInfo[j].R >= vecClickPos[i].X &&
				vecButtonInfo[j].B <= vecClickPos[i].Y && vecButtonInfo[j].T >= vecClickPos[i].Y)
			{
				++vecButtonInfo[j].iClickedCount;
				break;
			}
		}
	}

	// ���
	for (int i = 0; i < vecButtonInfo.size(); ++i)
	{
		std::cout << "Button #" << vecButtonInfo[i].iButtonNumber << ": " << vecButtonInfo[i].iClickedCount << std::endl;
	}

	return;
}

char * CSmilegateAlgorithm::StrTok(char * string, const char * change, char ** context)
{
	const char* text;
	static char* c = NULL;



	return nullptr;
}

