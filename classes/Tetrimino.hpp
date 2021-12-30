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
    this->orientation = 0;
    this->cells = { Cell(Xs[0], Ys[0], color),
                    Cell(Xs[1], Ys[1], color),
                    Cell(Xs[2], Ys[2], color),
                    Cell(Xs[3], Ys[3], color)};

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

/* LongPiece Header and Implementation*/
class LongPiece : public Tetrimino{
public:
    LongPiece(Environment* env, int color, std::vector<unsigned int>& Xs, std::vector<unsigned int>& Ys)
    : Tetrimino(env, color, Xs, Ys) {}
    bool rotateLeft() override;
    bool rotateRight() override;
private:
    bool rotateLeftOrientationZero();
    bool rotateLeftOrientationOne();
    bool rotateLeftOrientationTwo();
    bool rotateLeftOrientationThree();
    bool rotateRightOrientationZero();
    bool rotateRightOrientationOne();
    bool rotateRightOrientationTwo();
    bool rotateRightOrientationThree();
};

bool LongPiece::rotateLeft(){
    switch(this->orientation){
        case 0: return rotateLeftOrientationZero();
        case 1: return rotateLeftOrientationOne();
        case 2: return rotateLeftOrientationTwo();
        case 3: return rotateLeftOrientationThree();
        default: return false;// This should never occur
    }
}
bool LongPiece::rotateLeftOrientationZero(){
    int aX = cells[0].getx();
    int aY = cells[0].gety();
    
    //Left Side
    int eX = aX - 1;
    int eY = aY;
    int iX = aX - 2;
    int iY = aY + 1;
    int fX = aX - 1;
    int fY = aY + 1;
    int kX = aX - 3;
    int kY = aY + 2;
    int jX = aX - 2;
    int jY = aY + 2;
    int gX = aX - 1;
    int gY = aY + 2;
    int hX = aX - 1;
    int hY = aY + 3;

    //Right Side
    int lX = aX + 1;
    int lY = aY;
    int mX = aX + 1;
    int mY = aY + 1;
    int pX = aX + 2;
    int pY = aY;
    int rX = aX + 2;
    int rY = aY + 2;
    int nX = aX + 1;
    int nY = aY + 2;
    int qX = aX + 2;
    int qY = aY + 1;
    int oX = aX + 1;
    int oY = aY + 3;
    int sX = aX + 3;
    int sY = aY + 1;

    if(environment->isOccupied(eX, eY)){
        if( ! (
                environment->isOccupied(mX, mY) ||
                environment->isOccupied(nX, nY) ||
                environment->isOccupied(oX, oY) ||
                environment->isOccupied(qX, qY) ||
                environment->isOccupied(rX, rY) ||
                environment->isOccupied(sX, sY))){
                    //do a(0,1)
                }
                else{
                    //do nothing
                }
    }
    else if(environment->isOccupied(fX, fY)){
        if( ! ( environment->isOccupied(lX, lY) ||
                environment->isOccupied(mX, mY) ||
                environment->isOccupied(pX, pY) ||
                environment->isOccupied(rX, rY) ||
                environment->isOccupied(nX, nY) ||
                environment->isOccupied(qX, qY) ||
                environment->isOccupied(oX, oY))){
                    //do a(-1,0)
                }
                else{
                    //do nothing
                }
    }
    else if(environment->isOccupied(gX, gY) ||
            environment->isOccupied(hX, hY)){
        if( ! ( environment->isOccupied(mX, mY) ||
                environment->isOccupied(rX, rY) ||
                environment->isOccupied(nX, nY) ||
                environment->isOccupied(qX, qY) ||
                environment->isOccupied(oX, oY))){
                    //do a(-1,1)
                }
                else{
                    //do nothing
                }
    }
    else if(environment->isOccupied(oX, oY) ||
            environment->isOccupied(nX, nY)){
        if( ! (environment->isOccupied(iX, iY) ||
                environment->isOccupied(jX, jY) ||
                environment->isOccupied(kX, kY))){
                    //do a(-3,2)
                }
                else{
                    //do nothing
                }
    }
    else if(environment->isOccupied(mX, mY)){
        if(! environment->isOccupied(rX, rY)){
            //do a(-1,2)
        }
        else{
            //do nothing
        }
    }
    else{
        if((environment->isOccupied(qX, qY) ||
            environment->isOccupied(rX, rY))){
            if(! environment->isOccupied(iX, iY)){
                //do a(-2,1)
            }
            else{
                //do nothing
            }
        }
        else{
            //do a(-1,1)
        }
    }
    

}
bool LongPiece::rotateLeftOrientationOne(){
    

}

