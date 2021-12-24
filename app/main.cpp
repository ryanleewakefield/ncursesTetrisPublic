#include <iostream>
#include <ncurses.h>

#include "../classes/Cell.hpp"
#include "../classes/Environment.hpp"
#include "../classes/Tetrimino.hpp"

using namespace std;

int runApp();
int main(int argc, char* argv[]){

    return runApp();
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
    refresh();

    getch();

    endwin();

    return 0;
}