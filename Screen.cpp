#include "Screen.h"
#include <locale.h>

Screen::Screen() {
    //�ʱ� ����
    setlocale(LC_ALL,"");
    initscr();

    resize_term(SCREEN_HEIGHT,SCREEN_WIDTH);
    noecho();
    curs_set(0);
    start_color();
    
    //���� ����
    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    
    //�ʱ� ��� ����
    attron(COLOR_PAIR(0));
    wbkgd(stdscr,COLOR_PAIR(0) | A_BOLD);
}

//Ÿ��Ʋ ȭ�� ǥ�� ȭ��
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
    mvprintw(22, 35, "������ �����Ϸ��� �ƹ�Ű�� �����ֽʽÿ�");
    attroff(COLOR_PAIR(0));

    BorderScreen();
    refresh();
}

void Screen::GameOverScreen(){
}

void Screen::GameClearScreen() {
}

void Screen::NextStageScreen() {
}

void Screen::GamePlayScreen(Map map){
    _gameScreen = subwin(stdscr,22,44,7,2);
    wbkgd(_gameScreen, COLOR_PAIR(1));
    wattron(_gameScreen, COLOR_PAIR(1));

    for (int r = 0; r < map.GetMapRows(); r++){
        for (int c = 0; c < map.GetMapCols(); c++) {
           int value = map.GetMapValue(r,c);
           if (value == 0) {
                wattron(_gameScreen, COLOR_PAIR('w'));
                wprintw(_gameScreen, "  ");
           }
            else if(value == 1 || value == -1) {
                wattron(_gameScreen, COLOR_PAIR(2));
                wprintw(_gameScreen, " ");
                mvwprintw(_gameScreen, r, 2*c, "��");
            }
        }        
    }
}

//���� ȭ�� ��� ǥ�� �Լ�
void Screen::BorderScreen() {
    attron(COLOR_PAIR(3));
    border(0, 0, 0, 0, 0, 0, 0, 0);
    attroff(COLOR_PAIR(3));
}

void Screen::Update(Map map){
    GamePlayScreen(map);
    refresh();
    wrefresh(_gameScreen);
}