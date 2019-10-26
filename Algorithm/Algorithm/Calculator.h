#pragma once

#include <iostream>
#include <queue>
#include <vector>

class CCalculator
{
public:
	CCalculator();
	~CCalculator();

public:
	double Calculate(const std::vector<std::string>& cEquation);

private:
	double CalculatePostFixNumbers(std::queue<std::string>& vecPost);
};

