#ifndef __STARTINGPOSITIONS_HPP__
#define __STARTINGPOSITIONS_HPP__
#include <vector>
class StartingPositions{
public:
    static std::vector<unsigned int> LongPieceInitialX; 
    static std::vector<unsigned int> LongPieceInitialY;
    static std::vector<unsigned int> LeftLInitialX;
    static std::vector<unsigned int> LeftLInitialY;
    static std::vector<unsigned int> RightLInitialX;
    static std::vector<unsigned int> RightLInitialY;
    static std::vector<unsigned int> LeftSInitialX;
    static std::vector<unsigned int> LeftSInitialY;
    static std::vector<unsigned int> RightSInitialX;
    static std::vector<unsigned int> RightSInitialY;
    static std::vector<unsigned int> TPieceInitialX;
    static std::vector<unsigned int> TPieceInitialY;
    static std::vector<unsigned int> SquareInitialX;
    static std::vector<unsigned int> SquareInitialY;
};

std::vector<unsigned int> StartingPositions::LongPieceInitialX{8,8,8,8};
std::vector<unsigned int> StartingPositions::LongPieceInitialY{0,1,2,3};
std::vector<unsigned int> StartingPositions::LeftLInitialX{8,8,8,9};
std::vector<unsigned int> StartingPositions::LeftLInitialY{0,1,2,2};
std::vector<unsigned int> StartingPositions::RightLInitialX{8,8,8,7};
std::vector<unsigned int> StartingPositions::RightLInitialY{0,1,2,2};
std::vector<unsigned int> StartingPositions::LeftSInitialX{7,8,8,9};
std::vector<unsigned int> StartingPositions::LeftSInitialY{1,1,0,0};
std::vector<unsigned int> StartingPositions::RightSInitialX{7,8,8,9};
std::vector<unsigned int> StartingPositions::RightSInitialY{0,0,1,1};
std::vector<unsigned int> StartingPositions::TPieceInitialX{7,8,8,9};
std::vector<unsigned int> StartingPositions::TPieceInitialY{1,0,1,1};
std::vector<unsigned int> StartingPositions::SquareInitialX{7,8,7,8};
std::vector<unsigned int> StartingPositions::SquareInitialY{0,0,1,1};
#endif