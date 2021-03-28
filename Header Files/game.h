//
// Created by Ben on 3/26/21.
//

#ifndef GAME_H
#define GAME_H

#include <ctime>
#include "../Header Files/drawEngine.h"

class Game{
public:
    bool run(void);
    Game();
    ~Game();

protected:
    void timerUpdate();
    bool getInput(char*);


private:
    double frameCount;
    time_t  startTime;
    time_t lastTime;
};

#endif
