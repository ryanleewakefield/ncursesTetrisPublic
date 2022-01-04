#ifndef __RIGHTS_HPP__
#define __RIGHTS_HPP__

#include <ncurses.h>
#include <string>
#include <vector>
#include <memory>

#include "Cell.hpp"
#include "Environment.hpp"
#include "Tetrimino.hpp"

class RightS : public Tetrimino{
public:
    RightS(Environment* env, int color, std::vector<unsigned int>& Xs, std::vector<unsigned int>& Ys)
    : Tetrimino(env, color, Xs, Ys) {}
    bool rotateLeft() override;
    bool rotateRight() override;
private:
    void doRotateLeft(int incX, int incY, unsigned int newOrientation);
    bool rotateLeftOrientationZero();
    bool rotateLeftOrientationOne();
    void doRotateRight(int incX, int incY, unsigned int newOrientation);
    bool rotateRightOrientationZero();
    bool rotateRightOrientationOne();

};
bool RightS::rotateLeft(){
    switch(this->orientation){
        case 0: return rotateLeftOrientationZero();
        case 1: return rotateLeftOrientationOne();
        default: return false;// This should never occur
    }
}

bool RightS::rotateLeftOrientationZero(){
    int bX = cells[1].getx();
    int bY = cells[1].gety();

    int eX = bX + 1;
    int eY = bY;

    int fX = bX + 1;
    int fY = bY - 1;
    
    int gX = bX;
    int gY = bY - 1;

    int hX = bX - 1;
    int hY = bY - 1;

    int iX = bX + 1;
    int iY = bY - 2;

    int jX = bX;
    int jY = bY - 2;

    int lX = bX - 1;
    int lY = bY;

    int mX = bX + 1;
    int mY = bY + 2;

    int nX = bX;
    int nY = bY + 1;

    int oX = bX - 1;
    int oY = bY + 2;

    int rX = bX - 1;
    int rY = bY + 3;

    bool willRotateHappen = false;
    int incX = 0;
    int incY = 0;

    if(environment->isOccupied(lX, lY)){
        if( ! (environment->isOccupied(eX, eY) ||
                environment->isOccupied(fX, fY) ||
                environment->isOccupied(gX, gY) ||
                environment->isOccupied(hX, hY) ||
                environment->isOccupied(iX, iY) ||
                environment->isOccupied(jX, jY))){  
                    incX = 0;
                    incY = -1;
                    willRotateHappen = true;   
                }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(eX, eY)){
                if(! (environment->isOccupied(mX, mY) ||
                    environment->isOccupied(nX, nY) ||
                    environment->isOccupied(oX, oY) ||
                    environment->isOccupied(rX, rY))){
                        incX = 0;
                        incY = 2;
                        willRotateHappen = true;
                    }
                else{
                    //do nothing
                }
            }
    else if(environment->isOccupied(fX, fY) ||
            environment->isOccupied(gX, gY)){
                if(! environment->isOccupied(oX, oY)){
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
        unsigned newOrientation = (this->orientation - 1) % 2;
        if(newOrientation < 0){
            newOrientation = newOrientation + 2;
        }
        this->orientation = newOrientation;
        doRotateLeft(incX, incY, newOrientation);
    }
    return willRotateHappen;
}
bool RightS::rotateLeftOrientationOne(){
    int bX = cells[1].getx();
    int bY = cells[1].gety();


    int eX = bX;
    int eY = bY - 1;

    int fX = bX - 1;
    int fY = bY - 1;
    
    int gX = bX - 1;
    int gY = bY;

    int hX = bX - 1;
    int hY = bY + 1;

    int iX = bX + -2;
    int iY = bY - 1;

    int lX = bX + 1;
    int lY = bY + 1;

    int mX = bX + 2;
    int mY = bY - 1;

    int nX = bX + 1;
    int nY = bY;

    int oX = bX + 2;
    int oY = bY + 1;

    int rX = bX + 3;
    int rY = bY + 1;
    

    bool willRotateHappen = false;
    int incX = 0;
    int incY = 0;

    if(environment->isOccupied(eX, eY)){
        if( ! (environment->isOccupied(lX, lY) ||
                environment->isOccupied(nX, nY) ||
                environment->isOccupied(oX, oY) ||
                environment->isOccupied(rX, rY))){
                    incX = 2;
                    incY = -1;
                    willRotateHappen = true;
                }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(lX, lY)){
                if(! (environment->isOccupied(fX, fY) ||
                    environment->isOccupied(gX, gY) ||
                    environment->isOccupied(iX, iY))){
                        incX = -1;
                        incY = 0;
                        willRotateHappen = true;
                    }
                else{
                    //do nothing
                }
            }
    else if(environment->isOccupied(fX, fY)){
                if(! (environment->isOccupied(nX, nY)||
                    environment->isOccupied(oX,oY))){
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
        unsigned newOrientation = (this->orientation - 1) % 2;
        if(newOrientation < 0){
            newOrientation = newOrientation + 2;
        }
        this->orientation = newOrientation;
        doRotateLeft(incX, incY, newOrientation);
    }
    return willRotateHappen;
}
void RightS::doRotateLeft(int incX, int incY, unsigned int newOrientation){
    unsigned int new_bX = cells[1].getx() + incX;
    unsigned int new_bY = cells[1].gety() + incY;
    for(unsigned int i = 0; i < cells.size(); i++){
        cells[i].erase();
    }
    if(newOrientation == 0){    
        cells[0].move(new_bX - 1, new_bY);
        cells[1].move(new_bX, new_bY);
        cells[2].move(new_bX, new_bY + 1);
        cells[3].move(new_bX + 1, new_bY + 1);   
    }
    else if(newOrientation == 1){
        cells[0].move(new_bX, new_bY - 1);
        cells[1].move(new_bX, new_bY);
        cells[2].move(new_bX - 1, new_bY);
        cells[3].move(new_bX - 1, new_bY + 1);   
    }
    for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].paint();
        }
}
bool RightS::rotateRight(){
    switch(this->orientation){
        case 0: return rotateRightOrientationZero();
        case 1: return rotateRightOrientationOne();
        default: return false;// This should never occur
    }
}
bool RightS::rotateRightOrientationZero(){
    int bX = cells[1].getx();
    int bY = cells[1].gety();

    int eX = bX + 1;
    int eY = bY;

    int fX = bX + 1;
    int fY = bY - 1;
    
    int gX = bX;
    int gY = bY - 1;

    int hX = bX - 1;
    int hY = bY - 1;

    int lX = bX - 1;
    int lY = bY;

    int mX = bX + 1;
    int mY = bY + 2;

    int nX = bX;
    int nY = bY + 1;

    int oX = bX - 1;
    int oY = bY + 2;

    bool willRotateHappen = false;
    int incX = 0;
    int incY = 0;

    if(environment->isOccupied(eX, eY)){
        if( ! (environment->isOccupied(lX, lY) ||
                environment->isOccupied(mX, mY) ||
                environment->isOccupied(nX, nY))){
                    if(! (environment->isOccupied(gX, gY) ||
                        environment->isOccupied(hX, hY))){
                            incX = 0;
                            incY = 0;
                            willRotateHappen = true;
                        }
                    else if(! environment->isOccupied(oX, oY)){
                        incX = 0;
                        incY = 1;
                        willRotateHappen = true;
                    }
                    else{
                        //do nothing
                    }
                }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(lX, lY) ||
            environment->isOccupied(mX, mY) ||
            environment->isOccupied(nX, nY)){
                if(! (environment->isOccupied(fX, fY) ||
                    environment->isOccupied(gX, gY) ||
                    environment->isOccupied(hX, hY))){
                        incX = -1;
                        incY = 0;
                        willRotateHappen = true;
                    }
                else{
                    //do nothing
                }
            }
    else if(environment->isOccupied(gX, gY) ||
            environment->isOccupied(hX, hY)){
                if(! environment->isOccupied(oX, oY)){
                    incX = 0;
                    incY = 1;
                    willRotateHappen = true;
                }
                else{
                    incX = -1;
                    incY = 1;
                }
            }
    else{
        incX = 0;
        incY = 0;
        willRotateHappen = true;
    }

    if(willRotateHappen){
        unsigned newOrientation = (this->orientation + 1) % 2;
        if(newOrientation < 0){
            newOrientation = newOrientation + 2;
        }
        this->orientation = newOrientation;
        doRotateLeft(incX, incY, newOrientation);
    }
    return willRotateHappen;
}
bool RightS::rotateRightOrientationOne(){
    int bX = cells[1].getx();
    int bY = cells[1].gety();

    int eX = bX;
    int eY = bY - 1;

    int fX = bX - 1;
    int fY = bY - 1;
    
    int gX = bX - 1;
    int gY = bY;

    int hX = bX - 1;
    int hY = bY + 1;

    int lX = bX + 1;
    int lY = bY + 1;

    int mX = bX + 2;
    int mY = bY - 1;

    int nX = bX + 1;
    int nY = bY;

    bool willRotateHappen = false;
    int incX = 0;
    int incY = 0;

    if(environment->isOccupied(eX, eY)){
        if( ! (environment->isOccupied(gX, gY) ||
                environment->isOccupied(hX, hY) ||
                environment->isOccupied(lX, lY))){
                    incX = 0;
                    incY = -1;
                    willRotateHappen = true;
                }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(gX, gY) ||
            environment->isOccupied(hX, hY)){
                if(! (environment->isOccupied(mX, mY) ||
                    environment->isOccupied(nX, nY))){
                        incX = 1;
                        incY = 0;
                        willRotateHappen = true;
                    }
                else{
                    //do nothing
                }
            }
    else if(environment->isOccupied(fX, fY)){
                if(! environment->isOccupied(lX, lY)){
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
        unsigned newOrientation = (this->orientation + 1) % 2;
        if(newOrientation < 0){
            newOrientation = newOrientation + 2;
        }
        this->orientation = newOrientation;
        doRotateLeft(incX, incY, newOrientation);
    }
    return willRotateHappen;
}
void RightS::doRotateRight(int incX, int incY, unsigned int newOrientation){
    unsigned int new_bX = cells[1].getx() + incX;
    unsigned int new_bY = cells[1].gety() + incY;
    for(unsigned int i = 0; i < cells.size(); i++){
        cells[i].erase();
    }
    if(newOrientation == 0){    
        cells[0].move(new_bX - 1, new_bY);
        cells[1].move(new_bX, new_bY);
        cells[2].move(new_bX, new_bY + 1);
        cells[3].move(new_bX + 1, new_bY + 1);   
    }
    else if(newOrientation == 1){
        cells[0].move(new_bX, new_bY - 1);
        cells[1].move(new_bX, new_bY);
        cells[2].move(new_bX - 1, new_bY);
        cells[3].move(new_bX - 1, new_bY + 1);   
    }
    for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].paint();
        }
}
#endif