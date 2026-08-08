/*
@file Bullet.h

* Struct Bullet where each instance is a individual bullet.
* This instance has it's own x, y coordinates.
* int m_val is a integer that represents the Part class i'd.

*/

#pragma once
#include "engine/Vector2C.h"
#include <vector>

namespace cs {

    namespace Arsenal {

        struct Bullet {
            int m_val;
            Eng::Vector2C m_bulCoord;
            bool m_bul_isAlive = false;

            /*
            * To fix bullets tunneling we added m_bul_isAlive
              flag that extends to is the bullet alive.
            * Whenever bullet hits a obstacle this flag it turned
              false.
            * This gives renderer chance only to print bullets that
              are alive.
            * Even after crashing mid way the bullets are not popped
              from the queue.
            * To the dead bullets no movement or any other functions
              are applied.
            */

            //constructor
            Bullet();
            Bullet(int val); 
        
            void coordinateModifier(const Eng::Vector2C& host);     //modifies bullets coordinates

            void bulletMovement();       //increments the bullet position on y axis
        };

    }

}