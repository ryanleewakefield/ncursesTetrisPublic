#ifndef __TETRIMINOFACTORY_HPP__
#define __TETRIMINOFACTORY_HPP__

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
    Tetrimino* next;
    Tetrimino* onDeck;
    GenerationAlgorithm* algo;
};
TetriminoFactory::TetriminoFactory(GenerationAlgorithm* ga){
    algo = ga;
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

        }
        case LEFT_L:{

        }
        case RIGHT_L:{

        }
        case LEFT_S:{

        }
        case RIGHT_S:{

        }
        case T_PIECE:{

        }
        
    }
}
#endif