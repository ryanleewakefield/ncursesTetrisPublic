#include <ncurses.h>
#include <string>
#include <vector>
#include <memory>

#include "Cell.hpp"
#include "Environment.hpp"

//Refactor bare pointers to smart pointers later
class Tetrimino{
public:
    Tetrimino(Environment* env, int color, std::vector<int>& Xs, std::vector<int>& Ys);
    Tetrimino(const Tetrimino& rhs);
    ~Tetrimino();
    bool virtual moveLeft() = 0;
    bool virtual moveRight() = 0;
    bool virtual moveDown() = 0;
    bool virtual moveUp() = 0;
    bool virtual rotateLeft() = 0;
    bool virtual rotateRight() = 0;
    bool isActive();
    void setActive(bool active);
private:
    Environment* environment;
    bool active;
    std::vector<Cell> cells;
    
};

    /*  
    The object that is responsible for generating Tetriminos knows where they will be placed.
    So this constructor can assume they are correct for any subtype.
    */
Tetrimino::Tetrimino(Environment* env, int color, std::vector<int>& Xs, std::vector<int>& Ys){
    this->environment = env;
    this->active = false;

}

class LongPiece : Tetrimino{

};

class RightL : Tetrimino{

};

class LeftL : Tetrimino{

};

class RightS : Tetrimino{

};

class Square : Tetrimino{

};