#include <iostream>
#include <ncurses.h>
#include <string>
#include <thread>
#include <mutex>
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


bool cycleTetrimino(Tetrimino* tetrimino, mutex* mux, bool* stopSignal);

bool controllerListener(UserController* userController, Tetrimino* tetrimino, mutex* mux, bool* stopSignal);

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

    // testKeyboardListener();
    testUserController();
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
    
    createCellsInPlainFunctionStack();

    vector<Cell> cells = {Cell(30, 20, COLOR_YELLOW, 'A'),
                        Cell(30, 21, COLOR_YELLOW, 'B'),
                        Cell(30, 22, COLOR_YELLOW, 'C'),
                        Cell(30, 23, COLOR_YELLOW, 'D')};

    for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].paint();
        }
    getch();
    //createVectorOfCells();

    // Cell* cell1 = new Cell(20, 20, COLOR_YELLOW);
    // cell1->paint();
    // Cell* cell2 = new Cell(20, 21, COLOR_YELLOW);
    // cell2->paint();
    // Cell* cell3 = new Cell(20, 22, COLOR_YELLOW);
    // cell3->paint();
    // Cell* cell4 = new Cell(20, 23, COLOR_YELLOW);
    // cell4->paint();
    
    // getch();
    // cell1->move(0, 1);
    // getch();
    // delete cell1;
    // delete cell2;
    // delete cell3;
    // delete cell4;
    endwin();

    return 0;
}

void createCellsInPlainFunctionStack(){
    Cell cell1(20, 20, COLOR_YELLOW, 'A');
    cell1.paint();
    Cell cell2(20, 21, COLOR_YELLOW, 'B');
    cell2.paint();
    Cell cell3(20, 22, COLOR_YELLOW, 'C');
    cell3.paint();
    Cell cell4(20, 23, COLOR_YELLOW, 'D');
    cell4.paint();
    getch();
}

