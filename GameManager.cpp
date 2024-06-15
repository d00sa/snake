#include "GameManager.h"

void GameManager::GameStart(){
    _scr = Screen();
    _level = Level();
    _level.buildMap();

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
    srand((unsigned int)time(NULL));
    nodelay(stdscr,TRUE);
    Timer GameTimer;
    Timer ItemTimer;
    Timer ClockTimer;
    Timer DeleteTimer;

    _map = _level.getNowMap();
    _snake = Snake(_map);
    _mission = _level.getMission();
    _items.clear();

    GameTimer.TimerStart();
    ItemTimer.TimerStart();
    ClockTimer.TimerStart();
    DeleteTimer.TimerStart();
    _gamePlayTime = 0;

    _scr.Update(_map,_snake,_items,_mission,_gamePlayTime);
    bool IsGameOver = false;

    while (!IsGameOver) {
        GameTimer.TimerUpdate();
        ItemTimer.TimerUpdate();
        ClockTimer.TimerUpdate();
        DeleteTimer.TimerUpdate();

        _gamePlayTime = GameTimer.GetTickToPlayTime();
         
        _snake.SetKeyDir();

        if (ClockTimer.GetTimeToTick() > 0.2){
            _snake.SnakeUpdate();

            if(!IsSnakeGetItem()){
                if((DeleteTimer.GetTimeToTick() > rand() % 5 + 10) && !_items.empty()){
                    _items.erase(_items.begin());
                    DeleteTimer.TimerStart();
                }
            }

            _level.markCompleted(false);
            _scr.Update(_map,_snake,_items,_mission,_gamePlayTime);
            ClockTimer.TimerStart();
        }

        if(ItemTimer.GetTimeToTick() > rand() % 3 + 3) {
            if(_items.size() < 3) {
                Item newItem = Item(_map, _snake);
                for(int i=0; i < _items.size(); i++) {
                    if(_items[i] == newItem) {
                        newItem = Item(_map, _snake);
                        i = 0;
                    }
                }
                _items.push_back(newItem);
            }
            ItemTimer.TimerStart();
        }
    }
}

//뱀이 아이템을 먹었는가?
bool GameManager::IsSnakeGetItem() {
    pair<int,int> Head = _snake.GetSnakePos()[0];
    for(int i=0; i < _items.size(); i++) {
        pair<int,int> Item = _items[i].getItemPos();
        if(Head.first == Item.first && Head.second == Item.second) {
            if(_items[i].isGrowthItem()) {
                _snake.Growth();
            }else {
                _snake.Degeneration();
            }
            _items.erase(_items.begin()+i);
            return true;
        }
    }
    return false;
}

//게임이 끝났는가?
bool GameManager::isGameOver() {
    if (_snake.isDead()) return true;
    return false;
}

//게임을 클리어 했는가?
bool GameManager::isGameClear() {
    return false;
}
