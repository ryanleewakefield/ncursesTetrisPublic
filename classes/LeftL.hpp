#ifndef __LEFTL_HPP__
#define __LEFTL_HPP__

#include <ncurses.h>
#include <string>
#include <vector>
#include <memory>

#include "Cell.hpp"
#include "Environment.hpp"
#include "Tetrimino.hpp"

class LeftL : Tetrimino{
public:
    LeftL(Environment* env, int color, std::vector<unsigned int>& Xs, std::vector<unsigned int>& Ys)
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

bool LeftL::rotateLeft(){
    switch(this->orientation){
        case 0: return rotateLeftOrientationZero();
        case 1: return rotateLeftOrientationOne();
        case 2: return rotateLeftOrientationTwo();
        case 3: return rotateLeftOrientationThree();
        default: return false;// This should never occur
    }
}
bool LeftL::rotateLeftOrientationZero(){
    int cX = cells[2].getx();
    int cY = cells[2].gety();

    int eX = cX - 1;
    int eY = cY - 2;

    int fX = cX - 1;
    int fY = cY - 1;

    int gX = cX - 1;
    int gY = cY;
     
    int pX = cX - 1;
    int pY = cY + 1;

    int iX = cX - 2;
    int iY = cY - 1;

    int jX = cX - 2;
    int jY = cY;

    int qX = cX;
    int qY = cY + 1;

    int rX = cX + 1;
    int rY = cY + 1;

    int kX = cX + 1;
    int kY = cY - 2;
    
    int lX = cX + 1;
    int lY = cY - 1;

    int mX = cX + 2;
    int mY = cY - 2;

    int nX = cX + 2;
    int nY = cY - 1;

    int oX = cX + 2;
    int oY = cY;

    bool willRotateHappen = false;
    int incX = 0;
    int incY = 0;
    if(environment->isOccupied(eX, eY) ||
        environment->isOccupied(fX, fY)){
            if(! (environment->isOccupied(nX, nY) ||
                environment->isOccupied(oX, oY))){
                 incX = 2;
                 incY = 0;
                 willRotateHappen = true;   
                }
            else{
                //do nothing
            }
        }
    else if(environment->isOccupied(gX, gY)){
        if(! (environment->isOccupied(kX, kY) ||
            environment->isOccupied(lX, lY))){
                incX = 1;
                incY = -1;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(lX, lY)){
        if( ! (environment->isOccupied(pX, pY) ||
                environment->isOccupied(qX, qY) ||
                environment->isOccupied(rX, rY))){
                incX = 1;
                incY = 1;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(iX, iY) ||
            environment->isOccupied(jX, jY)){
        if(! (environment->isOccupied(nX, nY) ||
                environment->isOccupied(oX, oY))){
                    incX = 2;
                    incY = 0;
                    willRotateHappen = true;
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
//Matrix transformation of (x,y) to (y,-x)
bool LeftL::rotateLeftOrientationOne(){
    int cX = cells[2].getx();
    int cY = cells[2].gety();

    int eY = cX - 1;
    int eX = -(cY - 2);

    int fY = cX - 1;
    int fX = -(cY - 1);

    int gY = cX - 1;
    int gX = -(cY);
     
    int pY = cX - 1;
    int pX = -(cY + 1);

    int iY = cX - 2;
    int iX = -(cY - 1);

    int jY = cX - 2;
    int jX = -(cY);

    int qY = cX;
    int qX = -(cY + 1);

    int rY = cX + 1;
    int rX = -(cY + 1);

    int kY = cX + 1;
    int kX = -(cY - 2);
    
    int lY = cX + 1;
    int lX = -(cY - 1);

    int mY = cX + 2;
    int mX = -(cY - 2);

    int nY = cX + 2;
    int nX = -(cY - 1);

    int oY = cX + 2;
    int oX = -(cY);

    bool willRotateHappen = false;
    int incX = 0;
    int incY = 0;
    if(environment->isOccupied(eX, eY) ||
        environment->isOccupied(fX, fY)){
            if(! (environment->isOccupied(nX, nY) ||
                environment->isOccupied(oX, oY))){
                 incX = 2;
                 incY = 0;

                 incX = 0;
                 incY = -2;
                 willRotateHappen = true;   
                }
            else{
                //do nothing
            }
        }
    else if(environment->isOccupied(gX, gY)){
        if(! (environment->isOccupied(kX, kY) ||
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
    else if(environment->isOccupied(lX, lY)){
        if( ! (environment->isOccupied(pX, pY) ||
                environment->isOccupied(qX, qY) ||
                environment->isOccupied(rX, rY))){
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
    else if(environment->isOccupied(iX, iY) ||
            environment->isOccupied(jX, jY)){
        if(! (environment->isOccupied(nX, nY) ||
                environment->isOccupied(oX, oY))){
                    incX = 2;
                    incY = 0;

                    incX = 0;
                    incY = -2;
                    willRotateHappen = true;
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
bool LeftL::rotateLeftOrientationTwo(){

}
bool LeftL::rotateLeftOrientationThree(){

}
void LeftL::doRotateLeft(int incX, int incY, unsigned int newOrientation){

}
bool LeftL::rotateRight(){
    switch(this->orientation){
        case 0: return rotateRightOrientationZero();
        case 1: return rotateRightOrientationOne();
        case 2: return rotateRightOrientationTwo();
        case 3: return rotateRightOrientationThree();
        default: return false;// This should never occur
    }
}
bool LeftL::rotateRightOrientationZero(){
    int cX = cells[2].getx();
    int cY = cells[2].gety();

    int eX = cX - 1;
    int eY = cY - 2;

    int fX = cX - 1;
    int fY = cY - 1;

    int gX = cX - 1;
    int gY = cY;
     
    int pX = cX - 1;
    int pY = cY + 1;

    int iX = cX - 2;
    int iY = cY - 1;

    int jX = cX - 2;
    int jY = cY;

    int qX = cX;
    int qY = cY + 1;

    int rX = cX + 1;
    int rY = cY + 1;

    int kX = cX + 1;
    int kY = cY - 2;
    
    int lX = cX + 1;
    int lY = cY - 1;

    int mX = cX + 2;
    int mY = cY - 2;

    int nX = cX + 2;
    int nY = cY - 1;

    int oX = cX + 2;
    int oY = cY;

    bool willRotateHappen = false;
    int incX = 0;
    int incY = 0;

    if(environment->isOccupied(kX, kY)){
        if(! (environment->isOccupied(fX, fY) ||
            environment->isOccupied(gX, gY) ||
            environment->isOccupied(iX, iY) ||
            environment->isOccupied(jX, jY))){
                incX = -1;
                incY = -1;
                willRotateHappen = true;
        }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(lX, lY)){
        if(!( environment->isOccupied(eX, eY) ||
            environment->isOccupied(fX, fY))){
                incX = -1;
                incY = -2;
                willRotateHappen = true;
            }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(qX, qY) ||
            environment->isOccupied(rX, rY)){
            if(! (environment->isOccupied(mX, mY) ||
                environment->isOccupied(nX, nY))){
                    incX = 0;
                    incY = -1;
                    willRotateHappen = true;
                }
            
            else{
                //do nothing
            }
    }
    else if(environment->isOccupied(mX, mY) ||
            environment->isOccupied(nX, nY) ||
            environment->isOccupied(oX, oY)){
                if(! (environment->isOccupied(gX, gY) ||
                    environment->isOccupied(pX, pY))){
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
        doRotateRight(incX, incY, newOrientation);
    }
    return willRotateHappen;
}
bool LeftL::rotateRightOrientationOne(){

}
bool LeftL::rotateRightOrientationTwo(){

}
bool LeftL::rotateRightOrientationThree(){

}
void LeftL::doRotateRight(int incX, int incY, unsigned int newOrientation){

}
#endif