//
// Created by Ben on 5/25/21.
//

#ifndef countingAspect_h
#define countingAspect_h

#include "drawEngine.h"
#include "character.h"
#include "level.h"

namespace Concern {

    using namespace EvilMonkeys;

    // generic wrapper (aspect), that adds counting to any queue class
    // Target, as long it has the proper interface
    template <class Target> // Target is the component class this
    class Counting_Aspect : public Target
    { // aspect should be applied on

        Level* level_;
        Character* hero_;

        // added properties for added methods
        // int counter_;

        // wrap joinpoint invocations into action classes
        struct SpawnAction
        {
            int s_index;
            int goalDistance;
            int xpos;
            int ypos;
            float xface;
            float yface;
            bool ret;

            void proceed(Target* component){
                ret = component->spawnNPC(s_index, goalDistance, xpos, ypos, xface, yface);
            }
        };

    public:
        // for Bomb
        Counting_Aspect(DrawEngine *de, int sprite_index, float sprite_xpos, float sprite_ypos);

        // for Fireball
        Counting_Aspect(DrawEngine *de, int sprite_index, float xpos, float ypos, float xDir, float yDir);

        // for Mage
        Counting_Aspect(DrawEngine *de, int sprite_index);

        bool __hookToLevel(Level* lvl, bool draw_at_once = true);

        template <class ActionInterface> // template inside another template
        void advice(ActionInterface* targetAction)
        {
            targetAction->proceed(this);
        }

        void __addLives(int num);

        bool __isKeyPressExecuteAction(int key);

        bool spawnNPC(int sprite_index, int distanceToGoal = 9, int xpos = -1, int ypos = -1, float xface = 0, float yface = 0);

        // sections for added methods to the component code (introduction)
        // int count() const { return counter_; }
    };
}

#endif