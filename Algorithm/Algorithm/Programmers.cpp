#include "pch.h"
#include "Programmers.h"

CProgrammers::CProgrammers()
{
    std::string a = "123";
    GenerateHashKey(a, 3);
}

CProgrammers::~CProgrammers()
{
}

struct Ctest
{
    int a;
};

bool CProgrammers::PhoneBook(std::vector<std::string> phone_book)
{
    bool answer = true;

    std::sort(phone_book.begin(), phone_book.end());

    bool bFound = false;
    for (int i = 0; i < phone_book.size(); ++i)
    {
        int iKey = GenerateHashKey(phone_book[i], phone_book[i].length());        
        
        for (int j = i + 1; j < phone_book.size(); ++j)
        {
            int iKey2 = GenerateHashKey(phone_book[j], phone_book[i].length());

            if (iKey == iKey2)
            {
                answer = false;
                bFound = true;
                break;
            }
        }

        if (bFound)
            break;
    }

    return answer;
}

int CProgrammers::GenerateHashKey(std::string strNum, int iLength)
{
    int iResult = 0;
    
    const char* cStr = strNum.c_str();
    for (int i = 0; i < iLength; ++i)
    {
        char a = strNum[i];
        int iNumber = atoi(&a);
        int iPower = atoi(&a);
        for (int j = 1; j < i + 1; ++j)
        {
            iPower *= iNumber;
        }
        iResult += iPower;
    }

    return iResult;
}