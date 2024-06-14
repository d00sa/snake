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
    _snake = Snake(_map);
    _scr.Update(_map,_snake);
    bool IsGameOver = false;

    while (!IsGameOver) {
        _snake.SetKeyDir();
        _snake.SnakeUpdate();
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
