//
// Created by Ben on 3/26/21.
//

#ifndef game_h
#define game_h

#include "level.h"

namespace EvilMonkeys
{
    typedef Concern::Counting_Aspect<Target::Bomb> Bomb;
    typedef Concern::Counting_Aspect<Target::Fireball> Fireball;
    typedef Concern::Counting_Aspect<Target::Mage> Mage;

#define GAME_SPEED 50
#define KEY_QUIT_GAME 'q'

#define NUM_ENEMY 1
#define NUM_BOMB 20

    class DrawEngine;
    class Level;

    class Game
    {
        std::shared_ptr<Level> world;

    public:
        void run(DrawEngine* drawArea);

    private:
        void timerUpdate_(double& lastTime);

    };
}
#endif