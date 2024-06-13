#include <ncurses.h>
#include <GameManager.h>

int main(int, char**) {
    GameManager manager;
    manager.GameStart();
    manager.GamePlaying();
	endwin();	
	return 0;
}