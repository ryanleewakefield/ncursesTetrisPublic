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

int debugEnvironment(){
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


    // //**************************************************
    // //LongPiece
    // vector<unsigned int> initialX = {20,20,20,20};
    // vector<unsigned int> initialY = {10,11,12,13};
    // tetrimino = new LongPiece(mainEnv, COLOR_MAGENTA, initialX, initialY);

    // //**************************************************
    // //LeftL
    // vector<unsigned int> initialX = {20,20,20,21};
    // vector<unsigned int> initialY = {10,11,12,12};
    // tetrimino = new LeftL(mainEnv, COLOR_MAGENTA, initialX, initialY);

    // //**************************************************
    // //RightL
    // vector<unsigned int> initialX = {20,20,20,19};
    // vector<unsigned int> initialY = {10,11,12,12};
    // tetrimino = new RightL(mainEnv, COLOR_MAGENTA, initialX, initialY);

    // //**************************************************
    // //LeftS
    // vector<unsigned int> initialX = {19,20,20,21};
    // vector<unsigned int> initialY = {11,11,10,10};
    // tetrimino = new LeftS(mainEnv, COLOR_MAGENTA, initialX, initialY);

    // //**************************************************
    // //RightS
    // vector<unsigned int> initialX = {19,20,20,21};
    // vector<unsigned int> initialY = {10,10,11,11};
    // tetrimino = new RightS(mainEnv, COLOR_MAGENTA, initialX, initialY);
    
    // //**************************************************
    // //TPiece
    // vector<unsigned int> initialX = {19,20,20,21};
    // vector<unsigned int> initialY = {10,9,10,10};
    // tetrimino = new TPiece(mainEnv, COLOR_MAGENTA, initialX, initialY); 
    
    // //**************************************************
    // //Sqaure
    // vector<unsigned int> initialX = {0,1,0,1};
    // vector<unsigned int> initialY = {0,0,1,1};
    // tetrimino = new Square(mainEnv, COLOR_MAGENTA, initialX, initialY); 
    
    tetrimino->show();
    getch();
    
    KeyboardListener* KeyboardListener = KeyboardListener::getInstance();


    AppController ac;
    AppLogic al;
    ac.setControllable(&al);

    TetriminoController tc;
    tc.setControllable(tetrimino);


    KeyboardListener::getInstance()->registerController(&ac);
    KeyboardListener::getInstance()->registerController(&tc);

    
    KeyboardListener::getInstance()->startListening();
    
    KeyboardListener::getInstance()->waitOnListener();
    
    delete tetrimino;
    
    endwin();

    return 0;


}