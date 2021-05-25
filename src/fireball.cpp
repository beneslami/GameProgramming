//
// Created by Ben on 5/25/21.
//

#include "fireball.h"

void Target::Fireball::__idleUpdate()
{
    if (Sprite::__move(facingDirection_.x, facingDirection_.y))
        // kill the enemy OR Fireball got hit and then kill itself
        Bomb::__idleUpdate();
    else
        // hit the wall border
        __addLives(-1);
}