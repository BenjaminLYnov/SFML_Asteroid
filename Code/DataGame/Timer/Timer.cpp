#include "Timer.hpp"

Timer::Timer()
{
     chrono = 0;
     isStart = false;
     isStop = true;
}

Timer::~Timer()
{
}

void Timer::Start()
{
     isStop = false;
     isStart = true;
}

void Timer::Stop()
{
     isStart = false;
     isStop = true;
}

void Timer::Reset()
{
     chrono = 0;
}

float Timer::GetTime()
{
     return chrono;
}

void Timer::UpTime()
{
     chrono += ((float)1) / ((float)60);
}