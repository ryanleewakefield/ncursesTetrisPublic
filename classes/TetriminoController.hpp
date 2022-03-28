#ifndef __TETRIMINOCONTROLLER_HPP__
#define __TETRIMINOCONTROLLER_HPP__

#include "AppLogic.hpp"
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
            case DownButton_Conditional :{
                return controllable->sendEvent(DETECT_COLLISION);
            }
        }
    }
}
void TetriminoController::setControllable(ITetriminoControl* controllable){
    this->controllable = controllable;
}
#endif