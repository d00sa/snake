#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#pragma once
#include <bits/stdc++.h>
#include <Map.h>
#include <Screen.h>

class GameManager
{
private:
    Map _map;
    Snake _snake;
    Screen _scr;
public:
    GameManager(){};
    void GameStart();   //���� Ÿ��Ʋ �Լ�.
    void GamePlay(); //���� ���� ��(�������� ����) �ݺ��� ������ �Լ�.
    void PlayingLevelStage();  //���� level�� stage �÷���.
    bool isGameOver();
    bool isGameClear();
};

#endif