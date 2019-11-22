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
���簢���� ����� �� �ʿ��� 4���� �� �� 3���� ��ǥ�� �־��� ��, ������ �� ���� ��ǥ�� ���Ϸ��� �մϴ�.
�� 3���� ��ǥ�� ����ִ� �迭 v�� �Ű������� �־��� ��, ���簢���� ����� �� �ʿ��� ������ �� ����
��ǥ�� return �ϵ��� solution �Լ��� �ϼ����ּ���. ��, ���簢���� �� ���� x��, y�࿡ �����ϸ�, 
�ݵ�� ���簢���� ���� �� �ִ� ��츸 �Է����� �־����ϴ�.

<���ѻ���>
v�� �� ���� ��ǥ�� ����ִ� 2���� �迭�Դϴ�.
v�� �� ���Ҵ� ���� ��ǥ�� ��Ÿ����, ��ǥ�� [x�� ��ǥ, y�� ��ǥ] ������ �־����ϴ�.
��ǥ���� 1 �̻� 10�� ������ �ڿ����Դϴ�.
���簢���� ����� �� �ʿ��� ������ �� ���� ��ǥ�� [x�� ��ǥ, y�� ��ǥ] ������ ��� return ���ּ���.
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
0 �Ǵ� ���� ������ �־����� ��, ������ �̾� �ٿ� ���� �� �ִ� ���� ū ���� �˾Ƴ� �ּ���.
���� ���, �־��� ������ [6, 10, 2]��� [6102, 6210, 1062, 1026, 2610, 2106]�� ���� �� �ְ�, ���� ���� ū ���� 6210�Դϴ�.
0 �Ǵ� ���� ������ ��� �迭 numbers�� �Ű������� �־��� ��, ������ ���ġ�Ͽ� ���� �� �ִ� ���� ū ���� ���ڿ��� �ٲپ� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���� ����
numbers�� ���̴� 1 �̻� 100,000 �����Դϴ�.
numbers�� ���Ҵ� 0 �̻� 1,000 �����Դϴ�.
������ �ʹ� Ŭ �� ������ ���ڿ��� �ٲپ� return �մϴ�.

����� ��
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
