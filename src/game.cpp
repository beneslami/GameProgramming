//
// Created by Ben on 3/26/21.
//
#include "game.h"
#include "mage.h"
#include "sprite.h"
#include <sys/time.h>
#include <iostream>
#include <iomanip>
#include <memory>

using namespace EvilMonkeys;

bool kbhit(void);
bool getKeyInput(int& key);

void EvilMonkeys::Game::run(DrawEngine* drawArea)
{
    //setup a new world
    world = std::make_shared<Level>(drawArea);

    //int playerSprite { drawArea->registerSprite(SPRITE_PLAYER, PLAYER_CHAR, GREEN_BLACK) };

    std::unique_ptr<Sprite> hero = std::unique_ptr<Target::Mage>(
            reinterpret_cast<Target::Mage *>(drawArea->registerSprite(SPRITE_PLAYER, PLAYER_CHAR, GREEN_BLACK)));
    hero->__hookToLevel( world.get() );

    int enemySprite = drawArea->registerSprite(SPRITE_ENEMY, ENEMY_CHAR, YELLOW_BLACK);
    for (int i=0; i < NUM_ENEMY; ++i)
        world->spawnNPC( enemySprite );

    int bombSprite = drawArea->registerSprite(SPRITE_BOMB, BOMB_CHAR);
    for (int i=0; i < NUM_BOMB; ++i)
        world->spawnNPC( bombSprite );

    auto lastTime = (double)0;
    auto key = (int)(' ');

    nodelay(stdscr, TRUE);

    while (key != KEY_QUIT_GAME)
    {
        while (!getKeyInput(key))
        {
            if (!world->isPaused())
                this->timerUpdate_(lastTime);
            else
                drawArea->printScore("paused ", 72);

            // constantly refresh the windows
            drawArea->refresh();
        }

        // pass the pressed key to the level
        world->isKeyPressExecuteAction(key);
    }
}

void EvilMonkeys::Game::timerUpdate_(double & lastTime)
{
    auto tv = std::unique_ptr<timeval>();
    gettimeofday( tv.get(), nullptr );

    auto currentTime = (tv->tv_sec + double(tv->tv_usec)/1000000.0)*1000 - lastTime ;

    if (currentTime < GAME_SPEED)
        return;

    //----------------------------------

    // this is for NPC not our hero
    world->update(lastTime);

    //----------------------------------

    gettimeofday( tv.get(), nullptr );
    lastTime = (tv->tv_sec + double(tv->tv_usec)/1000000.0)*1000;
}


bool getKeyInput(int & key)
{
    if (kbhit())
    {
        key = getch();
        return true;
    }

    return false;
}

bool kbhit()
{
    auto ch = getch();

    if (ch != ERR)
    {
        ungetch(ch);
        return true;
    }

    return false;
}