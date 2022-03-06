#pragma once
#pragma once
#ifndef _TimerClock_hpp_
#define _TimerClock_hpp_


#include <chrono>
using namespace std;
using namespace std::chrono;
class TimerClock
{
private:
	time_point<high_resolution_clock>_start;
public:
	TimerClock() {
		update();
	}
	~TimerClock() {};
	void update() {
		_start = high_resolution_clock::now();
	}
	double getTimerSecond() {
		return getTimerMicroSec() * 0.000001;
	}
	double getTimerMilliSec() {
		return getTimerMicroSec() * 0.001;
	}
	double getTimerMicroSec() {
		return duration_cast<microseconds>(high_resolution_clock::now() - _start).count();
	}
};

#endif // !_TimerClock_hpp_