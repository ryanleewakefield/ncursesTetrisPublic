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





int testStartingAndStopingThreads(){
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
    
    tetrimino = new TPiece(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->setActive(true); 
    tetrimino->show();
    
    KeyboardListener* KeyboardListener = KeyboardListener::getInstance();


    AppController ac;
    AppLogic al;
    ac.setControllable(&al);

    TetriminoController tc;
    tc.setControllable(tetrimino);


    KeyboardListener::getInstance()->registerController(&ac);
    KeyboardListener::getInstance()->registerController(&tc);

    

    GravityCycle gravityCycle;
    gravityCycle.setController(&tc);
    
    al.registerGameDaemon(&gravityCycle);

    gravityCycle.setDelay(100);
    gravityCycle.startAutoThread();


    KeyboardListener::getInstance()->startListening();
    // for(int i = 0; i < 5; i++){
        
        // getch();
        
        
        


        //  gravityCycle.waitOnAutoThread();
        //  gravityCycle.cleanUpThread();
    // }
     
    // KeyboardListener::getInstance()->stopListening();
    KeyboardListener::getInstance()->waitOnListener();
    // delete tetrimino;
    
    endwin();

    return 0;
}