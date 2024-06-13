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
public:
    Screen();
    void GameTitleScreen(); //게임 시작 화면
    void GameOverScreen();    //게임 오버 화면
    void GameClearScreen();    //클리어 화면
    void NextStageScreen();   //다음 스테이지 화면
    void GamePlayScreen(Map map);  //플레이 화면
    void BorderScreen();    //경계면 화면
    void Update(Map map);  //화면 업데이트
};

#endif