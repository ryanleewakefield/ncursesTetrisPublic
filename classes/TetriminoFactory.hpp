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
    TetriminoFactory(const TetriminoFactory& rhs);
    ~TetriminoFactory();
private:
    Tetrimino* next;
    Tetrimino* temp;
    GenerationAlgorithm* algo;
};

#endif