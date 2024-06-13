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
    void GameStart();   //���� ���� ��(�������� ����) �ݺ��� ������ �Լ�.
    void GamePlaying(); //���� Ÿ��Ʋ �Լ�.
};

#endif