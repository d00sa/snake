#include "GameManager.h"

void GameManager::GameStart(){
    _scr = Screen();
    _map = Map(1);
    keypad(stdscr,TRUE);
    _scr.GameTitleScreen();
    getch();
}

void GameManager::GamePlay() {
    clear();
    while(!isGameClear()) {
        clear();
        PlayingLevelStage();
    }
}

void GameManager::PlayingLevelStage() {
    srand((unsigned int)time(0));
    nodelay(stdscr, TRUE);
    _snake = Snake(_map);
    _scr.Update(_map,_snake);
    bool IsGameOver = false;

    while (!IsGameOver) {
        _snake.SetKeyDir();
        _scr.Update(_map,_snake);
    }
}

bool GameManager::isGameOver() {
    if (_snake.isDead()) return true;
    return false;
}

bool GameManager::isGameClear() {
    return false;
}
