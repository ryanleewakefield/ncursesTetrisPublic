#ifndef __USERCONTROLLER_HPP__
#define __USERCONTROLLER_HPP__

#include "IControllable.hpp"
#include "ButtonSignal.hpp"
#include "EventSignal.hpp"
#include <mutex>
#include <thread>

class UserController{
public:
    UserController();
    UserController(const UserController& rhs);
    ~UserController();
    bool virtual processEventSignal(EventSignal est) = 0;
    bool virtual processInputSignal(ButtonSignal bst) = 0;
    void virtual setControllable(IControllable* controllable);
protected:
    IControllable* controllable;
};

UserController::UserController() = default;

UserController::UserController(const UserController& rhs){
    this->controllable = rhs.controllable;
}
UserController::~UserController(){
    controllable = nullptr;
}
void UserController::setControllable(IControllable* controllable){
    this->controllable = controllable;
}

class AppController : public UserController{
public:
    bool virtual processEventSignal(EventSignal est);
    bool virtual processInputSignal(ButtonSignal bst);

};
bool AppController::processEventSignal(EventSignal est){
    return false;
}
bool AppController::processInputSignal(ButtonSignal bst){
    switch(bst){
        case QuitButton: controllable->actionOne(); break;
    }
}

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
        switch(bst){
            case UpButton :{
                std::unique_lock<std::mutex> lck {*(controllable->getMutex())};
                return controllable->actionOne();
            }
            case DownButton :{
                std::unique_lock<std::mutex> lck {*(controllable->getMutex())};
                return controllable->actionTwo();
            }
            case LeftButton :{
                std::unique_lock<std::mutex> lck {*(controllable->getMutex())};
                return controllable->actionThree();
            }
            case RightButton :{
                std::unique_lock<std::mutex> lck {*(controllable->getMutex())};
                return controllable->actionFour();
            }
            case BButton :{
                std::unique_lock<std::mutex> lck {*(controllable->getMutex())};
                return controllable->actionFive();
            }
            case AButton :{
                std::unique_lock<std::mutex> lck {*(controllable->getMutex())};
                return controllable->actionSix(); 
            }
        }
    }
}
void TetriminoController::setControllable(ITetriminoControl* controllable){
    this->controllable = controllable;
}
#endif