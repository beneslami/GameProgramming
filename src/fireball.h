//
// Created by Ben on 5/25/21.
//

#ifndef fireball_h
#define fireball_h

#include "bomb.h"

namespace Target
{
    class Fireball : public Bomb
    {
    public:
        Fireball(DrawEngine *de, int sprite_index, float xpos, float ypos
                , float xDir, float yDir, int i_lives = 1)
                : Bomb(de, sprite_index, xpos, ypos, i_lives)
        {
            facingDirection_.x = xDir;
            facingDirection_.y = yDir;

            setClassID(FIREBALL_CLASSID);
        }

    private:
        void __idleUpdate(void);

    };
}

#endif
