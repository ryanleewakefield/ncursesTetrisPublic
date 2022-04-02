#ifndef __CELL_HPP__
#define __CELL_HPP__

#include <ncurses.h>
class Cell{
public:
    Cell(unsigned int px, unsigned int py, unsigned int xOff, unsigned int yOff, int color, char letter);
    Cell(const Cell& rhs);
    ~Cell();
    // A Cell's (x,y) position was in absolute terms i.e. relative to the
    // terminal screen.
    // It is now refactored to take a relative position and an offset position
    // upon construction.
    unsigned int getx();
    unsigned int gety();
    int getColor();
    void move(unsigned int px, unsigned int py);
    void paint();
    void erase();
private:
    unsigned int x;
    unsigned int y;
    unsigned int xOffset;
    unsigned int yOffset;
    const static int unitHeight = 1;
    const static int unitWidth = 2;
    int color;
    char letter;
    WINDOW* win;
};

Cell::Cell(unsigned int px, unsigned int py, unsigned int xOff, unsigned int yOff, int c, char l){
    x = px;
    y = py;
    xOffset = xOff;
    yOffset = yOff;
    color = c;
    letter = l;
    win = newwin(unitHeight, unitWidth, (py + yOff) * unitHeight, (px + xOff) * unitWidth);
}
Cell::Cell(const Cell& rhs){
    this->x = rhs.x;
    this->y = rhs.y;
    this->xOffset = rhs.xOffset;
    this->yOffset = rhs.yOffset;
    this->color = rhs.color;
    this->letter = rhs.letter;
    this->win = newwin(unitHeight, unitWidth, (this->y + this->yOffset) * unitHeight, (this->x + this->yOffset) * unitWidth);
}
Cell::~Cell(){
    delwin(this->win);
}
unsigned int Cell::getx(){
    return x;
}
unsigned int Cell::gety(){
    return y;
}
int Cell::getColor(){
    return color;
}
//erase, move, and paint must be called in batches for Tetriminos
void Cell::move(unsigned int px, unsigned int py){
    this->x = px;
    this->y = py;
}
void Cell::paint(){
    mvwin(this->win, this->y + this->yOffset, (this->x + this->xOffset)*2);
    init_pair(this->color, COLOR_WHITE, this->color);
    wattron(win, COLOR_PAIR(this->color));
    mvwaddch(win, 0, 0, letter);
    mvwaddch(win, 0, 1, ' ');
    wattroff(win, COLOR_PAIR(this->color));
    wrefresh(win);
}
void Cell::erase(){
    init_pair(COLOR_BLACK, COLOR_WHITE, COLOR_BLACK);
    wattron(win, COLOR_PAIR(COLOR_BLACK));
    mvwaddch(this->win, 0, 0, ' ');
    mvwaddch(this->win, 0, 1, ' ');
    wattroff(win, COLOR_PAIR(COLOR_BLACK));
    wrefresh(win);
}

#endif