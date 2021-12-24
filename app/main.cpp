#include <iostream>
#include <ncurses.h>

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