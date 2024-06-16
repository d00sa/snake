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
    int _growthCount;
    int _degenerationCount;
    int _gateCount;
    bool _isUseGate;
    pair<int,int> _moveGatePos; //����Ʈ�� �̵��� ��ǥ
public:
    Snake() = default;
    Snake(Map& map);

    inline vector<pair<int,int>>& GetSnakePos() {return _snakePos; }    //�� ��ġ ��������

    inline void SetSnakeLength() { _snakeLength = _snakePos.size(); }  //�� ���� ����

    inline int GetSnakeLength() {return _snakePos.size(); }   //�� ���� ��������

    inline void SetMaxSnakeLength() {if (GetSnakeLength() > _maxSnakeLength) _maxSnakeLength = GetSnakeLength(); }    //�� �ִ� ���� ����

    inline int GetMaxSnakeLength() {return _maxSnakeLength; }    //�� �ִ� ���� ��������

    inline void SetDir(char dir) {_direction = dir; }  //�� ���� ����

    inline char GetDir() {return _direction; }  //�� ���� ��������

    inline bool isDead() {return _isDead; }

    inline bool SetDead() {_isDead = true; }

    inline int GetGrowthCount() {return _growthCount;}

    inline int GetDenerationCount() {return _degenerationCount; }

    inline int GetGateUseCount() { return _gateCount; }

    inline bool IsUseGate() { return _isUseGate; }

    inline int IncreaseGateCount() { return _gateCount++; } //����Ʈ �̿� �� ����

    inline void SetSnakeHeadPos(pair<int,int> p) {_snakePos[0] = p;}

    inline pair<int,int> GetGatePos() {return _moveGatePos;}

    void UseGate(pair<int,int> pos);    //����Ʈ �����

    void FinishGate();  //����Ʈ �̿� ��

    void SetKeyDir();   //�� ���� Ű������ ����

    void SnakeUpdate(); //�� ��ġ �̵�(�� Ŭ������ �ش� ��������)

    void CheckSnakeHeadPos();   //�� �Ӹ� ��ġ Ȯ��

    inline void CheckSnakeLength() {if (GetSnakeLength() < 3) _isDead = true;}    //�� ���� Ȯ�� (2���ϸ� GameOver)

    void Growth();

    void Degeneration();
};

#endif