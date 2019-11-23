#pragma once

class CLineDemoTest
{
public:
	CLineDemoTest();
	~CLineDemoTest();

public:
	void FindFinalRectPosition(const std::vector<std::vector<int>>& vecInput);
	void TheLargestNumber(std::vector<int> numbers);
	void SkillTree(std::string skill, std::vector<std::string> skill_trees);
	void MathDropper(std::vector<int> answers);
	void EcryptedString(std::string ecryptedString);
	int Heightsolution(std::vector<int> heightList);
	int YootSolution(std::vector<int> inputList);

private:
	std::vector<std::vector<int>> m_vecRandomRect;

public:
	const std::vector<std::vector<int>>& GetRandomRectVector();
	void PrintInputPositions();	

private:
	void GenerateRandomRect();
	//bool StringCompare(const std::string& first, const std::string& second);
};

