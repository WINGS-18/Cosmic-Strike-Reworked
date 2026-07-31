/*
@file Enemy.h :

* Enemies are inherited from the character class.
*/

#pragma once

#include "game/entities/Character.h"

namespace cs {

    class Enemy : public Character {
    public:
        using Character::Character;

        void survivalCheck(Character* p);       //reduces hp and also calls functions to check weather entity is alive
    };
}