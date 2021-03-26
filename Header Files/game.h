//
// Created by Ben on 3/26/21.
//

#ifndef GAME_H
#define GAME_H

class Game{
public:
    bool run(void);

protected:
    void timerUpdate();
    bool getInput(char*);

private:
    double frameCount;
    double startTime;
    double lastTime;

};

#endif
