/*
@file Bullet.h

* Struct Bullet where each instance is a individual bullet.
* This instance has it's own x, y coordinates.
* int m_val is a integer that represents the Part class i'd.

*/

#pragma once
#include "engine/Vector2C.h"

namespace cs {

    namespace Arsernal {

        struct Bullet {
        int m_val;
        Eng::Vector2C m_bulCoord;

            //constructor
            Bullet();
            Bullet(int val); 
        
            void coordinateModifier(const Eng::Vector2C& host);     //modifies bullets coordinates

            void bulletMovement();       //increments the bullet position on y axis
        };

    }

}