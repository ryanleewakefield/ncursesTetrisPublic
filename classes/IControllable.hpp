#ifndef __ICONTROLLABLE_HPP__
#define __ICONTROLLABLE_HPP__

class IControllable{
public:
    bool virtual controllerUp() = 0;
    bool virtual controllerDown() = 0;
    // bool virtual controllerRight() = 0;
    // bool virtual controllerLeft() = 0;
    // bool virtual controllerAButton() = 0;
    // bool virtual controllerBButton() = 0;
    // bool virtual controllerStartButton() = 0;
    // bool virtual controllerSelectButton() = 0;
};

#endif