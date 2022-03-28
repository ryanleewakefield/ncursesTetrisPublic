#ifndef __GENERATIONALGORITHM_HPP__
#define __GENERATIONALGORITHM_HPP__

#include <random>

#include "TetriminoType.hpp"

class GenerationAlgorithm{
public:
    GenerationAlgorithm() = default;
    GenerationAlgorithm(const GenerationAlgorithm& rhs) = default;
    ~GenerationAlgorithm() = default;
    virtual TetriminoType getType() = 0;
};

class UniformGeneration : public GenerationAlgorithm{
public:
    UniformGeneration();
    ~UniformGeneration();
    virtual TetriminoType getType();
private:
    std::random_device* rd;
    std::mt19937* gen;
    std::uniform_int_distribution<int>* distrib;
};
UniformGeneration::UniformGeneration(){
    rd = new std::random_device();
    gen = new std::mt19937((*rd)());
    distrib = new std::uniform_int_distribution<int>(0,6);
}
UniformGeneration::~UniformGeneration(){
    delete rd;
    delete gen;
    delete distrib;
}
TetriminoType UniformGeneration::getType(){
    TetriminoType tt = static_cast<TetriminoType>((*distrib)(*gen));
    return tt;
}
#endif