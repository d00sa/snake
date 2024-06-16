#ifndef TIMER_H
#define TIMER_H

#pragma once
#include <bits/stdc++.h>
#include <ncursesw\ncurses.h>
using namespace std;

class Timer {
public:
    Timer() = default;
    //타이머 시작
    void TimerStart();
    //타이머 업데이트
    void TimerUpdate();
    // 시간 간격이 지났는지 확인하는 함수
    inline double GetTimeToTick() {return _clock;}
    // 정수로 반환
    inline int GetTickToPlayTime() {return _clock;}

private:
    clock_t _start_time; // 시작 시간
    clock_t _cur_time; // 현재 시간
    double _clock;
};

#endif