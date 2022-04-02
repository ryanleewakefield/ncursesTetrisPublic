#ifndef __ENVIRONMENT_HPP__
#define __ENVIRONMENT_HPP__

#include <ncurses.h>
#include <vector>
#include <memory>
#include "Cell.hpp"
#include "Space.hpp"
// A shared smart pointer would work well with this class
class Environment{
public:
    static Environment* getInstance();
    static bool freeInstance();
    bool isOccupied(unsigned int x, unsigned int y);
    bool legalMove(std::vector<unsigned int>& Xs, std::vector<unsigned int>& Ys);
    bool occupySpace(unsigned int x, unsigned int y);
    void addCell(Cell* cellptr);
    static int getXOffset();
    static int getYOffset();
    void checkClearDropLines();
    // void erase(Space& s);
    // void move(Space& s);
    // void paint(Space& s);
    // Space spaces[15 + 1][23 + 1];
private:
    static Environment* uniqueInstance;
    const static unsigned int minX = 0;
    const static unsigned int minY = 0;
    const static unsigned int maxX = 15;
    const static unsigned int maxY = 23;
    const static unsigned int total_spaces = (maxX+1) * (maxY+1);
    const static unsigned int xOffsetStart = 7;
    const static unsigned int yOffsetStart = 7;
    const static unsigned int xOffsetEnd = xOffsetStart + maxX + 1;
    const static unsigned int yOffsetEnd = yOffsetStart + maxY + 1;
    WINDOW* boundaryElement;
    unsigned int boundaryColor = COLOR_WHITE;
    Space spaces[maxX + 1][maxY + 1];
    Environment();
    Environment(const Environment& rhs);
    ~Environment();
    void paintBoundary();
    bool isWithinBounds(unsigned int x, unsigned y);
    void erase(Space* s);
    void move(Space** s);
    void paint(Space* s);

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
    this->boundaryElement = newwin(25,37,7,13);
    paintBoundary();
}
Environment::~Environment(){
    delwin(boundaryElement);
}
void Environment::paintBoundary(){
    init_pair(this->boundaryColor, COLOR_WHITE, COLOR_WHITE);
    wattron(boundaryElement, COLOR_PAIR(this->boundaryColor));
    //Vertical Sides
    for(int i = 0; i < (yOffsetEnd - yOffsetStart) + 1; i++){
        mvwaddch(boundaryElement, i, 0, ' ');
        mvwaddch(boundaryElement, i, 2*(xOffsetEnd - xOffsetStart) + 1, ' ');
    }
    //Horizontal Side
    for(int i = 0; i < 2*(xOffsetEnd - xOffsetStart) + 1; i++){
        mvwaddch(boundaryElement, (yOffsetEnd - yOffsetStart), i, ' ');
    }
    wattroff(boundaryElement, COLOR_PAIR(this->boundaryColor));
    wrefresh(boundaryElement);
}
bool Environment::isWithinBounds(unsigned int x, unsigned int y){
    if( (minX <= x && x <= maxX) && (minY <= y && y <= maxY)){
        return true;
    }
    else{
        return false;
    }
}
void Environment::erase(Space* s){
    init_pair(COLOR_BLACK, COLOR_WHITE, COLOR_BLACK);
    wattron(boundaryElement, COLOR_PAIR(COLOR_BLACK));
    mvwaddch(boundaryElement, s->y, (s->x)*2 + 1, ' ');
    mvwaddch(boundaryElement, s->y, (s->x)*2 + 2, ' ');
    wattroff(boundaryElement, COLOR_PAIR(COLOR_BLACK));
    wrefresh(boundaryElement);
    s->occupied = false;
    s->toBeCleared = false;
}
void Environment::move(Space** s){
    int oldX = (*s)->x;
    int newY = (*s)->y + (*s)->adjustLevel;
    spaces[(*s)->x][newY].adjustLevel = 0;
    spaces[(*s)->x][newY].y = newY;
    spaces[(*s)->x][newY].toBeCleared = false;
    spaces[(*s)->x][newY].occupied = true;
    spaces[(*s)->x][newY].color = (*s)->color;
    (*s)->adjustLevel = 0;
    (*s)->toBeCleared = false;
    *s = &spaces[oldX][newY];
}
void Environment::paint(Space* s){
    init_pair(s->color, COLOR_WHITE, s->color);
    wattron(boundaryElement, COLOR_PAIR(s->color));
    mvwaddch(boundaryElement, s->y, (s->x)*2 + 1, ' ');
    mvwaddch(boundaryElement, s->y, (s->x)*2 + 2, ' ');
    wattroff(boundaryElement, COLOR_PAIR(s->color));
    wrefresh(boundaryElement);
}

bool Environment::legalMove(std::vector<unsigned int>& Xs, std::vector<unsigned int>& Ys){
    bool okay = true;
    int index = -1;
    for(unsigned int i = 0; i < Xs.size(); i++){
        if(this->isWithinBounds(Xs[i], Ys[i])){
            bool isSpaceFree = !spaces[Xs[i]][Ys[i]].occupied;
            okay = okay && isSpaceFree;
        }
        else{
            return false;
        }
    }
    return okay;
}


bool Environment::isOccupied(unsigned int x, unsigned int y){
    
    if(this->isWithinBounds(x,y)){
        return this->spaces[x][y].occupied;
    }
    return true;
}

bool Environment::occupySpace(unsigned int x, unsigned int y){

    if(this->isOccupied(x,y)) {
        return false;
    }
    else{
        this->spaces[x][y].occupied = true;
        return true;
    }
    //This below should never occur
    return false;
}
void Environment::addCell(Cell* cellptr){
    int x = cellptr->getx();
    int y = cellptr->gety();
    if(this->occupySpace(x,y)){
        this->spaces[x][y].y = y;
        this->spaces[x][y].x = x;
        this->spaces[x][y].color = cellptr->getColor();
    }
}
void Environment::checkClearDropLines(){  
    bool environmentChanged = false;
    int globalAdjustLevel = 0;
    do{
        environmentChanged = false;
        globalAdjustLevel = 0;
        //Check each line
        for(int yLevel = maxY; yLevel != -1; yLevel--){
            bool allOccupied = true;
            //check if each space is occupied on yLevel line
            for(int x = 0; x <= maxX; x++){
                allOccupied = allOccupied && spaces[x][yLevel].occupied;
            }
            if(allOccupied){
                for(int x = 0; x <= maxX; x++){
                  spaces[x][yLevel].toBeCleared = true;  
                }
                globalAdjustLevel += 1;
                environmentChanged = true;
            }
            else{
                 for(int x = 0; x <= maxX; x++){
                     if(spaces[x][yLevel].occupied){
                         spaces[x][yLevel].adjustLevel = globalAdjustLevel;
                     }
                }
            }
        }
        //Clear and Drop each line as needed
        for(int yLevel = maxY; yLevel != -1; yLevel--){
            if(spaces[0][yLevel].toBeCleared){
                for(int x = 0; x <= maxX; x++){
                    Space* ref = &spaces[x][yLevel];
                    erase(ref);
                }
            }
            else{
                for(int x = 0; x <= maxX; x++){
                    Space* ref = &spaces[x][yLevel];
                    if(ref->occupied){
                        erase(ref);
                        move(&ref);
                        paint(ref);
                    }
                }
            }
        }
    }while(environmentChanged);
}
#endif