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

using namespace std;

/*
    Have the UserController listening for button presses
    while another module is controlling a Tetrimino.
*/
int testUserController(){
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
    vector<unsigned int> initialX = {19,20,20,21};
    vector<unsigned int> initialY = {10,9,10,10};
    
    
    
    
    KeyboardListener* KeyboardListener = KeyboardListener::getInstance();


    AppController ac;
    
    ac.setControllable(AppLogic::getInstance());

    TetriminoController tc;
   
    AppLogic* ref = nullptr;

    KeyboardListener::getInstance()->registerController(&ac);
    KeyboardListener::getInstance()->registerController(&tc);

    TetriminoCycle tetCycle;
    tetCycle.setController(&tc);
    AppLogic::getInstance()->registerGameDaemon(&tetCycle);
    tetrimino = new TPiece(mainEnv, COLOR_MAGENTA, initialX, initialY); 
    tetrimino->show();
     tc.setControllable(tetrimino);
    tetCycle.setDelay(20);
    // tetCycle.startAutoThread();

    KeyboardListener::getInstance()->startListening();
    

    // tetCycle.waitOnAutoThread();
    KeyboardListener::getInstance()->waitOnListener();
    
    delete tetrimino;
    
    endwin();

    return 0;
}