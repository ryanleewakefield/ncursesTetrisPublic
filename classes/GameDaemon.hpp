#ifndef __GAMEDAEMON_HPP__
#define __GAMEDAEMON_HPP__

#include <thread>
#include <chrono>
#include <mutex>

#include "GameEventListener.hpp"
#include "IControllable.hpp"
#include "UserController.hpp"
#include "EventSignal.hpp"
#include "ButtonSignal.hpp"
#include "TetriminoController.hpp"

class GameDaemon{
public:
    GameDaemon();
    GameDaemon(const GameDaemon& rhs) = delete;
    ~GameDaemon();
    bool virtual processEventSignal(EventSignal est) = 0;
    void virtual setController(UserController* controller);
    bool virtual startAutoThread() = 0;
    bool waitOnAutoThread();
    bool stopAutoThread();
    bool cleanUpThread();
protected:
    static int runThread(bool* stop);
    UserController* controller;
    std::thread* autoThread;
    bool running;
    bool stop;
};
GameDaemon::GameDaemon(){
    autoThread = nullptr;
    running = false;
    stop = false;
}
GameDaemon::~GameDaemon(){

}
void GameDaemon::setController(UserController* controller){
    this->controller = controller;
}
bool GameDaemon::startAutoThread(){
    if(running == false){
        stop = false;
        autoThread =  new std::thread(GameDaemon::runThread, &stop);
        running = true;
        return true;
    }
    else{
        return false;
    }
}
bool GameDaemon::waitOnAutoThread(){
    autoThread->join();
}
bool GameDaemon::stopAutoThread(){
    if(running == true){
        stop = true;
        running = false;
        
        return true;
    }
    else{
        return false;
    }
}
bool GameDaemon::cleanUpThread(){
    delete autoThread; 
    autoThread = nullptr;
}
int GameDaemon::runThread(bool* stop){
    //do nothing
    // Need to find a way to make this static method
    // a pure virtual function i.e. ensure that a subclass
    // writes a function for this.
    
}

/*
    **************************************************************
    **************************************************************
*/
class TetriminoCycle : public GameDaemon{
public:
    bool virtual processEventSignal(EventSignal est);
    void virtual setController(TetriminoController* controller);
    bool virtual startAutoThread() override;
    void setDelay(int delay);
private:
    static int runThread(TetriminoController* controllable, bool* stop, int* delay);
    TetriminoController* controller;
    int delay;
};
bool TetriminoCycle::processEventSignal(EventSignal est){
    switch(est){
        case APP_QUIT: this->stopAutoThread(); return true;
        case START_THREAD:{
            if(!running){
                this->startAutoThread();
                
            }
        }break;
        case STOP_THREAD:{
            if(running){
            this->stopAutoThread();
            this->waitOnAutoThread();
            this->cleanUpThread();
            }
        }break;
    }
}
bool TetriminoCycle::startAutoThread(){
    if(running == false){
        stop = false;
        autoThread =  new std::thread(TetriminoCycle::runThread, controller, &stop, &delay);
        running = true;
        return true;
    }
    else{
        return false;
    }
}
void TetriminoCycle::setController(TetriminoController* controller){
    this->controller = controller;
}
void TetriminoCycle::setDelay(int delay){
    this->delay = delay;
}
int TetriminoCycle::runThread(TetriminoController* controller, bool* stop, int* delay){
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


class GravityCycle : public GameDaemon{
public:
    bool virtual processEventSignal(EventSignal est);
    void virtual setController(TetriminoController* controller);
    bool virtual startAutoThread() override;
    void setDelay(int delay);
    void increaseLevel();
    int getLevel();
private:
    static int runThread(TetriminoController* controllable, bool* stop, int* delay);
    TetriminoController* controller;
    int delay = 500;
    int level = 0;
    int levels[16] = {500,450,400,350,325,300,275,250,225,200,180,160,140,120,100,80};
};
bool GravityCycle::processEventSignal(EventSignal est){
    switch(est){
        case APP_QUIT: this->stopAutoThread(); return true;
        case START_THREAD:{
            if(!running){
                this->startAutoThread();
                
            }
        }return true;
        case STOP_THREAD:{
            if(running){
            this->stopAutoThread();
            this->waitOnAutoThread();
            this->cleanUpThread();
            }
        }return true;
    }
}
bool GravityCycle::startAutoThread(){
    if(running == false){
        stop = false;
        autoThread =  new std::thread(GravityCycle::runThread, controller, &stop, &delay);
        running = true;
        return true;
    }
    else{
        return false;
    }
}
void GravityCycle::setController(TetriminoController* controller){
    this->controller = controller;
}
void GravityCycle::setDelay(int delay){
    this->delay = delay;
}
void GravityCycle::increaseLevel(){
    if(level < 15){
        level += 1;
        setDelay(levels[level]);
    }
}
int GravityCycle::getLevel(){
    return level;
}
int GravityCycle::runThread(TetriminoController* controller, bool* stop, int* delay){
    GameEventListener* ref = GameEventListener::getInstance();
    while(!(*stop)){

        std::this_thread::sleep_for(std::chrono::milliseconds(*delay));
        bool fail = !controller->processInputSignal(DownButton_Conditional);
        if(fail){
            
            std::unique_lock<std::mutex> lck(ref->mux1);
            
            ref->detectedCollision = true;
            ref->waitForNextCollision.notify_one();
            ref->waitForNextTetrimino.wait(lck, [&] 
                {return ref->readyForGravity;});
            ref->readyForGravity = false;
        }
    }  
}
#endif