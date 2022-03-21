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

/*
* Passed initial tests
*/
int debugLongPieceLeftRotationOrientationZero(){
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
    vector<unique_ptr<Cell>> cellsForEnviroment;

    //Left Side
    cellsForEnviroment.push_back(move(make_unique<Cell>(2,1,7,7,COLOR_GREEN, 'e')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(2,2,7,7,COLOR_GREEN, 'f')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(2,3,7,7,COLOR_GREEN, 'g')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(2,4,7,7,COLOR_GREEN, 'h')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(1,2,7,7,COLOR_GREEN, 'i')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(1,3,7,7,COLOR_GREEN, 'j')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(0,3,7,7,COLOR_GREEN, 'k')));


    //Right Side
    // cellsForEnviroment.push_back(move(make_unique<Cell>(4,1,7,7,COLOR_GREEN, 'l')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(4,2,7,7,COLOR_GREEN, 'm')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(4,3,7,7,COLOR_GREEN, 'n')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(4,4,7,7,COLOR_GREEN, 'o')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(5,1,7,7,COLOR_GREEN, 'p')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(5,2,7,7,COLOR_GREEN, 'q')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(5,3,7,7,COLOR_GREEN, 'r')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(6,2,7,7,COLOR_GREEN, 's')));


    for(unsigned int i = 0; i < cellsForEnviroment.size(); i++){
        cellsForEnviroment[i]->paint();
        Environment::getInstance()->addCell(move(cellsForEnviroment[i]));
    }
    Tetrimino* tetrimino = nullptr;
    vector<unsigned int> initialX = {3,3,3,3};
    vector<unsigned int> initialY = {1,2,3,4};
    
    tetrimino = new LongPiece(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->show();
    


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

int debugLongPieceLeftRotationOrientationOne(){
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
    vector<unique_ptr<Cell>> cellsForEnviroment;

    //Left Side
    // cellsForEnviroment.push_back(move(make_unique<Cell>(11,13,7,7,COLOR_GREEN, 'e')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,13,7,7,COLOR_GREEN, 'f')));
   
    // cellsForEnviroment.push_back(move(make_unique<Cell>(13,13,7,7,COLOR_GREEN, 'g')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,13,7,7,COLOR_GREEN, 'h')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,14,7,7,COLOR_GREEN, 'i')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(13,14,7,7,COLOR_GREEN, 'j')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(13,15,7,7,COLOR_GREEN, 'k')));


    //Right Side
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,11,7,7,COLOR_GREEN, 'l')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,11,7,7,COLOR_GREEN, 'm')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(13,11,7,7,COLOR_GREEN, 'n')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,11,7,7,COLOR_GREEN, 'o')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,10,7,7,COLOR_GREEN, 'p')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,10,7,7,COLOR_GREEN, 'q')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(13,10,7,7,COLOR_GREEN, 'r')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,9,7,7,COLOR_GREEN, 's')));


    for(unsigned int i = 0; i < cellsForEnviroment.size(); i++){
        cellsForEnviroment[i]->paint();
        Environment::getInstance()->addCell(move(cellsForEnviroment[i]));
    }
    Tetrimino* tetrimino = nullptr;
    vector<unsigned int> initialX = {14,13,12,11};
    vector<unsigned int> initialY = {12,12,12,12};
    
    tetrimino = new LongPiece(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->setOrientation(1);
    tetrimino->show();
    


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

int debugLongPieceLeftRotationOrientationTwo(){
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
    vector<unique_ptr<Cell>> cellsForEnviroment;

    //Left Side
    // cellsForEnviroment.push_back(move(make_unique<Cell>(2,1,7,7,COLOR_GREEN, 'e')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(2,2,7,7,COLOR_GREEN, 'f')));
   
    // cellsForEnviroment.push_back(move(make_unique<Cell>(2,3,7,7,COLOR_GREEN, 'g')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(2,4,7,7,COLOR_GREEN, 'h')));
   
    // cellsForEnviroment.push_back(move(make_unique<Cell>(1,2,7,7,COLOR_GREEN, 'i')));
   
    // cellsForEnviroment.push_back(move(make_unique<Cell>(1,3,7,7,COLOR_GREEN, 'j')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(0,3,7,7,COLOR_GREEN, 'k')));


    //Right Side
    cellsForEnviroment.push_back(move(make_unique<Cell>(4,1,7,7,COLOR_GREEN, 'l')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(4,2,7,7,COLOR_GREEN, 'm')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(4,3,7,7,COLOR_GREEN, 'n')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(4,4,7,7,COLOR_GREEN, 'o')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(5,1,7,7,COLOR_GREEN, 'p')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(5,2,7,7,COLOR_GREEN, 'q')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(5,3,7,7,COLOR_GREEN, 'r')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(6,2,7,7,COLOR_GREEN, 's')));


    for(unsigned int i = 0; i < cellsForEnviroment.size(); i++){
        cellsForEnviroment[i]->paint();
        Environment::getInstance()->addCell(move(cellsForEnviroment[i]));
    }
    Tetrimino* tetrimino = nullptr;
    vector<unsigned int> initialX = {3,3,3,3};
    vector<unsigned int> initialY = {4,3,2,1};
    
    tetrimino = new LongPiece(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->setOrientation(2);
    tetrimino->show();
    


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

int debugLongPieceLeftRotationOrientationThree(){
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
    vector<unique_ptr<Cell>> cellsForEnviroment;

    //Left Side
    // cellsForEnviroment.push_back(move(make_unique<Cell>(11,13,7,7,COLOR_GREEN, 'e')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,13,7,7,COLOR_GREEN, 'f')));
   
    // cellsForEnviroment.push_back(move(make_unique<Cell>(13,13,7,7,COLOR_GREEN, 'g')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,13,7,7,COLOR_GREEN, 'h')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,14,7,7,COLOR_GREEN, 'i')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(13,14,7,7,COLOR_GREEN, 'j')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(13,15,7,7,COLOR_GREEN, 'k')));


    //Right Side
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,11,7,7,COLOR_GREEN, 'l')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,11,7,7,COLOR_GREEN, 'm')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(13,11,7,7,COLOR_GREEN, 'n')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,11,7,7,COLOR_GREEN, 'o')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,10,7,7,COLOR_GREEN, 'p')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,10,7,7,COLOR_GREEN, 'q')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(13,10,7,7,COLOR_GREEN, 'r')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,9,7,7,COLOR_GREEN, 's')));


    for(unsigned int i = 0; i < cellsForEnviroment.size(); i++){
        cellsForEnviroment[i]->paint();
        Environment::getInstance()->addCell(move(cellsForEnviroment[i]));
    }
    Tetrimino* tetrimino = nullptr;
    vector<unsigned int> initialX = {11,12,13,14};
    vector<unsigned int> initialY = {12,12,12,12};
    
    tetrimino = new LongPiece(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->setOrientation(3);
    tetrimino->show();
    


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

int debugLongPieceRightRotationOrientationZero(){
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
    vector<unique_ptr<Cell>> cellsForEnviroment;

    //Left Side
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,11,7,7,COLOR_GREEN, 'l')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,12,7,7,COLOR_GREEN, 'm')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,13,7,7,COLOR_GREEN, 'n')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,14,7,7,COLOR_GREEN, 'o')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,11,7,7,COLOR_GREEN, 'p')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,12,7,7,COLOR_GREEN, 'q')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,13,7,7,COLOR_GREEN, 'r')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(10,12,7,7,COLOR_GREEN, 's')));


    //Right Side
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,11,7,7,COLOR_GREEN, 'e')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,12,7,7,COLOR_GREEN, 'f')));
   
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,13,7,7,COLOR_GREEN, 'g')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(14,14,7,7,COLOR_GREEN, 'h')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(15,12,7,7,COLOR_GREEN, 'i')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(15,13,7,7,COLOR_GREEN, 'j')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(16,13,7,7,COLOR_GREEN, 'k')));



    for(unsigned int i = 0; i < cellsForEnviroment.size(); i++){
        cellsForEnviroment[i]->paint();
        Environment::getInstance()->addCell(move(cellsForEnviroment[i]));
    }
    Tetrimino* tetrimino = nullptr;
    vector<unsigned int> initialX = {13,13,13,13};
    vector<unsigned int> initialY = {11,12,13,14};
    
    tetrimino = new LongPiece(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->setOrientation(0);
    tetrimino->show();
    


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


int debugLongPieceRightRotationOrientationOne(){
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
    vector<unique_ptr<Cell>> cellsForEnviroment;

    //Top Side
    // cellsForEnviroment.push_back(move(make_unique<Cell>(11,11,7,7,COLOR_GREEN, 'e')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,11,7,7,COLOR_GREEN, 'f')));
   
    // cellsForEnviroment.push_back(move(make_unique<Cell>(13,11,7,7,COLOR_GREEN, 'g')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,11,7,7,COLOR_GREEN, 'h')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,10,7,7,COLOR_GREEN, 'i')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(13,10,7,7,COLOR_GREEN, 'j')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(13,9,7,7,COLOR_GREEN, 'k')));


    //Bottom Side
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,13,7,7,COLOR_GREEN, 'l')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,13,7,7,COLOR_GREEN, 'm')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(13,13,7,7,COLOR_GREEN, 'n')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,13,7,7,COLOR_GREEN, 'o')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,14,7,7,COLOR_GREEN, 'p')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,14,7,7,COLOR_GREEN, 'q')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(13,14,7,7,COLOR_GREEN, 'r')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,15,7,7,COLOR_GREEN, 's')));


    for(unsigned int i = 0; i < cellsForEnviroment.size(); i++){
        cellsForEnviroment[i]->paint();
        Environment::getInstance()->addCell(move(cellsForEnviroment[i]));
    }
    Tetrimino* tetrimino = nullptr;
    vector<unsigned int> initialX = {14,13,12,11};
    vector<unsigned int> initialY = {12,12,12,12};
    
    // vector<unsigned int> initialX = {13,13,13,13};
    // vector<unsigned int> initialY = {13,12,11,10};
    tetrimino = new LongPiece(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->setOrientation(1);
    tetrimino->show();
    


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
int debugLongPieceRightRotationOrientationTwo(){
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
    vector<unique_ptr<Cell>> cellsForEnviroment;

    //Right Side
    cellsForEnviroment.push_back(move(make_unique<Cell>(14,10,7,7,COLOR_GREEN, 'e')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(14,11,7,7,COLOR_GREEN, 'f')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(14,12,7,7,COLOR_GREEN, 'g')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(14,13,7,7,COLOR_GREEN, 'h')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(15,11,7,7,COLOR_GREEN, 'i')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(15,12,7,7,COLOR_GREEN, 'j')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(16,12,7,7,COLOR_GREEN, 'k')));


    //Left Side
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,10,7,7,COLOR_GREEN, 'l')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,11,7,7,COLOR_GREEN, 'm')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,12,7,7,COLOR_GREEN, 'n')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,13,7,7,COLOR_GREEN, 'o')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,10,7,7,COLOR_GREEN, 'p')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(11,11,7,7,COLOR_GREEN, 'q')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(11,12,7,7,COLOR_GREEN, 'r')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(10,11,7,7,COLOR_GREEN, 's')));


    for(unsigned int i = 0; i < cellsForEnviroment.size(); i++){
        cellsForEnviroment[i]->paint();
        Environment::getInstance()->addCell(move(cellsForEnviroment[i]));
    }
    Tetrimino* tetrimino = nullptr;
    vector<unsigned int> initialX = {13,13,13,13};
    vector<unsigned int> initialY = {13,12,11,10};

    tetrimino = new LongPiece(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->setOrientation(2);
    tetrimino->show();
    


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

int debugLeftLLeftRotationOrientationZero(){
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
    vector<unique_ptr<Cell>> cellsForEnviroment;

    //Left Side
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,13,7,7,COLOR_GREEN, 'e')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,14,7,7,COLOR_GREEN, 'f')));
   
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,15,7,7,COLOR_GREEN, 'g')));

    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,16,7,7,COLOR_GREEN, 'p')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(11,14,7,7,COLOR_GREEN, 'i')));
   
    // cellsForEnviroment.push_back(move(make_unique<Cell>(11,15,7,7,COLOR_GREEN, 'j')));
    
    
    //Right Side
    cellsForEnviroment.push_back(move(make_unique<Cell>(14,13,7,7,COLOR_GREEN, 'k')));

    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,14,7,7,COLOR_GREEN, 'l')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(15,13,7,7,COLOR_GREEN, 'm')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(15,14,7,7,COLOR_GREEN, 'n')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(15,15,7,7,COLOR_GREEN, 'o')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(13,16,7,7,COLOR_GREEN, 'q')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(14,16,7,7,COLOR_GREEN, 'r')));


    for(unsigned int i = 0; i < cellsForEnviroment.size(); i++){
        cellsForEnviroment[i]->paint();
        Environment::getInstance()->addCell(move(cellsForEnviroment[i]));
    }
    Tetrimino* tetrimino = nullptr;
    vector<unsigned int> initialX = {13,13,13,14};
    vector<unsigned int> initialY = {13,14,15,15};

    tetrimino = new LeftL(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->setOrientation(0);
    tetrimino->show();
    


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

int debugLeftLLeftRotationOrientationThree(){
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
    vector<unique_ptr<Cell>> cellsForEnviroment;

    //Left Side
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,16,7,7,COLOR_GREEN, 'e')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,16,7,7,COLOR_GREEN, 'f')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(13,16,7,7,COLOR_GREEN, 'g')));

    cellsForEnviroment.push_back(move(make_unique<Cell>(14,16,7,7,COLOR_GREEN, 'p')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,17,7,7,COLOR_GREEN, 'i')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(13,17,7,7,COLOR_GREEN, 'j')));
    
    
    //Right Side
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,14,7,7,COLOR_GREEN, 'k')));

    cellsForEnviroment.push_back(move(make_unique<Cell>(12,14,7,7,COLOR_GREEN, 'l')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,13,7,7,COLOR_GREEN, 'm')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,13,7,7,COLOR_GREEN, 'n')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(13,13,7,7,COLOR_GREEN, 'o')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,15,7,7,COLOR_GREEN, 'q')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,14,7,7,COLOR_GREEN, 'r')));


    for(unsigned int i = 0; i < cellsForEnviroment.size(); i++){
        cellsForEnviroment[i]->paint();
        Environment::getInstance()->addCell(move(cellsForEnviroment[i]));
    }
    Tetrimino* tetrimino = nullptr;
    vector<unsigned int> initialX = {11,12,13,13};
    vector<unsigned int> initialY = {15,15,15,14};

    tetrimino = new LeftL(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->setOrientation(3);
    tetrimino->show();
    


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
int debugLeftLLeftRotationOrientationTwo(){
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
    vector<unique_ptr<Cell>> cellsForEnviroment;

    //Left Side
    cellsForEnviroment.push_back(move(make_unique<Cell>(14,17,7,7,COLOR_GREEN, 'e')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(14,16,7,7,COLOR_GREEN, 'f')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(14,15,7,7,COLOR_GREEN, 'g')));

    cellsForEnviroment.push_back(move(make_unique<Cell>(14,14,7,7,COLOR_GREEN, 'p')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(15,16,7,7,COLOR_GREEN, 'i')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(15,15,7,7,COLOR_GREEN, 'j')));
    
    
    //Right Side
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,17,7,7,COLOR_GREEN, 'k')));

    cellsForEnviroment.push_back(move(make_unique<Cell>(12,16,7,7,COLOR_GREEN, 'l')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,17,7,7,COLOR_GREEN, 'm')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,16,7,7,COLOR_GREEN, 'n')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,15,7,7,COLOR_GREEN, 'o')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(13,14,7,7,COLOR_GREEN, 'q')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,14,7,7,COLOR_GREEN, 'r')));


    for(unsigned int i = 0; i < cellsForEnviroment.size(); i++){
        cellsForEnviroment[i]->paint();
        Environment::getInstance()->addCell(move(cellsForEnviroment[i]));
    }
    Tetrimino* tetrimino = nullptr;
    vector<unsigned int> initialX = {13,13,13,12};
    vector<unsigned int> initialY = {17,16,15,15};

    tetrimino = new LeftL(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->setOrientation(2);
    tetrimino->show();
    


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
int debugLeftLLeftRotationOrientationOne(){
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
    vector<unique_ptr<Cell>> cellsForEnviroment;

    //Left Side
    cellsForEnviroment.push_back(move(make_unique<Cell>(15,14,7,7,COLOR_GREEN, 'e')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(14,14,7,7,COLOR_GREEN, 'f')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(13,14,7,7,COLOR_GREEN, 'g')));

    cellsForEnviroment.push_back(move(make_unique<Cell>(12,14,7,7,COLOR_GREEN, 'p')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(14,13,7,7,COLOR_GREEN, 'i')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(13,13,7,7,COLOR_GREEN, 'j')));
    
    
    //Right Side
    cellsForEnviroment.push_back(move(make_unique<Cell>(15,16,7,7,COLOR_GREEN, 'k')));

    cellsForEnviroment.push_back(move(make_unique<Cell>(14,16,7,7,COLOR_GREEN, 'l')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(15,17,7,7,COLOR_GREEN, 'm')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(14,17,7,7,COLOR_GREEN, 'n')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(13,17,7,7,COLOR_GREEN, 'o')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,15,7,7,COLOR_GREEN, 'q')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,16,7,7,COLOR_GREEN, 'r')));


    for(unsigned int i = 0; i < cellsForEnviroment.size(); i++){
        cellsForEnviroment[i]->paint();
        Environment::getInstance()->addCell(move(cellsForEnviroment[i]));
    }
    Tetrimino* tetrimino = nullptr;
    vector<unsigned int> initialX = {15,14,13,13};
    vector<unsigned int> initialY = {15,15,15,16};

    tetrimino = new LeftL(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->setOrientation(1);
    tetrimino->show();
    


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

int debugLeftLRightRotationOrientationZero(){
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
    vector<unique_ptr<Cell>> cellsForEnviroment;

    //Left Side
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,13,7,7,COLOR_GREEN, 'e')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,14,7,7,COLOR_GREEN, 'f')));
   
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,15,7,7,COLOR_GREEN, 'g')));

    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,16,7,7,COLOR_GREEN, 'p')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,14,7,7,COLOR_GREEN, 'i')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,15,7,7,COLOR_GREEN, 'j')));
    
    
    //Right Side
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,13,7,7,COLOR_GREEN, 'k')));

    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,14,7,7,COLOR_GREEN, 'l')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(15,13,7,7,COLOR_GREEN, 'm')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(15,14,7,7,COLOR_GREEN, 'n')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(15,15,7,7,COLOR_GREEN, 'o')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(13,16,7,7,COLOR_GREEN, 'q')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,16,7,7,COLOR_GREEN, 'r')));


    for(unsigned int i = 0; i < cellsForEnviroment.size(); i++){
        cellsForEnviroment[i]->paint();
        Environment::getInstance()->addCell(move(cellsForEnviroment[i]));
    }
    Tetrimino* tetrimino = nullptr;
    vector<unsigned int> initialX = {13,13,13,14};
    vector<unsigned int> initialY = {13,14,15,15};

    tetrimino = new LeftL(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->setOrientation(0);
    tetrimino->show();
    


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

int debugRightLLeftRotationOrientationZero(){
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
    vector<unique_ptr<Cell>> cellsForEnviroment;

    //Left Side
    cellsForEnviroment.push_back(move(make_unique<Cell>(14,13,7,7,COLOR_GREEN, 'e')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,14,7,7,COLOR_GREEN, 'f')));
   
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,15,7,7,COLOR_GREEN, 'g')));

    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,16,7,7,COLOR_GREEN, 'p')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(15,14,7,7,COLOR_GREEN, 'i')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(15,15,7,7,COLOR_GREEN, 'j')));
    
    
    //Right Side
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,13,7,7,COLOR_GREEN, 'k')));

    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,14,7,7,COLOR_GREEN, 'l')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,13,7,7,COLOR_GREEN, 'm')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,14,7,7,COLOR_GREEN, 'n')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,15,7,7,COLOR_GREEN, 'o')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(13,16,7,7,COLOR_GREEN, 'q')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,16,7,7,COLOR_GREEN, 'r')));


    for(unsigned int i = 0; i < cellsForEnviroment.size(); i++){
        cellsForEnviroment[i]->paint();
        Environment::getInstance()->addCell(move(cellsForEnviroment[i]));
    }
    Tetrimino* tetrimino = nullptr;
    vector<unsigned int> initialX = {13,13,13,12};
    vector<unsigned int> initialY = {13,14,15,15};

    tetrimino = new RightL(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->setOrientation(0);
    tetrimino->show();
    


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

int debugRightLLeftRotationOrientationOne(){
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
    vector<unique_ptr<Cell>> cellsForEnviroment;

    //Left Side
    cellsForEnviroment.push_back(move(make_unique<Cell>(15,16,7,7,COLOR_GREEN, 'e')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(14,16,7,7,COLOR_GREEN, 'f')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(13,16,7,7,COLOR_GREEN, 'g')));

    cellsForEnviroment.push_back(move(make_unique<Cell>(12,16,7,7,COLOR_GREEN, 'p')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(14,17,7,7,COLOR_GREEN, 'i')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(13,17,7,7,COLOR_GREEN, 'j')));
    
    
    //Right Side
    cellsForEnviroment.push_back(move(make_unique<Cell>(15,14,7,7,COLOR_GREEN, 'k')));

    cellsForEnviroment.push_back(move(make_unique<Cell>(14,14,7,7,COLOR_GREEN, 'l')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(15,13,7,7,COLOR_GREEN, 'm')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(14,13,7,7,COLOR_GREEN, 'n')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(13,13,7,7,COLOR_GREEN, 'o')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,15,7,7,COLOR_GREEN, 'q')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,14,7,7,COLOR_GREEN, 'r')));


    for(unsigned int i = 0; i < cellsForEnviroment.size(); i++){
        cellsForEnviroment[i]->paint();
        Environment::getInstance()->addCell(move(cellsForEnviroment[i]));
    }
    Tetrimino* tetrimino = nullptr;
    vector<unsigned int> initialX = {15,14,13,13};
    vector<unsigned int> initialY = {15,15,15,14};

    tetrimino = new RightL(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->setOrientation(1);
    tetrimino->show();
    


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

int debugRightLLeftRotationOrientationTwo(){
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
    vector<unique_ptr<Cell>> cellsForEnviroment;

    //Left Side
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,17,7,7,COLOR_GREEN, 'e')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,16,7,7,COLOR_GREEN, 'f')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,15,7,7,COLOR_GREEN, 'g')));

    cellsForEnviroment.push_back(move(make_unique<Cell>(12,14,7,7,COLOR_GREEN, 'p')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,16,7,7,COLOR_GREEN, 'i')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,15,7,7,COLOR_GREEN, 'j')));
    
    
    //Right Side
    cellsForEnviroment.push_back(move(make_unique<Cell>(14,17,7,7,COLOR_GREEN, 'k')));

    cellsForEnviroment.push_back(move(make_unique<Cell>(14,16,7,7,COLOR_GREEN, 'l')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(15,17,7,7,COLOR_GREEN, 'm')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(15,16,7,7,COLOR_GREEN, 'n')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(15,15,7,7,COLOR_GREEN, 'o')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(13,14,7,7,COLOR_GREEN, 'q')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(14,14,7,7,COLOR_GREEN, 'r')));


    for(unsigned int i = 0; i < cellsForEnviroment.size(); i++){
        cellsForEnviroment[i]->paint();
        Environment::getInstance()->addCell(move(cellsForEnviroment[i]));
    }
    Tetrimino* tetrimino = nullptr;
    vector<unsigned int> initialX = {13,13,13,14};
    vector<unsigned int> initialY = {17,16,15,15};

    tetrimino = new RightL(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->setOrientation(2);
    tetrimino->show();
    


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

int debugRightLLeftRotationOrientationThree(){
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
    vector<unique_ptr<Cell>> cellsForEnviroment;

    //Left Side
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,14,7,7,COLOR_GREEN, 'e')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,14,7,7,COLOR_GREEN, 'f')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(13,14,7,7,COLOR_GREEN, 'g')));

    cellsForEnviroment.push_back(move(make_unique<Cell>(14,14,7,7,COLOR_GREEN, 'p')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,13,7,7,COLOR_GREEN, 'i')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(13,13,7,7,COLOR_GREEN, 'j')));
    
    
    //Right Side
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,16,7,7,COLOR_GREEN, 'k')));

    cellsForEnviroment.push_back(move(make_unique<Cell>(12,16,7,7,COLOR_GREEN, 'l')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,17,7,7,COLOR_GREEN, 'm')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,17,7,7,COLOR_GREEN, 'n')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(13,17,7,7,COLOR_GREEN, 'o')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(14,15,7,7,COLOR_GREEN, 'q')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(14,16,7,7,COLOR_GREEN, 'r')));


    for(unsigned int i = 0; i < cellsForEnviroment.size(); i++){
        cellsForEnviroment[i]->paint();
        Environment::getInstance()->addCell(move(cellsForEnviroment[i]));
    }
    Tetrimino* tetrimino = nullptr;
    vector<unsigned int> initialX = {11,12,13,13};
    vector<unsigned int> initialY = {15,15,15,16};

    tetrimino = new RightL(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->setOrientation(3);
    tetrimino->show();
    


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

int debugLeftSLeftRotationOrientationZero(){
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
    vector<unique_ptr<Cell>> cellsForEnviroment;

    //Left Side
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,15,7,7,COLOR_GREEN, 'e')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,14,7,7,COLOR_GREEN, 'f')));
   
    // cellsForEnviroment.push_back(move(make_unique<Cell>(13,14,7,7,COLOR_GREEN, 'g')));

    //  cellsForEnviroment.push_back(move(make_unique<Cell>(14,14,7,7,COLOR_GREEN, 'h')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,13,7,7,COLOR_GREEN, 'i')));
   
    // cellsForEnviroment.push_back(move(make_unique<Cell>(13,13,7,7,COLOR_GREEN, 'j')));

    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,13,7,7,COLOR_GREEN, 'k')));
    
    
    //Right Side
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,16,7,7,COLOR_GREEN, 'l')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,17,7,7,COLOR_GREEN, 'm')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(13,17,7,7,COLOR_GREEN, 'n')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,17,7,7,COLOR_GREEN, 'o')));

    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,18,7,7,COLOR_GREEN, 'p')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(13,18,7,7,COLOR_GREEN, 'q')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,18,7,7,COLOR_GREEN, 'r')));


    for(unsigned int i = 0; i < cellsForEnviroment.size(); i++){
        cellsForEnviroment[i]->paint();
        Environment::getInstance()->addCell(move(cellsForEnviroment[i]));
    }
    Tetrimino* tetrimino = nullptr;
    vector<unsigned int> initialX = {12,13,13,14};
    vector<unsigned int> initialY = {16,16,15,15};

    tetrimino = new LeftS(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->setOrientation(0);
    tetrimino->show();
    


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

int debugLeftSLeftRotationOrientationOne(){
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
    vector<unique_ptr<Cell>> cellsForEnviroment;

    //Left Side
    // cellsForEnviroment.push_back(move(make_unique<Cell>(13,16,7,7,COLOR_GREEN, 'e')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,16,7,7,COLOR_GREEN, 'f')));
   
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,15,7,7,COLOR_GREEN, 'g')));

    //  cellsForEnviroment.push_back(move(make_unique<Cell>(12,14,7,7,COLOR_GREEN, 'h')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(11,16,7,7,COLOR_GREEN, 'i')));
   
    // cellsForEnviroment.push_back(move(make_unique<Cell>(11,15,7,7,COLOR_GREEN, 'j')));

    // cellsForEnviroment.push_back(move(make_unique<Cell>(11,14,7,7,COLOR_GREEN, 'k')));
    
    
    //Right Side
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,14,7,7,COLOR_GREEN, 'l')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(15,16,7,7,COLOR_GREEN, 'm')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(15,15,7,7,COLOR_GREEN, 'n')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(15,14,7,7,COLOR_GREEN, 'o')));

    // cellsForEnviroment.push_back(move(make_unique<Cell>(16,16,7,7,COLOR_GREEN, 'p')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(16,15,7,7,COLOR_GREEN, 'q')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(16,14,7,7,COLOR_GREEN, 'r')));


    for(unsigned int i = 0; i < cellsForEnviroment.size(); i++){
        cellsForEnviroment[i]->paint();
        Environment::getInstance()->addCell(move(cellsForEnviroment[i]));
    }
    Tetrimino* tetrimino = nullptr;
    vector<unsigned int> initialX = {14,14,13,13};
    vector<unsigned int> initialY = {16,15,15,14};

    tetrimino = new LeftS(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->setOrientation(1);
    tetrimino->show();
    


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

int debugRightSLeftRotationOrientationZero(){
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
    vector<unique_ptr<Cell>> cellsForEnviroment;

    //Left Side
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,15,7,7,COLOR_GREEN, 'e')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,14,7,7,COLOR_GREEN, 'f')));
   
    // cellsForEnviroment.push_back(move(make_unique<Cell>(13,14,7,7,COLOR_GREEN, 'g')));

    //  cellsForEnviroment.push_back(move(make_unique<Cell>(14,14,7,7,COLOR_GREEN, 'h')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,13,7,7,COLOR_GREEN, 'i')));
   
    // cellsForEnviroment.push_back(move(make_unique<Cell>(13,13,7,7,COLOR_GREEN, 'j')));

    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,13,7,7,COLOR_GREEN, 'k')));
    
    
    //Right Side
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,16,7,7,COLOR_GREEN, 'l')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,17,7,7,COLOR_GREEN, 'm')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(13,17,7,7,COLOR_GREEN, 'n')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,17,7,7,COLOR_GREEN, 'o')));

    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,18,7,7,COLOR_GREEN, 'p')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(13,18,7,7,COLOR_GREEN, 'q')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,18,7,7,COLOR_GREEN, 'r')));


    for(unsigned int i = 0; i < cellsForEnviroment.size(); i++){
        cellsForEnviroment[i]->paint();
        Environment::getInstance()->addCell(move(cellsForEnviroment[i]));
    }
    Tetrimino* tetrimino = nullptr;
    //Must set center to B cell
    vector<unsigned int> initialX = {12,13,13,14};
    vector<unsigned int> initialY = {15,15,14,14};

    tetrimino = new RightS(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->setOrientation(0);
    tetrimino->show();
    


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

int debugRightSLeftRotationOrientationOne(){
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
    vector<unique_ptr<Cell>> cellsForEnviroment;

    //Left Side
    // cellsForEnviroment.push_back(move(make_unique<Cell>(13,16,7,7,COLOR_GREEN, 'e')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,16,7,7,COLOR_GREEN, 'f')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(12,15,7,7,COLOR_GREEN, 'g')));

     cellsForEnviroment.push_back(move(make_unique<Cell>(12,14,7,7,COLOR_GREEN, 'h')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,16,7,7,COLOR_GREEN, 'i')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(11,15,7,7,COLOR_GREEN, 'j')));

    cellsForEnviroment.push_back(move(make_unique<Cell>(11,14,7,7,COLOR_GREEN, 'k')));
    
    
    //Right Side
    cellsForEnviroment.push_back(move(make_unique<Cell>(13,16,7,7,COLOR_GREEN, 'l')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,14,7,7,COLOR_GREEN, 'm')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,15,7,7,COLOR_GREEN, 'n')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(14,16,7,7,COLOR_GREEN, 'o')));

    cellsForEnviroment.push_back(move(make_unique<Cell>(16,16,7,7,COLOR_GREEN, 'p')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(16,15,7,7,COLOR_GREEN, 'q')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(16,14,7,7,COLOR_GREEN, 'r')));


    for(unsigned int i = 0; i < cellsForEnviroment.size(); i++){
        cellsForEnviroment[i]->paint();
        Environment::getInstance()->addCell(move(cellsForEnviroment[i]));
    }
    Tetrimino* tetrimino = nullptr;
    //Must set center to B cell
    vector<unsigned int> initialX = {13,13,12,12};
    vector<unsigned int> initialY = {14,15,15,16};

    tetrimino = new RightS(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->setOrientation(1);
    tetrimino->show();
    


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

int debugTPieceLeftRotationOrientationZero(){
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
    vector<unique_ptr<Cell>> cellsForEnviroment;

    //Left Side
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,15,7,7,COLOR_GREEN, 'e')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,14,7,7,COLOR_GREEN, 'f')));
   
    // cellsForEnviroment.push_back(move(make_unique<Cell>(13,14,7,7,COLOR_GREEN, 'g')));

    //  cellsForEnviroment.push_back(move(make_unique<Cell>(14,14,7,7,COLOR_GREEN, 'h')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,13,7,7,COLOR_GREEN, 'i')));
   
    // cellsForEnviroment.push_back(move(make_unique<Cell>(13,13,7,7,COLOR_GREEN, 'j')));

    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,13,7,7,COLOR_GREEN, 'k')));
    
    
    //Right Side
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,16,7,7,COLOR_GREEN, 'l')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,17,7,7,COLOR_GREEN, 'm')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(13,17,7,7,COLOR_GREEN, 'n')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,17,7,7,COLOR_GREEN, 'o')));

    // cellsForEnviroment.push_back(move(make_unique<Cell>(12,18,7,7,COLOR_GREEN, 'p')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(13,18,7,7,COLOR_GREEN, 'q')));
    
    // cellsForEnviroment.push_back(move(make_unique<Cell>(14,18,7,7,COLOR_GREEN, 'r')));


    for(unsigned int i = 0; i < cellsForEnviroment.size(); i++){
        cellsForEnviroment[i]->paint();
        Environment::getInstance()->addCell(move(cellsForEnviroment[i]));
    }
    Tetrimino* tetrimino = nullptr;
    //Must set center to B cell
    vector<unsigned int> initialX = {13,12,13,14};
    vector<unsigned int> initialY = {14,15,15,15};

    tetrimino = new TPiece(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->setOrientation(0);
    tetrimino->show();
    


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