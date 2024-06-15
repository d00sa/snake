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

class GameManager
{
private:
    Map _map;
    Snake _snake;
    Screen _scr;
    Level _level;
    vector<Item> _items;
    Mission _mission;
    int _gamePlayTime;
public:
    GameManager(){};
    void GameStart();   //게임 타이틀 함수.
    void GamePlay(); //게임 실행 중(연속적인 세상) 반복문 돌리는 함수.
    void PlayingLevelStage();  //현재 level의 stage 플레이.
    bool IsSnakeGetItem();
    bool IsCollision();
    bool isGameOver();
    bool isGameClear();
};

#endif