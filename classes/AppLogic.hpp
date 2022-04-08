#ifndef __APPLOGIC_HPP__
#define __APPLOGIC_HPP__

#include <vector>
#include <algorithm>
#include "KeyboardListener.hpp"
#include "EventSignal.hpp"
#include "IControllable.hpp"
#include "../classes/GameDaemon.hpp"
#include "TetriminoController.hpp"
#include "GameEventListener.hpp"
typedef std::mutex* mutexPtr;
class AppLogic : public IControllableThree{
public:
    static AppLogic* getInstance();
    bool registerGameDaemon(GameDaemon* gameDaemon);
    bool unregisterGameDaemon(GameDaemon* gameDaemon);
    void setTetriminoController(TetriminoController* tcPtr);
    bool sendStopSignal();
    bool virtual actionOne();
    bool virtual actionTwo();
    bool virtual actionThree();
private:
    static AppLogic* uniqueInstance;
    AppLogic() = default;
    AppLogic(const AppLogic& rhs) = default;
    ~AppLogic();
    std::vector<GameDaemon*> gameDaemons;
    bool paused = false;
    TetriminoController* tcPtr = nullptr;
};

AppLogic* AppLogic::uniqueInstance = nullptr;
AppLogic::~AppLogic(){
    if(uniqueInstance != nullptr){
            delete uniqueInstance;
        }
}
AppLogic* AppLogic::getInstance(){
    if(uniqueInstance == nullptr){
        uniqueInstance = new AppLogic();
    }
    return uniqueInstance;
}

bool AppLogic::registerGameDaemon(GameDaemon* gameDaemon){
    //Check if already registered
    for(unsigned int i = 0; i < this->gameDaemons.size(); i++){
        if(gameDaemon == gameDaemons[i]){
            return false;
        }
    }
    gameDaemons.push_back(gameDaemon);
    return true;
}
bool AppLogic::unregisterGameDaemon(GameDaemon* gameDaemon){
    //Check if registered
    for(unsigned int i = 0; i < this->gameDaemons.size(); i++){
        if(gameDaemon == gameDaemons[i]){
            gameDaemons[i] = nullptr;
            return true;
        }
    }
    //Didn't find registered GameDaemon
    return false;
}
void AppLogic::setTetriminoController(TetriminoController* tcPtr){
    this->tcPtr = tcPtr;
}
bool AppLogic::sendStopSignal(){
    std::for_each(gameDaemons.begin(), gameDaemons.end(), [](auto e){
        e->processEventSignal(APP_QUIT);
    } );
    GameEventListener::getInstance()->appShouldQuit = true;
    GameEventListener::getInstance()->waitForNextCollision.notify_one();
    KeyboardListener::getInstance()->stopListening();
    return true;
    
}
bool AppLogic::actionOne(){
    return this->sendStopSignal();
}
bool AppLogic::actionTwo(){
    if(!paused){
        //First, unregister tc from keyboardListener...
        KeyboardListener::getInstance()->unRegisterController(tcPtr);
        //Then, stop all GameDaemon threads
        std::for_each(gameDaemons.begin(), gameDaemons.end(), [](auto e){
            e->processEventSignal(STOP_THREAD);
        } );
        paused = true;
        return true;
    }
    else{
        //First, register tc from keyboardListener...
        KeyboardListener::getInstance()->registerController(tcPtr);
        //Then, start all GameDaemon threads
        std::for_each(gameDaemons.begin(), gameDaemons.end(), [](auto e){
            e->processEventSignal(START_THREAD);
        } );
        paused = false;
        return true;
    }
    return false;
}
bool AppLogic::actionThree(){
    return true;// do nothing for now...
}
#endif