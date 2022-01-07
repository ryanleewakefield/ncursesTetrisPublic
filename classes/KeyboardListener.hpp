#ifndef __KEYBOARDLISTENER_HPP__
#define __KEYBOARDLISTENER_HPP__

#include <vector>
#include <thread>



#include "UserController.hpp"
#include "ButtonSignal.hpp"


class KeyboardListener{
public:
    static KeyboardListener* getInstance();
    static bool freeInstance();
    bool registerController(UserController * userController);
    bool unRegisterController(UserController * userController);
    bool startListening();
    bool waitOnListener();
    bool stopListening();
private:
    static const int BLOCKING_READ = -1;
    static const int ONE_FRAME = 30;
    static KeyboardListener* uniqueInstance;
    static int runThread(bool* stop, WINDOW* ep);
    KeyboardListener();
    KeyboardListener(const KeyboardListener& rhs);
    ~KeyboardListener();
    void notify(ButtonSignal bst);
    WINDOW* entryPoint;
    std::vector<UserController*> controllers;
    std::thread* listeningThread;
    bool running;
    bool stop;

};
KeyboardListener* KeyboardListener::uniqueInstance = nullptr;

KeyboardListener* KeyboardListener::getInstance(){
    if(uniqueInstance == nullptr){
        uniqueInstance = new KeyboardListener();
    }
    return uniqueInstance;
}

int KeyboardListener::runThread(bool* stop, WINDOW* ep){
    char c;
    while(!(*stop)){
        c = wgetch(ep);
        switch(c){
            case 'w': KeyboardListener::getInstance()->notify(UpButton); break;
            case 's': KeyboardListener::getInstance()->notify(DownButton); break;
            case 'a': KeyboardListener::getInstance()->notify(LeftButton); break;
            case 'd': KeyboardListener::getInstance()->notify(RightButton); break;
            case 'q': KeyboardListener::getInstance()->notify(QuitButton); break;
        }
    }
}
KeyboardListener::KeyboardListener(){
    listeningThread = nullptr;
    running = false;
    stop = true;
    entryPoint = newwin(0,0,0,0);
    keypad(entryPoint, true);
    wtimeout(entryPoint, ONE_FRAME);
}
KeyboardListener::~KeyboardListener(){
    delwin(entryPoint);
}
bool KeyboardListener::registerController(UserController* userController){
    //Check if already registered
    for(unsigned int i = 0; i < this->controllers.size(); i++){
        if(userController == controllers[i]){
            return false;
        }
    }
    controllers.push_back(userController);
    return true;
}
bool KeyboardListener::unRegisterController(UserController* userController){
    //Check if registered
    for(unsigned int i = 0; i < this->controllers.size(); i++){
        if(userController == controllers[i]){
            controllers[i] = nullptr;
            return true;
        }
    }
    //Didn't find registered UserControlller
    return false;
}
bool KeyboardListener::startListening(){
    if(running == false){
        stop = false;
        listeningThread =  new std::thread(KeyboardListener::runThread, &(this->stop), entryPoint);
        running = true;
        return true;
    }
    else{
        return false;
    }
}
bool KeyboardListener::waitOnListener(){
    listeningThread->join();
}
bool KeyboardListener::stopListening(){
    if(running == true){
        stop = true;
        running = false;
        return true;
    }
    else{
        return false;
    }
}
void KeyboardListener::notify(ButtonSignal bst){
    for(unsigned int i = 0; i < controllers.size(); i++){
        if(controllers[i] != nullptr){
            controllers[i]->processInputSignal(bst);
        }
    }
}
#endif