#ifndef __TETRIMINOCONTROLLER_HPP__
#define __TETRIMINOCONTROLLER_HPP__

#include "IControllable.hpp"
#include "ButtonSignal.hpp"
#include "EventSignal.hpp"
#include "UserController.hpp"
#include <mutex>
#include <thread>

class TetriminoController : public UserController{
public:
    bool virtual processEventSignal(EventSignal est);
    bool virtual processInputSignal(ButtonSignal bst);
    void virtual setControllable(ITetriminoControl* controllable);
protected:
    ITetriminoControl* controllable;
};
bool TetriminoController::processEventSignal(EventSignal est){
    if(controllable != nullptr){
        switch(est){
            case GRAVITY_THREAD_STOPPED:{
                // The Tetrimino should get destroyed
                std::unique_lock<std::mutex> lck{*(controllable->getMutex())};
                controllable->sendEvent(GRAVITY_THREAD_STOPPED);
                delete controllable;
                controllable = nullptr;
            }
        }
    }
}
bool TetriminoController::processInputSignal(ButtonSignal bst){
    if(controllable != nullptr){
        std::unique_lock<std::mutex> lck {*(controllable->getMutex())};
        switch(bst){
            case UpButton :{
                return controllable->actionOne();
            }
            case DownButton :{
                return controllable->actionTwo();
            }
            case LeftButton :{
                return controllable->actionThree();
            }
            case RightButton :{
                return controllable->actionFour();
            }
            case BButton :{
                return controllable->actionFive();
            }
            case AButton :{
                return controllable->actionSix(); 
            }
        }
    }
}
void TetriminoController::setControllable(ITetriminoControl* controllable){
    this->controllable = controllable;
}
#endif