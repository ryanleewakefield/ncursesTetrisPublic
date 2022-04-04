#include <iostream>
#include <ncurses.h>
#include <string>
#include <thread>
#include <mutex>
#include <memory>
#include <chrono>

#include "../classes/Cell.hpp"
#include "../classes/Environment.hpp"
#include "../classes/Tetrimino.hpp"
#include "../classes/UserController.hpp"
#include "../classes/LongPiece.hpp"
#include "../classes/LeftL.hpp"
#include "../classes/RightL.hpp"
#include "../classes/LeftS.hpp"
#include "../classes/RightS.hpp"
#include "../classes/TPiece.hpp"
#include "../classes/Square.hpp"

#include "../classes/KeyboardListener.hpp"
#include "../classes/ScreenWriter.hpp"
#include "../classes/AppLogic.hpp"
#include "../classes/GameDaemon.hpp"
#include "../classes/AppController.hpp"
#include "../classes/TetriminoController.hpp"
#include "../classes/GameEventListener.hpp"
#include "../classes/TetriminoFactory.hpp"
#include "../classes/GenerationAlgorithm.hpp"
#include "../classes/TetriminoColors.hpp"

using namespace std;
void writeToLine(WINDOW* win, int line, string data);

int testFullGame(){
    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, true);
    curs_set(0);
    refresh();
    int height = 43;
    int width = 80;
    defineInitialColors();
    // Get instance of Environment Singleton object
    // boundaryElement should print to the screen
    Environment* mainEnv = Environment::getInstance();
    
   
    

    AppController ac;
    
    ac.setControllable(AppLogic::getInstance());

    TetriminoController tc;
    
    KeyboardListener::getInstance()->registerController(&ac);
    KeyboardListener::getInstance()->registerController(&tc);

    

    GravityCycle gravityCycle;
    gravityCycle.setController(&tc);
    
    AppLogic::getInstance()->registerGameDaemon(&gravityCycle);
   
    GameEventListener* ref = GameEventListener::getInstance();

    TetriminoFactory tf(new UniformGeneration());
    
    Tetrimino* tetrimino = nullptr;
    tetrimino = tf.getNextTetrimino();
    tetrimino->show();
    // getch();
    tc.setControllable(tetrimino);
    bool gameOver = false;
    gravityCycle.setDelay(500);
    KeyboardListener::getInstance()->startListening();
    gravityCycle.startAutoThread();
    for(int i = 0; ; i++){
        writeToLine(stdscr, 35, string("Tetrimino num: " + to_string(i + 1)));
        std::unique_lock<std::mutex> lck(ref->mux1);
        ref->waitForNextCollision.wait(lck, [ref]{
            return ref->detectedCollision;
        });
        ref->detectedCollision = false;
        //put code to setup next tetrimino here...
        tetrimino->passCellsToEnvironment();
        delete tetrimino;
        tetrimino = nullptr;
        //put code to check, clear, and drop lines here...
        mainEnv->checkClearDropLines();
        tetrimino = tf.getNextTetrimino();
        //put code to test for GameOver here...
        tetrimino->show();
        std::vector<unsigned int> xs = tetrimino->getXs();
        std::vector<unsigned int> ys = tetrimino->getYs();
        if(!mainEnv->legalMove(xs, ys)){
            gameOver = true;
            break;
        }
        //put code to check for level increase here...
        if(mainEnv->metRequirementForLines()){
            mainEnv->resetLinesLeftForLevel();
            gravityCycle.increaseLevel();
            shiftColors(gravityCycle.getLevel());
        }
        //put code to update HUD data here...
        writeToLine(stdscr, 33, string("Level: " + to_string(gravityCycle.getLevel())));
        writeToLine(stdscr, 34, string("Lines until next level: " + to_string(mainEnv->getLinesLeft())));
        tc.setControllable(tetrimino);
        ref->readyForGravity = true;
        ref->waitForNextTetrimino.notify_one();
        
    }
    if(gameOver){
    writeToLine(stdscr, 36, string("Game Over"));
    }
    KeyboardListener::getInstance()->waitOnListener();
    
    // delete tetrimino;
    
    endwin();

    return 0;
}
// void writeToLine(WINDOW* win, int line, string data){
// 	wmove(win, line, 0);
// 	wclrtoeol(win);
// 	wrefresh(win);
// 	waddstr(win, data.c_str());
// 	wrefresh(win);
// }