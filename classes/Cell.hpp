#include <ncurses.h>

#ifndef __CELL_HPP__
#define __CELL_HPP__

class Cell{
public:
    Cell(int px, int py, int color);
    ~Cell();
    void move(int px, int py);
    void paint();
    void erase();
private:
    
    
    unsigned int x;
    unsigned int y;
    int color;
    WINDOW* win;
};

Cell::Cell(int px, int py, int c){
    x = px;
    y = py;
    color = c;
    win = newwin(1,2, py, 2*px);
    //this->paint();
}
Cell::~Cell(){
    delwin(this->win);
}

void Cell::move(int px, int py){
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