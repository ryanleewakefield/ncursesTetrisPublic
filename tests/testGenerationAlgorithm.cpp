#include <iostream>
#include <ncurses.h>
#include <string>
#include <thread>
#include <mutex>
#include <memory>
#include <chrono>

#include "../classes/GenerationAlgorithm.hpp"
using namespace std;

int testGenerationAlgorithm(){
    //get 10 values from generator and output them to console
    GenerationAlgorithm* ga = new UniformGeneration();
    for(int i = 0; i < 10; i++){
        cout << ga->getType() << endl;
    }
    delete ga;
}