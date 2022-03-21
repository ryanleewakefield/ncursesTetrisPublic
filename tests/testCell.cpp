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
    

    vector<Cell> cells = {Cell(30, 20, 0,0, COLOR_YELLOW, 'A'),
                        Cell(30, 21, 0,0, COLOR_YELLOW, 'B'),
                        Cell(30, 22, 0,0, COLOR_YELLOW, 'C'),
                        Cell(30, 23, 0,0, COLOR_YELLOW, 'D')};

    for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].paint();
        }
    getch();
    
    endwin();

    return 0;
}
