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

};

