//
// Created by Ben on 5/25/21.
//

#include "level.h"

void Target::Bomb::__idleUpdate()
{
    if ( hits( level_->player() ) && is(BOMB_CLASSID) )
        // player collects the bomb
        this->__addLives(-1);

    // not yet support early break or skip out element with range-for
    for( auto& Iter : level_->NPC() )
        if ( Iter->hits(this) )
        {
            // kill the enemy OR Fireball got hit
            Iter->__addLives(-1);

            // and kill itself
            this->__addLives(-1);
        }

}