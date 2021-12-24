#include <ncurses.h>
#include <string>

class Cell{
public:
    Cell(int px, int py, std::string color);
    ~Cell();
    void move(int px, int py);
private:
    void erase();
    void paint();
    unsigned int x;
    unsigned int y;
    std::string color;
    WINDOW* win;
};

Cell::Cell(int px, int py, std::string c){
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

}