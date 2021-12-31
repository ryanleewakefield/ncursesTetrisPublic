#ifndef __LONGPIECE_HPP__
#define __LONGPIECE_HPP__

#include <ncurses.h>
#include <string>
#include <vector>
#include <memory>

#include "Cell.hpp"
#include "Environment.hpp"
#include "Tetrimino.hpp"

/* LongPiece Header and Implementation*/
class LongPiece : public Tetrimino{
public:
    LongPiece(Environment* env, int color, std::vector<unsigned int>& Xs, std::vector<unsigned int>& Ys)
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

bool LongPiece::rotateLeft(){
    switch(this->orientation){
        case 0: return rotateLeftOrientationZero();
        case 1: return rotateLeftOrientationOne();
        case 2: return rotateLeftOrientationTwo();
        case 3: return rotateLeftOrientationThree();
        default: return false;// This should never occur
    }
}

/*
      0 1 2 3 4 5 6
    0
    1     e a l p
    2   i f b m q s
    3 k j g c n r
    4     h d o
    5
    6

    a b c d is the Long Piece
*/
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

    bool willRotateHappen = false;
    int incX = 0;
    int incY = 0;
    if(environment->isOccupied(eX, eY)){
        if( ! ( environment->isOccupied(lX, lY) ||
                environment->isOccupied(mX, mY) ||
                environment->isOccupied(nX, nY) ||
                environment->isOccupied(oX, oY) ||
                environment->isOccupied(qX, qY) ||
                environment->isOccupied(rX, rY) ||
                environment->isOccupied(sX, sY))){
                    //do a(0,1)
                    incX = 0;
                    incY = 1;
                    willRotateHappen = true;
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
        if( ! ( environment->isOccupied(mX, mY) ||
                environment->isOccupied(rX, rY) ||
                environment->isOccupied(nX, nY) ||
                environment->isOccupied(qX, qY) ||
                environment->isOccupied(oX, oY))){
                    //do a(-1,1)
                    incX = -1;
                    incY = 1;
                    willRotateHappen = true;
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
                    incX = -3;
                    incY = 2;
                    willRotateHappen = true;
                }
                else{
                    //do nothing
                }
    }
    else if(environment->isOccupied(mX, mY)){
        if(! environment->isOccupied(rX, rY)){
            //do a(-1,2)
            incX = -1;
            incY = 2;
            willRotateHappen = true;
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
                incX = -2;
                incY = 1;
                willRotateHappen = true;
            }
            else{
                //do nothing
            }
        }
        else{
            //do a(-1,1)
            incX = -1;
            incY = 1;
            willRotateHappen = true;
        }
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
bool LongPiece::rotateLeftOrientationOne(){
    int dX = cells[3].getx();
    int dY = cells[3].gety();
    
    //Bottom Side
    int eX = dX;
    int eY = dY + 1;  
    int iX = dX + 1;
    int iY = dY + 2;  
    int fX = dX + 1;
    int fY = dY + 1;  
    int kX = dX + 2;
    int kY = dY + 3;  
    int jX = dX + 2;
    int jY = dY + 2;  
    int gX = dX + 2;
    int gY = dY + 1;   
    int hX = dX + 3;
    int hY = dY + 1;

    //Top Side
    int lX = dX;
    int lY = dY - 1;    
    int mX = dX + 1;
    int mY = dY - 1;  
    int pX = dX;
    int pY = dY - 2;  
    int rX = dX + 2;
    int rY = dY - 2;   
    int nX = dX + 2;
    int nY = dY - 1;  
    int qX = dX + 1;
    int qY = dY - 2;  
    int oX = dX + 3;
    int oY = dY - 1;  
    int sX = dX + 1;
    int sY = dY - 3;

    bool willRotateHappen = false;
    int incX = 0;
    int incY = 0;
    if(environment->isOccupied(eX, eY)){
        if( ! ( environment->isOccupied(lX, lY) ||
                environment->isOccupied(mX, mY) ||
                environment->isOccupied(nX, nY) ||
                environment->isOccupied(oX, oY) ||
                environment->isOccupied(qX, qY) ||
                environment->isOccupied(rX, rY) ||
                environment->isOccupied(sX, sY))){
                    //do d(1,0)
                    incX = 1;
                    incY = 0;
                    willRotateHappen = true;
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
                    //do d(0,1)
                    incX = 0;
                    incY = 1;
                    willRotateHappen = true;
                }
                else{
                    //do nothing
                }
    }
    else if(environment->isOccupied(gX, gY)){
        if( ! ( environment->isOccupied(mX, mY) ||
                environment->isOccupied(nX, nY) ||
                environment->isOccupied(oX, oY))){
                    if(! environment->isOccupied(iX, iY)){
                        //do d(1,1)
                        incX = 1;
                        incY = 2;
                        willRotateHappen = true;
                    }
                    else if(! environment->isOccupied(qX, qY)){
                        //do d(1,1)
                        incX = 1;
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
    else if(environment->isOccupied(hX, hY)){
        if(! ( environment->isOccupied(nX, nY) ||
                environment->isOccupied(oX, oY)) ){
                    if(! (environment->isOccupied(iX, iY) ||
                        environment->isOccupied(jX,jY))){
                            incX = 2;
                            incY = 2;
                            willRotateHappen = true;
                        }
                    else if(! (environment->isOccupied(qX, qY) ||
                            environment->isOccupied(rX, rY))){
                                incX = 1;
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
    else if(environment->isOccupied(oX, oY) ||
            environment->isOccupied(nX, nY)){
        if( ! (environment->isOccupied(iX, iY) ||
                environment->isOccupied(jX, jY) ||
                environment->isOccupied(kX, kY))){
                    //do d(2,3)
                    incX = 2;
                    incY = 3;
                    willRotateHappen = true;
                }
                else{
                    //do nothing
                }
    }
    else{
        if(! (environment->isOccupied(iX, iY) ||
              environment->isOccupied(jX, jY))){
            incX = 2;
            incY = 2;
            willRotateHappen = true;
        }
        else if(! (environment->isOccupied(qX, qY) ||
                    environment->isOccupied(rX, rY))){
            //do d(1,1)
                incX = 1;
                incY = 1;
                willRotateHappen = true;
        }
        else{
            //do nothing
        }
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
bool LongPiece::rotateLeftOrientationTwo(){
    int dX = cells[3].getx();
    int dY = cells[3].gety();
    
    //Left Side
    int eX = dX - 1;
    int eY = dY;
    int iX = dX - 2;
    int iY = dY + 1;
    int fX = dX - 1;
    int fY = dY + 1;
    int kX = dX - 3;
    int kY = dY + 2;
    int jX = dX - 2;
    int jY = dY + 2;
    int gX = dX - 1;
    int gY = dY + 2;
    int hX = dX - 1;
    int hY = dY + 3;

    //Right Side
    int lX = dX + 1;
    int lY = dY;
    int mX = dX + 1;
    int mY = dY + 1;
    int pX = dX + 2;
    int pY = dY;
    int rX = dX + 2;
    int rY = dY + 2;
    int nX = dX + 1;
    int nY = dY + 2;
    int qX = dX + 2;
    int qY = dY + 1;
    int oX = dX + 1;
    int oY = dY + 3;
    int sX = dX + 3;
    int sY = dY + 1;

    bool willRotateHappen = false;
    int incX = 0;
    int incY = 0;
    if(environment->isOccupied(eX, eY)){
        if( ! ( environment->isOccupied(lX, lY) ||
                environment->isOccupied(mX, mY) ||
                environment->isOccupied(nX, nY) ||
                environment->isOccupied(oX, oY) ||
                environment->isOccupied(qX, qY) ||
                environment->isOccupied(rX, rY) ||
                environment->isOccupied(sX, sY))){
                    //do d(0,1)
                    incX = 1;
                    incY = 1;
                    willRotateHappen = true;
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
                    //do d(-1,0)
                    incX = -1;
                    incY = 0;
                    willRotateHappen = true;
                }
                else{
                    //do nothing
                }
    }
    else if(environment->isOccupied(gX, gY)){
        if( ! ( environment->isOccupied(mX, mY) ||
                environment->isOccupied(rX, rY) ||
                environment->isOccupied(nX, nY) ||
                environment->isOccupied(qX, qY) ||
                environment->isOccupied(oX, oY))){
                    if(! environment->isOccupied(iX, iY)){
                    //do d(-1,1)
                    incX = -2;
                    incY = 1;
                    willRotateHappen = true;
                    }
                    else{
                        incX = -1;
                        incY = 1;
                        willRotateHappen = true;
                    }
                }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(hX, hY)){
        if( ! ( environment->isOccupied(nX, nY) ||
                environment->isOccupied(oX, oY))){
                    if( environment->isOccupied(iX, iY) ||
                        environment->isOccupied(jX, jY)){
                        if(! environment->isOccupied(rX, rY)){
                            incX = -1;
                            incY = 2;
                            willRotateHappen = true;
                        }
                        else{
                            //do nothing
                        }
                    }else{
                        incX = -2;
                        incY = 2;
                        willRotateHappen = true;
                    }
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
                    //do d(-3,2)
                    incX = -3;
                    incY = 2;
                    willRotateHappen = true;
                }
                else{
                    //do nothing
                }
    }
    else if(environment->isOccupied(iX, iY) ||
            environment->isOccupied(jX, jY)){
                if(! environment->isOccupied(rX, rY)){
                    incX = -1;
                    incY = 2;
                    willRotateHappen = true;
                }
                else{
                    //do nothing
                }
            }
    else{
        incX = -2;
        incY = 2;
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
bool LongPiece::rotateLeftOrientationThree(){
    int aX = cells[0].getx();
    int aY = cells[0].gety();
    
    //Bottom Side
    int eX = aX;
    int eY = aY + 1;  
    int iX = aX + 1;
    int iY = aY + 2;   
    int fX = aX + 1;
    int fY = aY + 1;   
    int kX = aX + 2;
    int kY = aY + 3;   
    int jX = aX + 2;
    int jY = aY + 2;   
    int gX = aX + 2;
    int gY = aY + 1;   
    int hX = aX + 3;
    int hY = aY + 1;

    //Top Side
    int lX = aX;
    int lY = aY - 1;  
    int mX = aX + 1;
    int mY = aY - 1;  
    int pX = aX;
    int pY = aY - 2;  
    int rX = aX + 2;
    int rY = aY - 2;  
    int nX = aX + 2;
    int nY = aY - 1;   
    int qX = aX + 1;
    int qY = aY - 2;   
    int oX = aX + 3;
    int oY = aY - 1;   
    int sX = aX + 1;
    int sY = aY - 3;

    bool willRotateHappen = false;
    int incX = 0;
    int incY = 0;
    if(environment->isOccupied(eX, eY)){
        if( ! ( environment->isOccupied(lX, lY) ||
                environment->isOccupied(mX, mY) ||
                environment->isOccupied(nX, nY) ||
                environment->isOccupied(oX, oY) ||
                environment->isOccupied(qX, qY) ||
                environment->isOccupied(rX, rY) ||
                environment->isOccupied(sX, sY))){
                    //do a(1,0)
                    incX = 1;
                    incY = 0;
                    willRotateHappen = true;
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
                    //do a(0,1)
                    incX = 0;
                    incY = 1;
                    willRotateHappen = true;
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
                    //do a(1,1)
                    incX = 1;
                    incY = 1;
                    willRotateHappen = true;
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
                    //do a(2,3)
                    incX = 2;
                    incY = 3;
                    willRotateHappen = true;
                }
                else{
                    //do nothing
                }
    }
    else if(environment->isOccupied(mX, mY)){
        if(! environment->isOccupied(rX, rY)){
            //do a(2,1)
            incX = 2;
            incY = 1;
            willRotateHappen = true;
        }
        else{
            //do nothing
        }
    }
    else{
        if((environment->isOccupied(qX, qY) ||
            environment->isOccupied(rX, rY))){
            if(! environment->isOccupied(iX, iY)){
                //do a(2,2)
                incX = 2;
                incY = 2;
                willRotateHappen = true;
            }
            else{
                //do nothing
            }
        }
        else{
            //do a(1,1)
            incX = 1;
            incY = 1;
            willRotateHappen = true;
        }
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
void LongPiece::doRotateLeft(int incX, int incY, unsigned int newOrientation){
    /* Zero    One      Two      Three
        a                d         
        b     d c b a    c       a b c d
        c                b
        d                a
    */
    if(newOrientation == 0){
        unsigned int new_dX = cells[3].getx() + incX;
        unsigned int new_dY = cells[3].gety() + incY;
        for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].erase();
        }
        for(unsigned int i = 0; i < cells.size(); i++){
            //cells[i].move(new_aX, new_aY - i);
            cells[cells.size() - 1 - i].move(new_dX, new_dY - i);
        }
        for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].paint();
        }
    }
    else if(newOrientation == 1){
        unsigned int new_dX = cells[3].getx() + incX;
        unsigned int new_dY = cells[3].gety() + incY;
        for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].erase();
        }
        for(unsigned int i = 0; i < cells.size(); i++){
            //cells[i].move(new_dX + i, new_dY);
            cells[cells.size() - 1 - i].move(new_dX + i, new_dY);
        }
        for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].paint();
        }
    }
     else if(newOrientation == 2){
        unsigned int new_aX = cells[0].getx() + incX;
        unsigned int new_aY = cells[0].gety() + incY;
        for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].erase();
        }
        for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].move(new_aX, new_aY - i);
        }
        for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].paint();
        }
    }
     else if(newOrientation == 3){
        unsigned int new_aX = cells[0].getx() + incX;
        unsigned int new_aY = cells[0].gety() + incY;
        for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].erase();
        }
        for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].move(new_aX + i, new_aY);
            
        }
        for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].paint();
        }
    }
}


