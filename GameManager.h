#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#pragma once
#include <Map.h>
#include <Screen.h>

class GameManager
{
private:
    Map _map;
    Screen _scr;
public:
    GameManager(){};
    void GameStart();   //게임 실행 중(연속적인 세상) 반복문 돌리는 함수.
    void GamePlaying(); //게임 타이틀 함수.
};

#endif