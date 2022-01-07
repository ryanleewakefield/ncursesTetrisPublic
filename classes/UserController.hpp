#ifndef __USERCONTROLLER_HPP__
#define __USERCONTROLLER_HPP__

#include "IControllable.hpp"
#include "ButtonSignal.hpp"
#include <mutex>
#include <thread>

class UserController{
public:
    UserController();
    UserController(const UserController& rhs);
    ~UserController();
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
    bool virtual processInputSignal(ButtonSignal bst);
};
bool AppController::processInputSignal(ButtonSignal bst){
    switch(bst){
        case QuitButton: controllable->actionOne(); break;
    }
}

class ScreenWriterController : public UserController{
public:
    bool virtual processInputSignal(ButtonSignal bst);
    void virtual setControllable(IControllableTwo * controllable);
protected:
    IControllableTwo* controllable;
};
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
    bool virtual processInputSignal(ButtonSignal bst);
    void virtual setControllable(ITetriminoControl* controllable);
protected:
    ITetriminoControl* controllable;
};
bool TetriminoController::processInputSignal(ButtonSignal bst){
    switch(bst){
        case UpButton :{
            unique_lock<mutex> lck {*(controllable->getMutex())};
            controllable->actionOne();
            break;
        }
        case DownButton :{
            unique_lock<mutex> lck {*(controllable->getMutex())};
            controllable->actionTwo();
            break;
        }
        case LeftButton :{
            unique_lock<mutex> lck {*(controllable->getMutex())};
            controllable->actionThree();
            break;
        }
        case RightButton :{
            unique_lock<mutex> lck {*(controllable->getMutex())};
            controllable->actionFour();
            break;
        }
        case BButton :{
            unique_lock<mutex> lck {*(controllable->getMutex())};
            controllable->actionFive();
            break;
        }
        case AButton :{
            unique_lock<mutex> lck {*(controllable->getMutex())};
            controllable->actionSix();
            break;
        }
    }
}
#endif