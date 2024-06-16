#ifndef SCREEN_H
#define SCREEN_H

#pragma once
#include <ncurses.h>
#include <Map.h>
#include "Snake.h"
#include <Item.h>
#include <Mission.h>
#include <Gate.h>
#define SCREEN_HEIGHT       30
#define SCREEN_WIDTH        110
#define PINK_COLOR  15

class Screen {
private:
    WINDOW* _gameScreen;
    WINDOW* _scoreScreen;
    WINDOW* _gameNameScreen;
public:
    Screen();
    void GameTitleScreen(); //���� ���� ȭ��
    void GameClearScreen(); //���� Ŭ����
    void GameOverScreen();  //���� ����
    void GameStageClearScreen();    //�������� Ŭ����
    void Update(Map& map,Snake& snake,vector<Item>& items,Mission& mission,vector<Gate>& gate,int gamePlayTime);  //ȭ�� ������Ʈ
private:
    void GamePlayScreen(Map& map);  //�÷��� ȭ��
    void GameScordBoardScreen(Snake& snake, Mission& mission, int gamePlayTime);  //���ھ� ����
    void GameNameScreen();  //���� �̸� ���
    void GameSnakeScreen(Snake& snake);     //�� ���ӿ� ���
    void GameItemScreen(vector<Item>& items);   //������ ���ӿ� ���
    void GameGateScreen(vector<Gate>& gate);
    void BorderScreen();    //���� ȭ��
};

#endif