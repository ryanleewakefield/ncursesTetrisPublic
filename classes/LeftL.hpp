#ifndef __LEFTL_HPP__
#define __LEFTL_HPP__

#include <ncurses.h>
#include <string>
#include <vector>
#include <memory>

#include "Cell.hpp"
#include "Environment.hpp"
#include "Tetrimino.hpp"

class LeftL : public Tetrimino{
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
    // if # 1 - Passed
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
    // if # 2 - Passed
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
    // if # 3 - Passed
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
    // if # 4 - Passed
    else if(environment->isOccupied(iX, iY) ||
            environment->isOccupied(jX, jY)){
        if(! (environment->isOccupied(nX, nY) ||
                environment->isOccupied(oX, oY))){
                    incX = 2;
                    incY = 0;
                    willRotateHappen = true;
                }
            }
    // if # 5 - Passed
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

//Matrix transformation of (x,y) to (-y,x)
bool LeftL::rotateLeftOrientationOne(){
    int cX = cells[2].getx();
    int cY = cells[2].gety();

    int eY = cY - 1;
    int eX = cX + 2;

    int fY = cY - 1;
    int fX = cX + 1;

    int gY = cY - 1;
    int gX = cX;
     
    int pY = cY - 1;
    int pX = cX - 1;

    int iY = cY - 2;
    int iX = cX + 1;

    int jY = cY - 2;
    int jX = cX;

    int qY = cY;
    int qX = cX - 1;

    int rY = cY + 1;
    int rX = cX - 1;

    int kY = cY + 1;
    int kX = cX + 2;
    
    int lY = cY + 1;
    int lX = cX + 1;

    int mY = cY + 2;
    int mX = cX + 2;

    int nY = cY + 2;
    int nX = cX + 1;

    int oY = cY + 2;
    int oX = cX;

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
                 incY = 2;
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

                incX = 1;
                incY = 1;
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

                incX = -1;
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

                    incX = 0;
                    incY = 2;
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


//Matrix transformation (x,y) to (-x,-y)
bool LeftL::rotateLeftOrientationTwo(){
    int cX = cells[2].getx();
    int cY = cells[2].gety();

    int eX = cX + 1;
    int eY = cY + 2;

    int fX = cX + 1;
    int fY = cY + 1;

    int gX = cX + 1;
    int gY = cY;
     
    int pX = cX + 1;
    int pY = cY - 1;

    int iX = cX + 2;
    int iY = cY + 1;

    int jX = cX + 2;
    int jY = cY;

    int qX = cX;
    int qY = cY - 1;

    int rX = cX - 1;
    int rY = cY - 1;

    int kX = cX - 1;
    int kY = cY + 2;
    
    int lX = cX - 1;
    int lY = cY + 1;

    int mX = cX - 2;
    int mY = cY + 2;

    int nX = cX - 2;
    int nY = cY + 1;

    int oX = cX - 2;
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

                 incX = -2;
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

                incX = -1;
                incY = 1;
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

                incX = -1;
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

                    incX = -2;
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
bool LeftL::rotateLeftOrientationThree(){
    int cX = cells[2].getx();
    int cY = cells[2].gety();

    int eY = cY + 1;
    int eX = cX - 2;

    int fY = cY + 1;
    int fX = cX - 1;

    int gY = cY + 1;
    int gX = cX;
     
    int pY = cY + 1;
    int pX = cX + 1;

    int iY = cY + 2;
    int iX = cX - 1;

    int jY = cY + 2;
    int jX = cX;

    int qY = cY;
    int qX = cX + 1;

    int rY = cY - 1;
    int rX = cX + 1;

    int kY = cY - 1;
    int kX = cX - 2;
    
    int lY = cY - 1;
    int lX = cX - 1;

    int mY = cY - 2;
    int mX = cX - 2;

    int nY = cY - 2;
    int nX = cX - 1;

    int oY = cY - 2;
    int oX = cX;

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

void LeftL::doRotateLeft(int incX, int incY, unsigned int newOrientation){
    /*
        Zero       One         Two         Three

         a
         b                                      d
         c d        c b a       d c         a b c
                    d             b
                                  a

    */
   //This part should be the same for all orientations
    unsigned int new_cX = cells[2].getx() + incX;
    unsigned int new_cY = cells[2].gety() + incY;
    for(unsigned int i = 0; i < cells.size(); i++){
        cells[i].erase();
    }
    
    if(newOrientation == 0){    
        cells[0].move(new_cX, new_cY - 2);
        cells[1].move(new_cX, new_cY - 1);
        cells[2].move(new_cX, new_cY);
        cells[3].move(new_cX + 1, new_cY);   
    }
    else if(newOrientation == 1){
        cells[0].move(new_cX + 2, new_cY);
        cells[1].move(new_cX + 1, new_cY);
        cells[2].move(new_cX, new_cY);
        cells[3].move(new_cX, new_cY + 1);   
    }
    else if(newOrientation == 2){
        cells[0].move(new_cX, new_cY + 2);
        cells[1].move(new_cX, new_cY + 1);
        cells[2].move(new_cX, new_cY);
        cells[3].move(new_cX - 1, new_cY);   
    }
    else if(newOrientation == 3){
        cells[0].move(new_cX - 2, new_cY);
        cells[1].move(new_cX - 1, new_cY);
        cells[2].move(new_cX, new_cY);
        cells[3].move(new_cX, new_cY - 1);   
     }
    for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].paint();
        }
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
        if(! (environment->isOccupied(eX, eY) ||
            environment->isOccupied(fX, fY) ||
            environment->isOccupied(gX, gY) ||
            environment->isOccupied(iX, iY) ||
            environment->isOccupied(jX, jY))){
                incX = -2;
                incY = -1;
                willRotateHappen = true;
        }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(lX, lY)){
        if(!( environment->isOccupied(eX, eY) ||
            environment->isOccupied(fX, fY) ||
            environment->isOccupied(gX, gY))){
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
                if(! (environment->isOccupied(fX, fY) ||
                    environment->isOccupied(gX, gY) ||
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
    int cX = cells[2].getx();
    int cY = cells[2].gety();

    int eY = cY - 1;
    int eX = cX + 2;

    int fY = cY - 1;
    int fX = cX + 1;

    int gY = cY - 1;
    int gX = cX;
     
    int pY = cY - 1;
    int pX = cX - 1;

    int iY = cY - 2;
    int iX = cX + 1;

    int jY = cY - 2;
    int jX = cX;

    int qY = cY;
    int qX = cX - 1;

    int rY = cY + 1;
    int rX = cX - 1;

    int kY = cY + 1;
    int kX = cX + 2;
    
    int lY = cY + 1;
    int lX = cX + 1;

    int mY = cY + 2;
    int mX = cX + 2;

    int nY = cY + 2;
    int nX = cX + 1;

    int oY = cY + 2;
    int oX = cX;

    bool willRotateHappen = false;
    int incX = 0;
    int incY = 0;

    if(environment->isOccupied(kX, kY)){
        if(! (environment->isOccupied(eX, eY) ||
            environment->isOccupied(fX, fY) ||
            environment->isOccupied(gX, gY) ||
            environment->isOccupied(iX, iY) ||
            environment->isOccupied(jX, jY))){
                incX = -2;
                incY = -1;

                incX = 1;
                incY = -2;
                willRotateHappen = true;
        }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(lX, lY)){
        if(!( environment->isOccupied(eX, eY) ||
            environment->isOccupied(fX, fY) ||
            environment->isOccupied(gX, gY))){
                incX = -1;
                incY = -2;

                incX = 2;
                incY = -1;
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

                     incX = 1;
                    incY = 0;
                    willRotateHappen = true;
                }
            
            else{
                //do nothing
            }
    }
    else if(environment->isOccupied(mX, mY) ||
            environment->isOccupied(nX, nY) ||
            environment->isOccupied(oX, oY)){
                if(! (environment->isOccupied(fX, fY) ||
                    environment->isOccupied(gX, gY) ||
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
bool LeftL::rotateRightOrientationTwo(){
    int cX = cells[2].getx();
    int cY = cells[2].gety();

    int eX = cX + 1;
    int eY = cY + 2;

    int fX = cX + 1;
    int fY = cY + 1;

    int gX = cX + 1;
    int gY = cY;
     
    int pX = cX + 1;
    int pY = cY - 1;

    int iX = cX + 2;
    int iY = cY + 1;

    int jX = cX + 2;
    int jY = cY;

    int qX = cX;
    int qY = cY - 1;

    int rX = cX - 1;
    int rY = cY - 1;

    int kX = cX - 1;
    int kY = cY + 2;
    
    int lX = cX - 1;
    int lY = cY + 1;

    int mX = cX - 2;
    int mY = cY + 2;

    int nX = cX - 2;
    int nY = cY + 1;

    int oX = cX - 2;
    int oY = cY;

    bool willRotateHappen = false;
    int incX = 0;
    int incY = 0;

    if(environment->isOccupied(kX, kY)){
        if(! (environment->isOccupied(eX, eY) ||
            environment->isOccupied(fX, fY) ||
            environment->isOccupied(gX, gY) ||
            environment->isOccupied(iX, iY) ||
            environment->isOccupied(jX, jY))){
                incX = -2;
                incY = -1;

                incX = 2;
                incY = 1;
                willRotateHappen = true;
        }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(lX, lY)){
        if(!( environment->isOccupied(eX, eY) ||
            environment->isOccupied(fX, fY) ||
            environment->isOccupied(gX, gY))){
                incX = -1;
                incY = -2;

                incX = 1;
                incY = 2;
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

                    incX = 0;
                    incY = 1;
                    willRotateHappen = true;
                }
            
            else{
                //do nothing
            }
    }
    else if(environment->isOccupied(mX, mY) ||
            environment->isOccupied(nX, nY) ||
            environment->isOccupied(oX, oY)){
                if(! (environment->isOccupied(fX, fY) ||
                    environment->isOccupied(gX, gY) ||
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
bool LeftL::rotateRightOrientationThree(){
    int cX = cells[2].getx();
    int cY = cells[2].gety();

    int eY = cY + 1;
    int eX = cX - 2;

    int fY = cY + 1;
    int fX = cX - 1;

    int gY = cY + 1;
    int gX = cX;
     
    int pY = cY + 1;
    int pX = cX + 1;

    int iY = cY + 2;
    int iX = cX - 1;

    int jY = cY + 2;
    int jX = cX;

    int qY = cY;
    int qX = cX + 1;

    int rY = cY - 1;
    int rX = cX + 1;

    int kY = cY - 1;
    int kX = cX - 2;
    
    int lY = cY - 1;
    int lX = cX - 1;

    int mY = cY - 2;
    int mX = cX - 2;

    int nY = cY - 2;
    int nX = cX - 1;

    int oY = cY - 2;
    int oX = cX;

    bool willRotateHappen = false;
    int incX = 0;
    int incY = 0;

    if(environment->isOccupied(kX, kY)){
        if(! (environment->isOccupied(eX, eY) ||
            environment->isOccupied(fX, fY) ||
            environment->isOccupied(gX, gY) ||
            environment->isOccupied(iX, iY) ||
            environment->isOccupied(jX, jY))){
                incX = -2;
                incY = -1;

                incX = -1;
                incY = 2;
                willRotateHappen = true;
        }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(lX, lY)){
        if(!( environment->isOccupied(eX, eY) ||
            environment->isOccupied(fX, fY) ||
            environment->isOccupied(gX, gY))){
                incX = -1;
                incY = -2;

                incX = -2;
                incY = 1;
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

                    incX = -1;
                    incY = 0;
                    willRotateHappen = true;
                }
            
            else{
                //do nothing
            }
    }
    else if(environment->isOccupied(mX, mY) ||
            environment->isOccupied(nX, nY) ||
            environment->isOccupied(oX, oY)){
                if(! (environment->isOccupied(fX, fY) ||
                    environment->isOccupied(gX, gY) ||
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

void LeftL::doRotateRight(int incX, int incY, unsigned int newOrientation){
    /*
        Zero        One         Two        Three

         a
         b                                      d
         c d        c b a       d c         a b c
                    d             b
                                  a

    */
   //This part should be the same for all orientations
    unsigned int new_cX = cells[2].getx() + incX;
    unsigned int new_cY = cells[2].gety() + incY;
    for(unsigned int i = 0; i < cells.size(); i++){
        cells[i].erase();
    }
    
    if(newOrientation == 0){    
        cells[0].move(new_cX, new_cY - 2);
        cells[1].move(new_cX, new_cY - 1);
        cells[2].move(new_cX, new_cY);
        cells[3].move(new_cX + 1, new_cY);   
    }
    else if(newOrientation == 1){
        cells[0].move(new_cX + 2, new_cY);
        cells[1].move(new_cX + 1, new_cY);
        cells[2].move(new_cX, new_cY);
        cells[3].move(new_cX, new_cY + 1);   
    }
    else if(newOrientation == 2){
        cells[0].move(new_cX, new_cY + 2);
        cells[1].move(new_cX, new_cY + 1);
        cells[2].move(new_cX, new_cY);
        cells[3].move(new_cX - 1, new_cY);   
    }
    else if(newOrientation == 3){
        cells[0].move(new_cX - 2, new_cY);
        cells[1].move(new_cX - 1, new_cY);
        cells[2].move(new_cX, new_cY);
        cells[3].move(new_cX, new_cY - 1);   
     }
    for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].paint();
        }
}
#endif