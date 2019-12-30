#pragma once
class CProgrammers
{
public:
	CProgrammers();
	~CProgrammers();


public:
    bool PhoneBook(std::vector<std::string> phone_book);
private:
	int GenerateHashKey(std::string strNum, int iLength);

public:
	int truck(int bridge_length, int weight, std::vector<int> truck_weights);
private:
	int calculate(std::queue<int> data);

public:
	std::vector<int> FunctionDevelopment(std::vector<int> progresses, std::vector<int> speeds);

private:
	static bool ExamSort(std::pair<int, int>& src, std::pair<int, int>& dest);
public:
	std::vector<int> Exam(std::vector<int> answers);

};

