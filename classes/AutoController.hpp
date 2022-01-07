#ifndef __AUTOCONTROLLER_HPP__
#define __AUTOCONTROLLER_HPP__

#include <thread>

#include "IControllable.hpp"
#include "EventSignal.hpp"

class AutoController{
public:
    AutoController();
    AutoController(const AutoController& rhs) = delete;
    ~AutoController();
    bool virtual processEventSignal(EventSignal est) = 0;
    void virtual setControllable(IControllable* controllable) = 0;
    bool startAutoThread();
    bool waitOnAutoThread();
    bool stopAutoThread();
protected:
    virtual int runThread(bool* stop) = 0;
    IControllable* controllable;
    std::thread* autoThread;
    bool running;
    bool stop;
};
AutoController::AutoController(){
    controllable = nullptr;
    autoThread = nullptr;
    running = false;
    stop = false;
}
AutoController::~AutoController(){

}
bool AutoController::startAutoThread(){
    if(running == false){
        stop = false;
        autoThread =  new std::thread(runThread, &(this->stop));
        running = true;
        return true;
    }
    else{
        return false;
    }
}
bool AutoController::waitOnAutoThread(){
    autoThread->join();
}
#endif