#include <ncurses.h>

#ifndef __CELL_HPP__
#define __CELL_HPP__

class Cell{
public:
    Cell(unsigned int px, unsigned int py, int color);
    ~Cell();
    unsigned int getx();
    unsigned int gety();
    void move(unsigned int px, unsigned int py);
    void paint();
    void erase();
private:
    unsigned int x;
    unsigned int y;
    int color;
    WINDOW* win;
};

Cell::Cell(unsigned int px, unsigned int py, int c){
    x = px;
    y = py;
    color = c;
    win = newwin(1,2, py, 2*px);
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
void Cell::move(unsigned int px, unsigned int py){
    this->erase();
    this->x = px;
    this->y = py;
    this->paint();
}
void Cell::paint(){
    mvwin(this->win, this->y, this->x*2);
    init_pair(1, COLOR_WHITE, this->color);
    wattron(win, COLOR_PAIR(1));
    mvwaddch(this->win, 0, 0, ' ');
    mvwaddch(this->win, 0, 1, ' ');
    wattroff(win, COLOR_PAIR(1));
    wrefresh(win);
}
void Cell::erase(){
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    wattron(win, COLOR_PAIR(2));
    mvwaddch(this->win, 0, 0, ' ');
    mvwaddch(this->win, 0, 1, ' ');
    wattroff(win, COLOR_PAIR(2));
    wrefresh(win);
}

#endif