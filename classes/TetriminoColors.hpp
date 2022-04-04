#ifndef __TETRIMINOCOLORS_HPP__
#define __TETRIMINOCOLORS_HPP__

#include <ncurses.h>
// This class can be a bunch of define directives
// and function definitions that work with ncurses 
// color support.

#define COLOR_LONGPIECE 100
#define COLOR_LEFTL 101
#define COLOR_RIGHTL 102
#define COLOR_LEFTS 103
#define COLOR_RIGHTS 104
#define COLOR_TPIECE 105
#define COLOR_SQUARE 106

// Colors are define by 0 - 255 range
// Convert them to 0 - 1000 range
constexpr unsigned int reds[] = {245,131,132,255,245,168,219};
constexpr unsigned int greens[] = {120,154,230,245,168,88,81};
constexpr unsigned int blues[] = {197,252,173,133,132,230,43};

int convert(unsigned int c){
    return (int)((double)c / 255.0 * 1000);
}

void defineInitialColors(){
    // init_color(COLOR_LONGPIECE, reds[0], greens[0], blues[0]);
    // init_color(COLOR_LEFTL, reds[1], greens[1], blues[1]);
    // init_color(COLOR_RIGHTL, reds[2], greens[2], blues[2]);
    // init_color(COLOR_LEFTS, reds[3], greens[3], blues[3]);
    // init_color(COLOR_RIGHTS, reds[4], greens[4], blues[4]);
    // init_color(COLOR_TPIECE, reds[5], greens[5], blues[5]);
    // init_color(COLOR_SQUARE, reds[6], greens[6], blues[6]);
    for(int i = 0; i < 7; i++){
        init_color(100+i, convert(reds[i]), convert(greens[i]), convert(blues[i]));
    }
}
void shiftColors(int level){
    switch(level % 3){
        case 0: {
            for(int i = 0; i < 7; i++){
                init_color(100+i, convert(reds[i]), convert(greens[i]), convert(blues[i]));
            }
            break;
        }
        case 1: {
            for(int i = 0; i < 7; i++){
                init_color(100+i, convert(greens[i]), convert(blues[i]), convert(reds[i]));
            }
            break;
        }
        case 3: {
            for(int i = 0; i < 7; i++){
                init_color(100+i, convert(blues[i]), convert(reds[i]), convert(greens[i]));
            }
            break;
        }
    }
}
#endif