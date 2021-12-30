#include <iostream>
#include <ncurses.h>
#include <string>

#include "../classes/Cell.hpp"
#include "../classes/Environment.hpp"
#include "../classes/Tetrimino.hpp"
#include "../classes/LongPiece.hpp"

using namespace std;

void writeToLine(WINDOW* win, int line, string data);
int runApp();
int testCell();
int testEnvironment();
int testTetriminoSubClasses();
int testLeftRotationLongPiece();
int testRightRotationLongPiece();
void createCellsInPlainFunctionStack();
void createVectorOfCells();
int main(int argc, char* argv[]){

    //return testCell();
    //return testTetriminoSubClasses();
    //return testLeftRotationLongPiece();
    return testRightRotationLongPiece();
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
void writeToLine(WINDOW* win, int line, string data){
	wmove(win, line, 0);
	wclrtoeol(win);
	wrefresh(win);
	waddstr(win, data.c_str());
	wrefresh(win);
}