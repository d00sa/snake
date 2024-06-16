#include "Timer.h"
void Timer::TimerStart() {
    _start_time = clock();
}

void Timer::TimerUpdate() {
    _cur_time = clock();
    _clock = (double)(_cur_time - _start_time) / CLOCKS_PER_SEC;
}