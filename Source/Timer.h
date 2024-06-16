#ifndef TIMER_H
#define TIMER_H

#pragma once
#include <bits/stdc++.h>
#include <ncursesw\ncurses.h>
using namespace std;

class Timer {
public:
    Timer() = default;
    //Ÿ�̸� ����
    void TimerStart();
    //Ÿ�̸� ������Ʈ
    void TimerUpdate();
    // �ð� ������ �������� Ȯ���ϴ� �Լ�
    inline double GetTimeToTick() {return _clock;}
    // ������ ��ȯ
    inline int GetTickToPlayTime() {return _clock;}

private:
    clock_t _start_time; // ���� �ð�
    clock_t _cur_time; // ���� �ð�
    double _clock;
};

#endif