#ifndef __TPIECE_HPP__
#define __TPIECE_HPP__

#include <ncurses.h>
#include <string>
#include <vector>
#include <memory>

#include "Cell.hpp"
#include "Environment.hpp"
#include "Tetrimino.hpp"

class TPiece : public Tetrimino{
public:
    TPiece(Environment* env, int color, std::vector<unsigned int>& Xs, std::vector<unsigned int>& Ys)
    : Tetrimino(env, color, Xs, Ys) {}
    bool rotateLeft() override;
    bool rotateRight() override;
private:
    void doRotateLeft(int incX, int incY, unsigned int newOrientation);
    bool rotateLeftOrientationZero();
    bool rotateLeftOrientationOne();
    bool rotateLeftOrientationTwo();
    bool rotateLeftOrientationThree();
    void doRotateRight(int incX, int incY, unsigned int newOrientation);
    bool rotateRightOrientationZero();
    bool rotateRightOrientationOne();
    bool rotateRightOrientationTwo();
    bool rotateRightOrientationThree();

};

bool TPiece::rotateLeft(){
    switch(this->orientation){
        case 0: return rotateLeftOrientationZero();
        case 1: return rotateLeftOrientationOne();
        case 2: return rotateLeftOrientationTwo();
        case 3: return rotateLeftOrientationThree();
        default: return false;// This should never occur
    }
}
bool TPiece::rotateLeftOrientationZero(){
    int cX = cells[2].getx();
    int cY = cells[2].gety();

    int eX = cX - 2;
    int eY = cY;

    int fX = cX + 2;
    int fY = cY;

    int gX = cX - 2;
    int gY = cY - 1;

    int hX = cX - 1;
    int hY = cY - 1;

    int iX = cX + 1;
    int iY = cY - 1;

    int jX = cX + 2;
    int jY = cY - 1;

    int kX = cX - 1;
    int kY = cY - 2;

    int lX = cX;
    int lY = cY - 2;

    int mX = cX + 1;
    int mY = cY - 2;

    int nX = cX - 1;
    int nY = cY + 1;

    int oX = cX;
    int oY = cY + 1;

    int pX = cX + 1;
    int pY = cY + 1;

    int qX = cX - 1;
    int qY = cY + 2;

    int rX = cX;
    int rY = cY + 2;

    int sX = cX + 1;
    int sY = cY + 2;

    bool willRotateHappen = false;
    int incX = 0;
    int incY = 0;

}
bool TPiece::rotateLeftOrientationOne(){

}
bool TPiece::rotateLeftOrientationTwo(){

}
bool TPiece::rotateLeftOrientationThree(){

}
void TPiece::doRotateLeft(int incX, int incY, unsigned int newOrientation){
    
}
bool TPiece::rotateRight(){
    switch(this->orientation){
        case 0: return rotateRightOrientationZero();
        case 1: return rotateRightOrientationOne();
        case 2: return rotateRightOrientationTwo();
        case 3: return rotateRightOrientationThree();
        default: return false;// This should never occur
    }
}
bool TPiece::rotateRightOrientationZero(){

}
bool TPiece::rotateRightOrientationOne(){

}
bool TPiece::rotateRightOrientationTwo(){

}
bool TPiece::rotateRightOrientationThree(){

}
void TPiece::doRotateRight(int incX, int incY, unsigned int newOrientation){

}
#endif