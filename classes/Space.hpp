#ifndef __SPACE_HPP__
#define __SPACE_HPP__
class Space{
public:
    explicit Space(){
        occupied = false;
        color = 0;
        x = 0;
        y = 0;
        toBeCleared = false;
        adjustLevel = 0;
    }
    Space(bool o, int c, int px, int py, bool t, int a): 
    occupied(o), 
    color(c),
    x(px),
    y(py),
    toBeCleared(t),
    adjustLevel(a){}
    //member variables
    bool occupied;
    int color;
    int x;
    int y;
    bool toBeCleared;
    int adjustLevel;
};

#endif