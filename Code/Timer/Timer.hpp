#ifndef TIMER_H
#define TIMER_H
#pragma once

#include "../Include/MainInclude.hpp"

class Timer
{
private:
	double chrono;
	bool isStart;
	bool isStop;

public:
	Timer();
	~Timer();
	void start();
	void stop();
	void reset();
	void upTime();
	double getTime();
};
#endif