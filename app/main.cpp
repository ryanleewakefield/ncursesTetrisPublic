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

void writeToLine(WINDOW* win, int line, string data);
int runApp();
int testCell();
int testEnvironment();
int testTetriminoSubClasses();

int testLeftRotationLongPiece();
int testRightRotationLongPiece();

int testLeftRotationLeftL();
int testRightRotationLeftL();

int testLeftRotationRightL();
int testRightRotationRightL();

int testPassingCellsToEnvironment();

int testLeftRotationLeftS();
int testRightRotationLeftS();

int testLeftRotationRightS();
int testRightRotationRightS();

int testLeftRotationTPiece();
int testRightRotationTPiece();

void createCellsInPlainFunctionStack();
void createVectorOfCells();

int testKeyboardListener();
int testUserController();

int debugEnvironment();

int debugLongPieceLeftRotation();
int debugLongPieceRightRotation();

int main(int argc, char* argv[]){

    //return testCell();
    //return testEnvironment();
    //return testTetriminoSubClasses();
    //return testLeftRotationLongPiece();
    //return testRightRotationLongPiece();
    //return testLeftRotationLeftL();
    //return testRightRotationLeftL();
    //return testLeftRotationRightL();
    //return testRightRotationRightL();
    // return testPassingCellsToEnvironment();
    // return testLeftRotationLeftS();
    // return testRightRotationLeftS();

    // return testLeftRotationRightS();
    // return testRightRotationRightS();

    // return testLeftRotationTPiece();
    // return testRightRotationTPiece();

    // return testKeyboardListener();
    // return testUserController();

    // return debugEnvironment();

    return debugLongPieceLeftRotation();
    // return debugLongPieceRightRotation();
}

int runApp(){

    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, true);
    refresh();
    getch();

    endwin();

    return 0;
}

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



