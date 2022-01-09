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
    static int getXOffset();
    static int getYOffset();
private:
    static Environment* uniqueInstance;
    const static unsigned int total_spaces = 576;
    const static unsigned int minX = 0;
    const static unsigned int minY = 0;
    const static unsigned int maxX = 23;
    const static unsigned int maxY = 23;
    const static unsigned int xOffsetStart = 7;
    const static unsigned int yOffsetStart = 7;
    const static unsigned int xOffsetEnd = 31;
    const static unsigned int yOffsetEnd = 31;
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
        uniqueInstance = nullptr;
        return true;
    }
    else{
        return false;
    }
}
int Environment::getXOffset(){return xOffsetStart;}
int Environment::getYOffset(){return yOffsetStart;}

Environment::Environment(){
    this->spaces = std::vector<bool>(total_spaces);
    this->cells = std::vector<std::unique_ptr<Cell>>(total_spaces);
    this->boundaryElement = newwin(25,54,7,13);
    paintBoundary();
}
Environment::~Environment(){
    delwin(boundaryElement);
}
void Environment::paintBoundary(){
    init_pair(1, COLOR_WHITE, COLOR_WHITE);
    wattron(boundaryElement, COLOR_PAIR(1));
    //Vertical Sides
    for(int i = 0; i < (yOffsetEnd - yOffsetStart) + 1; i++){
        mvwaddch(boundaryElement, i, 0, ' ');
        mvwaddch(boundaryElement, i, 2*(xOffsetEnd - xOffsetStart) + 1, ' ');
    }
    for(int i = 0; i < 2*(xOffsetEnd - xOffsetStart) + 1; i++){
        mvwaddch(boundaryElement, (yOffsetEnd - yOffsetStart), i, ' ');
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
            bool isSpaceFree = !spaces[index];
            okay = okay && isSpaceFree;
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