//This should be similar to OrientationZero
bool LongPiece::rotateLeftOrientationTwo(){
    int aX = cells[0].getx();
    int aY = cells[0].gety();
    
    //Left Side
    int eX = aX - 1;
    int eY = aY;
    int iX = aX - 2;
    int iY = aY + 1;
    int fX = aX - 1;
    int fY = aY + 1;
    int kX = aX - 3;
    int kY = aY + 2;
    int jX = aX - 2;
    int jY = aY + 2;
    int gX = aX - 1;
    int gY = aY + 2;
    int hX = aX - 1;
    int hY = aY + 3;

    //Right Side
    int lX = aX + 1;
    int lY = aY;
    int mX = aX + 1;
    int mY = aY + 1;
    int pX = aX + 2;
    int pY = aY;
    int rX = aX + 2;
    int rY = aY + 2;
    int nX = aX + 1;
    int nY = aY + 2;
    int qX = aX + 2;
    int qY = aY + 1;
    int oX = aX + 1;
    int oY = aY + 3;
    int sX = aX + 3;
    int sY = aY + 1;

    if(environment->isOccupied(eX, eY)){
        if( ! (
                environment->isOccupied(mX, mY) ||
                environment->isOccupied(nX, nY) ||
                environment->isOccupied(oX, oY) ||
                environment->isOccupied(qX, qY) ||
                environment->isOccupied(rX, rY) ||
                environment->isOccupied(sX, sY))){
                    //do a(0,1)
                }
                else{
                    //do nothing
                }
    }
    else if(environment->isOccupied(fX, fY)){
        if( ! ( environment->isOccupied(lX, lY) ||
                environment->isOccupied(mX, mY) ||
                environment->isOccupied(pX, pY) ||
                environment->isOccupied(rX, rY) ||
                environment->isOccupied(nX, nY) ||
                environment->isOccupied(qX, qY) ||
                environment->isOccupied(oX, oY))){
                    //do a(-1,0)
                }
                else{
                    //do nothing
                }
    }
    else if(environment->isOccupied(gX, gY) ||
            environment->isOccupied(hX, hY)){
        if( ! ( environment->isOccupied(mX, mY) ||
                environment->isOccupied(rX, rY) ||
                environment->isOccupied(nX, nY) ||
                environment->isOccupied(qX, qY) ||
                environment->isOccupied(oX, oY))){
                    //do a(-1,1)
                }
                else{
                    //do nothing
                }
    }
    else if(environment->isOccupied(oX, oY) ||
            environment->isOccupied(nX, nY)){
        if( ! (environment->isOccupied(iX, iY) ||
                environment->isOccupied(jX, jY) ||
                environment->isOccupied(kX, kY))){
                    //do a(-3,2)
                }
                else{
                    //do nothing
                }
    }
    else if(environment->isOccupied(mX, mY)){
        if(! environment->isOccupied(rX, rY)){
            //do a(-1,2)
        }
        else{
            //do nothing
        }
    }
    else{
        if((environment->isOccupied(qX, qY) ||
            environment->isOccupied(rX, rY))){
            if(! environment->isOccupied(iX, iY)){
                //do a(-2,1)
            }
            else{
                //do nothing
            }
        }
        else{
            //do a(-1,1)
        }
    }   
    
}
bool LongPiece::rotateLeftOrientationThree(){

}

bool LongPiece::rotateRight(){

}
class RightL : Tetrimino{

};

bool LongPiece::rotateRightOrientationOne(){
    int aX = cells[0].getx();
    int aY = cells[0].gety();
    
    //Left Side
    int eX = aX;
    int eY = aY - 1;
    
    int iX = aX + 1;
    int iY = aY - 2;
    
    int fX = aX + 1;
    int fY = aY - 1;
    
    int kX = aX + 2;
    int kY = aY - 3;
    
    int jX = aX + 2;
    int jY = aY - 2;
    
    int gX = aX + 2;
    int gY = aY - 1;
    
    int hX = aX + 3;
    int hY = aY + 1;

    //Right Side
    int lX = aX;
    int lY = aY + 1;
    
    int mX = aX + 1;
    int mY = aY + 1;
    
    int pX = aX;
    int pY = aY + 2;
    
    int rX = aX + 2;
    int rY = aY + 2;
    
    int nX = aX + 2;
    int nY = aY + 1;
    
    int qX = aX + 1;
    int qY = aY + 2;
    
    int oX = aX + 3;
    int oY = aY + 1;
    
    int sX = aX + 1;
    int sY = aY + 3;

    if(environment->isOccupied(eX, eY)){
        if( ! (
                environment->isOccupied(mX, mY) ||
                environment->isOccupied(nX, nY) ||
                environment->isOccupied(oX, oY) ||
                environment->isOccupied(qX, qY) ||
                environment->isOccupied(rX, rY) ||
                environment->isOccupied(sX, sY))){
                    //do a23
                }
                else{
                    //do nothing
                }
    }
    else if(environment->isOccupied(fX, fY)){
        if( ! ( environment->isOccupied(lX, lY) ||
                environment->isOccupied(mX, mY) ||
                environment->isOccupied(pX, pY) ||
                environment->isOccupied(rX, rY) ||
                environment->isOccupied(nX, nY) ||
                environment->isOccupied(qX, qY) ||
                environment->isOccupied(oX, oY))){
                    //do a12
                }
                else{
                    //do nothing
                }
    }
    else if(environment->isOccupied(gX, gY) ||
            environment->isOccupied(hX, hY)){
        if( ! ( environment->isOccupied(mX, mY) ||
                environment->isOccupied(rX, rY) ||
                environment->isOccupied(nX, nY) ||
                environment->isOccupied(qX, qY) ||
                environment->isOccupied(oX, oY))){
                    //do a22
                }
                else{
                    //do nothing
                }
    }
    else if(environment->isOccupied(oX, oY) ||
            environment->isOccupied(nX, nY)){
        if( ! (environment->isOccupied(iX, iY) ||
                environment->isOccupied(jX, jY) ||
                environment->isOccupied(kX, kY))){
                    //do a30
                }
                else{
                    //do nothing
                }
    }
    else if(environment->isOccupied(mX, mY)){
        if(! environment->isOccupied(rX, rY)){
            //do a32
        }
        else{
            //do nothing
        }
    }
    else{
        if(! (environment->isOccupied(qX, qY) ||
            environment->isOccupied(rX, rY))){
                //do a22
        }
        else{
            if(! environment->isOccupied(iX, iY)){
                //do a21
            }
            else{
                //do nothing
            }
        }
    }
}
class LeftL : Tetrimino{

};

class RightS : Tetrimino{

};

class LeftS : Tetrimino{

};

class TPiece : Tetrimino{

};

class Square : Tetrimino{

};

#endif