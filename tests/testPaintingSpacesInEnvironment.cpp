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
#include "../classes/GameEventListener.hpp"

using namespace std;

int testPaintingSpacesInEnvironment(){
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


    //stuff to modify

    // Environment* mainEnv = Environment::getInstance();

    // int myX = 7;
    // int myY = 18;

    // int oX = 6;
    // int oY = 18;
    // mainEnv->spaces[oX][oY] = Space(true, COLOR_GREEN, oX,oY, false, 0);
    // Space& ss = mainEnv->spaces[oX][oY];
    // mainEnv->paint(ss);
    // // // Must modify Environment class to do this testing
    // // // by making the following public...
    // mainEnv->spaces[myX][myY] = Space(true, COLOR_GREEN, myX,myY, false, 0);
    // Space& s = mainEnv->spaces[myX][myY];
    // mainEnv->paint(s);
    // getch();
    // mainEnv->spaces[myX][myY].adjustLevel = 1;
    // mainEnv->erase(s);
    // getch();
    // mainEnv->move(s);
    // getch();
    // mainEnv->paint(s);
    // getch();
    




    // vector<unsigned int> initialX = {11,11,11,11};
    // vector<unsigned int> initialY = {0,1,2,3};
    

    // AppController ac;
    
    // ac.setControllable(AppLogic::getInstance());

    // TetriminoController tc;
    
    // KeyboardListener::getInstance()->registerController(&ac);
    // KeyboardListener::getInstance()->registerController(&tc);

    

    // GravityCycle gravityCycle;
    // gravityCycle.setController(&tc);
    
    // AppLogic::getInstance()->registerGameDaemon(&gravityCycle);
   
    // GameEventListener* ref = GameEventListener::getInstance();
    // Tetrimino* tetrimino = nullptr;
    // tetrimino = new LongPiece(mainEnv, COLOR_WHITE, initialX, initialY); 
    // tetrimino->show();
    // // getch();
    // tc.setControllable(tetrimino);
    
    // gravityCycle.setDelay(500);
    // KeyboardListener::getInstance()->startListening();
    // gravityCycle.startAutoThread();
    // for(int i = 0; i < 5; i++){
        
    //     std::unique_lock<std::mutex> lck(ref->mux1);
    //     ref->waitForNextCollision.wait(lck, [ref]{
    //         return ref->detectedCollision;
    //     });
    //     ref->detectedCollision = false;
    //     //put code to setup next tetrimino here...
    //     tetrimino->passCellsToEnvironment();
    //     delete tetrimino;
    //     tetrimino = new LongPiece(mainEnv, COLOR_MAGENTA, initialX, initialY);
    //     tetrimino->show();
    //     tc.setControllable(tetrimino);
    //     ref->readyForGravity = true;
    //     ref->waitForNextTetrimino.notify_one();
        
        
        
    // }
    // KeyboardListener::getInstance()->waitOnListener();
    
    // // delete tetrimino;

    
    endwin();

    return 0;
}