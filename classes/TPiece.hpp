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
    if(environment->isOccupied(hX, hY)){
        if(! (environment->isOccupied(iX, iY) ||
            environment->isOccupied(nX, nY) ||
            environment->isOccupied(oX, oY) ||
            environment->isOccupied(pX, pY))){
                incX = 1;
                incY = 0;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(iX, iY)){
        if(! (environment->isOccupied(nX, nY) ||
            environment->isOccupied(oX, oY) ||
            environment->isOccupied(pX, pY) ||
            environment->isOccupied(rX, rY) ||
            environment->isOccupied(sX, sY))){
                incX = 1;
                incY = 1;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(nX, nY)){
        if(! (environment->isOccupied(gX, gY) ||
            environment->isOccupied(kX, kY) ||
            environment->isOccupied(lX, lY))){
                incX = -1;
                incY = -1;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(oX, oY)){
        if(! environment->isOccupied(eX, eY)){
            incX = -1;
            incY = 0;
            willRotateHappen = true;
        }
        else{
            //do nothing
        }
    }
    else{
        incX = 0;
        incY = 0;
        willRotateHappen = true;
    }
    if(willRotateHappen){
        unsigned newOrientation = (this->orientation - 1) % 4;
        if(newOrientation < 0){
            newOrientation = newOrientation + 4;
        }
        this->orientation = newOrientation;
        doRotateLeft(incX, incY, newOrientation);
    }
    return willRotateHappen;

}
bool TPiece::rotateLeftOrientationOne(){
    int cX = cells[2].getx();
    int cY = cells[2].gety();

    int eX = cX;
    int eY = cY - 2;
    
    int fX = cX;
    int fY = cY + 2;
    
    int gX = cX + 1;
    int gY = cY - 2;
    
    int hX = cX + 1;
    int hY = cY - 1;
    
    int iX = cX + 1;
    int iY = cY + 1;
    
    int jX = cX + 1;
    int jY = cY + 2;
    
    int kX = cX + 2;
    int kY = cY - 1;
    
    int lX = cX + 2;
    int lY = cY;
    
    int mX = cX + 2;
    int mY = cY + 1;
    
    int nX = cX - 1;
    int nY = cY - 1;
    
    int oX = cX - 1;
    int oY = cY;
    
    int pX = cX - 1;
    int pY = cY + 1;
    
    int qX = cX - 2;
    int qY = cY - 1;
    
    int rX = cX - 2;
    int rY = cY;
    
    int sX = cX - 2;
    int sY = cY + 1;
    

    bool willRotateHappen = false;
    int incX = 0;
    int incY = 0;
    if(environment->isOccupied(hX, hY)){
        if(! (environment->isOccupied(iX, iY) ||
            environment->isOccupied(nX, nY) ||
            environment->isOccupied(oX, oY) ||
            environment->isOccupied(pX, pY))){
                incX = 1;
                incY = 0;

                incX = 0;
                incY = 1;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(iX, iY)){
        if(! (environment->isOccupied(nX, nY) ||
            environment->isOccupied(oX, oY) ||
            environment->isOccupied(pX, pY) ||
            environment->isOccupied(rX, rY) ||
            environment->isOccupied(sX, sY))){
                incX = 1;
                incY = 1;

                incX = -1;
                incY = 1;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(nX, nY)){
        if(! (environment->isOccupied(gX, gY) ||
            environment->isOccupied(kX, kY) ||
            environment->isOccupied(lX, lY))){
                incX = -1;
                incY = -1;

                incX = 1;
                incY = -1;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(oX, oY)){
        if(! environment->isOccupied(eX, eY)){
            incX = -1;
            incY = 0;

            incX = 0;
            incY = -1;
            willRotateHappen = true;
        }
        else{
            //do nothing
        }
    }
    else{
        incX = 0;
        incY = 0;
        willRotateHappen = true;
    }
    if(willRotateHappen){
        unsigned newOrientation = (this->orientation - 1) % 4;
        if(newOrientation < 0){
            newOrientation = newOrientation + 4;
        }
        this->orientation = newOrientation;
        doRotateLeft(incX, incY, newOrientation);
    }
    return willRotateHappen;
}
bool TPiece::rotateLeftOrientationTwo(){
    int cX = cells[2].getx();
    int cY = cells[2].gety();

    int eX = cX + 2;
    int eY = cY;

    int fX = cX - 2;
    int fY = cY;

    int gX = cX + 2;
    int gY = cY + 1;

    int hX = cX + 1;
    int hY = cY + 1;

    int iX = cX - 1;
    int iY = cY + 1;

    int jX = cX - 2;
    int jY = cY + 1;

    int kX = cX + 1;
    int kY = cY + 2;

    int lX = cX;
    int lY = cY + 2;

    int mX = cX - 1;
    int mY = cY + 2;

    int nX = cX + 1;
    int nY = cY - 1;

    int oX = cX;
    int oY = cY - 1;

    int pX = cX - 1;
    int pY = cY - 1;

    int qX = cX + 1;
    int qY = cY - 2;

    int rX = cX;
    int rY = cY - 2;

    int sX = cX - 1;
    int sY = cY - 2;

    bool willRotateHappen = false;
    int incX = 0;
    int incY = 0;
    if(environment->isOccupied(hX, hY)){
        if(! (environment->isOccupied(iX, iY) ||
            environment->isOccupied(nX, nY) ||
            environment->isOccupied(oX, oY) ||
            environment->isOccupied(pX, pY))){
                incX = 1;
                incY = 0;

                incX = -1;
                incY = 0;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(iX, iY)){
        if(! (environment->isOccupied(nX, nY) ||
            environment->isOccupied(oX, oY) ||
            environment->isOccupied(pX, pY) ||
            environment->isOccupied(rX, rY) ||
            environment->isOccupied(sX, sY))){
                incX = 1;
                incY = 1;

                incX = -1;
                incY = -1;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(nX, nY)){
        if(! (environment->isOccupied(gX, gY) ||
            environment->isOccupied(kX, kY) ||
            environment->isOccupied(lX, lY))){
                incX = -1;
                incY = -1;

                incX = 1;
                incY = 1;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(oX, oY)){
        if(! environment->isOccupied(eX, eY)){
            incX = -1;
            incY = 0;

            incX = 1;
            incY = 0;
            willRotateHappen = true;
        }
        else{
            //do nothing
        }
    }
    else{
        incX = 0;
        incY = 0;
        willRotateHappen = true;
    }
    if(willRotateHappen){
        unsigned newOrientation = (this->orientation - 1) % 4;
        if(newOrientation < 0){
            newOrientation = newOrientation + 4;
        }
        this->orientation = newOrientation;
        doRotateLeft(incX, incY, newOrientation);
    }
    return willRotateHappen;
}
bool TPiece::rotateLeftOrientationThree(){
    int cX = cells[2].getx();
    int cY = cells[2].gety();

    int eX = cX;
    int eY = cY + 2;
    
    int fX = cX;
    int fY = cY - 2;
    
    int gX = cX - 1;
    int gY = cY + 2;
    
    int hX = cX - 1;
    int hY = cY + 1;
    
    int iX = cX - 1;
    int iY = cY - 1;
    
    int jX = cX - 1;
    int jY = cY - 2;
    
    int kX = cX - 2;
    int kY = cY + 1;
    
    int lX = cX - 2;
    int lY = cY;
    
    int mX = cX - 2;
    int mY = cY - 1;
    
    int nX = cX + 1;
    int nY = cY + 1;
    
    int oX = cX + 1;
    int oY = cY;
    
    int pX = cX + 1;
    int pY = cY - 1;
    
    int qX = cX + 2;
    int qY = cY + 1;
    
    int rX = cX + 2;
    int rY = cY;
    
    int sX = cX + 2;
    int sY = cY - 1;

    bool willRotateHappen = false;
    int incX = 0;
    int incY = 0;
    if(environment->isOccupied(hX, hY)){
        if(! (environment->isOccupied(iX, iY) ||
            environment->isOccupied(nX, nY) ||
            environment->isOccupied(oX, oY) ||
            environment->isOccupied(pX, pY))){
                incX = 1;
                incY = 0;

                incX = 0;
                incY = -1;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(iX, iY)){
        if(! (environment->isOccupied(nX, nY) ||
            environment->isOccupied(oX, oY) ||
            environment->isOccupied(pX, pY) ||
            environment->isOccupied(rX, rY) ||
            environment->isOccupied(sX, sY))){
                incX = 1;
                incY = 1;

                incX = 1;
                incY = -1;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(nX, nY)){
        if(! (environment->isOccupied(gX, gY) ||
            environment->isOccupied(kX, kY) ||
            environment->isOccupied(lX, lY))){
                incX = -1;
                incY = -1;

                incX = -1;
                incY = 1;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(oX, oY)){
        if(! environment->isOccupied(eX, eY)){
            incX = -1;
            incY = 0;

            incX = 0;
            incY = 1;
            willRotateHappen = true;
        }
        else{
            //do nothing
        }
    }
    else{
        incX = 0;
        incY = 0;
        willRotateHappen = true;
    }
    if(willRotateHappen){
        unsigned newOrientation = (this->orientation - 1) % 4;
        if(newOrientation < 0){
            newOrientation = newOrientation + 4;
        }
        this->orientation = newOrientation;
        doRotateLeft(incX, incY, newOrientation);
    }
    return willRotateHappen;
}
void TPiece::doRotateLeft(int incX, int incY, unsigned int newOrientation){
    unsigned int new_cX = cells[2].getx() + incX;
    unsigned int new_cY = cells[2].gety() + incY;
    for(unsigned int i = 0; i < cells.size(); i++){
        cells[i].erase();
    }
    if(newOrientation == 0){    
        cells[0].move(new_cX - 1, new_cY);
        cells[1].move(new_cX, new_cY - 1);
        cells[2].move(new_cX, new_cY);
        cells[3].move(new_cX + 1, new_cY);   
    }
    else if(newOrientation == 1){
        cells[0].move(new_cX, new_cY - 1);
        cells[1].move(new_cX + 1, new_cY);
        cells[2].move(new_cX, new_cY);
        cells[3].move(new_cX, new_cY + 1);   
    }
    else if(newOrientation == 2){
        cells[0].move(new_cX + 1, new_cY);
        cells[1].move(new_cX, new_cY + 1);
        cells[2].move(new_cX, new_cY);
        cells[3].move(new_cX - 1, new_cY);   
    }
    else if(newOrientation == 3){
        cells[0].move(new_cX, new_cY + 1);
        cells[1].move(new_cX - 1, new_cY);
        cells[2].move(new_cX, new_cY);
        cells[3].move(new_cX, new_cY - 1);   
     }
    for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].paint();
        }
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
    if(environment->isOccupied(iX, iY)){
        if(! (environment->isOccupied(hX, hY) ||
            environment->isOccupied(nX, nY) ||
            environment->isOccupied(oX, oY) ||
            environment->isOccupied(pX, pY))){
                incX = -1;
                incY = 0;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(hX, hY)){
        if(! (environment->isOccupied(nX, nY) ||
            environment->isOccupied(oX, oY) ||
            environment->isOccupied(pX, pY) ||
            environment->isOccupied(qX, qY) ||
            environment->isOccupied(sX, sY))){
                incX = -1;
                incY = 1;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(pX, pY)){
        if(! (environment->isOccupied(jX, jY) ||
            environment->isOccupied(mX, mY) ||
            environment->isOccupied(lX, lY))){
                incX = 1;
                incY = -1;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(oX, oY)){
        if(! environment->isOccupied(fX, fY)){
            incX = 1;
            incY = 0;
            willRotateHappen = true;
        }
        else{
            //do nothing
        }
    }
    else{
        incX = 0;
        incY = 0;
        willRotateHappen = true;
    }
    if(willRotateHappen){
        unsigned newOrientation = (this->orientation + 1) % 4;
        if(newOrientation < 0){
            newOrientation = newOrientation + 4;
        }
        this->orientation = newOrientation;
        doRotateLeft(incX, incY, newOrientation);
    }
    return willRotateHappen;
}
bool TPiece::rotateRightOrientationOne(){
    int cX = cells[2].getx();
    int cY = cells[2].gety();

    int eX = cX;
    int eY = cY - 2;
    
    int fX = cX;
    int fY = cY + 2;
    
    int gX = cX + 1;
    int gY = cY - 2;
    
    int hX = cX + 1;
    int hY = cY - 1;
    
    int iX = cX + 1;
    int iY = cY + 1;
    
    int jX = cX + 1;
    int jY = cY + 2;
    
    int kX = cX + 2;
    int kY = cY - 1;
    
    int lX = cX + 2;
    int lY = cY;
    
    int mX = cX + 2;
    int mY = cY + 1;
    
    int nX = cX - 1;
    int nY = cY - 1;
    
    int oX = cX - 1;
    int oY = cY;
    
    int pX = cX - 1;
    int pY = cY + 1;
    
    int qX = cX - 2;
    int qY = cY - 1;
    
    int rX = cX - 2;
    int rY = cY;
    
    int sX = cX - 2;
    int sY = cY + 1;

    bool willRotateHappen = false;
    int incX = 0;
    int incY = 0;
    if(environment->isOccupied(iX, iY)){
        if(! (environment->isOccupied(hX, hY) ||
            environment->isOccupied(nX, nY) ||
            environment->isOccupied(oX, oY) ||
            environment->isOccupied(pX, pY))){
                incX = -1;
                incY = 0;

                incX = 0;
                incY = -1;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(hX, hY)){
        if(! (environment->isOccupied(nX, nY) ||
            environment->isOccupied(oX, oY) ||
            environment->isOccupied(pX, pY) ||
            environment->isOccupied(qX, qY) ||
            environment->isOccupied(sX, sY))){
                incX = -1;
                incY = 1;

                incX = -1;
                incY = -1;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(pX, pY)){
        if(! (environment->isOccupied(jX, jY) ||
            environment->isOccupied(mX, mY) ||
            environment->isOccupied(lX, lY))){
                incX = 1;
                incY = -1;

                incX = 1;
                incY = 1;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(oX, oY)){
        if(! environment->isOccupied(fX, fY)){
            incX = 1;
            incY = 0;

            incX = 0;
            incY = 1;
            willRotateHappen = true;
        }
        else{
            //do nothing
        }
    }
    else{
        incX = 0;
        incY = 0;
        willRotateHappen = true;
    }
    if(willRotateHappen){
        unsigned newOrientation = (this->orientation + 1) % 4;
        if(newOrientation < 0){
            newOrientation = newOrientation + 4;
        }
        this->orientation = newOrientation;
        doRotateLeft(incX, incY, newOrientation);
    }
    return willRotateHappen;
}
bool TPiece::rotateRightOrientationTwo(){
    int cX = cells[2].getx();
    int cY = cells[2].gety();

    int eX = cX + 2;
    int eY = cY;

    int fX = cX - 2;
    int fY = cY;

    int gX = cX + 2;
    int gY = cY + 1;

    int hX = cX + 1;
    int hY = cY + 1;

    int iX = cX - 1;
    int iY = cY + 1;

    int jX = cX - 2;
    int jY = cY + 1;

    int kX = cX + 1;
    int kY = cY + 2;

    int lX = cX;
    int lY = cY + 2;

    int mX = cX - 1;
    int mY = cY + 2;

    int nX = cX + 1;
    int nY = cY - 1;

    int oX = cX;
    int oY = cY - 1;

    int pX = cX - 1;
    int pY = cY - 1;

    int qX = cX + 1;
    int qY = cY - 2;

    int rX = cX;
    int rY = cY - 2;

    int sX = cX - 1;
    int sY = cY - 2;

    bool willRotateHappen = false;
    int incX = 0;
    int incY = 0;
    if(environment->isOccupied(iX, iY)){
        if(! (environment->isOccupied(hX, hY) ||
            environment->isOccupied(nX, nY) ||
            environment->isOccupied(oX, oY) ||
            environment->isOccupied(pX, pY))){
                incX = -1;
                incY = 0;

                incX = 1;
                incY = 0;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(hX, hY)){
        if(! (environment->isOccupied(nX, nY) ||
            environment->isOccupied(oX, oY) ||
            environment->isOccupied(pX, pY) ||
            environment->isOccupied(qX, qY) ||
            environment->isOccupied(sX, sY))){
                incX = -1;
                incY = 1;

                incX = 1;
                incY = -1;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(pX, pY)){
        if(! (environment->isOccupied(jX, jY) ||
            environment->isOccupied(mX, mY) ||
            environment->isOccupied(lX, lY))){
                incX = 1;
                incY = -1;

                incX = -1;
                incY = 1;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(oX, oY)){
        if(! environment->isOccupied(fX, fY)){
            incX = 1;
            incY = 0;

            incX = -1;
            incY = 0;
            willRotateHappen = true;
        }
        else{
            //do nothing
        }
    }
    else{
        incX = 0;
        incY = 0;
        willRotateHappen = true;
    }
    if(willRotateHappen){
        unsigned newOrientation = (this->orientation + 1) % 4;
        if(newOrientation < 0){
            newOrientation = newOrientation + 4;
        }
        this->orientation = newOrientation;
        doRotateLeft(incX, incY, newOrientation);
    }
    return willRotateHappen;
}
bool TPiece::rotateRightOrientationThree(){
    int cX = cells[2].getx();
    int cY = cells[2].gety();

    int eX = cX;
    int eY = cY + 2;
    
    int fX = cX;
    int fY = cY - 2;
    
    int gX = cX - 1;
    int gY = cY + 2;
    
    int hX = cX - 1;
    int hY = cY + 1;
    
    int iX = cX - 1;
    int iY = cY - 1;
    
    int jX = cX - 1;
    int jY = cY - 2;
    
    int kX = cX - 2;
    int kY = cY + 1;
    
    int lX = cX - 2;
    int lY = cY;
    
    int mX = cX - 2;
    int mY = cY - 1;
    
    int nX = cX + 1;
    int nY = cY + 1;
    
    int oX = cX + 1;
    int oY = cY;
    
    int pX = cX + 1;
    int pY = cY - 1;
    
    int qX = cX + 2;
    int qY = cY + 1;
    
    int rX = cX + 2;
    int rY = cY;
    
    int sX = cX + 2;
    int sY = cY - 1;

    bool willRotateHappen = false;
    int incX = 0;
    int incY = 0;
    if(environment->isOccupied(iX, iY)){
        if(! (environment->isOccupied(hX, hY) ||
            environment->isOccupied(nX, nY) ||
            environment->isOccupied(oX, oY) ||
            environment->isOccupied(pX, pY))){
                incX = -1;
                incY = 0;

                incX = 0;
                incY = 1;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(hX, hY)){
        if(! (environment->isOccupied(nX, nY) ||
            environment->isOccupied(oX, oY) ||
            environment->isOccupied(pX, pY) ||
            environment->isOccupied(qX, qY) ||
            environment->isOccupied(sX, sY))){
                incX = -1;
                incY = 1;

                incX = 1;
                incY = 1;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(pX, pY)){
        if(! (environment->isOccupied(jX, jY) ||
            environment->isOccupied(mX, mY) ||
            environment->isOccupied(lX, lY))){
                incX = 1;
                incY = -1;

                incX = -1;
                incY = -1;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(oX, oY)){
        if(! environment->isOccupied(fX, fY)){
            incX = 1;
            incY = 0;

            incX = 0;
            incY = -1;
            willRotateHappen = true;
        }
        else{
            //do nothing
        }
    }
    else{
        incX = 0;
        incY = 0;
        willRotateHappen = true;
    }
    if(willRotateHappen){
        unsigned newOrientation = (this->orientation + 1) % 4;
        if(newOrientation < 0){
            newOrientation = newOrientation + 4;
        }
        this->orientation = newOrientation;
        doRotateLeft(incX, incY, newOrientation);
    }
    return willRotateHappen;
}
void TPiece::doRotateRight(int incX, int incY, unsigned int newOrientation){
    unsigned int new_cX = cells[2].getx() + incX;
    unsigned int new_cY = cells[2].gety() + incY;
    for(unsigned int i = 0; i < cells.size(); i++){
        cells[i].erase();
    }
    if(newOrientation == 0){    
        cells[0].move(new_cX - 1, new_cY);
        cells[1].move(new_cX, new_cY - 1);
        cells[2].move(new_cX, new_cY);
        cells[3].move(new_cX + 1, new_cY);   
    }
    else if(newOrientation == 1){
        cells[0].move(new_cX, new_cY - 1);
        cells[1].move(new_cX + 1, new_cY);
        cells[2].move(new_cX, new_cY);
        cells[3].move(new_cX, new_cY + 1);   
    }
    else if(newOrientation == 2){
        cells[0].move(new_cX + 1, new_cY);
        cells[1].move(new_cX, new_cY + 1);
        cells[2].move(new_cX, new_cY);
        cells[3].move(new_cX - 1, new_cY);   
    }
    else if(newOrientation == 3){
        cells[0].move(new_cX, new_cY + 1);
        cells[1].move(new_cX - 1, new_cY);
        cells[2].move(new_cX, new_cY);
        cells[3].move(new_cX, new_cY - 1);   
     }
    for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].paint();
        }
}
#endif