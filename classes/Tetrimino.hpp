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
    Tetrimino(const Tetrimino& rhs) = delete;
    ~Tetrimino() = default;
    void show();
    bool  moveLeft();
    bool  moveRight();
    bool  moveDown();
    bool  moveUp();
    bool virtual rotateLeft() = 0;
    bool virtual rotateRight() = 0;
    bool isActive();
    void setActive(bool active);
    //This should get called in destructor, possibly?
    void passCellsToEnvironment();
protected:
    Environment* environment;
    bool active;
    unsigned int orientation;
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
    // If the orientation is not provided by the factory,
    // then each piece needs to be in its appropriate orientation
    // from the factory
    this->orientation = 0;
    this->cells = { Cell(Xs[0], Ys[0], color, 'A'),
                    Cell(Xs[1], Ys[1], color, 'B'),
                    Cell(Xs[2], Ys[2], color, 'C'),
                    Cell(Xs[3], Ys[3], color, 'D')};

}

void Tetrimino::show(){
    for(unsigned int i = 0; i < cells.size(); i++){
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
        //All erasing, moving, and painting must be done in batches
        for(unsigned int i = 0; i < newXs.size(); i++){
            cells[i].erase();
        }
        for(unsigned int i = 0; i < newXs.size(); i++){
            cells[i].move(newXs[i], newYs[i]);
        }
        for(unsigned int i = 0; i < newXs.size(); i++){
            cells[i].paint();
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
void Tetrimino::passCellsToEnvironment(){
    for(unsigned int i = 0; i < cells.size(); i++){
        environment->addCell(make_unique<Cell>(cells[i]));
    }
}
#endif