#ifndef __FORMATTING_HPP__
#define __FORMATTING_HPP__

#include <string>

std::string formatStat(int stat){
    // let 999 be the max
    stat = stat % 1000;
    if(0 <= stat && stat <= 9){
        return std::string("00" + std::to_string(stat));
    }
    else if(10 <= stat && stat <= 99){
        return std::string("0" + std::to_string(stat));
    }
    else if(100 <= stat && stat <= 999){
        return std::to_string(stat);
    }
    
}

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
    minutes = minutes % 100;
    if(0 <= minutes && minutes <= 9){
        if(0 <= seconds && seconds <= 9){
            return std::string("0" + std::to_string(minutes) + ":" + "0" + std::to_string(seconds));
        }
        else{
            return std::string("0" + std::to_string(minutes) + ":" + std::to_string(seconds));
        }
    }
    else{
        if(0 <= seconds && seconds <= 9){
            return std::string(std::to_string(minutes) + ":" + "0" + std::to_string(seconds));
        }
        else{
            return std::string(std::to_string(minutes) + ":" + std::to_string(seconds));
        }
    }
    
}
#endif