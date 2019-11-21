#pragma once

class CLineDemoTest
{
public:
	CLineDemoTest();
	~CLineDemoTest();

public:
	void FindFinalRectPosition(const std::vector<std::vector<int>>& vecInput);

private:
	std::vector<std::vector<int>> m_vecRandomRect;

public:
	const std::vector<std::vector<int>>& GetRandomRectVector();
	void PrintInputPositions();

private:
	void GenerateRandomRect();
};

