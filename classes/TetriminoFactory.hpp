#ifndef __TETRIMINOFACTORY_HPP__
#define __TETRIMINOFACTORY_HPP__

#include <vector>

#include "Environment.hpp"
#include "Tetrimino.hpp"
#include "LongPiece.hpp"
#include "LeftL.hpp"
#include "RightL.hpp"
#include "LeftS.hpp"
#include "RightS.hpp"
#include "TPiece.hpp"
#include "Square.hpp"

#include "TetriminoType.hpp"
#include "GenerationAlgorithm.hpp"
#include "StartingPositions.hpp"
#include "TetriminoColors.hpp"

class TetriminoFactory{
public:
    TetriminoFactory() = default;
    TetriminoFactory(GenerationAlgorithm* ga);
    TetriminoFactory(const TetriminoFactory& rhs);
    ~TetriminoFactory();
    Tetrimino* getNextTetrimino();
    TetriminoType getOnDeckType();
    TetriminoType getNextType();
private:
    Tetrimino* setInitialTetrimino();
    Tetrimino* next;
    Tetrimino* onDeck;
    TetriminoType nextType;
    TetriminoType onDeckType;
    GenerationAlgorithm* algo;
};
TetriminoFactory::TetriminoFactory(GenerationAlgorithm* ga){
    algo = ga;
    this->setInitialTetrimino();
}
TetriminoFactory::~TetriminoFactory(){
    //Only the onDeck and algo pointers need taken care of
    delete onDeck;
    delete algo;
}
Tetrimino* TetriminoFactory::getNextTetrimino(){
    next = onDeck;
    nextType = onDeckType;
    //Setup onDeck for new Tetrimino but return next to keep the cycle going
    TetriminoType tt = algo->getType();
    onDeckType = tt;
    switch(tt){
        case LONG_PIECE:{
            onDeck = new LongPiece(Environment::getInstance(), COLOR_LONGPIECE, StartingPositions::LongPieceInitialX, StartingPositions::LongPieceInitialY);
            break;
        }
        case LEFT_L:{
            onDeck = new LeftL(Environment::getInstance(), COLOR_LEFTL, StartingPositions::LeftLInitialX, StartingPositions::LeftLInitialY);
            break;
        }
        case RIGHT_L:{
            onDeck = new RightL(Environment::getInstance(), COLOR_RIGHTL, StartingPositions::RightLInitialX, StartingPositions::RightLInitialY);
            break;
        }
        case LEFT_S:{
            onDeck = new LeftS(Environment::getInstance(), COLOR_LEFTS, StartingPositions::LeftSInitialX, StartingPositions::LeftSInitialY);
            break;
        }
        case RIGHT_S:{
            onDeck = new RightS(Environment::getInstance(), COLOR_RIGHTS, StartingPositions::RightSInitialX, StartingPositions::RightSInitialY);
            break;
        }
        case T_PIECE:{
            onDeck = new TPiece(Environment::getInstance(), COLOR_TPIECE, StartingPositions::TPieceInitialX, StartingPositions::TPieceInitialY);
            break;
        }
        case SQUARE:{
            onDeck = new Square(Environment::getInstance(), COLOR_SQUARE, StartingPositions::SquareInitialX, StartingPositions::SquareInitialY);
            break;
        }
    }
    return next;
}
Tetrimino* TetriminoFactory::setInitialTetrimino(){
    TetriminoType tt = algo->getType();
    onDeckType = tt;
    switch(tt){
        case LONG_PIECE:{
            onDeck = new LongPiece(Environment::getInstance(), COLOR_LONGPIECE, StartingPositions::LongPieceInitialX, StartingPositions::LongPieceInitialY);
            break;
        }
        case LEFT_L:{
            onDeck = new LeftL(Environment::getInstance(), COLOR_LEFTL, StartingPositions::LeftLInitialX, StartingPositions::LeftLInitialY);
            break;
        }
        case RIGHT_L:{
            onDeck = new RightL(Environment::getInstance(), COLOR_RIGHTL, StartingPositions::RightLInitialX, StartingPositions::RightLInitialY);
            break;
        }
        case LEFT_S:{
            onDeck = new LeftS(Environment::getInstance(), COLOR_LEFTS, StartingPositions::LeftSInitialX, StartingPositions::LeftSInitialY);
            break;
        }
        case RIGHT_S:{
            onDeck = new RightS(Environment::getInstance(), COLOR_RIGHTS, StartingPositions::RightSInitialX, StartingPositions::RightSInitialY);
            break;
        }
        case T_PIECE:{
            onDeck = new TPiece(Environment::getInstance(), COLOR_TPIECE, StartingPositions::TPieceInitialX, StartingPositions::TPieceInitialY);
            break;
        }
        case SQUARE:{
            onDeck = new Square(Environment::getInstance(), COLOR_SQUARE, StartingPositions::SquareInitialX, StartingPositions::SquareInitialY);
            break;
        }
    }
}
TetriminoType TetriminoFactory::getOnDeckType(){
    return onDeckType;
}
TetriminoType TetriminoFactory::getNextType(){
    return nextType;
}
#endif