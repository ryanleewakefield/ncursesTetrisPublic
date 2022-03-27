#ifndef __APPCONTROLLER_HPP__
#define __APPCONTROLLER_HPP__

#include "IControllable.hpp"
#include "ButtonSignal.hpp"
#include "EventSignal.hpp"
#include "UserController.hpp"
#include <mutex>
#include <thread>

class AppController : public UserController{
public:
    bool virtual processEventSignal(EventSignal est);
    bool virtual processInputSignal(ButtonSignal bst);
    void virtual setControllable(IControllableThree* controllable);
protected:
    IControllableThree* controllable;
};
bool AppController::processEventSignal(EventSignal est){
    return false;
}
bool AppController::processInputSignal(ButtonSignal bst){
    switch(bst){
        case QuitButton:
            controllable->actionOne(); 
            break;
        case StartThread: 
            controllable->actionTwo(); 
            break;
        case StopThread: 
            controllable->actionThree(); 
            break;
    }
}
void AppController::setControllable(IControllableThree* controllable){
    this->controllable = controllable;
}
#endif