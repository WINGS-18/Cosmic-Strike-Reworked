/*
@file Enemy.h :

* Enemies are inherited from the character class.
*/

#pragma once

#include "Character.h"

namespace cs {

    class Enemy : public Character {
    public:
        using Character::Character;
    };
}