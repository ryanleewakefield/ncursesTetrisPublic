#ifndef __SQUARE_HPP__
#define __SQUARE_HPP__

#include <ncurses.h>
#include <string>
#include <vector>
#include <memory>

#include "Cell.hpp"
#include "Environment.hpp"
#include "Tetrimino.hpp"

class Square : public Tetrimino{
public:
    Square(Environment* env, int color, std::vector<unsigned int>& Xs, std::vector<unsigned int>& Ys)
    : Tetrimino(env, color, Xs, Ys) {}
    bool rotateLeft() override;
    bool rotateRight() override;
};
/*  Since a Square Tetrimino cannot rotate, it will never
    "successfully" rotate, so each method should return false
    when called.
*/
bool Square::rotateLeft(){ return false;}
bool Square::rotateRight(){ return false;}

#endif