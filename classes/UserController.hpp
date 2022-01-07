#ifndef __USERCONTROLLER_HPP__
#define __USERCONTROLLER_HPP__

#include "IControllable.hpp"
#include "ButtonSignal.hpp"

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
#endif