void createVectorOfCells(){
    vector<Cell> cells = {Cell(30, 20, COLOR_YELLOW, 'A'),
                            Cell(30, 21, COLOR_YELLOW, 'B'),
                            Cell(30, 22, COLOR_YELLOW, 'C'),
                            Cell(30, 23, COLOR_YELLOW, 'D')};

    for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].paint();
        }
    getch();
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
    Cell* cellMark1 = new Cell(15,7,COLOR_YELLOW, '1');
    cellMark1->paint();
    Cell* cellMark2 = new Cell(15,8,COLOR_YELLOW, '2');
    cellMark2->paint();
    Cell* cellMark3 = new Cell(15,9,COLOR_YELLOW, '3');
    cellMark3->paint();
    Cell* cellMark4 = new Cell(15,10,COLOR_YELLOW, '4');
    cellMark4->paint();
    Tetrimino* tetrimino = nullptr;
    vector<unsigned int> initialX = {20,20,20,20};
    vector<unsigned int> initialY = {10,11,12,13};
    getch();
    tetrimino = new LongPiece(mainEnv, COLOR_MAGENTA, initialX, initialY);
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
    Cell* cellMark1 = new Cell(15,7,COLOR_YELLOW, '1');
    cellMark1->paint();
    Cell* cellMark2 = new Cell(15,8,COLOR_YELLOW, '2');
    cellMark2->paint();
    Cell* cellMark3 = new Cell(15,9,COLOR_YELLOW, '3');
    cellMark3->paint();
    Cell* cellMark4 = new Cell(15,10,COLOR_YELLOW, '4');
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
    Cell* cellMark1 = new Cell(15,7,COLOR_YELLOW, '1');
    cellMark1->paint();
    Cell* cellMark2 = new Cell(15,8,COLOR_YELLOW, '2');
    cellMark2->paint();
    Cell* cellMark3 = new Cell(15,9,COLOR_YELLOW, '3');
    cellMark3->paint();
    Cell* cellMark4 = new Cell(15,10,COLOR_YELLOW, '4');
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
    Cell* cellMark1 = new Cell(15,7,COLOR_YELLOW, '1');
    cellMark1->paint();
    Cell* cellMark2 = new Cell(15,8,COLOR_YELLOW, '2');
    cellMark2->paint();
    Cell* cellMark3 = new Cell(15,9,COLOR_YELLOW, '3');
    cellMark3->paint();
    Cell* cellMark4 = new Cell(15,10,COLOR_YELLOW, '4');
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
    Cell* cellMark1 = new Cell(15,7,COLOR_YELLOW, '1');
    cellMark1->paint();
    Cell* cellMark2 = new Cell(15,8,COLOR_YELLOW, '2');
    cellMark2->paint();
    Cell* cellMark3 = new Cell(15,9,COLOR_YELLOW, '3');
    cellMark3->paint();
    Cell* cellMark4 = new Cell(15,10,COLOR_YELLOW, '4');
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
    Cell* cellMark1 = new Cell(15,7,COLOR_YELLOW, '1');
    cellMark1->paint();
    Cell* cellMark2 = new Cell(15,8,COLOR_YELLOW, '2');
    cellMark2->paint();
    Cell* cellMark3 = new Cell(15,9,COLOR_YELLOW, '3');
    cellMark3->paint();
    Cell* cellMark4 = new Cell(15,10,COLOR_YELLOW, '4');
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
    Cell* cellMark1 = new Cell(15,7,COLOR_YELLOW, '1');
    cellMark1->paint();
    Cell* cellMark2 = new Cell(15,8,COLOR_YELLOW, '2');
    cellMark2->paint();
    Cell* cellMark3 = new Cell(15,9,COLOR_YELLOW, '3');
    cellMark3->paint();
    Cell* cellMark4 = new Cell(15,10,COLOR_YELLOW, '4');
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
    Cell* cellMark1 = new Cell(15,7,COLOR_YELLOW, '1');
    cellMark1->paint();
    Cell* cellMark2 = new Cell(15,8,COLOR_YELLOW, '2');
    cellMark2->paint();
    Cell* cellMark3 = new Cell(15,9,COLOR_YELLOW, '3');
    cellMark3->paint();
    Cell* cellMark4 = new Cell(15,10,COLOR_YELLOW, '4');
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
    Cell* cellMark1 = new Cell(15,7,COLOR_YELLOW, '1');
    cellMark1->paint();
    Cell* cellMark2 = new Cell(15,8,COLOR_YELLOW, '2');
    cellMark2->paint();
    Cell* cellMark3 = new Cell(15,9,COLOR_YELLOW, '3');
    cellMark3->paint();
    Cell* cellMark4 = new Cell(15,10,COLOR_YELLOW, '4');
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
    Cell* cellMark1 = new Cell(15,7,COLOR_YELLOW, '1');
    cellMark1->paint();
    Cell* cellMark2 = new Cell(15,8,COLOR_YELLOW, '2');
    cellMark2->paint();
    Cell* cellMark3 = new Cell(15,9,COLOR_YELLOW, '3');
    cellMark3->paint();
    Cell* cellMark4 = new Cell(15,10,COLOR_YELLOW, '4');
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
    Cell* cellMark1 = new Cell(15,7,COLOR_YELLOW, '1');
    cellMark1->paint();
    Cell* cellMark2 = new Cell(15,8,COLOR_YELLOW, '2');
    cellMark2->paint();
    Cell* cellMark3 = new Cell(15,9,COLOR_YELLOW, '3');
    cellMark3->paint();
    Cell* cellMark4 = new Cell(15,10,COLOR_YELLOW, '4');
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
    Cell* cellMark1 = new Cell(15,7,COLOR_YELLOW, '1');
    cellMark1->paint();
    Cell* cellMark2 = new Cell(15,8,COLOR_YELLOW, '2');
    cellMark2->paint();
    Cell* cellMark3 = new Cell(15,9,COLOR_YELLOW, '3');
    cellMark3->paint();
    Cell* cellMark4 = new Cell(15,10,COLOR_YELLOW, '4');
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
    Cell* cellMark1 = new Cell(15,7,COLOR_YELLOW, '1');
    cellMark1->paint();
    Cell* cellMark2 = new Cell(15,8,COLOR_YELLOW, '2');
    cellMark2->paint();
    Cell* cellMark3 = new Cell(15,9,COLOR_YELLOW, '3');
    cellMark3->paint();
    Cell* cellMark4 = new Cell(15,10,COLOR_YELLOW, '4');
    cellMark4->paint();
    Tetrimino* tetrimino = nullptr;
    vector<unsigned int> initialX = {19,20,20,21};
    vector<unsigned int> initialY = {10,9,10,10};
    getch();
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
    
    KeyboardListener* KeyboardListener = KeyboardListener::getInstance();

    ScreenWriterController swc;
    ScreenWriter sw;
    swc.setControllable(&sw);

    AppController ac;
    AppLogic al;
    ac.setControllable(&al);

    TetriminoController tc;
    tc.setControllable(tetrimino);

    KeyboardListener::getInstance()->registerController(&swc);
    KeyboardListener::getInstance()->registerController(&ac);
    KeyboardListener::getInstance()->registerController(&tc);
    KeyboardListener::getInstance()->startListening();

    bool stopCycleThread = false;
    mutex tetriminoMutex;
    thread cycleThread {cycleTetrimino, tetrimino, &tetriminoMutex, &stopCycleThread};

    stopCycleThread = true;
    cycleThread.join();

    getch();

    delete tetrimino;
    
    endwin();

    return 0;
}



bool cycleTetrimino(Tetrimino* tetrimino, mutex* mux, bool* stopSignal){
    int movesLeft = 4;
    int movesRight = 4;
    int movesUp = 4;
    int movesDown = 4;
    //writeToLine(stdscr, 24, "This thread works");
    while(!(*stopSignal)){
        this_thread::sleep_for(chrono::milliseconds(750));
        unique_lock<mutex> lck {*mux};
        if(movesDown != 0){
            tetrimino->moveDown();
            movesDown--;
        }
        else if(movesLeft != 0){
            tetrimino->moveLeft();
            movesLeft--;
        }
        else if(movesUp != 0){
            tetrimino->moveUp();
            movesUp--;
        }
        else if(movesRight != 0){
            tetrimino->moveRight();
            movesRight--;
        }
        else{
            movesDown = 4;
            movesLeft = 4;
            movesUp = 4;
            movesRight = 4;
            tetrimino->moveDown();
            movesDown--;
        }
    }
}
bool controllerListener(UserController* userController, Tetrimino* tetrimino, mutex* mux, bool* stopSignal){
    char c;
    UserController* user;
    while(!(*stopSignal)){
        c = getch();
        unique_lock<mutex> lck {*mux};

        // userController->processInput(c);
    }
}
void writeToLine(WINDOW* win, int line, string data){
	wmove(win, line, 0);
	wclrtoeol(win);
	wrefresh(win);
	waddstr(win, data.c_str());
	wrefresh(win);
}