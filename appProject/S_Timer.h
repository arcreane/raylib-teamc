#pragma once
class S_Timer
{
private:
	int time;
	int now;
	int lastTime;
public:
	S_Timer();
	int getTime();
	void doClock(int time);
};

