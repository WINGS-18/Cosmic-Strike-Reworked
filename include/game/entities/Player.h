/*

@File Player.h :

    - Manages player.
    
*/

#pragma once

#include "game/entities/Character.h"
#include "game/arsenal/Gun.h"

namespace cs {

    class Player : public Character {
    public:
        Arsenal::Gun m_playerGun;
        int score = 0;
        
        //constructor
        Player(std::vector<std::vector<int>> ed, bool isAl, Eng::Vector2C xny, Arsenal::Gun g, const std::vector<Part>& parts);

        void userMovement(char key);        //makes user move or interact based on the keyboard inputs

        void survivalCheck(Character* obj);     //Triggers hp reduction and also checks weather alive.

        void addScore();
    };
}