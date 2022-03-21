#ifndef __APPLOGIC_HPP__
#define __APPLOGIC_HPP__

#include <vector>
#include <algorithm>
#include "KeyboardListener.hpp"
#include "EventSignal.hpp"
#include "IControllable.hpp"
#include "../classes/GameDaemon.hpp"

class AppLogic : public IControllable{
public:
    AppLogic() = default;
    AppLogic(const AppLogic& rhs) = default;
    ~AppLogic() = default;
    bool registerGameDaemon(GameDaemon* gameDaemon);
    bool unregisterGameDaemon(GameDaemon* gameDaemon);
    bool sendStopSignal();
    bool virtual actionOne();
private:
    std::vector<GameDaemon*> gameDaemons;
};
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
    //Didn't find registered UserControlller
    return false;
}
bool AppLogic::sendStopSignal(){
    std::for_each(gameDaemons.begin(), gameDaemons.end(), [](auto e){
        e->processEventSignal(APP_QUIT);
    } );

    // for(unsigned int i = 0; i < this->gameDaemons.size(); i++){
    //     gameDaemons[i].processEventSignal(APP_QUIT);
    // }
    KeyboardListener::getInstance()->stopListening();
    return true;
}
bool AppLogic::actionOne(){
    return this->sendStopSignal();
}

#endif