bool LongPiece::rotateRight(){
    switch(this->orientation){
        case 0: return rotateRightOrientationZero();
        case 1: return rotateRightOrientationOne();
        case 2: return rotateRightOrientationTwo();
        case 3: return rotateRightOrientationThree();
        default: return false;// This should never occur
    }
}
bool LongPiece::rotateRightOrientationZero(){
    int aX = cells[0].getx();
    int aY = cells[0].gety();
    
    //Right Side
    int eX = aX + 1;
    int eY = aY;
    
    int iX = aX + 2;
    int iY = aY + 1;
    
    int fX = aX + 1;
    int fY = aY + 1;
    
    int kX = aX + 3;
    int kY = aY + 2;
    
    int jX = aX + 2;
    int jY = aY + 2;
    
    int gX = aX + 1;
    int gY = aY + 2;
    
    int hX = aX + 1;
    int hY = aY + 3;

    //Left Side
    int lX = aX - 1;
    int lY = aY;
    
    int mX = aX - 1;
    int mY = aY + 1;
    
    int pX = aX - 2;
    int pY = aY;
    
    int rX = aX - 2;
    int rY = aY + 2;
    
    int nX = aX - 1;
    int nY = aY + 2;
    
    int qX = aX - 2;
    int qY = aY + 1;
    
    int oX = aX - 1;
    int oY = aY + 3;
    
    int sX = aX - 3;
    int sY = aY + 1;

    bool willRotateHappen = false;
    int incX = 0;
    int incY = 0;
    if(environment->isOccupied(eX, eY)){
        if( ! ( environment->isOccupied(lX, lY) ||
                environment->isOccupied(mX, mY) ||
                environment->isOccupied(nX, nY) ||
                environment->isOccupied(oX, oY) ||
                environment->isOccupied(qX, qY) ||
                environment->isOccupied(rX, rY) ||
                environment->isOccupied(sX, sY))){
                    
                    incX = 0;
                    incY = 1;
                    willRotateHappen = true;
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
                    
                    incX = 1;
                    incY = 0;
                    willRotateHappen = true;
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
                    
                    incX = 1;
                    incY = 1;
                    willRotateHappen = true;
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
                    
                    incX = 3;
                    incY = 2;
                    willRotateHappen = true;
                }
                else{
                    //do nothing
                }
    }
    else if(environment->isOccupied(mX, mY)){
        if(! environment->isOccupied(rX, rY)){
            
            incX = 1;
            incY = 2;
            willRotateHappen = true;
        }
        else{
            //do nothing
        }
    }
    else{
        if((environment->isOccupied(qX, qY) ||
            environment->isOccupied(rX, rY))){
            if(! environment->isOccupied(iX, iY)){
                
                incX = 2;
                incY = 1;
                willRotateHappen = true;
            }
            else{
                //do nothing
            }
        }
        else{
            
            incX = 1;
            incY = 1;
            willRotateHappen = true;
        }
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
bool LongPiece::rotateRightOrientationOne(){
    int dX = cells[3].getx();
    int dY = cells[3].gety();
    
    //Bottom Side
    int eX = dX;
    int eY = dY - 1;  
    
    int iX = dX + 1;
    int iY = dY - 2;  
    
    int fX = dX + 1;
    int fY = dY - 1;  
    
    int kX = dX + 2;
    int kY = dY - 3;  
    
    int jX = dX + 2;
    int jY = dY - 2;  
    
    int gX = dX + 2;
    int gY = dY - 1;   
    
    int hX = dX + 3;
    int hY = dY - 1;

    //Top Side
    int lX = dX;
    int lY = dY + 1;    
    
    int mX = dX + 1;
    int mY = dY + 1;  
    
    int pX = dX;
    int pY = dY + 2;  
    
    int rX = dX + 2;
    int rY = dY + 2;   
    
    int nX = dX + 2;
    int nY = dY + 1;  
    
    int qX = dX + 1;
    int qY = dY + 2;  
    
    int oX = dX + 3;
    int oY = dY + 1;  
    
    int sX = dX + 1;
    int sY = dY + 3;

    bool willRotateHappen = false;
    int incX = 0;
    int incY = 0;
    if(environment->isOccupied(eX, eY)){
        if( ! ( environment->isOccupied(lX, lY) ||
                environment->isOccupied(mX, mY) ||
                environment->isOccupied(nX, nY) ||
                environment->isOccupied(oX, oY) ||
                environment->isOccupied(qX, qY) ||
                environment->isOccupied(rX, rY) ||
                environment->isOccupied(sX, sY))){
                    
                    incX = 1;
                    incY = 0;
                    willRotateHappen = true;
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
                    
                    incX = 0;
                    incY = -1;
                    willRotateHappen = true;
                }
                else{
                    //do nothing
                }
    }
    else if(environment->isOccupied(gX, gY)){
        if( ! ( environment->isOccupied(mX, mY) ||
                environment->isOccupied(nX, nY) ||
                environment->isOccupied(oX, oY))){
                    if(! environment->isOccupied(iX, iY)){
                        
                        incX = 1;
                        incY = -2;
                        willRotateHappen = true;
                    }
                    else if(! environment->isOccupied(qX, qY)){
                        
                        incX = 1;
                        incY = -1;
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
    else if(environment->isOccupied(hX, hY)){
        if(! ( environment->isOccupied(nX, nY) ||
                environment->isOccupied(oX, oY)) ){
                    if(! (environment->isOccupied(iX, iY) ||
                        environment->isOccupied(jX,jY))){
                            incX = 2;
                            incY = -2;
                            willRotateHappen = true;
                        }
                    else if(! (environment->isOccupied(qX, qY) ||
                            environment->isOccupied(rX, rY))){
                                incX = 1;
                                incY = -1;
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
    else if(environment->isOccupied(oX, oY) ||
            environment->isOccupied(nX, nY)){
        if( ! (environment->isOccupied(iX, iY) ||
                environment->isOccupied(jX, jY) ||
                environment->isOccupied(kX, kY))){
                    
                    incX = 2;
                    incY = -3;
                    willRotateHappen = true;
                }
                else{
                    //do nothing
                }
    }
    else{
        if(! (environment->isOccupied(iX, iY) ||
              environment->isOccupied(jX, jY))){
            incX = 2;
            incY = -2;
            willRotateHappen = true;
        }
        else if(! (environment->isOccupied(qX, qY) ||
                    environment->isOccupied(rX, rY))){
            
                incX = 1;
                incY = -1;
                willRotateHappen = true;
        }
        else{
            //do nothing
        }
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
bool LongPiece::rotateRightOrientationTwo(){
    int dX = cells[3].getx();
    int dY = cells[3].gety();
    
    //Left Side
    int eX = dX + 1;
    int eY = dY;
    
    int iX = dX + 2;
    int iY = dY + 1;
    
    int fX = dX + 1;
    int fY = dY + 1;
    
    int kX = dX + 3;
    int kY = dY + 2;
   
    int jX = dX + 2;
    int jY = dY + 2;
    
    int gX = dX + 1;
    int gY = dY + 2;
    
    int hX = dX + 1;
    int hY = dY + 3;

    //Right Side
    int lX = dX - 1;
    int lY = dY;
    
    int mX = dX - 1;
    int mY = dY + 1;
    
    int pX = dX - 2;
    int pY = dY;
    
    int rX = dX - 2;
    int rY = dY + 2;
    
    int nX = dX - 1;
    int nY = dY + 2;
    
    int qX = dX - 2;
    int qY = dY + 1;
    
    int oX = dX - 1;
    int oY = dY + 3;
    
    int sX = dX - 3;
    int sY = dY + 1;

    bool willRotateHappen = false;
    int incX = 0;
    int incY = 0;
    if(environment->isOccupied(eX, eY)){
        if( ! ( environment->isOccupied(lX, lY) ||
                environment->isOccupied(mX, mY) ||
                environment->isOccupied(nX, nY) ||
                environment->isOccupied(oX, oY) ||
                environment->isOccupied(qX, qY) ||
                environment->isOccupied(rX, rY) ||
                environment->isOccupied(sX, sY))){
                    
                    incX = -1;
                    incY = 1;
                    willRotateHappen = true;
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
                    
                    incX = 1;
                    incY = 0;
                    willRotateHappen = true;
                }
                else{
                    //do nothing
                }
    }
    else if(environment->isOccupied(gX, gY)){
        if( ! ( environment->isOccupied(mX, mY) ||
                environment->isOccupied(rX, rY) ||
                environment->isOccupied(nX, nY) ||
                environment->isOccupied(qX, qY) ||
                environment->isOccupied(oX, oY))){
                    if(! environment->isOccupied(iX, iY)){
                    
                    incX = 2;
                    incY = 1;
                    willRotateHappen = true;
                    }
                    else{
                        incX = 1;
                        incY = 1;
                        willRotateHappen = true;
                    }
                }
        else{
            //do nothing
        }
    }
    else if(environment->isOccupied(hX, hY)){
        if( ! ( environment->isOccupied(nX, nY) ||
                environment->isOccupied(oX, oY))){
                    if( environment->isOccupied(iX, iY) ||
                        environment->isOccupied(jX, jY)){
                        if(! environment->isOccupied(rX, rY)){
                            incX = 1;
                            incY = 2;
                            willRotateHappen = true;
                        }
                        else{
                            //do nothing
                        }
                    }else{
                        incX = 2;
                        incY = 2;
                        willRotateHappen = true;
                    }
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
                    
                    incX = 3;
                    incY = 2;
                    willRotateHappen = true;
                }
                else{
                    //do nothing
                }
    }
    else if(environment->isOccupied(iX, iY) ||
            environment->isOccupied(jX, jY)){
                if(! environment->isOccupied(rX, rY)){
                    incX = 1;
                    incY = 2;
                    willRotateHappen = true;
                }
                else{
                    //do nothing
                }
            }
    else{
        incX = 2;
        incY = 2;
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
bool LongPiece::rotateRightOrientationThree(){
    int aX = cells[0].getx();
    int aY = cells[0].gety();
    
    //Bottom Side
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
    int hY = aY - 1;

    //Top Side
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

    bool willRotateHappen = false;
    int incX = 0;
    int incY = 0;
    if(environment->isOccupied(eX, eY)){
        if( ! ( environment->isOccupied(lX, lY) ||
                environment->isOccupied(mX, mY) ||
                environment->isOccupied(nX, nY) ||
                environment->isOccupied(oX, oY) ||
                environment->isOccupied(qX, qY) ||
                environment->isOccupied(rX, rY) ||
                environment->isOccupied(sX, sY))){
                    
                    incX = 1;
                    incY = 0;
                    willRotateHappen = true;
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
        if( ! ( environment->isOccupied(mX, mY) ||
                environment->isOccupied(rX, rY) ||
                environment->isOccupied(nX, nY) ||
                environment->isOccupied(qX, qY) ||
                environment->isOccupied(oX, oY))){
                    
                    incX = 1;
                    incY = -1;
                    willRotateHappen = true;
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
                    
                    incX = 2;
                    incY = -3;
                    willRotateHappen = true;
                }
                else{
                    //do nothing
                }
    }
    else if(environment->isOccupied(mX, mY)){
        if(! environment->isOccupied(rX, rY)){
            
            incX = 2;
            incY = -1;
            willRotateHappen = true;
        }
        else{
            //do nothing
        }
    }
    else{
        if((environment->isOccupied(qX, qY) ||
            environment->isOccupied(rX, rY))){
            if(! environment->isOccupied(iX, iY)){
                
                incX = 2;
                incY = -2;
                willRotateHappen = true;
            }
            else{
                //do nothing
            }
        }
        else{
            
            incX = 1;
            incY = -1;
            willRotateHappen = true;
        }
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
void LongPiece::doRotateRight(int incX, int incY, unsigned int newOrientation){
    /* Zero    One      Two      Three
        a                d         
        b     d c b a    c       a b c d
        c                b
        d                a
    */
    if(newOrientation == 0){
        unsigned int new_aX = cells[0].getx() + incX;
        unsigned int new_aY = cells[0].gety() + incY;
        for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].erase();
        }
        for(unsigned int i = 0; i < cells.size(); i++){
            //cells[i].move(new_aX, new_aY - i);
            cells[i].move(new_aX, new_aY + i);
        }
        for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].paint();
        }
    }
    else if(newOrientation == 1){
        unsigned int new_aX = cells[0].getx() + incX;
        unsigned int new_aY = cells[0].gety() + incY;
        for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].erase();
        }
        for(unsigned int i = 0; i < cells.size(); i++){
            //cells[i].move(new_dX + i, new_dY);
            cells[i].move(new_aX - i, new_aY);
        }
        for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].paint();
        }
    }
     else if(newOrientation == 2){
        unsigned int new_dX = cells[3].getx() + incX;
        unsigned int new_dY = cells[3].gety() + incY;
        for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].erase();
        }
        for(unsigned int i = 0; i < cells.size(); i++){
            cells[cells.size() - 1 - i].move(new_dX, new_dY + i);
        }
        for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].paint();
        }
    }
     else if(newOrientation == 3){
        unsigned int new_dX = cells[3].getx() + incX;
        unsigned int new_dY = cells[3].gety() + incY;
        for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].erase();
        }
        for(unsigned int i = 0; i < cells.size(); i++){
            cells[cells.size() - 1 - i].move(new_dX - i, new_dY);
            
        }
        for(unsigned int i = 0; i < cells.size(); i++){
            cells[i].paint();
        }
    }
}
#endif