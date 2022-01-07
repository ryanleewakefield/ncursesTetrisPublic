#ifndef __APPLOGIC_HPP__
#define __APPLOGIC_HPP__

#include "KeyboardListener.hpp"
#include "IControllable.hpp"

class AppLogic : public IControllable{
public:
    AppLogic() = default;
    AppLogic(const AppLogic& rhs) = default;
    ~AppLogic() = default;
    bool sendStopSignal();
    bool virtual actionOne();
};
bool AppLogic::sendStopSignal(){
    KeyboardListener::getInstance()->stopListening();
    return true;
}
bool AppLogic::actionOne(){
    return this->sendStopSignal();
}
#endif