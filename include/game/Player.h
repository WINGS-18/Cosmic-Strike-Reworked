#pragma once

#include "game/Character.h"
#include "game/Gun.h"

namespace cs {

    class Player : public Character {
    public:
        Arsernal::Gun m_playerGun;
        
        //constructor
        Player(std::vector<std::vector<int>> ed, bool isAl, Eng::Vector2C xny, Arsernal::Gun g);

        void userMovement(char key);        //makes user move or interact based on the keyboard inputs
    };
}