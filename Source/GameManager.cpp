#include "GameManager.h"

void GameManager::GameStart(){
    _scr = Screen();
    _level = Level();
    _level.buildMap();

    keypad(stdscr,TRUE);
    _scr.GameTitleScreen();
    // _scr.GameStageClearScreen();
    getch();
}

void GameManager::GamePlay() {
    clear();
    while(!IsGameClear()) {
        printf("�������� %d �����մϴ�.\n",_level.getNowLevel());
        clear();
        PlayingLevelStage();

        if (_level.checkCompleted()){
            if (_level.getNowLevel() >= 3) break;
            _level.increaseLevel();
            _scr.GameStageClearScreen();
        }
        else{
            _scr.GameOverScreen();
            break;
        }        
    }
    if (IsGameClear()) _scr.GameClearScreen();
}

void GameManager::PlayingLevelStage() {
    srand((unsigned int)time(NULL));
    nodelay(stdscr,TRUE);
    
    _map = _level.getNowMap();
    _snake = Snake(_map);
    _mission = _level.getMission();
    _gates.clear();
    _items.clear();

    Timer GameTimer;
    Timer ItemTimer;
    Timer ClockTimer;
    Timer GateTimer;
    Timer DeleteTimer;

    GameTimer.TimerStart();
    ItemTimer.TimerStart();
    ClockTimer.TimerStart();
    DeleteTimer.TimerStart();
    GateTimer.TimerStart();
    _gamePlayTime = 0;
    printf("���� ���� �Ϸ�.\n");

    _scr.Update(_map,_snake,_items,_mission,_gates,_gamePlayTime);
    bool GamePlay = true;

    while (GamePlay) {
        GameTimer.TimerUpdate();
        ItemTimer.TimerUpdate();
        ClockTimer.TimerUpdate();
        GateTimer.TimerUpdate();
        DeleteTimer.TimerUpdate();

        _gamePlayTime = GameTimer.GetTickToPlayTime();
         
        _snake.SetKeyDir();

        if (ClockTimer.GetTimeToTick() > 0.3){
            _snake.SnakeUpdate();

            if(!IsSnakeGetItem()){
                if((DeleteTimer.GetTimeToTick() > rand() % 5 + 10) && !_items.empty()){
                    _items.erase(_items.begin());
                    DeleteTimer.TimerStart();
                }
            }

            if(IsUsingGate()) GateTimer.TimerStart();

            _level.markCompleted(false);
            GamePlay = !IsGameOver() && !IsLevelStageClear();
            _scr.Update(_map,_snake,_items,_mission,_gates,_gamePlayTime);
            ClockTimer.TimerStart();
        }

        if(ItemTimer.GetTimeToTick() > rand() % 3 + 4) {
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

        if (GateTimer.GetTimeToTick() >= 10){
            if (_gates.size() < 1){
                Gate NewGate = Gate(_map);
                _gates.push_back(NewGate);
            }
            GateTimer.TimerStart();
        }
    }
}

//���� �������� �Ծ��°�?
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

//�浹 �Ͽ��°�? (��,�浹 �Ұ����� ��)
bool GameManager::IsCollision() {
    printf("�浹üũ��..\n");
    pair<int,int> Head = _snake.GetSnakePos()[0];
    int Value = _map.GetMapValue(Head.first, Head.second);
    printf("%d is Value\n",Value);
    if((Value == 1) || (Value == -1)) { 
        if(!_gates.empty()) {
            printf("����Ʈ �ִµ�..\n");
            printf("Head: [%d,%d]\n",Head.first,Head.second);
            printf("gateA: [%d,%d]\n",_gates[0].getGatePos(1).first,_gates[0].getGatePos(1).second);
            printf("gateB: [%d,%d]\n",_gates[0].getGatePos(2).first,_gates[0].getGatePos(2).second);
            if(Head == _gates[0].getGatePos(1) || Head == _gates[0].getGatePos(2)) {
                return false;
            }
        }
        printf("�浹�̾�!!\n");
        return true;
    }
    return false;
}

bool GameManager::IsUsingGate() {
    // ����Ʈ�� ����ִٸ� false
    if(_gates.empty()) return false;
    std::vector<pair<int,int>> snakePos = _snake.GetSnakePos();
    Gate gate = _gates[0];
    //���� ���� ���� u=0 d=1 l=2 r=3
    int upDirSquence[4] = {0, 3, 2, 1};
    int downDirSquence[4] = {1, 2, 3, 0};
    int leftDirSquence[4] = {2, 0, 1, 3};
    int rightDirSquence[4] = {3, 1, 0, 2};

    int* dirSquence[4] = {upDirSquence, downDirSquence, leftDirSquence, rightDirSquence}; 
    char charDir[4] = {'u', 'd', 'l', 'r'};

    //�Ӹ���ǥ �ٲٱ�
    if(snakePos[0] == _gates[0].getGatePos(1)) {
        snakePos[0] = _gates[0].getGatePos(2);
        char dir = _snake.GetDir();
        int dirIdx;
        //dir �ε��� ����
        for(int i=0; i<sizeof(charDir); i++) {
            if (dir == charDir[i]) {
                dirIdx = i;
                break;
            }
        }
        int* squence = dirSquence[dirIdx];

        char newDir;
        for (int i=0; i<4; i++) {
           if(gate.getDirections(2, squence[i]) == 0) {
               newDir = charDir[squence[i]];
               break;
           }
        }
        _snake.IncreaseGateCount();
        _snake.SetDir(newDir);
        _snake.SetSnakeHeadPos(snakePos[0]);
        _snake.UseGate(snakePos[0]);
    }

    else if(snakePos[0] == _gates[0].getGatePos(2)) {
        snakePos[0] = _gates[0].getGatePos(1);
        char dir = _snake.GetDir();
        int diridx;
        //dir �ε��� ����
        for(int i=0; i<sizeof(charDir); i++) {
            if (dir == charDir[i]) {
                diridx = i;
                break;
            }
        }
        int* squence = dirSquence[diridx];

        char newDir;
        for (int i=0; i<4; i++) {
           if(gate.getDirections(1, squence[i]) == 0) {
               newDir = charDir[squence[i]];
               break;
           }
        }
        _snake.IncreaseGateCount();
        _snake.SetDir(newDir);
        _snake.SetSnakeHeadPos(snakePos[0]);
        _snake.UseGate(snakePos[0]);
    }

    for(int i=0; i < _snake.GetSnakeLength(); i++) {
        if (snakePos[i] == _snake.GetGatePos()) {
            if (i==_snake.GetSnakeLength()-1) {
                _snake.FinishGate();
                _gates.erase(_gates.begin());
            }
            return true;
        }
    }
    return false;
}

//������ �����°�?
bool GameManager::IsGameOver() {
    if (_snake.isDead()) return true;
    if(IsCollision()) return true;
    return false;
}

bool GameManager::IsLevelStageClear() {
    Mission StageMission = _level.getMission();
    if(_snake.GetMaxSnakeLength() < StageMission.getScoreObjective()) return false;
    if(_snake.GetGrowthCount() < StageMission.getGrowObjective()) return false;
    if(_snake.GetDenerationCount() < StageMission.getPoisonObjective()) return false;
    if(_snake.GetGateUseCount() < StageMission.getGateObjective()) return false;
    _level.markCompleted(true);
    return true;
}

//������ Ŭ���� �ߴ°�?
bool GameManager::IsGameClear() {
    if (_level.isCompleted[3]) return true;
    return false;
}
