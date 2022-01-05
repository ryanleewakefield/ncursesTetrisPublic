#ifndef __ENVIRONMENT_HPP__
#define __ENVIRONMENT_HPP__

#include <ncurses.h>
#include <vector>
#include <memory>
#include "Cell.hpp"
// A shared smart pointer would work well with this class
class Environment{
public:
    static Environment* getInstance();
    static bool freeInstance();
    bool isOccupied(unsigned int x, unsigned int y);
    bool legalMove(std::vector<unsigned int>& Xs, std::vector<unsigned int>& Ys);
    bool occupySpace(unsigned int x, unsigned int y);
    void addCell(std::unique_ptr<Cell> cellptr);
private:
    static Environment* uniqueInstance;
    const static unsigned int total_spaces = 576;
    const static unsigned int minX = 8;
    const static unsigned int minY = 8;
    const static unsigned int maxX = 32;
    const static unsigned int maxY = 32;
    WINDOW* boundaryElement;
    std::vector<bool> spaces;
    std::vector<std::unique_ptr<Cell>> cells;
    Environment();
    Environment(const Environment& rhs);
    ~Environment();
    void paintBoundary();
    int xyToIndex(unsigned int x, unsigned y);

};
Environment* Environment::uniqueInstance = nullptr;

Environment* Environment::getInstance(){
    if(uniqueInstance == nullptr){
        uniqueInstance = new Environment();
    }
    return uniqueInstance;
}
bool Environment::freeInstance(){
    if(uniqueInstance != nullptr){
        delete uniqueInstance;
        return true;
    }
    else{
        return false;
    }
}
Environment::Environment(){
    this->spaces = std::vector<bool>(total_spaces);
    this->cells = std::vector<std::unique_ptr<Cell>>(total_spaces);
    this->boundaryElement = newwin(26,50,7,13);
    paintBoundary();
}
Environment::~Environment(){
    delwin(boundaryElement);
}
void Environment::paintBoundary(){
    init_pair(1, COLOR_WHITE, COLOR_WHITE);
    wattron(boundaryElement, COLOR_PAIR(1));
    for(int i = 0; i < 26; i++){
        mvwaddch(boundaryElement, i, 0, ' ');
        mvwaddch(boundaryElement, i, 49, ' ');
    }
    for(int i = 0; i < 50; i++){
        mvwaddch(boundaryElement, 25, i, ' ');
    }
    wattroff(boundaryElement, COLOR_PAIR(1));
    wrefresh(boundaryElement);
}
bool Environment::legalMove(std::vector<unsigned int>& Xs, std::vector<unsigned int>& Ys){
    bool okay = true;
    int index = -1;
    for(unsigned int i = 0; i < Xs.size(); i++){
        index = xyToIndex(Xs[i], Ys[i]);
        if(index != -1){
            okay = okay && !spaces[index];
        }
        else{
            return false;// Since an index of -1 means the move 
                         // would be out of bounds
        }
    }
    return okay;
}

// This function needs to do bounds checking
// This function returns a valid Index upon valid x and y
// Otherwise this function return -1
int Environment::xyToIndex(unsigned int x, unsigned int y){
    if( (minX <= x && x <= maxX) && (minY <= y && y <= maxY)){
        return 24 * y + x;
    }
    else{
        return -1;
    }
}

bool Environment::isOccupied(unsigned int x, unsigned int y){
    int index = this->xyToIndex(x,y);
    if(index != -1){
        return this->spaces[index];
    }
    // In the case of index == -1,
    // the out-of-bounds space should be
    // reported as occupied, as this
    // will follow any logic down the line
    return true;
}

bool Environment::occupySpace(unsigned int x, unsigned int y){
    int index;
    if(this->isOccupied(x,y)) {
        return false;
    }
    else if((index = this->xyToIndex(x,y)) == -1){
        return false;
    }
    else{
        spaces[index] = true;
        return true;
    }
    //This below should never occur
    return false;
}
void Environment::addCell(std::unique_ptr<Cell> cellptr){
    int x = cellptr->getx();
    int y = cellptr->gety();
    if(this->occupySpace(x,y)){
        cells[this->xyToIndex(x,y)] = move(cellptr);
    }
}
#endif