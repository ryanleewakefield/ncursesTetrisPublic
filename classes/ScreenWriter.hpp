#ifndef __SCREENWRITER_HPP__
#define __SCREENWRITER_HPP__


#include <ncurses.h>
#include <string>
#include "IControllable.hpp"

class ScreenWriter : public IControllable{
public:
    ScreenWriter() = default;
    ScreenWriter(const ScreenWriter& rhs);
    void writeLineAtTop();
    void writeLineAtBottom();
    bool virtual controllerUp();
    bool virtual controllerDown();
private:
    void writeToLine(WINDOW* win, int line, std::string data);
};
bool ScreenWriter::controllerUp(){
    this->writeLineAtTop();
    return true;
}
bool ScreenWriter::controllerDown(){
    this->writeLineAtBottom();
    return true;
}

void ScreenWriter::writeLineAtBottom(){
    this->writeToLine(stdscr, 30, "Line at Bottom");
}
void ScreenWriter::writeLineAtTop(){
    this->writeToLine(stdscr, 10, "Line at Top");
}
void ScreenWriter::writeToLine(WINDOW* win, int line, std::string data){
	wmove(win, line, 0);
	wclrtoeol(win);
	wrefresh(win);
	waddstr(win, data.c_str());
	wrefresh(win);
}
#endif