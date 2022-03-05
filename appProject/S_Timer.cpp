#include "S_Timer.h"
#include <ctime>
S_Timer::S_Timer() {
    time=0;
    now=0;
    lastTime=0;
}

int S_Timer::getTime() {
	return time;
}
void S_Timer::doClock(int time) {
    while (1) {
        now = clock();
        if (now - lastTime > 0) {
            time++;
            lastTime = now;
        }
    }
}
