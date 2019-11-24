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
[���� ū��]
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
bool StringCompare(const std::string& first, const std::string& second)
{
	return first + second > second + first ? true : false;
}

void CLineDemoTest::TheLargestNumber(std::vector<int> numbers)
{
	std::string answer;
	
	std::vector<std::string> strNumbers;

	for (int i = 0; i < numbers.size(); ++i)
	{
		strNumbers.push_back(std::to_string(numbers[i]));
	}

	std::sort(strNumbers.begin(), strNumbers.end(), StringCompare);

	for (int i = 0; i < strNumbers.size(); ++i)
	{
		answer += strNumbers[i];
	}

	if (strNumbers[0] == "0")
		answer = "0";

	std::cout << answer << std::endl;

	
	/*vector<string> vecData;
	for (int i = 0; i < numbers.size(); ++i)
	{
		vecData.push_back(to_string(numbers[i]));
	}

	sort(vecData.begin(), vecData.end(), SortCondition);

	for (int i = 0; i < vecData.size(); ++i)
	{
		answer += vecData[i];
	}

	if (answer[0] == '0')
		return "0";*/
}

void CLineDemoTest::SkillTree(std::string skill, std::vector<std::string> skill_trees)
{
	int answer = 0;
	std::vector<std::string> vecTemp;

	std::string strCompare = "";
	for (int i = 0; i < skill.size(); ++i)
	{
		strCompare += std::to_string(i + 1);
	}

	for (int i = 0; i < skill_trees.size(); ++i)
	{
		std::string strTemp = skill_trees[i];

		std::string strNum = "";

		for (int j = 0; j < strTemp.size(); ++j)
		{			
			for (int k = 0; k < skill.size(); ++k)
			{
				if (strTemp[j] == skill[k])
				{
					strNum += std::to_string(k + 1);
					break;
				}					
			}		
		}

		vecTemp.push_back(strNum);
	}

	for (int i = 0; i < vecTemp.size(); ++i)
	{	
		bool bIsTrue = true;
		for (int j = 0; j < vecTemp[i].size(); ++j)
		{			
			if (vecTemp[i][j] != strCompare[j])
			{
				bIsTrue = false;
				break;
			}
		}

		if (bIsTrue)
			++answer;
	}	

	std::cout << answer << std::endl;
}

void CLineDemoTest::MathDropper(std::vector<int> answers)
{
	std::vector<int> answer;
	std::map<int, int> map_total;

	std::vector<int> MathDropper1 = { 1, 2, 3, 4, 5 };
	std::vector<int> MathDropper2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
	std::vector<int> MathDropper3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

	int iCorrectCount1 = 0;
	int iCorrectCount2 = 0;
	int iCorrectCount3 = 0;

	for (int i = 0, j1 = 0, j2 = 0, j3 = 0; i < answers.size(); ++i, ++j1, ++j2, ++j3)
	{
		if (answers[i] == MathDropper1[j1])
			++iCorrectCount1;
		if (answers[i] == MathDropper2[j2])
			++iCorrectCount2;
		if (answers[i] == MathDropper3[j3])
			++iCorrectCount3;


		if (j1 >= MathDropper1.size())
			j1 = 0;

		if (j2 >= MathDropper2.size())
			j2 = 0;

		if (j3 >= MathDropper3.size())
			j3 = 0;
	}
	map_total.insert(std::make_pair(iCorrectCount1, 1));
	map_total.insert(std::make_pair(iCorrectCount2, 2));
	map_total.insert(std::make_pair(iCorrectCount3, 3));
		
	std::map<int, int>::iterator iter = map_total.end();
	std::map<int, int>::iterator iterEnd = map_total.begin();

	int iPrev = 0;
	for (; iter != iterEnd; --iter)
	{
		if (iPrev < iter->first)
		{
			answer.push_back(iter->second);
			iPrev = iter->first;
		}
	}

	if (answer.size() > 1)
		std::sort(answer.begin(), answer.end());

	//return answer;
}

void CLineDemoTest::EcryptedString(std::string ecryptedString)
{
	std::string answer;

	std::stack<std::string> strLetters;
	std::stack<std::string> strBrackets;
	std::stack<char> iNumbers;

	for (int i = 0; i < ecryptedString.length(); ++i)
	{
		if (ecryptedString[i] >= '0' && ecryptedString[i] <= '9')
			iNumbers.push(ecryptedString[i]);
		else if (ecryptedString[i] == '}' || ecryptedString[i] == '{')
			strBrackets.push(std::to_string(ecryptedString[i]));
		else
			strLetters.push(std::to_string(ecryptedString[i]));
	}

	if (strLetters.empty())
	{
		answer = "ERROR";
		return;
	}
}

int CLineDemoTest::Heightsolution(std::vector<int> heightList)
{
	int nResult = 0;

	int iPrevHeight = 0;
	for (int i = 1; i < heightList.size(); ++i)
	{
		iPrevHeight = heightList[i - 1];
		if (iPrevHeight > heightList[i])
		{
			nResult += iPrevHeight - heightList[i];
			continue;
		}


	}

	return nResult;
}

int CLineDemoTest::YootSolution(std::vector<int> inputList)
{
	int answer = 0;
	bool bShortCut = false;
	bool bShortCut2 = false;
	bool bShortCut3 = false;

	for (int i = 0; i < inputList.size(); ++i)
	{
		if (bShortCut)
		{
			if (inputList[i] != -1)
				answer += 14;

			bShortCut = false;
		}

		answer += inputList[i];

		if (bShortCut3)
		{
			if (inputList[i] != -1)
				answer += 4;

			//bShortCut3 = false;
		}		

		if (answer == 0)
			return answer;

		if (answer == 5)
		{
			bShortCut = true;
			bShortCut2 = true;
		}

		if (bShortCut2 && answer == 22)
		{
			bShortCut2 = false;
			bShortCut3 = true;
		}

		if (answer == 10)
		{
			bShortCut = true;
		}
	}

	return answer;
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

/////////////////////////////////////////////////////////////////////////////////////

bool MovingStones(std::vector<int> stones)
{
	std::unordered_map<int, bool> stone;
	std::stack<int> stone_stack;

	int iCount = stones.size();

	for (int i = 0; i < iCount; ++i)
	{
		stone[stones[i]] = true;
	}

	int Index = 0;
	int iOffset = 1;

	stone_stack.push(Index);
	stone[Index] = false;

	std::unordered_map<int, bool>::iterator iterator;

	for (; !stone_stack.empty();)
	{
		if (Index == stones[iCount - 1])
			return true;

		Index = stone_stack.top();
		iterator = stone.find(Index + iOffset - 1);

		if (iterator != stone.end() && iterator->second)
		{
			iterator->second = false;
			stone_stack.push(iterator->first);
			continue;
		}

		iterator = stone.find(Index + iOffset);

		if (iterator != stone.end() && iterator->second)
		{
			iOffset += 1;
			iterator->second = false;
			stone_stack.push(iterator->first);
			continue;
		}

		iterator = stone.find(Index + iOffset + 1);
		if (iterator != stone.end() && iterator->second)
		{
			iOffset = iOffset + 2;

			iterator->second = false;
			stone_stack.push(iterator->first);
			continue;
		}

		stone_stack.pop();
	}

	return false;
}