int testEnvironment(){
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
    int stop = 0;
    getch();
    endwin();

    return 0;
}

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
int testLeftRotationLongPiece(){
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
    vector<unsigned int> initialX = {20,20,20,20};
    vector<unsigned int> initialY = {10,11,12,13};
    getch();
    tetrimino = new LongPiece(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->show();
    getch();
    
    delete tetrimino;
    delete cellMark1;
    delete cellMark2;
    delete cellMark3;
    delete cellMark4;
    endwin();

    return 0;
}
int testRightRotationLongPiece(){
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
    vector<unsigned int> initialX = {20,20,20,20};
    vector<unsigned int> initialY = {10,11,12,13};
    getch();
    tetrimino = new LongPiece(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->show();
    getch();
    tetrimino->rotateRight();
    getch();
    tetrimino->rotateRight();
    getch();
    tetrimino->rotateRight();
    getch();
    tetrimino->rotateRight();
    getch();
    delete tetrimino;
    delete cellMark1;
    delete cellMark2;
    delete cellMark3;
    delete cellMark4;
    endwin();

    return 0;
}
int testLeftRotationLeftL(){
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
    vector<unsigned int> initialX = {20,20,20,21};
    vector<unsigned int> initialY = {10,11,12,12};
    getch();
    tetrimino = new LeftL(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->show();
    getch();
    tetrimino->rotateLeft();
    getch();
    tetrimino->rotateLeft();
    getch();
    tetrimino->rotateLeft();
    getch();
    tetrimino->rotateLeft();
    getch();
    delete tetrimino;
    delete cellMark1;
    delete cellMark2;
    delete cellMark3;
    delete cellMark4;
    endwin();

    return 0;
}
int testRightRotationLeftL(){
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
    vector<unsigned int> initialX = {20,20,20,21};
    vector<unsigned int> initialY = {10,11,12,12};
    getch();
    tetrimino = new LeftL(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->show();
    getch();
    tetrimino->rotateRight();
    getch();
    tetrimino->rotateRight();
    getch();
    tetrimino->rotateRight();
    getch();
    tetrimino->rotateRight();
    getch();
    delete tetrimino;
    delete cellMark1;
    delete cellMark2;
    delete cellMark3;
    delete cellMark4;
    endwin();

    return 0;
}
int testLeftRotationRightL(){
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
    tetrimino->rotateLeft();
    getch();
    tetrimino->rotateLeft();
    getch();
    tetrimino->rotateLeft();
    getch();
    tetrimino->rotateLeft();
    getch();
    delete tetrimino;
    delete cellMark1;
    delete cellMark2;
    delete cellMark3;
    delete cellMark4;
    endwin();

    return 0;
}
int testRightRotationRightL(){
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
    tetrimino->rotateRight();
    getch();
    tetrimino->rotateRight();
    getch();
    tetrimino->rotateRight();
    getch();
    tetrimino->rotateRight();
    getch();
    delete tetrimino;
    delete cellMark1;
    delete cellMark2;
    delete cellMark3;
    delete cellMark4;
    endwin();

    return 0;
}
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
int testLeftRotationLeftS(){
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
    vector<unsigned int> initialX = {19,20,20,21};
    vector<unsigned int> initialY = {11,11,10,10};
    getch();
    tetrimino = new LeftS(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->show();
    getch();
    tetrimino->rotateLeft();
    getch();
    tetrimino->rotateLeft();
    getch();
    tetrimino->rotateLeft();
    getch();
    tetrimino->rotateLeft();
    getch();
    delete tetrimino;
    delete cellMark1;
    delete cellMark2;
    delete cellMark3;
    delete cellMark4;
    endwin();

    return 0;
}
int testRightRotationLeftS(){
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
    vector<unsigned int> initialX = {19,20,20,21};
    vector<unsigned int> initialY = {11,11,10,10};
    getch();
    tetrimino = new LeftS(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->show();
    getch();
    tetrimino->rotateRight();
    getch();
    tetrimino->rotateRight();
    getch();
    tetrimino->rotateRight();
    getch();
    tetrimino->rotateRight();
    getch();
    delete tetrimino;
    delete cellMark1;
    delete cellMark2;
    delete cellMark3;
    delete cellMark4;
    endwin();

    return 0;
}

int testLeftRotationRightS(){
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
    vector<unsigned int> initialX = {19,20,20,21};
    vector<unsigned int> initialY = {10,10,11,11};
    getch();
    tetrimino = new RightS(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->show();
    getch();
    tetrimino->rotateLeft();
    getch();
    tetrimino->rotateLeft();
    getch();
    tetrimino->rotateLeft();
    getch();
    tetrimino->rotateLeft();
    getch();
    delete tetrimino;
    delete cellMark1;
    delete cellMark2;
    delete cellMark3;
    delete cellMark4;
    endwin();

    return 0;
}
int testRightRotationRightS(){
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
    vector<unsigned int> initialX = {19,20,20,21};
    vector<unsigned int> initialY = {10,10,11,11};
    getch();
    tetrimino = new RightS(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->show();
    getch();
    tetrimino->rotateRight();
    getch();
    tetrimino->rotateRight();
    getch();
    tetrimino->rotateRight();
    getch();
    tetrimino->rotateRight();
    getch();
    delete tetrimino;
    delete cellMark1;
    delete cellMark2;
    delete cellMark3;
    delete cellMark4;
    endwin();

    return 0;
}

int testLeftRotationTPiece(){
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
    vector<unsigned int> initialX = {19,20,20,21};
    vector<unsigned int> initialY = {10,9,10,10};
    getch();
    tetrimino = new TPiece(mainEnv, COLOR_MAGENTA, initialX, initialY);
    tetrimino->show();
    getch();
    tetrimino->rotateLeft();
    getch();
    tetrimino->rotateLeft();
    getch();
    tetrimino->rotateLeft();
    getch();
    tetrimino->rotateLeft();
    getch();
    delete tetrimino;
    delete cellMark1;
    delete cellMark2;
    delete cellMark3;
    delete cellMark4;
    endwin();

    return 0;
}
int testRightRotationTPiece(){
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
    vector<unsigned int> initialX = {19,20,20,21};
    vector<unsigned int> initialY = {10,9,10,10};
    
    tetrimino = new TPiece(mainEnv, COLOR_MAGENTA, initialX, initialY); 
    tetrimino->show();
    getch();
    tetrimino->rotateRight();
    getch();
    tetrimino->rotateRight();
    getch();
    tetrimino->rotateRight();
    getch();
    tetrimino->rotateRight();
    getch();
    delete tetrimino;
    delete cellMark1;
    delete cellMark2;
    delete cellMark3;
    delete cellMark4;
    endwin();

    return 0;
}

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
    
    tetrimino = new TPiece(mainEnv, COLOR_MAGENTA, initialX, initialY); 
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

    // TetriminoCycle tetCycle;
    // tetCycle.setController(&tc);
    
    // tetCycle.setDelay(500);
    // tetCycle.startAutoThread();

    KeyboardListener::getInstance()->startListening();
    

    // tetCycle.waitOnAutoThread();
    KeyboardListener::getInstance()->waitOnListener();
    
    delete tetrimino;
    
    endwin();

    return 0;
}

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

int debugLongPieceLeftRotation(){
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

int debugLongPieceRightRotation(){
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
    cellsForEnviroment.push_back(move(make_unique<Cell>(2,1,7,7,COLOR_GREEN, 'l')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(2,2,7,7,COLOR_GREEN, 'm')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(2,3,7,7,COLOR_GREEN, 'n')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(2,4,7,7,COLOR_GREEN, 'o')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(1,1,7,7,COLOR_GREEN, 'p')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(1,2,7,7,COLOR_GREEN, 'q')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(1,3,7,7,COLOR_GREEN, 'r')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(0,2,7,7,COLOR_GREEN, 's')));


    //Right Side
    cellsForEnviroment.push_back(move(make_unique<Cell>(4,1,7,7,COLOR_GREEN, 'e')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(4,2,7,7,COLOR_GREEN, 'f')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(4,3,7,7,COLOR_GREEN, 'g')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(4,4,7,7,COLOR_GREEN, 'h')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(5,2,7,7,COLOR_GREEN, 'i')));
   
    cellsForEnviroment.push_back(move(make_unique<Cell>(5,3,7,7,COLOR_GREEN, 'j')));
    
    cellsForEnviroment.push_back(move(make_unique<Cell>(6,3,7,7,COLOR_GREEN, 'k')));



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

void writeToLine(WINDOW* win, int line, string data){
	wmove(win, line, 0);
	wclrtoeol(win);
	wrefresh(win);
	waddstr(win, data.c_str());
	wrefresh(win);
}