#ifndef __AUTOCONTROLLER_HPP__
#define __AUTOCONTROLLER_HPP__

#include <thread>
#include <chrono>
#include <mutex>

#include "IControllable.hpp"
#include "UserController.hpp"
#include "EventSignal.hpp"
#include "ButtonSignal.hpp"

class AutoController{
public:
    AutoController();
    AutoController(const AutoController& rhs) = delete;
    ~AutoController();
    bool virtual processEventSignal(EventSignal est) = 0;
    void virtual setController(UserController* controller) = 0;
    bool startAutoThread();
    bool waitOnAutoThread();
    bool stopAutoThread();
protected:
    virtual int runThread(bool* stop) = 0;
    UserController* controller;
    std::thread* autoThread;
    bool running;
    bool stop;
};
AutoController::AutoController(){
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
bool AutoController::stopAutoThread(){
    if(running == true){
        stop = true;
        running = false;
        return true;
    }
    else{
        return false;
    }
}

class TetriminoCycle : public AutoController{
public:
    bool virtual processEventSignal(EventSignal est);
    void virtual setController(TetriminoController* controller);
    void setDelay(int delay);
private:
    virtual int runThread(TetriminoController* controllable, bool* stop, int* delay) = 0;
    TetriminoController* controller;
    int delay;
};
bool TetriminoCycle::processEventSignal(EventSignal est){
    switch(est){
        case APP_QUIT: this->stopAutoThread(); return true;
    }
}
void TetriminoCycle::setController(TetriminoController* controller){
    this->controller = controller;
}
void TetriminoCycle::setDelay(int delay){
    this->delay = delay;
}
int TetriminoCycle::runThread(TetriminoController* controller, bool* stop, int* delay){
    while(!(*stop)){
        int movesLeft = 4;
    int movesRight = 4;
    int movesUp = 4;
    int movesDown = 4;
    
    while(!(*stop)){
        std::this_thread::sleep_for(std::chrono::milliseconds(*delay));
        if(movesDown != 0){
            controller->processInputSignal(DownButton);
            movesDown--;
        }
        else if(movesLeft != 0){
            controller->processInputSignal(LeftButton);
            movesLeft--;
        }
        else if(movesUp != 0){
            controller->processInputSignal(UpButton);
            movesUp--;
        }
        else if(movesRight != 0){
            controller->processInputSignal(RightButton);
            movesRight--;
        }
        else{
            movesDown = 4;
            movesLeft = 4;
            movesUp = 4;
            movesRight = 4;
            controller->processInputSignal(DownButton);
            movesDown--;
        }
    }
    }
}
#endif