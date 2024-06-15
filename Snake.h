#ifndef SNAKE_H
#define SNAKE_H

#pragma once
#include <bits/stdc++.h>
#include <Map.h>
#include <ncursesw\ncurses.h>
using namespace std;

class Snake {
private:
    //뱀의 위치를 담음.
    vector<pair<int,int>> _snakePos;
    //꼬리 부분 위치
    vector<pair<int,int>> _tail;
    char _direction;
    int _snakeLength;
    bool _isDead;
    int _maxSnakeLength;
    int _growthCount;
    int _degenerationCount;
public:
    Snake() = default;
    Snake(Map& map);

    inline vector<pair<int,int>>& GetSnakePos() {return _snakePos; }    //뱀 위치 가져오기

    inline void SetSnakeLength() { _snakeLength = _snakePos.size(); }  //뱀 길이 설정

    inline int GetSnakeLength() {return _snakePos.size(); }   //뱀 길이 가져오기

    inline int SetMaxSnakeLength() {if (GetSnakeLength() > _maxSnakeLength) _maxSnakeLength = GetSnakeLength(); }    //뱀 최대 길이 설정

    inline int GetMaxSnakeLength() {return _maxSnakeLength; }    //뱀 최대 길이 가져오기

    inline void SetDir(char dir) {_direction = dir; }  //뱀 방향 설정

    inline char GetDir() {return _direction; }  //뱀 방향 가져오기

    inline bool isDead() {return _isDead; }

    inline bool SetDead() {_isDead = true; }

    inline int GetGrowthCount() {return _growthCount;}

    inline int GetDenerationCount() {return _degenerationCount; }

    void SetKeyDir();   //뱀 방향 키값으로 설정

    void SnakeUpdate(); //뱀 위치 이동(매 클럭마다 해당 방향으로)

    void CheckSnakeHeadPos();   //뱀 머리 위치 확인

    inline void CheckSnakeLength() {if (GetSnakeLength() < 3) _isDead = true;}    //뱀 길이 확인 (2이하면 GameOver)

    void Growth();

    void Degeneration();
};

#endif