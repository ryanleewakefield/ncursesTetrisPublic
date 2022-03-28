#ifndef __APPLOGIC_HPP__
#define __APPLOGIC_HPP__

#include <vector>
#include <algorithm>
#include "KeyboardListener.hpp"
#include "EventSignal.hpp"
#include "IControllable.hpp"
#include "../classes/GameDaemon.hpp"
typedef std::mutex* mutexPtr;
class AppLogic : public IControllableThree{
public:
    static AppLogic* getInstance();
    bool registerGameDaemon(GameDaemon* gameDaemon);
    bool unregisterGameDaemon(GameDaemon* gameDaemon);
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
bool AppLogic::sendStopSignal(){
    std::for_each(gameDaemons.begin(), gameDaemons.end(), [](auto e){
        e->processEventSignal(APP_QUIT);
    } );
    KeyboardListener::getInstance()->stopListening();
    return true;
    
}
bool AppLogic::actionOne(){
    return this->sendStopSignal();
}
bool AppLogic::actionTwo(){
    std::for_each(gameDaemons.begin(), gameDaemons.end(), [](auto e){
        e->processEventSignal(START_THREAD);
    } );
}
bool AppLogic::actionThree(){
    std::for_each(gameDaemons.begin(), gameDaemons.end(), [](auto e){
        e->processEventSignal(STOP_THREAD);
    } );
}
#endif