#ifndef __ICONTROLLABLE_HPP__
#define __ICONTROLLABLE_HPP__

#include <mutex>

//Needed for intellsense nonsense
typedef  mutex* mutexPtr;
/*
    bool virtual controllerUp() = 0;
    bool virtual controllerDown() = 0;
    bool virtual controllerRight() = 0;
    bool virtual controllerLeft() = 0;
    bool virtual controllerAButton() = 0;
    bool virtual controllerBButton() = 0;
    bool virtual controllerStartButton() = 0;
    bool virtual controllerSelectButton() = 0;
*/
class IControllable{
public:
    
    bool virtual actionOne() = 0;
};

class IControllableTwo : public IControllable{
public:
    bool virtual actionOne() = 0;
    bool virtual actionTwo() = 0;
};

class ITetriminoControl : public IControllable{
public:
    mutexPtr virtual getMutex() = 0;
    bool virtual actionOne() = 0;
    bool virtual actionTwo() = 0;
    bool virtual actionThree() = 0;
    bool virtual actionFour() = 0;
    bool virtual actionFive() = 0;
    bool virtual actionSix() = 0;
};
#endif