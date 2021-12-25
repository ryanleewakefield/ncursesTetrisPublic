#ifndef __TETRIMINO_HPP__
#define __TETRIMINO_HPP__

#include <ncurses.h>
#include <string>
#include <vector>
#include <memory>

#include "Cell.hpp"
#include "Environment.hpp"

//Refactor bare pointers to smart pointers later
class Tetrimino{
public:
    Tetrimino(Environment* env, int color, std::vector<unsigned int>& Xs, std::vector<unsigned int>& Ys);
    Tetrimino(const Tetrimino& rhs);
    ~Tetrimino();
    void show();
    bool  moveLeft();
    bool  moveRight();
    bool  moveDown();
    bool  moveUp();
    bool virtual rotateLeft() = 0;
    bool virtual rotateRight() = 0;
    bool isActive();
    void setActive(bool active);
private:
    Environment* environment;
    bool active;
    std::vector<Cell> cells;
    bool doMove(int incX, int incY);
    
};

    /*  
    The object that is responsible for generating Tetriminos knows where they will be placed.
    So this constructor can assume they are correct for any subtype.
    */
Tetrimino::Tetrimino(Environment* env, int color, std::vector<unsigned int>& Xs, std::vector<unsigned int>& Ys){
    this->environment = env;
    this->active = false;
    this->cells = { Cell(Xs[0], Ys[0], color),
                    Cell(Xs[1], Ys[1], color),
                    Cell(Xs[2], Ys[2], color),
                    Cell(Xs[3], Ys[0], color)};
}

void Tetrimino::show(){
    for(unsigned i = 0; i < cells.size(); i++){
        cells[i].paint();
    }
}
bool Tetrimino::doMove(int incX, int incY){
    std::vector<unsigned int> newXs = { cells[0].getx() + incX,
                                        cells[1].getx() + incX, 
                                        cells[2].getx() + incX,
                                        cells[3].getx() + incX};

    std::vector<unsigned int> newYs = {cells[0].gety() + incY,
                                    cells[1].gety() + incY,
                                    cells[2].gety() + incY,
                                    cells[3].gety() + incY};
    
    bool okayToMove = environment->legalMove(newXs, newYs);
    if(okayToMove){
        for(unsigned int i = 0; i < newXs.size(); i++){
            cells[i].move(newXs[i], newYs[i]);
        }
    }
    return okayToMove;
}
bool Tetrimino::moveLeft(){
    return doMove(-1, 0);
}
bool Tetrimino::moveRight(){
    return doMove(1, 0);
}
bool Tetrimino::moveDown(){
    return doMove(0, 1);
}
bool Tetrimino::moveUp(){
    return doMove(0, -1);
}
bool Tetrimino::isActive(){
    return this->active;
}

void Tetrimino::setActive(bool active){
    this->active = active;
}

class LongPiece : Tetrimino{

};

class RightL : Tetrimino{

};

class LeftL : Tetrimino{

};

class RightS : Tetrimino{

};

class LeftS : Tetrimino{

};

class Square : Tetrimino{

};

#endif