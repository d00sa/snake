#include <ncurses.h>
#include <GameManager.h>

int main(int, char**) {
    GameManager manager;
    manager.GameStart();
    manager.GamePlay();
	endwin();	
	return 0;
}