#include "game/Bullet.h"

namespace cs::Arsenal {

    Bullet::Bullet() 
        : m_val(14) {}

    Bullet::Bullet(int val) 
        : m_val(val) {}

    void Bullet::coordinateModifier(const Eng::Vector2C& host) {   //modifies bullets coordinates
        m_bulCoord.x = host.x;
        m_bulCoord.y = host.y - 2;
    }

    void Bullet::bulletMovement() {     //increments the bullet position on y axis
        m_bulCoord.y -= 1;      //moves the bullets
    }

}