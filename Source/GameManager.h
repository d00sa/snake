#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#pragma once
#include <bits/stdc++.h>
#include <Map.h>
#include <Screen.h>
#include <Timer.h>
#include <Level.h>
#include <Item.h>
#include <Mission.h>
#include <Gate.h>

class GameManager
{
private:
    Map _map;
    Snake _snake;
    Screen _scr;
    Level _level;
    vector<Item> _items;
    vector<Gate> _gates;
    Mission _mission;
    int _gamePlayTime;
public:
    GameManager(){};
    void GameStart();   //���� Ÿ��Ʋ �Լ�.
    void GamePlay(); //���� ���� ��(�������� ����) �ݺ��� ������ �Լ�.
    void PlayingLevelStage();  //���� level�� stage �÷���.
    bool IsSnakeGetItem();
    bool IsCollision();
    bool IsUsingGate();
    bool IsGameOver();
    bool IsLevelStageClear();
    bool IsGameClear();
};

#endif