#pragma once

#include <chrono>
#include <iostream>

class CTimer
{
public:
	CTimer();
	~CTimer();


private:
	std::chrono::time_point<std::chrono::steady_clock> m_Start;
	std::chrono::time_point<std::chrono::steady_clock> m_End;
	std::chrono::duration<float> m_Duration;

};

CTimer::CTimer()	:
	m_Duration(0)
{
	m_Start = std::chrono::high_resolution_clock::now();
}


CTimer::~CTimer()
{
	m_End = std::chrono::high_resolution_clock::now();

	m_Duration = m_End - m_Start;

	float ms = m_Duration.count() * 1000.f;
	std::cout << "Timer Took " << ms << "ms" << std::endl;
}
