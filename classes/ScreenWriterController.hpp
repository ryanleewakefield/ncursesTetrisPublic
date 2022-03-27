#ifndef __SCREENWRITERCONTROLLER_HPP__
#define __SCREENWRITERCONTROLLER_HPP__

#include "IControllable.hpp"
#include "ButtonSignal.hpp"
#include "EventSignal.hpp"
#include "UserController.hpp"
#include <mutex>
#include <thread>

class ScreenWriterController : public UserController{
public:
    bool virtual processEventSignal(EventSignal est);
    bool virtual processInputSignal(ButtonSignal bst);
    void virtual setControllable(IControllableTwo * controllable);
protected:
    IControllableTwo* controllable;
};
bool ScreenWriterController::processEventSignal(EventSignal est){
    return false;
}
bool ScreenWriterController::processInputSignal(ButtonSignal bst){
    switch(bst){
        case UpButton: controllable->actionOne(); break;
        case DownButton: controllable->actionTwo(); break;
    }
}
void ScreenWriterController::setControllable(IControllableTwo* controllable){
    this->controllable = controllable;
}
#endif