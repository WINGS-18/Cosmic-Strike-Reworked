#include "game/Player.h"

namespace cs {

    Player::Player(std::vector<std::vector<int>> ed, bool isAl, Eng::Vector2C xny, Arsernal::Gun g) : Character(ed, isAl, xny) {
        this->m_playerGun = g;
    }

    void Player::userMovement(char key) {
        switch (key) {
        case 'a':
            if(m_coord.x > 0)   m_coord.x++;
            break;

        case 'b':
            if(m_coord.x < 5)   m_coord.x--;
            break;
        
        default:
            break;
        }
    }
}