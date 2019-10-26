#include "Calculator.h"
#include <stack>


CCalculator::CCalculator()
{
}


CCalculator::~CCalculator()
{
}

float CCalculator::Calculate(const char * cEquation)
{
	int iCount = (int)strlen(cEquation);

	std::stack<char> stackTemp;
	std::stack<char> stackPostfix;
		
	for (int i = 0; i < iCount; ++i)
	{
		bool bNumber = true;
		int iOrder = 0;

		switch (cEquation[i])
		{
		case '+':
			bNumber = false;
			break;
		case '-':
			bNumber = false;
			break;
		case '*':
			bNumber = false;
			iOrder = 1;
			break;
		case '/':
			break;
			bNumber = false;
			iOrder = 1;
		case '(':
			bNumber = false;
			break;
		case ')':
			bNumber = false;
			break;
		default:
			break;
		}


		if (bNumber)
		{
			stackPostfix.push(cEquation[i]);
		}
		else
		{
			if (cEquation[i] != ')')
			{
				int iTopOrder = 0;

				if (!stackTemp.empty())
				{
					if (stackTemp.top() == '*' || stackTemp.top() == '/')
						iTopOrder = 1;
				}				

				// ���ÿ� �ֱ� ���� ������ �켱���� �˻�. �켱������ ���ų� ���ÿ��ִ� �����ں��� ������ �����ڸ� ���� �̵�.
				if (iTopOrder >= iOrder && !stackTemp.empty())
				{
					char cTemp = stackTemp.top();
					stackTemp.pop();
					stackTemp.push(cEquation[i]);

					stackPostfix.push(cTemp);
				}				
				else
				{
					stackTemp.push(cEquation[i]);
				}
			}
			else
			{
				while (!stackTemp.empty())
				{
					if (stackTemp.top() == '(')
					{
						stackTemp.pop();
						break;
					}
					else
					{
						stackPostfix.push(stackTemp.top());
						stackTemp.pop();
					}
				}				
			}
		}
	}

	while (!stackTemp.empty())
	{
		char cTemp = stackTemp.top();
		
		stackPostfix.push(cTemp);

		stackTemp.pop();
	}

	return 0.0f;
}
