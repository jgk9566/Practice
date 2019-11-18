#include "pch.h"
#include "Calculator.h"

CCalculator::CCalculator()
{
}

CCalculator::~CCalculator()
{
}

double CCalculator::Calculate(const std::vector<std::string>& cEquation)
{
	int iCount = (int)cEquation.size();	

	std::stack<std::string> stackTemp;
	std::queue<std::string> queuePostfix;

	for (int i = 0; i < iCount; ++i)
	{
		bool bNumber = true;
		int iOrder = 0;

		if (cEquation[i] == "+" || cEquation[i] == "-")
		{
			bNumber = false;
			iOrder = 0;
		}
		else if (cEquation[i] == "*" || cEquation[i] == "/")
		{
			bNumber = false;
			iOrder = 1;
		}
		else if (cEquation[i] == "(" || cEquation[i] == ")")
		{
			bNumber = false;
			iOrder = 2;
		}


		if (bNumber)
		{
			queuePostfix.push(cEquation[i]);
		}
		else
		{
			if (cEquation[i] != ")")
			{
				if (stackTemp.empty())
				{
					stackTemp.push(cEquation[i]);
				}
				else if (cEquation[i] == "(")
				{
					stackTemp.push(cEquation[i]);
				}
				else
				{
					// 여기서 연산자 우선순위 체크
					int iStackOrder = 0;
					if (stackTemp.top() == "*" || stackTemp.top() == "/")
					{
						iStackOrder = 1;
					}

					if (iStackOrder >= iOrder)
					{
						if (stackTemp.top() != "(")
						{
							queuePostfix.push(stackTemp.top());
							stackTemp.pop();
						}
					}

					stackTemp.push(cEquation[i]);
				}
			}
			else
			{
				while (true)
				{
					if (stackTemp.empty())
					{
						break;
					}
					else if (stackTemp.top() == "(")
					{
						stackTemp.pop();
						break;
					}

					queuePostfix.push(stackTemp.top());
					stackTemp.pop();
				}
			}
		}		
	}

	while (!stackTemp.empty())
	{
		queuePostfix.push(stackTemp.top());
		stackTemp.pop();
	}

	return CalculatePostFixNumbers(queuePostfix);
}

double CCalculator::CalculatePostFixNumbers(std::queue<std::string>& vecPost)
{
	std::stack<float>	stackResult;

	while (!vecPost.empty())
	{
		if (vecPost.front() == "+")
		{
			if (!stackResult.empty())
			{
				float fCalculated = 0;

				// 스택에 쌓인 2개 번호를 빼서 + 연산자와 연산 후 다시 스택에 넣는다.
				float fNum1 = stackResult.top();
				stackResult.pop();
				float fNum2 = stackResult.top();
				stackResult.pop();

				fCalculated = fNum2 + fNum1;

				stackResult.push(fCalculated);
			}
		}
		else if (vecPost.front() == "-")
		{
			if (!stackResult.empty())
			{
				float fCalculated = 0;

				// 스택에 쌓인 2개 번호를 빼서 - 연산자와 연산 후 다시 스택에 넣는다.
				float fNum1 = stackResult.top();
				stackResult.pop();
				float fNum2 = stackResult.top();
				stackResult.pop();

				fCalculated = fNum2 - fNum1;

				stackResult.push(fCalculated);
			}
		}
		else if (vecPost.front() == "*")
		{
			if (!stackResult.empty())
			{
				float fCalculated = 0;

				// 스택에 쌓인 2개 번호를 빼서 * 연산자와 연산 후 다시 스택에 넣는다.
				float fNum1 = stackResult.top();
				stackResult.pop();
				float fNum2 = stackResult.top();
				stackResult.pop();

				fCalculated = fNum2 * fNum1;

				stackResult.push(fCalculated);
			}
		}
		else if (vecPost.front() == "/")
		{
			if (!stackResult.empty())
			{
				float fCalculated = 0;

				// 스택에 쌓인 2개 번호를 빼서 / 연산자와 연산 후 다시 스택에 넣는다.
				float fNum1 = stackResult.top();
				stackResult.pop();
				float fNum2 = stackResult.top();
				stackResult.pop();

				fCalculated = fNum2 / fNum1;

				stackResult.push(fCalculated);
			}
		}
		else
		{
			std::string strNumber = vecPost.front();
			stackResult.push(atof(strNumber.c_str()));
		}		
		
		vecPost.pop();
	}
	
	float fResult = stackResult.top();

	return fResult;
}
