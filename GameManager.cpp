#include "GameManager.h"

void GameManager::GameStart(){
    _scr = Screen();
    _map = Map(1);
    _scr.GameTitleScreen();
    getch();
}

void GameManager::GamePlaying() {
    int ch;
    clear();
    while(true) {
        clear();
        _scr.Update(_map);
        ch = getch();
        if (ch == 27) break;
    }
}