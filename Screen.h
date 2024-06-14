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
    void GameTitleScreen(); //게임 시작 화면
    void Update(Map map,Snake snake);  //화면 업데이트
private:
    void GamePlayScreen(Map map);  //플레이 화면
    void GameScordBoardScreen();  //스코어 보드
    void GameNameScreen();  //게임 이름 출력
    void GameSnakeScreen(Snake snake);     //뱀 게임에 출력
    void BorderScreen();    //경계면 화면
};

#endif