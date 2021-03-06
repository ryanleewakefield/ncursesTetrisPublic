#ifndef __SCREENWRITER_HPP__
#define __SCREENWRITER_HPP__


#include <ncurses.h>
#include <string>
#include "IControllable.hpp"

class ScreenWriter : public IControllableTwo{
public:
    ScreenWriter() = default;
    ScreenWriter(const ScreenWriter& rhs);
    void writeLineAtTop();
    void writeLineAtBottom();
    bool virtual actionOne();
    bool virtual actionTwo();
private:
    void writeToLine(WINDOW* win, int line, std::string data);
};
bool ScreenWriter::actionOne(){
    this->writeLineAtTop();
    return true;
}
bool ScreenWriter::actionTwo(){
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