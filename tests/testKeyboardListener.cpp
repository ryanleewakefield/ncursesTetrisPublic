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

int testKeyboardListener(){
    initscr();
    start_color();
    cbreak();
    noecho();
    //keypad(stdscr, true);
    curs_set(0);
    refresh();
    int height = 43;
    int width = 80;
    KeyboardListener* KeyboardListener = KeyboardListener::getInstance();

    ScreenWriterController swc;
    ScreenWriter sw;
    swc.setControllable(&sw);

    AppController ac;
    AppLogic al;
    ac.setControllable(&al);


    KeyboardListener::getInstance()->registerController(&swc);
    KeyboardListener::getInstance()->registerController(&ac);
    KeyboardListener::getInstance()->startListening();
    //React to stuff on keyboard listener thread for 30 seconds
    //this_thread::sleep_for(chrono::seconds(30));
    // KeyboardListener::getInstance()->stopListening();
    KeyboardListener::getInstance()->waitOnListener();
    endwin();

    return 0;
}