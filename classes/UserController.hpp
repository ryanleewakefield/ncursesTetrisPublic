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
    void setControllable(IControllable* controllable);
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

class ScreenWriterController : public UserController{
public:
    bool virtual processInputSignal(ButtonSignal bst);
};

bool ScreenWriterController::processInputSignal(ButtonSignal bst){
    switch(bst){
        case UpButton: controllable->controllerUp(); break;
        case DownButton: controllable->controllerDown(); break;
    }
}
#endif