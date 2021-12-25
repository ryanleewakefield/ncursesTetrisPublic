#include <iostream>
#include <ncurses.h>
#include <string>

#include "../classes/Cell.hpp"
#include "../classes/Environment.hpp"
#include "../classes/Tetrimino.hpp"

using namespace std;

void writeToLine(WINDOW* win, int line, string data);
int runApp();
int testCell();

int main(int argc, char* argv[]){

    return testCell();
}

int runApp(){

    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, true);
    refresh();
    getch();

    endwin();

    return 0;
}

int testCell(){
    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, true);
    curs_set(0);
    refresh();
    int height = 43;
    int width = 80;
    //Create Cell that appear near center of screen
    Cell* cell;
    cell = new Cell(10, 20, COLOR_YELLOW);
    cell->paint();
    getch();
    cell->move(15, 25);
    getch();
    delete cell;
    endwin();

    return 0;
}
void writeToLine(WINDOW* win, int line, string data){
	wmove(win, line, 0);
	wclrtoeol(win);
	wrefresh(win);
	waddstr(win, data.c_str());
	wrefresh(win);
}