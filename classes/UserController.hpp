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

UserController::UserController(){ controllable = nullptr;}

UserController::UserController(const UserController& rhs){
    this->controllable = rhs.controllable;
}
UserController::~UserController(){
    controllable = nullptr;
}
void UserController::setControllable(IControllable* controllable){
    this->controllable = controllable;
}


#endif