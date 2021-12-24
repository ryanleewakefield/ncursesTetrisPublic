#include <ncurses.h>
#include <string>

class Cell{
public:
    Cell(int px, int py, int color);
    ~Cell();
    void move(int px, int py);
private:
    void erase();
    void paint();
    unsigned int x;
    unsigned int y;
    int color;
    WINDOW* win;
};

Cell::Cell(int px, int py, int c){
    x = px;
    y = py;
    color = c;
    win = newwin(py, 2*px, 1, 2);

}
Cell::~Cell(){
    delwin(this->win);
}

void Cell::move(int px, int py){
    this->x = px;
    this->y = py;
    this->paint();
}

void Cell::paint(){
    this->erase();
    mvwin(this->win, this->y, this->x);
    init_pair(1, COLOR_WHITE, this->color);
    wattron(win, COLOR_PAIR(1));
    mvwaddch(this->win, this->y, this->x * 2, ' ');
    mvwaddch(this->win, this->y, this->x * 2 + 1, ' ');
    wattroff(win, COLOR_PAIR(1));
    wrefresh(win);
}

void Cell::erase(){
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    wattron(win, COLOR_PAIR(1));
    mvwaddch(this->win, this->y, this->x * 2, ' ');
    mvwaddch(this->win, this->y, this->x * 2 + 1, ' ');
    wattroff(win, COLOR_PAIR(1));
    wrefresh(win);
}