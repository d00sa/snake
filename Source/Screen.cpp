#include "Screen.h"
#include <locale.h>
Screen::Screen() {
    //초기 설정
    setlocale(LC_ALL,"");
    initscr();

    resize_term(SCREEN_HEIGHT,SCREEN_WIDTH);
    noecho();
    curs_set(0);
    start_color();

    //색상 정의
    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    init_pair(6, COLOR_BLUE, COLOR_BLACK);
    
    //초기 배경 설정
    attron(COLOR_PAIR(0));
    wbkgd(stdscr,COLOR_PAIR(0) | A_BOLD);
}

//타이틀 화면 표시 화면
void Screen::GameTitleScreen() {
    attron(COLOR_PAIR(2));
    mvprintw(8, 10, "  #####   ##   ##    ###    ##  ##   #######             ####     ###    ##   ##  ####### ");
    mvprintw(9, 10, " ##   ##  ###  ##   ## ##   ##  ##    ##   #            ##  ##   ## ##   ### ###   ##   # ");
    mvprintw(10, 10, " ##       #### ##  ##   ##  ## ##     ##               ##       ##   ##  #######   ##     ");
    mvprintw(11, 10, "  #####   ## ####  #######  ####      ####             ##  ###  #######  ## # ##   ####   ");
    mvprintw(12, 10, "      ##  ##  ###  ##   ##  ## ##     ##               ##   ##  ##   ##  ##   ##   ##     ");
    mvprintw(13, 10, " ##   ##  ##   ##  ##   ##  ##  ###   ##   #            ## ###  ##   ##  ##   ##   ##   # ");
    mvprintw(14, 10, "  #####   ##   ##  ##   ##  ##   ##  #######             ### #  ##   ##  ##   ##  ####### ");
    attroff(COLOR_PAIR(2));

    attron(COLOR_PAIR(0));
    mvprintw(22, 41, "Press Any Key Start to Game!");
    attroff(COLOR_PAIR(0));

    BorderScreen();
    refresh();
}

//게임 맵 표시 함수
void Screen::GamePlayScreen(Map& map){
    _gameScreen = subwin(stdscr,22,60,7,5);
    wbkgd(_gameScreen, COLOR_PAIR(1));
    wattron(_gameScreen, COLOR_PAIR(1));

    for (int r = 0; r < map.GetMapRows(); r++){
        for (int c = 0; c < map.GetMapCols(); c++) {
           int value = map.GetMapValue(r,c);
           if (value == 0) {
                wattron(_gameScreen, COLOR_PAIR('w'));
                wprintw(_gameScreen, "    ");
           }
            else if(value == 1 || value == -1) {
                wattron(_gameScreen, COLOR_PAIR(2));
                wprintw(_gameScreen, " ");
                mvwprintw(_gameScreen, r, 2*c, "■");
            }
        }        
    }
    BorderScreen();
}

//스코어 화면 표시 함수
void Screen::GameScordBoardScreen(Snake& snake, Mission& mission, int gamePlayTime) {
    _scoreScreen = subwin(stdscr,21,40,7,68);
    wattron(_scoreScreen, COLOR_PAIR(5)| A_BOLD);
    mvwprintw(_scoreScreen,1,1," ★ ★ ★ ★ ★ ★ ★  Score ★ ★ ★ ★ ★ ★ ★");
    wattron(_scoreScreen, COLOR_PAIR(6)| A_BOLD);
    mvwprintw(_scoreScreen,3,17,"B: ");
    mvwprintw(_scoreScreen,3,20,to_string(snake.GetSnakeLength()).c_str());
    mvwprintw(_scoreScreen,3,22,"/");
    mvwprintw(_scoreScreen,3,24,to_string(snake.GetMaxSnakeLength()).c_str());
    mvwprintw(_scoreScreen,4,17,"+: ");
    mvwprintw(_scoreScreen,4,20,to_string(snake.GetGrowthCount()).c_str());
    mvwprintw(_scoreScreen,5,17,"-: ");
    mvwprintw(_scoreScreen,5,20,to_string(snake.GetDenerationCount()).c_str());
    mvwprintw(_scoreScreen,6,17,"G: ");
    mvwprintw(_scoreScreen,6,20,to_string(snake.GetGateUseCount()).c_str());
    mvwprintw(_scoreScreen,7,17,"Time: ");
    mvwprintw(_scoreScreen,7,23,to_string(gamePlayTime).c_str());


    wattron(_scoreScreen, COLOR_PAIR(5)| A_BOLD);
    mvwprintw(_scoreScreen,10,1," ★ ★ ★ ★ ★ ★ ★  Mission ★ ★ ★ ★ ★ ★ ★");
    wattron(_scoreScreen, COLOR_PAIR(2)| A_BOLD);
    mvwprintw(_scoreScreen,12,17,"B: ");
    mvwprintw(_scoreScreen,12,20,to_string(mission.getScoreObjective()).c_str());
    if(mission.getScoreObjective() <= snake.GetSnakeLength()) mvwprintw(_scoreScreen, 12, 23, "(v)");
    mvwprintw(_scoreScreen,13,17,"+: ");
    mvwprintw(_scoreScreen,13,20,to_string(mission.getGrowObjective()).c_str());
    if(mission.getGrowObjective() <= snake.GetGrowthCount()) mvwprintw(_scoreScreen, 13, 23, "(v)");
    mvwprintw(_scoreScreen,14,17,"-: ");
    mvwprintw(_scoreScreen,14,20,to_string(mission.getPoisonObjective()).c_str());
    if(mission.getPoisonObjective() <= snake.GetDenerationCount()) mvwprintw(_scoreScreen, 14, 23, "(v)");
    mvwprintw(_scoreScreen,15,17,"G: ");    
    mvwprintw(_scoreScreen,15,20,to_string(mission.getGateObjective()).c_str());
    if(mission.getGateObjective() <= snake.GetGateUseCount()) mvwprintw(_scoreScreen, 15, 23, "(v)");
    wborder(_scoreScreen,0,0,0,0,0,0,0,0);
}

