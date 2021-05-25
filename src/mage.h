//
// Created by Ben on 5/25/21.
//

#ifndef mage_h
#define mage_h

#include "character.h"

namespace Target
{
#define FULL_AMMO 9
#define COOL_DOWN_RELOAD_IN_MILISECOND 500

    using namespace EvilMonkeys;

    class Mage : public Character
    {
        char spellKey_, reloadKey_, bombKey_;

        int ammoCartridge_;

    public:
        Mage(DrawEngine *de, int sprite_index,
             float xpos = 1,
             float ypos = 1,
             int lives = 3,
             char spellK = ' ',
             char reloadK = 'r',
             char bombK = 't',
             int up_key = KEY_UP,
             int down_key = KEY_DOWN,
             int left_key = KEY_LEFT,
             int right_key = KEY_RIGHT): Character(nullptr, 0, 0, 0, 0, de, sprite_index, xpos, ypos, lives, up_key, down_key, left_key,right_key)
        {
            setClassID(MAGE_CLASSID);
            spellKey_ = spellK;
            bombKey_ = bombK;
            reloadKey_ = reloadK;
            ammoCartridge_ = FULL_AMMO;
        }

        bool updateAmmoCartridge(int ammo){ ammoCartridge_ += ammo; return true; }
        int getAmmoCartridge(void){ return ammoCartridge_; }

        // thanks virtual, the keypress in parent is public, so this one can be hidden!
        bool __isKeyPressExecuteAction(int key);

    private:
        bool castSpell_(void);

    };
}
#endif