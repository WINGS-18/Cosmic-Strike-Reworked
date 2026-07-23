#include "game/Player.h"
#include <iostream>

namespace cs {

    //constructor
    Player::Player(std::vector<std::vector<int>> ed, bool isAl, Eng::Vector2C xny, Arsenal::Gun g) : Character(ed, isAl, xny) {
        this->m_playerGun = g;
        std::cout << "Player created\n";
    }

    //controls user movement
    void Player::userMovement(char key) {
        std::cout << "Entered\n";
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

    void Player::gunFire() {
        m_playerGun.bulletMove();
        m_playerGun.bulletAdder(m_coord);
    }
}