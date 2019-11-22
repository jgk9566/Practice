#include "pch.h"
#include "LineDemoTest.h"

CLineDemoTest::CLineDemoTest()
{
	m_vecRandomRect.resize(4);
	for (int i = 0; i < 4; ++i)
	{
		m_vecRandomRect[i].resize(2);
	}

	GenerateRandomRect();
}

CLineDemoTest::~CLineDemoTest()
{
}

/*
직사각형을 만드는 데 필요한 4개의 점 중 3개의 좌표가 주어질 때, 나머지 한 점의 좌표를 구하려고 합니다.
점 3개의 좌표가 들어있는 배열 v가 매개변수로 주어질 때, 직사각형을 만드는 데 필요한 나머지 한 점의
좌표를 return 하도록 solution 함수를 완성해주세요. 단, 직사각형의 각 변은 x축, y축에 평행하며, 
반드시 직사각형을 만들 수 있는 경우만 입력으로 주어집니다.

<제한사항>
v는 세 점의 좌표가 들어있는 2차원 배열입니다.
v의 각 원소는 점의 좌표를 나타내며, 좌표는 [x축 좌표, y축 좌표] 순으로 주어집니다.
좌표값은 1 이상 10억 이하의 자연수입니다.
직사각형을 만드는 데 필요한 나머지 한 점의 좌표를 [x축 좌표, y축 좌표] 순으로 담아 return 해주세요.
*/
void CLineDemoTest::FindFinalRectPosition(const std::vector<std::vector<int>>& vecInput)
{
	std::vector<int> vecOutput;
	int iValue = 0;

	// X axis
	for (int i = 0; i < 3; ++i)
	{
		iValue ^= vecInput[i][0];
	}

	vecOutput.push_back(iValue);

	iValue = 0;

	// Y axis
	for (int i = 0; i < 3; ++i)
	{
		iValue ^= vecInput[i][1];
	}

	vecOutput.push_back(iValue);


	std::cout << "(" << vecOutput[0] << ", " << vecOutput[1] << ")\n";

	if (vecOutput[0] == m_vecRandomRect[3][0] && vecOutput[1] == m_vecRandomRect[3][1])
		std::cout << "Correct Answer" << std::endl;
	else
		std::cout << "Wrong Answer" << std::endl;
}

/*
0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내 주세요.
예를 들어, 주어진 정수가 [6, 10, 2]라면 [6102, 6210, 1062, 1026, 2610, 2106]를 만들 수 있고, 이중 가장 큰 수는 6210입니다.
0 또는 양의 정수가 담긴 배열 numbers가 매개변수로 주어질 때, 순서를 재배치하여 만들 수 있는 가장 큰 수를 문자열로 바꾸어 return 하도록 solution 함수를 작성해주세요.

제한 사항
numbers의 길이는 1 이상 100,000 이하입니다.
numbers의 원소는 0 이상 1,000 이하입니다.
정답이 너무 클 수 있으니 문자열로 바꾸어 return 합니다.

입출력 예
numbers
return
[6, 10, 2]
6210
[3, 30, 34, 5, 9]
9534330
*/
void CLineDemoTest::FindTheLargestNumber(std::vector<int> vecNumber)
{

}

const std::vector<std::vector<int>>& CLineDemoTest::GetRandomRectVector()
{
	return m_vecRandomRect;
}

void CLineDemoTest::PrintInputPositions()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			std::cout << m_vecRandomRect[i][j] << " ";
		}
		
		std::cout << "\n";
	}
}

void CLineDemoTest::GenerateRandomRect()
{
	// first two positions (they do not have to be same pos)
	for (int i = 0; i < 2; ++i)
	{
		int iX = rand() % 1000000000;
		int iY = rand() % 1000000000;

		m_vecRandomRect[i][0] = iX;
		m_vecRandomRect[i][1] = iY;
	}

	int iRandIdx = rand() % 2;

	m_vecRandomRect[2][0] = m_vecRandomRect[iRandIdx][0];
	m_vecRandomRect[2][1] = m_vecRandomRect[static_cast<int>(1 - iRandIdx)][1];

	m_vecRandomRect[3][0] = m_vecRandomRect[static_cast<int>(1 - iRandIdx)][0];
	m_vecRandomRect[3][1] = m_vecRandomRect[iRandIdx][1];
}
