#ifndef TIMER_H
#define TIMER_H
#pragma once

class Timer
{

public:
	Timer();
	~Timer();
	void Start();
	void Stop();
	void Reset();
	void UpTime();
	float GetTime();

private:
	float chrono;
	bool isStart;
	bool isStop;
};
#endif