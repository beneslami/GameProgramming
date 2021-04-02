//
// Created by Ben on 3/26/21.
//

#ifndef GAME_H
#define GAME_H

#include <ctime>
#include "drawEngine.h"

class Game{
public:
    bool run();

protected:
    void timerUpdate();
    bool getInput(int *);

private:
    double frameCount;
    time_t  startTime;
    time_t lastTime;
    DrawEngine drawArea;
    int posx;
    int posy;
};

#endif
