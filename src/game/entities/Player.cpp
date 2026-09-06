#include "game/entities/Player.h"
#include <iostream>

namespace cs {

    //constructor
    Player::Player(std::vector<std::vector<int>> ed, bool isAl, Eng::Vector2C xny, Arsenal::Gun g, const std::vector<Part>& parts)
        : Character(std::move(ed), isAl, xny, parts), m_playerGun(std::move(g)) {}

    //controls user movement
    void Player::userMovement(char key) {
        switch (key) {
        case 'a':
            if(m_coord.x > 0)   m_coord.x--;
            break;

        //fix: key from b -> d && swapped increment and decrement
        case 'd':
            if(m_coord.x < 4)   m_coord.x++;
            break;
        
        default:
            break;
        }
    }

    void Player::survivalCheck(Character* obj) {
        HPReduction(obj);
        deathCondition();
    }

    void Player::addScore() {
        score++;
    }
}