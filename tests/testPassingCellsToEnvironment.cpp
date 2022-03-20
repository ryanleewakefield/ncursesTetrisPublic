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
#include "../classes/AutoController.hpp"

using namespace std;

int testPassingCellsToEnvironment(){
    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, true);
    curs_set(0);
    refresh();
    int height = 43;
    int width = 80;

    // Get instance of Environment Singleton object
    // boundaryElement should print to the screen
    Environment* mainEnv = Environment::getInstance();
    Cell* cellMark1 = new Cell(15,7,0,0, COLOR_YELLOW, '1');
    cellMark1->paint();
    Cell* cellMark2 = new Cell(15,8,0,0, COLOR_YELLOW, '2');
    cellMark2->paint();
    Cell* cellMark3 = new Cell(15,9,0,0, COLOR_YELLOW, '3');
    cellMark3->paint();
    Cell* cellMark4 = new Cell(15,10,0,0, COLOR_YELLOW, '4');
    cellMark4->paint();
    Tetrimino* tetrimino = nullptr;
    vector<unsigned int> initialX = {20,20,20,19};
    vector<unsigned int> initialY = {10,11,12,12};
    getch();
    tetrimino = new RightL(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->show();
    getch();
    tetrimino->passCellsToEnvironment();
    getch();
    delete tetrimino;
    delete cellMark1;
    delete cellMark2;
    delete cellMark3;
    delete cellMark4;
    endwin();

    return 0;
}