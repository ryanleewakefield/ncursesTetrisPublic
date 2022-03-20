#ifndef __LEFTS_HPP__
#define __LEFTS_HPP__

#include <ncurses.h>
#include <string>
#include <vector>
#include <memory>

#include "Cell.hpp"
#include "Environment.hpp"
#include "Tetrimino.hpp"

class LeftS : public Tetrimino{
public:
    LeftS(Environment* env, int color, std::vector<unsigned int>& Xs, std::vector<unsigned int>& Ys)
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
bool LeftS::rotateLeft(){
    switch(this->orientation){
        case 0: return rotateLeftOrientationZero();
        case 1: return rotateLeftOrientationOne();
        default: return false;// This should never occur
    }
}

bool LeftS::rotateLeftOrientationZero(){
    int cX = cells[2].getx();
    int cY = cells[2].gety();

    int eX = cX - 1;
    int eY = cY;

    int fX = cX - 1;
    int fY = cY - 1;
    
    int gX = cX;
    int gY = cY - 1;

    int hX = cX + 1;
    int hY = cY - 1;

    int lX = cX + 1;
    int lY = cY + 1;

    int mX = cX - 1;
    int mY = cY + 2;

    int nX = cX;
    int nY = cY + 2;

    int oX = cX + 1;
    int oY = cY + 2;

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
        unsigned newOrientation = (this->orientation - 1) % 2;
        if(newOrientation < 0){
            newOrientation = newOrientation + 2;
        }
        this->orientation = newOrientation;
        doRotateLeft(incX, incY, newOrientation);
    }
    return willRotateHappen;
}
bool LeftS::rotateLeftOrientationOne(){
    int cX = cells[2].getx();
    int cY = cells[2].gety();

    int eX = cX;
    int eY = cY + 1;

    int fX = cX - 1;
    int fY = cY + 1;
    
    int gX = cX - 1;
    int gY = cY;

    int hX = cX - 1;
    int hY = cY - 1;

    int lX = cX + 1;
    int lY = cY - 1;

    int mX = cX + 2;
    int mY = cY + 1;

    int nX = cX + 1;
    int nY = cY;

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
        unsigned newOrientation = (this->orientation - 1) % 2;
        if(newOrientation < 0){
            newOrientation = newOrientation + 2;
        }
        this->orientation = newOrientation;
        doRotateLeft(incX, incY, newOrientation);
    }
    return willRotateHappen;
}
void LeftS::doRotateLeft(int incX, int incY, unsigned int newOrientation){
    unsigned int new_cX = cells[2].getx() + incX;
    unsigned int new_cY = cells[2].gety() + incY;
    for(unsigned int i = 0; i < cells.size(); i++){
        cells[i].erase();
    }
    if(newOrientation == 0){    
        cells[0].move(new_cX - 1, new_cY + 1);
        cells[1].move(new_cX, new_cY + 1);
        cells[2].move(new_cX, new_cY);
        cells[3].move(new_cX + 1, new_cY);   
    }
    else if(newOrientation == 1){
        cells[0].move(new_cX + 1, new_cY + 1);
        cells[1].move(new_cX + 1, new_cY);
        cells[2].move(new_cX, new_cY);
        cells[3].move(new_cX, new_cY - 1);   
    }
    for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].paint();
        }
}
bool LeftS::rotateRight(){
    switch(this->orientation){
        case 0: return rotateRightOrientationZero();
        case 1: return rotateRightOrientationOne();
        default: return false;// This should never occur
    }
}
bool LeftS::rotateRightOrientationZero(){
    int cX = cells[2].getx();
    int cY = cells[2].gety();

    int eX = cX - 1;
    int eY = cY;

    int fX = cX - 1;
    int fY = cY - 1;
    
    int gX = cX;
    int gY = cY - 1;

    int hX = cX + 1;
    int hY = cY - 1;

    int iX = cX - 1;
    int iY = cY - 2;

    int jX = cX;
    int jY = cY - 2;

    int lX = cX + 1;
    int lY = cY + 1;

    int mX = cX - 1;
    int mY = cY + 2;

    int nX = cX;
    int nY = cY + 2;

    int oX = cX + 1;
    int oY = cY + 2;

    int rX = cX + 1;
    int rY = cY + 3;

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
        unsigned newOrientation = (this->orientation + 1) % 2;
        if(newOrientation < 0){
            newOrientation = newOrientation + 2;
        }
        this->orientation = newOrientation;
        doRotateLeft(incX, incY, newOrientation);
    }
    return willRotateHappen;
}
bool LeftS::rotateRightOrientationOne(){
    int cX = cells[2].getx();
    int cY = cells[2].gety();


    int eX = cX;
    int eY = cY + 1;

    int fX = cX - 1;
    int fY = cY + 1;
    
    int gX = cX - 1;
    int gY = cY;

    int hX = cX - 1;
    int hY = cY - 1;

    int iX = cX + -2;
    int iY = cY + 1;

    int lX = cX + 1;
    int lY = cY - 1;

    int mX = cX + 2;
    int mY = cY + 1;

    int nX = cX + 2;
    int nY = cY;

    int oX = cX + 2;
    int oY = cY - 1;

    int rX = cX + 3;
    int rY = cY - 1;
    

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
        unsigned newOrientation = (this->orientation + 1) % 2;
        if(newOrientation < 0){
            newOrientation = newOrientation + 2;
        }
        this->orientation = newOrientation;
        doRotateLeft(incX, incY, newOrientation);
    }
    return willRotateHappen;
}
void LeftS::doRotateRight(int incX, int incY, unsigned int newOrientation){
    unsigned int new_cX = cells[2].getx() + incX;
    unsigned int new_cY = cells[2].gety() + incY;
    for(unsigned int i = 0; i < cells.size(); i++){
        cells[i].erase();
    }
    if(newOrientation == 0){    
        cells[0].move(new_cX - 1, new_cY + 1);
        cells[1].move(new_cX, new_cY + 1);
        cells[2].move(new_cX, new_cY);
        cells[3].move(new_cX + 1, new_cY);   
    }
    else if(newOrientation == 1){
        cells[0].move(new_cX + 1, new_cY + 1);
        cells[1].move(new_cX + 1, new_cY);
        cells[2].move(new_cX, new_cY);
        cells[3].move(new_cX, new_cY - 1);   
    }
    for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].paint();
        }
}
#endif