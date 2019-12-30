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

int CProgrammers::truck(int bridge_length, int weight, std::vector<int> truck_weights)
{
    int answer = 0;
    answer = bridge_length * truck_weights.size();

    std::queue<int> on;
    int iSubtract = 0;
    for (int i = 0; i < truck_weights.size(); ++i)
    {
        if (calculate(on) <= weight)
        {
            on.push(truck_weights[i]);
        }

        if (calculate(on) == weight)
        {
            int icount = on.size() - 1;
            iSubtract += icount * bridge_length - on.size();

            while (!on.empty())
                on.pop();
        }
        else if (calculate(on) > weight)
        {            
            --i;
            on.pop();
            
            if (on.size() != 1)
            {
                int icount = on.size() - 1;

                iSubtract += icount * bridge_length - on.size();
            }           

            while (!on.empty())
                on.pop();            
        }
    }
    answer -= iSubtract;

    return answer;
}

int CProgrammers::calculate(std::queue<int> data)
{    
    std::queue<int> tData = data;
    int iSum = 0;
    while (!tData.empty())
    {
        iSum += tData.front();
        tData.pop();
    }

    return iSum; 
}

std::vector<int> CProgrammers::FunctionDevelopment(std::vector<int> progresses, std::vector<int> speeds)
{
    std::vector<int> answer;

    std::queue<int> queTemp;
    for (int i = 0; i < progresses.size(); ++i)
    {
        bool addone = false;
        int iDay = 100 - progresses[i];

        if (iDay % speeds[i] != 0)
        {
            addone = true;
        }

        iDay /= speeds[i];

        if (addone)
            iDay += 1;

        queTemp.push(iDay);
    }

    int iKey = 0;
    int iCount = 0;
    while (!queTemp.empty())
    {
        if (iCount == 0)
        {
            iKey = queTemp.front();
            queTemp.pop();
            ++iCount;

            if (queTemp.empty())
            {
                answer.push_back(iCount);
                break;
            }
        }

        if (iKey >= queTemp.front())
        {
            ++iCount;
            queTemp.pop();
        }
        else
        {
            answer.push_back(iCount);
            iCount = 0;
        }
    }

    return answer;
}

bool CProgrammers::ExamSort(std::pair<int, int>& src, std::pair<int, int>& dest)
{
    if (src.first == dest.first)
        return src.second < dest.second;

    return src.first > dest.first;
}

std::vector<int> CProgrammers::Exam(std::vector<int> answers)
{
    std::vector<int> answer;
    std::vector<std::pair<int, int>> total;

    std::vector<int> MathDropper1 = { 1, 2, 3, 4, 5 };
    std::vector<int> MathDropper2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    std::vector<int> MathDropper3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    int iCorrectCount1 = 0;
    int iCorrectCount2 = 0;
    int iCorrectCount3 = 0;

    int iIdx1 = 0;
    int iIdx2 = 0;
    int iIdx3 = 0;

    for (int i = 0; i < answers.size(); ++i)
    {
        if (iIdx1 >= MathDropper1.size())
            iIdx1 = 0;
        if (iIdx2 >= MathDropper2.size())
            iIdx2 = 0;
        if (iIdx3 >= MathDropper3.size())
            iIdx3 = 0;

        if (answers[i] == MathDropper1[iIdx1])
            ++iCorrectCount1;
        if (answers[i] == MathDropper2[iIdx2])
            ++iCorrectCount2;
        if (answers[i] == MathDropper3[iIdx3])
            ++iCorrectCount3;

        ++iIdx1;
        ++iIdx2;
        ++iIdx3;
    }

    total.push_back(std::make_pair(iCorrectCount1, 1));
    total.push_back(std::make_pair(iCorrectCount2, 2));
    total.push_back(std::make_pair(iCorrectCount3, 3));

    std::sort(total.begin(), total.end(), ExamSort);

    int iCount = 0;
    for (int i = 0; i < total.size(); ++i)
    {
        if (total[i].first == 0)
            break;
        
        if (iCount <= total[i].first)
        {
            iCount = total[i].first;
            answer.push_back(total[i].second);
        }
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