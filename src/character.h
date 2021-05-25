//
// Created by Ben on 5/25/21.
//

#ifndef character_h
#define character_h

#include "sprite.h"

namespace EvilMonkeys
{
    class Character : public Sprite
    {
        int i_upKey_, i_downKey_, i_rightKey_, i_leftKey_;

    public:
        Character(DrawEngine *de1, int spriteIndex, float xpos, float ypos, int iLives, DrawEngine *de,
                  int sprite_index,
                  float sprite_xpos = 1,
                  float sprite_ypos = 1,
                  int sprite_lives = 3,
                  int character_upKey = KEY_UP,
                  int character_downKey = KEY_DOWN,
                  int character_leftKey = KEY_LEFT,
                  int character_rightKey = KEY_RIGHT) : Sprite(de, sprite_index, sprite_xpos, sprite_ypos, sprite_lives) {
            setClassID(CHARACTER_CLASSID);
            i_upKey_ = character_upKey;
            i_downKey_ = character_downKey;
            i_rightKey_ = character_rightKey;
            i_leftKey_ = character_leftKey;
            nonNPC();
        }

        virtual bool __isKeyPressExecuteAction(int i_key);

        void __addLives(int num = 1);
        bool __hookToLevel(Level* lvl, bool draw_at_once = true);

        bool checkSafeSpawnPosition(int xpos, int ypos, int distance_to_player);

    };
}
#endif
