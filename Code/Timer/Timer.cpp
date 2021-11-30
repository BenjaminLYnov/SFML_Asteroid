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

void Timer::start()
{
     isStop = false;
     isStart = true;
}

void Timer::stop()
{
     isStart = false;
     isStop = true;
}

void Timer::reset()
{
     chrono = 0;
}

double Timer::getTime()
{
     return chrono;
}

void Timer::upTime()
{
     // if (isStart)
     chrono += ((float)1) / ((float)60);
}