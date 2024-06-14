#ifndef SCREEN_H
#define SCREEN_H

#pragma once
#include <ncurses.h>
#include <Map.h>
#include "Snake.h"
#define SCREEN_HEIGHT       30
#define SCREEN_WIDTH        110

class Screen {
private:
    WINDOW* _gameScreen;
    WINDOW* _scoreScreen;
    WINDOW* _gameNameScreen;
public:
    Screen();
    void GameTitleScreen(); //���� ���� ȭ��
    void Update(Map map,Snake snake);  //ȭ�� ������Ʈ
private:
    void GamePlayScreen(Map map);  //�÷��� ȭ��
    void GameScordBoardScreen();  //���ھ� ����
    void GameNameScreen();  //���� �̸� ���
    void GameSnakeScreen(Snake snake);     //�� ���ӿ� ���
    void BorderScreen();    //���� ȭ��
};

#endif