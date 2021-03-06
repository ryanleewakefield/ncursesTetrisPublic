#include <iostream>
#include <ncurses.h>
#include <string>
#include <thread>
#include <mutex>
#include <memory>
#include <chrono>

#include "../classes/Cell.hpp"
#include "../classes/Environment.hpp"
#include "../classes/Tetrimino.hpp"
#include "../classes/UserController.hpp"
#include "../classes/LongPiece.hpp"
#include "../classes/LeftL.hpp"
#include "../classes/RightL.hpp"
#include "../classes/LeftS.hpp"
#include "../classes/RightS.hpp"
#include "../classes/TPiece.hpp"
#include "../classes/Square.hpp"

#include "../classes/KeyboardListener.hpp"
#include "../classes/ScreenWriter.hpp"
#include "../classes/AppLogic.hpp"
#include "../classes/GameDaemon.hpp"
#include "../classes/AppController.hpp"
#include "../classes/TetriminoController.hpp"

#include "../tests/testCell.cpp"
#include "../tests/testUserController.cpp"
#include "../tests/testGravityAndPassingCellsToEnvironment.cpp"
#include "../tests/testGenerationAlgorithm.cpp"
#include "../tests/testTetriminoFactory.cpp"
#include "../tests/testPaintingSpacesInEnvironment.cpp"
#include "../tests/testCCDAlgorithm.cpp"
#include "../tests/testFullGame.cpp"

using namespace std;

void writeToLine(WINDOW* win, int line, string data);
int runApp();

int main(int argc, char* argv[]){

    // return testUserController();

    // return testGravityAndPassingCellsToEnvironment();
    
    // return testGenerationAlgorithm();

    // return testTetriminoFactory();

    // return testPaintingSpacesInEnvironment();

    // return testCCDAlgorithm();

    return testFullGame();

    // return runApp();
}

int runApp(){

    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, true);
    refresh();
    cout << can_change_color << endl;
    getch();

    endwin();

    return 0;
}


void writeToLine(WINDOW* win, int line, string data){
	wmove(win, line, 5);
	wclrtoeol(win);
	wrefresh(win);
	waddnstr(win, data.c_str(), data.length());
	wrefresh(win);
}
