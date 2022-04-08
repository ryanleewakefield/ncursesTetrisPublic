#ifndef __GAMEEVENTLISTENER_HPP__
#define __GAMEEVENTLISTENER_HPP__

#include <thread>
#include <atomic>
#include <condition_variable>

class GameEventListener{
public:
    static GameEventListener* getInstance();
    bool readyForGravity = false;
    bool detectedCollision = false;
    std::atomic<bool> appShouldQuit{false};
    std::mutex mux1;
    std::mutex mux2;
    // std::mutex mux3;
    std::condition_variable waitForNextCollision;
    std::condition_variable waitForNextTetrimino;
    // std::condition_variable waitForMux3;
private:
    static GameEventListener* uniqueInstance;
    GameEventListener() = default;
    GameEventListener(const GameEventListener& rhs) = default;
    ~GameEventListener();
};
GameEventListener* GameEventListener::uniqueInstance = nullptr;
GameEventListener::~GameEventListener(){
    if(uniqueInstance != nullptr){
            delete uniqueInstance;
        }
}
GameEventListener* GameEventListener::getInstance(){
    if(uniqueInstance == nullptr){
            uniqueInstance = new GameEventListener();
        }
    return uniqueInstance;
}
#endif