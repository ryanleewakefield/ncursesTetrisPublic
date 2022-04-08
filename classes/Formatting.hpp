#ifndef __FORMATTING_HPP__
#define __FORMATTING_HPP__

#include <string>

std::string formatLevelAndLines(int lv){
    if(0 <= lv && lv <= 9){
        return std::string(" " + std::to_string(lv));
    }
    else if(10 <= lv && lv <= 15){
        return std::to_string(lv);
    }
    return std::string("EE");
}

std::string formatSecondsToTime(int secs){
    int minutes = secs / 60;
    int seconds = secs % 60;
    // let 99 minutes be the limit
    while(minutes > 99){
        minutes = minutes - 99;
    }
    return std::string(std::to_string(minutes) + ":" + std::to_string(seconds));
}
#endif