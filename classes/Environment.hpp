#ifndef __ENVIRONMENT_HPP__
#define __ENVIRONMENT_HPP__

#include <ncurses.h>
#include <vector>
#include <memory>
#include <string>
#include "Cell.hpp"
#include "Space.hpp"
#include "TetriminoType.hpp"
#include "TetriminoColors.hpp"
#include "ResourceManager.hpp"
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
    int checkClearDropLines();
    int getLinesLeft();
    bool metRequirementForLines();
    void resetLinesLeftForLevel();
    void paintNextTetrimino(TetriminoType tt);
    void paintLevel(std::string lv);
    void paintLines(std::string ln);
    void paintTime(std::string time);
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
    const static unsigned int xNextBoxOffset = 24;
    const static unsigned int yNextBoxOffset = 7;
    const static unsigned int nextBoxHeight = 8;
    const static unsigned int nextBoxWidth = 16;
    const static unsigned int xHUDBoxOffset = 24;
    const static unsigned int yHUDBoxOffset = 16;
    const static unsigned int HUDBoxHeight = 9;
    const static unsigned int HUDBoxWidth = 16;
    const static int linesPerLevel = 10;
    WINDOW* boundaryElement;
    WINDOW* nextTetriminoBox;
    WINDOW* HUDBox;
    WINDOW* tetriminoStatsBox;
    unsigned int boundaryColor = COLOR_WHITE;
    unsigned int totalLinesCleared = 0;
    int linesLeftForLevel = linesPerLevel;
    Space spaces[maxX + 1][maxY + 1];
    Environment();
    Environment(const Environment& rhs);
    ~Environment();
    void paintBoundary();
    void paintNextTetriminoBox();
    void paintHUDBox();
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
    this->nextTetriminoBox = newwin(8, 16, yNextBoxOffset, (xNextBoxOffset)*2);
    this->HUDBox = newwin(HUDBoxHeight,
                                    HUDBoxWidth,
                                    yHUDBoxOffset,
                                    xHUDBoxOffset*2);
    paintBoundary();
    paintNextTetriminoBox();
    paintHUDBox();
}
Environment::~Environment(){
    delwin(boundaryElement);
}
void Environment::paintBoundary(){
    std::unique_lock<std::mutex> lck {ResourceManager::getInstance()->screenMux};
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
void Environment::paintNextTetriminoBox(){
    std::unique_lock<std::mutex> lck {ResourceManager::getInstance()->screenMux};
    wattron(nextTetriminoBox, COLOR_PAIR(this->boundaryColor));
    //Vertical Sides
    for(int i = 0; i < 8; i++){
        mvwaddch(nextTetriminoBox, i, 0, ' ');
        mvwaddch(nextTetriminoBox, i, nextBoxWidth - 1, ' ');
    }
     //Horizontal Sides
    for(int i = 0; i < 15; i++){
        mvwaddch(nextTetriminoBox, 0, i, ' ');
        mvwaddch(nextTetriminoBox, nextBoxHeight - 1 , i, ' ');
    }
    wattroff(nextTetriminoBox, COLOR_PAIR(this->boundaryColor));
    init_pair(COLOR_TEXT, COLOR_WHITE, COLOR_BLACK);
    wattron(nextTetriminoBox, COLOR_PAIR(COLOR_TEXT));
    mvwaddstr(nextTetriminoBox, 7, 5, " NEXT ");
    wattroff(nextTetriminoBox, COLOR_PAIR(COLOR_TEXT));
    wrefresh(nextTetriminoBox);
}
void Environment::paintHUDBox(){
    std::unique_lock<std::mutex> lck {ResourceManager::getInstance()->screenMux};
    wattron(HUDBox, COLOR_PAIR(this->boundaryColor));
    //Vertical Sides
    for(int i = 0; i < 9; i++){
        mvwaddch(HUDBox, i, 0, ' ');
        mvwaddch(HUDBox, i, HUDBoxWidth - 1, ' ');
    }
     //Horizontal Sides
    for(int i = 0; i < 15; i++){
        mvwaddch(HUDBox, 0, i, ' ');
        mvwaddch(HUDBox, HUDBoxHeight - 1 , i, ' ');
    }
    wattroff(HUDBox, COLOR_PAIR(this->boundaryColor));

    //Write headings to screen
    init_pair(COLOR_TEXT, COLOR_WHITE, COLOR_BLACK);
    wattron(HUDBox, COLOR_PAIR(COLOR_TEXT));
    mvwaddstr(HUDBox, 2, 2, "LEVEL: ");
    mvwaddstr(HUDBox, 4, 2, "LINES: ");
    mvwaddstr(HUDBox, 6, 2, "TIME: ");
    wattroff(HUDBox, COLOR_PAIR(COLOR_TEXT));
    wrefresh(HUDBox);
}
/*
    std::string lv must be in the format "XY" where
    X could be blank
*/
void Environment::paintLevel(std::string lv){
    // lv is guaranteed to be in the format "XY" where X could be blank
    // thus, no erasing is needed prior to painting
    std::unique_lock<std::mutex> lck {ResourceManager::getInstance()->screenMux};
    init_pair(COLOR_TEXT, COLOR_WHITE, COLOR_BLACK);
    wattron(HUDBox, COLOR_PAIR(COLOR_TEXT));
    mvwaddnstr(HUDBox, 2, 10, lv.c_str(), lv.length());
    wattroff(HUDBox, COLOR_PAIR(COLOR_TEXT));
    wrefresh(HUDBox);
}
/*
    std::string ln must be in the format "XY" where
    X could be blank
*/
void Environment::paintLines(std::string ln){
    std::unique_lock<std::mutex> lck {ResourceManager::getInstance()->screenMux};
    init_pair(COLOR_TEXT, COLOR_WHITE, COLOR_BLACK);
    wattron(HUDBox, COLOR_PAIR(COLOR_TEXT));
    mvwaddnstr(HUDBox, 4, 10, ln.c_str(), ln.length());
    wattroff(HUDBox, COLOR_PAIR(COLOR_TEXT));
    wrefresh(HUDBox);
}
/*
    std::string time must be in the format "00:00"
*/
void Environment::paintTime(std::string time){
    std::unique_lock<std::mutex> lck {ResourceManager::getInstance()->screenMux};
    init_pair(COLOR_TEXT, COLOR_WHITE, COLOR_BLACK);
    wattron(HUDBox, COLOR_PAIR(COLOR_TEXT));
    mvwaddnstr(HUDBox, 6, 9, time.c_str(), time.length());
    wattroff(HUDBox, COLOR_PAIR(COLOR_TEXT));
    wrefresh(HUDBox);
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
    std::unique_lock<std::mutex> lck {ResourceManager::getInstance()->screenMux};
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
    std::unique_lock<std::mutex> lck {ResourceManager::getInstance()->screenMux};
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
int Environment::checkClearDropLines(){  
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
                this->totalLinesCleared += 1;
                linesLeftForLevel--;
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
void Environment::resetLinesLeftForLevel(){
    this->linesLeftForLevel = this->linesLeftForLevel + linesPerLevel;// accounts for extra lines over the requirement
}
bool Environment::metRequirementForLines(){
    return linesLeftForLevel <= 0 ? true : false;
}
int Environment::getLinesLeft(){
    return linesLeftForLevel;
}
void Environment::paintNextTetrimino(TetriminoType tt){
    std::unique_lock<std::mutex> lck {ResourceManager::getInstance()->screenMux};
    //Erase all previous pieces here
    init_pair(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
    wattron(nextTetriminoBox, COLOR_PAIR(COLOR_BLACK));
    for(int i = 1; i < 6; i++){
        for(int j = 1; j < 15; j++){
            mvwaddch(nextTetriminoBox, i, j, ' ');
        }
    }
    wattroff(nextTetriminoBox, COLOR_PAIR(COLOR_BLACK));
    switch(tt){
        case LONG_PIECE:{
            init_pair(COLOR_LONGPIECE, COLOR_WHITE, COLOR_LONGPIECE);
            wattron(nextTetriminoBox, COLOR_PAIR(COLOR_LONGPIECE));
            mvwaddch(nextTetriminoBox, 2, 6, ' ');
            mvwaddch(nextTetriminoBox, 2, 6 + 1, ' ');
            mvwaddch(nextTetriminoBox, 3, 6, ' ');
            mvwaddch(nextTetriminoBox, 3, 6 + 1, ' ');
            mvwaddch(nextTetriminoBox, 4, 6, ' ');
            mvwaddch(nextTetriminoBox, 4, 6 + 1, ' ');
            mvwaddch(nextTetriminoBox, 5, 6, ' ');
            mvwaddch(nextTetriminoBox, 5, 6 + 1, ' ');
            wattroff(nextTetriminoBox, COLOR_PAIR(COLOR_LONGPIECE));
            break;
        }
        case LEFT_L:{
            init_pair(COLOR_LEFTL, COLOR_WHITE, COLOR_LEFTL);
            wattron(nextTetriminoBox, COLOR_PAIR(COLOR_LEFTL));
            mvwaddch(nextTetriminoBox, 2, 6, ' ');
            mvwaddch(nextTetriminoBox, 2, 6 + 1, ' ');
            mvwaddch(nextTetriminoBox, 3, 6, ' ');
            mvwaddch(nextTetriminoBox, 3, 6 + 1, ' ');
            mvwaddch(nextTetriminoBox, 4, 6, ' ');
            mvwaddch(nextTetriminoBox, 4, 6 + 1, ' ');
            mvwaddch(nextTetriminoBox, 4, 8, ' ');
            mvwaddch(nextTetriminoBox, 4, 8 + 1, ' ');
            wattroff(nextTetriminoBox, COLOR_PAIR(COLOR_LEFTL));
            break;
        }
        case RIGHT_L:{
            init_pair(COLOR_RIGHTL, COLOR_WHITE, COLOR_RIGHTL);
            wattron(nextTetriminoBox, COLOR_PAIR(COLOR_RIGHTL));
            mvwaddch(nextTetriminoBox, 2, 6, ' ');
            mvwaddch(nextTetriminoBox, 2, 6 + 1, ' ');
            mvwaddch(nextTetriminoBox, 3, 6, ' ');
            mvwaddch(nextTetriminoBox, 3, 6 + 1, ' ');
            mvwaddch(nextTetriminoBox, 4, 6, ' ');
            mvwaddch(nextTetriminoBox, 4, 6 + 1, ' ');
            mvwaddch(nextTetriminoBox, 4, 4, ' ');
            mvwaddch(nextTetriminoBox, 4, 4 + 1, ' ');
            wattroff(nextTetriminoBox, COLOR_PAIR(COLOR_RIGHTL));
            break;
        }
        case LEFT_S:{
            init_pair(COLOR_LEFTS, COLOR_WHITE, COLOR_LEFTS);
            wattron(nextTetriminoBox, COLOR_PAIR(COLOR_LEFTS));
            mvwaddch(nextTetriminoBox, 3, 10, ' ');
            mvwaddch(nextTetriminoBox, 3, 10 + 1, ' ');
            mvwaddch(nextTetriminoBox, 3, 8, ' ');
            mvwaddch(nextTetriminoBox, 3, 8 + 1, ' ');
            mvwaddch(nextTetriminoBox, 4, 6, ' ');
            mvwaddch(nextTetriminoBox, 4, 6 + 1, ' ');
            mvwaddch(nextTetriminoBox, 4, 8, ' ');
            mvwaddch(nextTetriminoBox, 4, 8 + 1, ' ');
            wattroff(nextTetriminoBox, COLOR_PAIR(COLOR_LEFTS));
            break;
        }
        case RIGHT_S:{
            init_pair(COLOR_RIGHTS, COLOR_WHITE, COLOR_RIGHTS);
            wattron(nextTetriminoBox, COLOR_PAIR(COLOR_RIGHTS));
            mvwaddch(nextTetriminoBox, 3, 4, ' ');
            mvwaddch(nextTetriminoBox, 3, 4 + 1, ' ');
            mvwaddch(nextTetriminoBox, 3, 6, ' ');
            mvwaddch(nextTetriminoBox, 3, 6 + 1, ' ');
            mvwaddch(nextTetriminoBox, 4, 6, ' ');
            mvwaddch(nextTetriminoBox, 4, 6 + 1, ' ');
            mvwaddch(nextTetriminoBox, 4, 8, ' ');
            mvwaddch(nextTetriminoBox, 4, 8 + 1, ' ');
            wattroff(nextTetriminoBox, COLOR_PAIR(COLOR_RIGHTS));
            break;
        }
        case T_PIECE:{
            init_pair(COLOR_TPIECE, COLOR_WHITE, COLOR_TPIECE);
            wattron(nextTetriminoBox, COLOR_PAIR(COLOR_TPIECE));
            mvwaddch(nextTetriminoBox, 4, 4, ' ');
            mvwaddch(nextTetriminoBox, 4, 4 + 1, ' ');
            mvwaddch(nextTetriminoBox, 4, 6, ' ');
            mvwaddch(nextTetriminoBox, 4, 6 + 1, ' ');
            mvwaddch(nextTetriminoBox, 3, 6, ' ');
            mvwaddch(nextTetriminoBox, 3, 6 + 1, ' ');
            mvwaddch(nextTetriminoBox, 4, 8, ' ');
            mvwaddch(nextTetriminoBox, 4, 8 + 1, ' ');
            wattroff(nextTetriminoBox, COLOR_PAIR(COLOR_TPIECE));
            break;
        }
        case SQUARE:{
            init_pair(COLOR_SQUARE, COLOR_WHITE, COLOR_SQUARE);
            wattron(nextTetriminoBox, COLOR_PAIR(COLOR_SQUARE));
            mvwaddch(nextTetriminoBox, 4, 6, ' ');
            mvwaddch(nextTetriminoBox, 4, 6 + 1, ' ');
            mvwaddch(nextTetriminoBox, 4, 8, ' ');
            mvwaddch(nextTetriminoBox, 4, 8 + 1, ' ');
            mvwaddch(nextTetriminoBox, 3, 6, ' ');
            mvwaddch(nextTetriminoBox, 3, 6 + 1, ' ');
            mvwaddch(nextTetriminoBox, 3, 8, ' ');
            mvwaddch(nextTetriminoBox, 3, 8 + 1, ' ');
            wattroff(nextTetriminoBox, COLOR_PAIR(COLOR_SQUARE));
            break;
        }
    }
     wrefresh(nextTetriminoBox);
}
#endif