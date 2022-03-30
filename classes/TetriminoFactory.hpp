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

class TetriminoFactory{
public:
    TetriminoFactory() = default;
    TetriminoFactory(GenerationAlgorithm* ga);
    TetriminoFactory(const TetriminoFactory& rhs);
    ~TetriminoFactory();
    Tetrimino* getNextTetrimino();
private:
    Tetrimino* setInitialTetrimino();
    Tetrimino* next;
    Tetrimino* onDeck;
    GenerationAlgorithm* algo;
    std::vector<unsigned int> LongPieceInitialX{11,11,11,11};
    std::vector<unsigned int> LongPieceInitialY{0,1,2,3};
    std::vector<unsigned int> LeftLInitialX{11,11,11,12};
    std::vector<unsigned int> LeftLInitialY{0,1,2,2};
    std::vector<unsigned int> RightLInitialX{11,11,11,10};
    std::vector<unsigned int> RightLInitialY{0,1,2,2};
    std::vector<unsigned int> LeftSInitialX{10,11,11,12};
    std::vector<unsigned int> LeftSInitialY{1,1,0,0};
    std::vector<unsigned int> RightSInitialX{10,11,11,12};
    std::vector<unsigned int> RightSInitialY{0,0,1,1};
    std::vector<unsigned int> TPieceInitialX{10,11,11,12};
    std::vector<unsigned int> TPieceInitialY{1,0,1,1};
    std::vector<unsigned int> SquareInitialX{10,11,10,11};
    std::vector<unsigned int> SquareInitialY{0,0,1,1};
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
    //Setup onDeck for new Tetrimino but return next to keep the cycle going
    TetriminoType tt = algo->getType();
    switch(tt){
        case LONG_PIECE:{
            onDeck = new LongPiece(Environment::getInstance(), COLOR_WHITE, LongPieceInitialX, LongPieceInitialY);
            break;
        }
        case LEFT_L:{
            onDeck = new LeftL(Environment::getInstance(), COLOR_BLUE, LeftLInitialX, LeftLInitialY);
            break;
        }
        case RIGHT_L:{
            onDeck = new RightL(Environment::getInstance(), COLOR_RED, RightLInitialX, RightLInitialY);
            break;
        }
        case LEFT_S:{
            onDeck = new LeftS(Environment::getInstance(), COLOR_CYAN,LeftSInitialX, LeftSInitialY);
            break;
        }
        case RIGHT_S:{
            onDeck = new RightS(Environment::getInstance(), COLOR_GREEN, RightSInitialX, RightSInitialY);
            break;
        }
        case T_PIECE:{
            onDeck = new TPiece(Environment::getInstance(), COLOR_MAGENTA, TPieceInitialX, TPieceInitialY);
            break;
        }
        case SQUARE:{
            onDeck = new Square(Environment::getInstance(), COLOR_YELLOW, SquareInitialX, SquareInitialY);
            break;
        }
    }
    return next;
}
Tetrimino* TetriminoFactory::setInitialTetrimino(){
    TetriminoType tt = algo->getType();
    switch(tt){
        case LONG_PIECE:{
            onDeck = new LongPiece(Environment::getInstance(), COLOR_WHITE, LongPieceInitialX, LongPieceInitialY);
            break;
        }
        case LEFT_L:{
            onDeck = new LeftL(Environment::getInstance(), COLOR_BLUE, LeftLInitialX, LeftLInitialY);
            break;
        }
        case RIGHT_L:{
            onDeck = new RightL(Environment::getInstance(), COLOR_RED, RightLInitialX, RightLInitialY);
            break;
        }
        case LEFT_S:{
            onDeck = new LeftS(Environment::getInstance(), COLOR_CYAN,LeftSInitialX, LeftSInitialY);
            break;
        }
        case RIGHT_S:{
            onDeck = new RightS(Environment::getInstance(), COLOR_GREEN, RightSInitialX, RightSInitialY);
            break;
        }
        case T_PIECE:{
            onDeck = new TPiece(Environment::getInstance(), COLOR_MAGENTA, TPieceInitialX, TPieceInitialY);
            break;
        }
        case SQUARE:{
            onDeck = new Square(Environment::getInstance(), COLOR_YELLOW, SquareInitialX, SquareInitialY);
            break;
        }
    }
}
#endif