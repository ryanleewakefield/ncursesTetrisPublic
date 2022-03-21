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

using namespace std;

int testTetriminoSubClasses(){
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
    Tetrimino* tetrimino = nullptr;
    vector<unsigned int> initialX = {20,20,20,20};
    vector<unsigned int> initialY = {20,21,22,23};
    getch();
    tetrimino = new LongPiece(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->show();
    getch();
    tetrimino->moveLeft();
    getch();
    tetrimino->moveUp();
    getch();
    tetrimino->moveRight();
    getch();
    tetrimino->moveDown();
    getch();
    tetrimino->rotateLeft();
    getch();
    delete tetrimino;
    endwin();

    return 0;
}