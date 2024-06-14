#ifndef SNAKE_H
#define SNAKE_H

#pragma once
#include <bits/stdc++.h>
#include <Map.h>
#include <ncursesw\ncurses.h>
using namespace std;

class Snake {
private:
    //���� ��ġ�� ����.
    vector<pair<int,int>> _snakePos;
    //���� �κ� ��ġ
    vector<pair<int,int>> _tail;
    char _direction;
    int _snakeLength;
    bool _isDead;
    int _maxSnakeLength;
public:
    Snake() = default;
    Snake(Map& map);

    inline vector<pair<int,int>> GetSnakePos() {return _snakePos; }    //�� ��ġ ��������

    inline void SetSnakeLength(int length) { _snakeLength = length; }  //�� ���� ����

    inline int GetSnakeLength() {return _snakeLength; }   //�� ���� ��������

    inline int SetMaxSnakeLength(int length) {_maxSnakeLength = length; }    //�� �ִ� ���� ����

    inline int GetMaxSnakeLength() {return _maxSnakeLength; }    //�� �ִ� ���� ��������

    inline void SetDir(char dir) {_direction = dir; }  //�� ���� ����

    inline char GetDir() {return _direction; }  //�� ���� ��������

    inline bool isDead() {return _isDead; }

    void SetKeyDir();   //�� ���� Ű������ ����

    void SnakeUpdate(); //�� ��ġ �̵�(�� Ŭ������ �ش� ��������)

    void CheckSnakeHeadPos();   //�� �Ӹ� ��ġ Ȯ��

    inline void CheckSnakeLength() {if (_snakeLength < 3) _isDead = true;}    //�� ���� Ȯ�� (2���ϸ� GameOver)
};

#endif