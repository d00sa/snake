#ifndef SCREEN_H
#define SCREEN_H

#pragma once
#include <ncurses.h>
#include <Map.h>
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
    void GameOverScreen();    //���� ���� ȭ��
    void GameClearScreen();    //Ŭ���� ȭ��
    void NextStageScreen();   //���� �������� ȭ��
    void GamePlayScreen(Map map);  //�÷��� ȭ��
    void GameScordBoardScreen();  //���ھ� ����
    void GameNameScreen();  //���� �̸� ���
    void BorderScreen();    //���� ȭ��
    void Update(Map map);  //ȭ�� ������Ʈ
};

#endif