//게임 상단 겜 이름 표시 함수
void Screen::GameNameScreen() {
    _gameNameScreen = subwin(stdscr,6,108,1,1);
    wattron(_scoreScreen, WA_BOLD);
    mvwprintw(_gameNameScreen,1,31," ___  _ _  ___  _ __ ___   ___   ___  __ __  ___");
    mvwprintw(_gameNameScreen,2,31,"/ __>| \\ || . || / /| __> /  _> | . ||  \\  \\| __>");
    mvwprintw(_gameNameScreen,3,31,"\\__ \\|   ||   ||  \\ | _>  | <_/\\|   ||     || _> ");
    mvwprintw(_gameNameScreen,4,31,"<___/|_\\_||_|_||_\\_\\|___> \\____/|_|_||_|_|_||___>");   
    wattroff(_scoreScreen, WA_BOLD);
}

//뱀 게임에 출력
void Screen::GameSnakeScreen(Snake& snake) {
    vector<pair<int,int>>& SnakePos = snake.GetSnakePos();

    wattron(_gameScreen, COLOR_PAIR(6));

    //머리
    wprintw(_gameScreen, " ");
    mvwprintw(_gameScreen, SnakePos[0].first, 2*SnakePos[0].second, "●");
    
    //몸
    for(int i=1; i < snake.GetSnakeLength(); i++) {
        pair<int,int> p = SnakePos[i];
        wprintw(_gameScreen, " ");
        mvwprintw(_gameScreen, p.first, 2*p.second, "○");
    }
}

//아이템 화면에 출력
void Screen::GameItemScreen(vector<Item> &items) {
    for(int i=0; i < items.size(); i++) {
        pair<int,int> pos = items[i].getItemPos();
        if(items[i].isGrowthItem()) {
            wattron(_gameScreen, COLOR_PAIR(1));
            mvwprintw(_gameScreen, pos.first, 2*pos.second, "■");
        }else{
            wattron(_gameScreen, COLOR_PAIR(3));
            mvwprintw(_gameScreen, pos.first, 2*pos.second, "■");
        }
    }
}

void Screen::GameStageClearScreen() {
    clear();
    nodelay(stdscr, FALSE);
    attron(COLOR_PAIR(0));
    mvprintw(12, 49, "Stage Clear!");
    mvprintw(17, 41, "Press Any Key to Next Stage");
    BorderScreen();
    getch();
    refresh();
}

void Screen::GameGateScreen(vector<Gate>& gate) {
    wattron(_gameScreen, COLOR_PAIR(4));
    if(!gate.empty()) {
        pair<int,int> gatepos1 = gate[0].getGatePos(1);
        pair<int,int> gatepos2 = gate[0].getGatePos(2);
        mvwprintw(_gameScreen, gatepos1.first, 2*gatepos1.second, "■");
        mvwprintw(_gameScreen, gatepos2.first, 2*gatepos2.second, "■");
    }
    BorderScreen();
}

void Screen::GameClearScreen() {
    clear();
    nodelay(stdscr, FALSE);
    attron(COLOR_PAIR(2));
    mvprintw(8, 10, "  #####   ##   ##    ###    ##  ##   #######             ####     ###    ##   ##  ####### ");
    mvprintw(9, 10, " ##   ##  ###  ##   ## ##   ##  ##    ##   #            ##  ##   ## ##   ### ###   ##   # ");
    mvprintw(10, 10, " ##       #### ##  ##   ##  ## ##     ##               ##       ##   ##  #######   ##     ");
    mvprintw(11, 10, "  #####   ## ####  #######  ####      ####             ##  ###  #######  ## # ##   ####   ");
    mvprintw(12, 10, "      ##  ##  ###  ##   ##  ## ##     ##               ##   ##  ##   ##  ##   ##   ##     ");
    mvprintw(13, 10, " ##   ##  ##   ##  ##   ##  ##  ###   ##   #            ## ###  ##   ##  ##   ##   ##   # ");
    mvprintw(14, 10, "  #####   ##   ##  ##   ##  ##   ##  #######             ### #  ##   ##  ##   ##  ####### ");
    attron(COLOR_PAIR('w'));
    mvprintw(19, 50, "Game Clear!!");
    mvprintw(22, 34, "C++ Snake 프로젝트 김치우 / 김민규 / 황시현");
    BorderScreen();
    getch();
    refresh();    
}

void Screen::GameOverScreen() {
    clear();
    nodelay(stdscr, FALSE);
    attron(COLOR_PAIR(2));
    mvprintw(12, 50, "Game Over!!");
    mvprintw(17, 44, "Press Any Key to Quit..");
    BorderScreen();
    getch();
    clear();
}

// 게임 화면 경계 표시 함수
void Screen::BorderScreen() {
    attron(COLOR_PAIR(3));
    wborder(stdscr,0, 0, 0, 0, 0, 0, 0, 0);
    attroff(COLOR_PAIR(3));
}

//게임 화면 refresh 함수
void Screen::Update(Map& map,Snake& snake,vector<Item>& items,Mission& mission,vector<Gate>& gate,int gamePlayTime) {
    GamePlayScreen(map);
    GameScordBoardScreen(snake,mission,gamePlayTime);
    GameNameScreen();
    GameSnakeScreen(snake);
    GameItemScreen(items);
    GameGateScreen(gate);

    refresh();
    wrefresh(_gameScreen);
    wrefresh(_scoreScreen);
    wrefresh(_gameNameScreen);
}